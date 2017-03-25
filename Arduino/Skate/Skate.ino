//Revision 3/24/2017
#define LEFT_SKATE_IND_PIN 52
#define RIGHT_SKATE_IND_PIN 53

#define FRC_OUTER_CH 0
#define FRC_INNER_CH 1
#define FRC_REAR_CH 2

#define ENC1_CHA_PIN 2
#define ENC1_CHB_PIN 3

#define ENC2_CHA_PIN 21
#define ENC2_CHB_PIN 20

#define DEAD_MAN_SW_PIN 30
#define HEARTBEAT_PIN 45

#define CTRL_PERIOD_MS 10.0
#define SAMP_PERIOD_MS 2.0
#define ALIVE_PERIOD_MS 500.0

#define SERIAL_BUFFER_SIZE 512
#define TIMEOUT_MS 1000

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <ros/time.h>
#include <morpheus_skates/skate_feedback.h>
#include <morpheus_skates/skate_command.h>
#include "Control.h"
#include "Drive.h"
#include "Force.h"
#include "UM.h"

float target = 0;

long currentTimeStamp = 0;
long lastCtrlTimeStamp = 0;
long lastSampTimeStamp = 0;
long lastAliveTimeStamp = 0;

int global_set_point;
float master_time;
byte skate_fault = 0;
int timeOverrunCnt = 0;
bool controlLoopActive = false;
bool imuRxComplete = false;
bool imuTxComplete = false;

long startTime = 0;

//float posnGainsFront[] = {0.3,0,0};
//float posnGainsRear[] = {0.3,0,0};
float posnGainsFront[] = {0,0,0};
float posnGainsRear[] = {0,0,0};
//float velGainsFront[] = {0,0.0006,0};
//float velGainsRear[] = {0,0.0006,0};
float velGainsFront[] = {0,0.00001,0};
float velGainsRear[] = {0,0.00001,0};

float frontVelCmd;
float frontVelCmdPrev = 0;
float rearVelCmd;
float rearVelCmdPrev = 0;

bool leftSkate = false;
bool rightSkate = false;

//UM7
const byte allRequests[] = {115,110,112,72,109,2,6,115,110,112,76,101,2,2,115,110,112,76,97,1,254};
/*const byte quatRequest[] = {115,110,112,72,109,2,6};
const byte accelRequest[] = {115,110,112,76,101,2,2};
const byte rateRequest[] = {115,110,112,76,97,1,254};*/
//UM6
/*const byte quatRequest[] = {115,110,112,72,100,1,253};
const byte accelRequest[] = {115,110,112,76,94,1,251};
const byte rateRequest[] = {115,110,112,76,92,1,249};*/

void ros_sub_cb(const morpheus_skates::skate_command&);
void formPacket();
void check_reset_system();
void doEncoderFrontChA();
void doEncoderFrontChB();
void doEncoderRearChA();
void doEncoderRearChB();

//Sensor data type and publisher declaration
morpheus_skates::skate_feedback feedback;
ros::Publisher ros_pub_left("left", &feedback);
ros::Publisher ros_pub_right("right", &feedback);
ros::Subscriber<morpheus_skates::skate_command> sub("servo", ros_sub_cb);
ros::NodeHandle nh;

Force forceSensors(FRC_OUTER_CH,FRC_INNER_CH,FRC_REAR_CH);

Drive frontDrive(ENC1_CHA_PIN,ENC1_CHB_PIN,&Serial2); 
Control frontControl(posnGainsFront,velGainsFront,CTRL_PERIOD_MS);

Drive rearDrive(ENC2_CHA_PIN,ENC2_CHB_PIN,&Serial3);
Control rearControl(posnGainsRear,velGainsRear,CTRL_PERIOD_MS);

UM imu;

void setup() {
  pinMode(LEFT_SKATE_IND_PIN, INPUT_PULLUP);
  pinMode(RIGHT_SKATE_IND_PIN, INPUT_PULLUP);
  if(digitalRead(LEFT_SKATE_IND_PIN) == digitalRead(RIGHT_SKATE_IND_PIN)) {
    while(1);
  }
  if(digitalRead(LEFT_SKATE_IND_PIN) == LOW) {
    leftSkate = true;    
  }
  if(digitalRead(RIGHT_SKATE_IND_PIN) == LOW) {
    rightSkate = true;
  }
  
  //ROS Setup
  nh.initNode();   
  nh.getHardware()->setBaud(115200);
  if(leftSkate == true) {
    nh.advertise(ros_pub_left);
  }
  if(rightSkate == true) {
    nh.advertise(ros_pub_right);
  }
  nh.subscribe(sub);

  //Set up Force Sensing
  ADCSRA = bit(ADEN); //turn ADC on
  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);  // Prescaler of 128
  ADMUX  =  bit (REFS0) | (FRC_OUTER_CH & 0x07);    // AVcc and select input port

  //Set Up Front Skate
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoderFrontChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoderFrontChB, CHANGE);
  frontDrive.initializeDrive();
  frontControl.setInvertFlag(leftSkate == true);

  //Set Up Rear Skate
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoderRearChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoderRearChB, CHANGE);
  rearDrive.initializeDrive();
  rearControl.setInvertFlag(rightSkate == true);

  pinMode(DEAD_MAN_SW_PIN, INPUT_PULLUP);
  pinMode(HEARTBEAT_PIN, OUTPUT);

  Serial1.begin(115200);
  Serial1.write(allRequests,21);
}

