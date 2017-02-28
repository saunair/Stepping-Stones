//Revision 2/28/2017
#define LEFT_SKATE 1
#define RIGHT_SKATE 0

#define FRC_OUTER_CH 2
#define FRC_INNER_CH 1
#define FRC_REAR_CH 0

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define CTRL_PERIOD_MS 4.0
#define SAMP_PERIOD_MS 1.0

#define SERIAL_BUFFER_SIZE 256
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
long lastPubTimeStamp = 0;

int global_set_point;
float master_time;
byte skate_fault = 0;
int timeOverrunCnt = 0;
bool controlLoopActive = false;
bool imuRxComplete = false;

float posnGainsFront[] = {0.3,0,0};
float posnGainsRear[] = {0.3,0,0};
float velGainsFront[] = {0,0.0003,0};
float velGainsRear[] = {0,0.0003,0};

float frontVelCmd;
float rearVelCmd;

bool checkAdcReady = false;

byte requestIdx = 0;
const byte quatRequest[] = {115,110,112,72,109,2,6};
const byte accelRequest[] = {115,110,112,76,101,2,2};
const byte rateRequest[] = {115,110,112,76,97,1,254};


void ros_sub_cb(const morpheus_skates::skate_command&);
void formPacket();
void check_reset_system();
void doEncoderFrontChA();
void doEncoderFrontChB();
void doEncoderRearChA();
void doEncoderRearChB();
void serialEvent1();


//Sensor data type and publisher declaration
morpheus_skates::skate_feedback feedback;
#if LEFT_SKATE == true
  ros::Publisher ros_pub("left", &feedback);
#endif
#if RIGHT_SKATE == true
  ros::Publisher ros_pub("right", &feedback);
#endif
ros::Subscriber<morpheus_skates::skate_command> sub("servo", ros_sub_cb);
ros::NodeHandle nh;

Force forceSensors(FRC_OUTER_CH,FRC_INNER_CH,FRC_REAR_CH);

Drive frontDrive(ENC1_CHA_PIN,ENC1_CHB_PIN,ESC1_PIN); 
Control frontControl(posnGainsFront,velGainsFront,LEFT_SKATE==true,CTRL_PERIOD_MS);

Drive rearDrive(ENC2_CHA_PIN,ENC2_CHB_PIN,ESC2_PIN);
Control rearControl(posnGainsRear,velGainsRear,RIGHT_SKATE==true,CTRL_PERIOD_MS);

UM imu;

void setup() {
  if(LEFT_SKATE == RIGHT_SKATE) {
    while(1);
  }
  
  //ROS Setup
  nh.initNode();   
  nh.getHardware()->setBaud(921600);
  nh.advertise(ros_pub);
  nh.subscribe(sub);

  //Set up Force Sensing
  ADCSRA = bit(ADEN); //turn ADC on
  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);  // Prescaler of 128
  ADMUX  =  bit (REFS0) | (0 & 0x07);    // AVcc and select input port

  //Set Up Front Skate
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoderFrontChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoderFrontChB, CHANGE);
  frontDrive.initializeDrive();

  //Set Up Rear Skate
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoderRearChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoderRearChB, CHANGE);
  rearDrive.initializeDrive();

  Serial1.begin(115200);
}

void loop(){ 
  currentTimeStamp = millis();

  //Sampling Loop
  if((currentTimeStamp - lastSampTimeStamp) >= SAMP_PERIOD_MS) {
    lastSampTimeStamp = currentTimeStamp;

    frontDrive.updateState();
    rearDrive.updateState();
    checkAdcReady = forceSensors.startCycle();
  }

  //Control Loop
  if((currentTimeStamp - lastCtrlTimeStamp) >= CTRL_PERIOD_MS) {
    lastCtrlTimeStamp = currentTimeStamp;
    
    if(controlLoopActive == true) {
      timeOverrunCnt = timeOverrunCnt + 1;
    }

    controlLoopActive = true;
    
    target = global_set_point;
    check_reset_system();

    switch(requestIdx) {
      case 0:
        Serial1.write(quatRequest,7);
        requestIdx = 1;
        break;
      case 1:
        Serial1.write(accelRequest,7);
        requestIdx = 2;
        break;
      case 2:
        Serial1.write(rateRequest,7);
        requestIdx = 0;
        break;
      default:
        requestIdx = 0;
        break;  
    }

    frontVelCmd = frontControl.computeCommand(target,frontDrive.getPosition(),frontDrive.getVelocity());
    if(frontControl.checkModeTransition() == true) frontDrive.resetState();
    frontDrive.setCommand(frontVelCmd);

    rearVelCmd = rearControl.computeCommand(target,rearDrive.getPosition(),rearDrive.getVelocity());
    if(rearControl.checkModeTransition() == true) rearDrive.resetState();
    rearDrive.setCommand(rearVelCmd);
       
    skate_fault = rearControl.checkErrors();
    skate_fault |= frontControl.checkErrors() << 2;
    skate_fault |= (timeOverrunCnt & 0xF) << 4;
    controlLoopActive = false;
  }

  if(checkAdcReady == true) {
    checkAdcReady = forceSensors.checkReady();
  }

  //if((imuRxComplete == true) || ((currentTimeStamp-lastPubTimeStamp) >= PUB_PERIOD_MS)) {
  if(imuRxComplete == true) {
    imuRxComplete = false;
    lastPubTimeStamp = currentTimeStamp;
    formPacket();
    ros_pub.publish(&feedback);
    nh.spinOnce();
  }
}

void ros_sub_cb(const morpheus_skates::skate_command& cmd_msg){
  global_set_point = cmd_msg.command_target*(skate_fault==0);
  master_time = millis();
}

void formPacket() {
    feedback.header.stamp = nh.now();
  
    feedback.force_front_outer = forceSensors.getAdcOuter();
    feedback.force_front_inner = forceSensors.getAdcInner();
    feedback.force_rear = forceSensors.getAdcRear();

    feedback.imu_accel_x = imu.accel_x;
    feedback.imu_accel_y = imu.accel_y;
    feedback.imu_accel_z = imu.accel_z;

    feedback.imu_rate_x = imu.gyro_x;
    feedback.imu_rate_y = imu.gyro_y;
    feedback.imu_rate_z = imu.gyro_z;

    feedback.imu_quat_x = imu.quatx;
    feedback.imu_quat_y = imu.quaty;
    feedback.imu_quat_z = imu.quatz;
    feedback.imu_quat_w = imu.quatw;

    feedback.velocity_cmd_rear = rearVelCmd; 
    feedback.velocity_cmd_front = frontVelCmd;

    feedback.skate_fault = skate_fault;
    feedback.position_filt_rear = rearDrive.getPosition();
    feedback.position_filt_front = frontDrive.getPosition();

    feedback.velocity_filt_rear = rearDrive.getVelocity();    
    feedback.velocity_filt_front = frontDrive.getVelocity();

    feedback.controller_target = frontControl.getControllerTarget(); //Need value for Rear Control

    feedback.skate_mode = frontControl.getMode() + (rearControl.getMode()<<2);
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
  checkAdcReady = forceSensors.serviceSensors(ADC);  
}

void serialEvent1() {
  bool returnVal;
  returnVal = imu.encode(Serial1.read());
  if(returnVal == true){
    imuRxComplete = true;
  }
}

