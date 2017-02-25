//Revision 2/25/2017
#define LEFT_SKATE 1
#define RIGHT_SKATE 0

#define FRC_OUTER_CH 0
#define FRC_INNER_CH 1
#define FRC_REAR_CH 2

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define CTRL_PERIOD_MS 4.0
#define SAMP_PERIOD_MS 1.0
//#define PUB_PERIOD_MS 4.0


//ROS Definitions
#define SERIAL_BUFFER_SIZE 256

//kept the ros master timout to 3 seconds
#define timeout_threshold 1000

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

//bool init_motors = 0;
float target = 0;

long currentTimeStamp = 0;
long lastCtrlTimeStamp = 0;
long lastSampTimeStamp = 0;
long lastPubTimeStamp = 0;

long spinStartTimeStamp = 0;
long spinDeltaTime = 0;

int global_state;
int global_set_point;
float master_time;
byte skate_fault = 0;

float posnGainsFront[] = {0.3,0,0};
float posnGainsRear[] = {0.3,0,0};
float velGainsFront[] = {0,0.0003,0};
float velGainsRear[] = {0,0.0003,0};

float frontVelCmd;
float rearVelCmd;

bool checkAdcReady = false;

byte requestIdx = 1;
const byte quatRequest[] = {115,110,112,72,109,2,6};
const byte accelRequest[] = {115,110,112,76,101,4,174};
const byte rateRequest[] = {115,110,112,76,97,1,254};


void servo_cb(const morpheus_skates::skate_command&);
void formPacket();
void check_reset_system();
void doEncoderFrontChA();
void doEncoderFrontChB();
void doEncoderRearChA();
void doEncoderRearChB();
void serialEvent1();


//Sensor data type and publisher declaration
morpheus_skates::skate_feedback sensor_data;
ros::Publisher chatter("left", &sensor_data);
ros::Subscriber<morpheus_skates::skate_command> sub("servo", servo_cb);
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
  nh.advertise(chatter);
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

  Serial1.begin(921600);
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

    target = global_set_point;

    frontVelCmd = frontControl.computeCommand(target,frontDrive.getPosition(),frontDrive.getVelocity());
    if(frontControl.checkModeTransition() == true) frontDrive.resetState();
    frontDrive.setCommand(frontVelCmd);

    rearVelCmd = rearControl.computeCommand(target,rearDrive.getPosition(),rearDrive.getVelocity());
    if(rearControl.checkModeTransition() == true) rearDrive.resetState();
    rearDrive.setCommand(rearVelCmd);
     
    //check_reset_system();
    
    //nh.spinOnce();   
  //}

  //if((currentTimeStamp - lastPubTimeStamp) >= PUB_PERIOD_MS) {
  //lastPubTimeStamp = currentTimeStamp;
    
    skate_fault = rearControl.checkErrors();
    skate_fault |= frontControl.checkErrors() << 2;

    formPacket();

    requestIdx = 1;
    Serial1.write(quatRequest,7);
    
    //spinStartTimeStamp = micros();
    chatter.publish( &sensor_data );
    nh.spinOnce();
    //spinDeltaTime = micros() - spinStartTimeStamp;
  }

  if(checkAdcReady == true) {
    checkAdcReady = forceSensors.checkReady();
  }
}

void servo_cb(const morpheus_skates::skate_command& cmd_msg){
  //global_set_point = cmd_msg.command_target*(skate_fault==0);
  global_set_point = cmd_msg.command_target;
  master_time = millis();
  //init_motors = 1;
}

void formPacket() {
    sensor_data.force_front_outer = forceSensors.getAdcOuter();
    sensor_data.force_front_inner = forceSensors.getAdcInner();
    sensor_data.force_rear = forceSensors.getAdcRear();

    sensor_data.imu_accel_x = imu.accel_x;
    sensor_data.imu_accel_y = imu.accel_y;
    sensor_data.imu_accel_z = imu.accel_z;

    sensor_data.imu_rate_x = imu.gyro_x;
    sensor_data.imu_rate_y = imu.gyro_y;
    sensor_data.imu_rate_z = imu.gyro_z;

    sensor_data.imu_quat_x = imu.quatx;
    sensor_data.imu_quat_y = imu.quaty;
    sensor_data.imu_quat_z = imu.quatz;
    sensor_data.imu_quat_w = imu.quatw;

    sensor_data.velocity_cmd_rear = rearVelCmd; 
    sensor_data.velocity_cmd_front = frontVelCmd;

    sensor_data.skate_fault = skate_fault;
    sensor_data.position_filt_rear = rearDrive.getPosition();
    sensor_data.position_filt_front = frontDrive.getPosition();

    sensor_data.velocity_filt_rear = rearDrive.getVelocity();    
    sensor_data.velocity_filt_front = frontDrive.getVelocity();

    sensor_data.controller_target = frontControl.getControllerTarget(); //Need value for Rear Control

    sensor_data.skate_mode = frontControl.getMode() + (rearControl.getMode()<<2);
}

void check_reset_system() 
{
  if(millis() - master_time > timeout_threshold) {
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
  while(Serial1.available()) {
    returnVal = imu.encode(Serial1.read());
  }
  if(returnVal == true){
    if(requestIdx == 1) {
      requestIdx = 2;
      Serial1.write(accelRequest,8);
    }
    if(requestIdx == 2) {
      requestIdx = 3;
      Serial1.write(rateRequest,8);
    }
  }
}