void loop(){ 
  currentTimeStamp = micros();

  //Sampling Loop
  if((currentTimeStamp - lastSampTimeStamp) >= (SAMP_PERIOD_MS*1000)) {
    lastSampTimeStamp = currentTimeStamp;

    forceSensors.startCycle();
    frontDrive.updateState();
    rearDrive.updateState();
  }

  //Control Loop
  if((currentTimeStamp - lastCtrlTimeStamp) >= (CTRL_PERIOD_MS*1000)) {
    lastCtrlTimeStamp = currentTimeStamp;
    feedback.debug_int3 = (micros() - startTime);
    startTime = micros();
    
    if(controlLoopActive == true) {
      timeOverrunCnt = timeOverrunCnt + 1;
    }

    controlLoopActive = true;

    target = global_set_point;
    check_reset_system();

    frontVelCmdPrev = frontVelCmd;
    frontVelCmd = frontControl.computeCommand(target,frontDrive.getPosition(),frontDrive.getVelocity());
    if(frontControl.checkModeTransition() == true) frontDrive.resetState();
    if(frontVelCmdPrev != frontVelCmd) frontDrive.setDutyCycle(frontVelCmd);

    rearVelCmdPrev = rearVelCmd;
    rearVelCmd = rearControl.computeCommand(target,rearDrive.getPosition(),rearDrive.getVelocity());
    if(rearControl.checkModeTransition() == true) rearDrive.resetState();
    if(rearVelCmdPrev != rearVelCmd) rearDrive.setDutyCycle(rearVelCmd);
       
    skate_fault = rearControl.checkErrors();
    skate_fault |= frontControl.checkErrors() << 2;
    skate_fault |= (timeOverrunCnt & 0xF) << 4;
    feedback.debug_int1 = int(micros() - startTime);

    formPacket();
    if(leftSkate == true) {
      ros_pub_left.publish(&feedback);
    }
    if(rightSkate == true) {
      ros_pub_right.publish(&feedback);
    }
    nh.spinOnce();
    feedback.debug_int2 = int(micros() - startTime);
    controlLoopActive = false;
  }

  //Alive Loop
  if((currentTimeStamp - lastAliveTimeStamp) >= (ALIVE_PERIOD_MS*1000)) {
    lastAliveTimeStamp = currentTimeStamp;
    
    frontDrive.resetTimeout();
    rearDrive.resetTimeout();

    digitalWrite(HEARTBEAT_PIN,!digitalRead(HEARTBEAT_PIN));
  }
}

void ros_sub_cb(const morpheus_skates::skate_command& cmd_msg){
  //global_set_point = cmd_msg.command_target*(skate_fault==0);
  global_set_point = cmd_msg.command_target;
  master_time = millis();
}

void formPacket() {
    feedback.header.stamp = nh.now();
  
    feedback.force_front_outer = forceSensors.getAdcOuter();
    feedback.force_front_inner = forceSensors.getAdcInner();
    feedback.force_rear = forceSensors.getAdcRear();

    feedback.velocity_cmd_rear = rearVelCmd; 
    feedback.velocity_cmd_front = frontVelCmd;

    feedback.skate_fault = skate_fault;
    feedback.position_filt_rear = rearDrive.getPosition();
    feedback.position_filt_front = frontDrive.getPosition();

    feedback.velocity_filt_rear = rearDrive.getVelocity();    
    feedback.velocity_filt_front = frontDrive.getVelocity();
    
    feedback.controller_target_rear = rearControl.getControllerTarget();
    feedback.controller_target_front = frontControl.getControllerTarget();

    feedback.skate_mode = frontControl.getMode() + (rearControl.getMode()<<2);

    //Migrate read to control class
    feedback.dead_man_enable = (digitalRead(DEAD_MAN_SW_PIN) == LOW);

    if(imu.updates == 7) {
      imu.updates = 0;
      feedback.debug_int4 = feedback.debug_int4 + 1;
         
      feedback.imu_accel_x = imu.accel_x;
      feedback.imu_accel_y = imu.accel_y;
      feedback.imu_accel_z = imu.accel_z;

      feedback.imu_rate_x = imu.gyro_x;
      feedback.imu_rate_y = imu.gyro_y;
      feedback.imu_rate_z = imu.gyro_z;

      feedback.imu_quat_x = imu.quatA;
      feedback.imu_quat_y = imu.quatB;
      feedback.imu_quat_z = imu.quatC;
      feedback.imu_quat_w = imu.quatD;

      Serial1.write(allRequests,21);
    }
}

void check_reset_system() 
{
  if(millis() - master_time > TIMEOUT_MS) {
    global_set_point = 0;
  }
}

void doEncoderFrontChA() {
  frontDrive.serviceEncoder(1);
}

void doEncoderFrontChB() {
  frontDrive.serviceEncoder(2);
}

void doEncoderRearChA() {
  rearDrive.serviceEncoder(1);
}

void doEncoderRearChB() {
  rearDrive.serviceEncoder(2);
}

ISR (ADC_vect) {
  //checkAdcReady = forceSensors.serviceSensors(ADC);  
  forceSensors.serviceSensors(ADC); 
}

ISR (USART1_RX_vect) {
  char data;
  data = UDR1;
  imu.encode(data);
}

