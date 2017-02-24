//Revision 2/23/2017
#define LEFT_SKATE 1
#define RIGHT_SKATE 0

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define CTRL_PERIOD_MS 4.0
#define SAMP_PERIOD_MS 1.0
#define PUB_PERIOD_MS 20.0

#define SAMPLE_NUM (int)(2*(CTRL_PERIOD_MS/SAMP_PERIOD_MS))

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

bool init_motors = 0;
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

//float posnGainsFront[] = {2,0,0};
float posnGainsFront[] = {1,0,0};
float posnGainsRear[] = {1,0,0};
float velGainsFront[] = {0,0.001,0};
float velGainsRear[] = {0,0.001,0};

float frontVelCmd;
float rearVelCmd;


void servo_cb(const morpheus_skates::skate_command&);
void check_reset_system();
void doEncoderFrontChA();
void doEncoderFrontChB();
void doEncoderRearChA();
void doEncoderRearChB();


//Sensor data type and publisher declaration
morpheus_skates::skate_feedback sensor_data;
ros::Publisher chatter("left", &sensor_data);
ros::Subscriber<morpheus_skates::skate_command> sub("servo", servo_cb);
ros::NodeHandle nh;

Drive frontDrive(ENC1_CHA_PIN,ENC1_CHB_PIN,ESC1_PIN); 
Control frontControl(posnGainsFront,velGainsFront,LEFT_SKATE==true,CTRL_PERIOD_MS);

Drive rearDrive(ENC2_CHA_PIN,ENC2_CHB_PIN,ESC2_PIN);
Control rearControl(posnGainsRear,velGainsRear,RIGHT_SKATE==true,CTRL_PERIOD_MS);

void setup() {
  //ROS Setup
  nh.initNode();   
  nh.getHardware()->setBaud(921600);
  nh.advertise(chatter);
  nh.subscribe(sub);

  while(!init_motors)
  {
      nh.spinOnce();
  }

  //Set Up Front Skate
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoderFrontChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoderFrontChB, CHANGE);
  frontDrive.initializeDrive();

  //Set Up Rear Skate
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoderRearChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoderRearChB, CHANGE);
  rearDrive.initializeDrive();

  if(LEFT_SKATE == RIGHT_SKATE) {
    while(1);
  }
}

void loop(){ 
  currentTimeStamp = millis();

  //Sampling Loop
  if((currentTimeStamp - lastSampTimeStamp) >= SAMP_PERIOD_MS) {
    lastSampTimeStamp = currentTimeStamp;

    frontDrive.updateState();
    rearDrive.updateState();
  }
  
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
  }

  if((currentTimeStamp - lastPubTimeStamp) >= PUB_PERIOD_MS) {
    lastPubTimeStamp = currentTimeStamp;
    
    skate_fault = rearControl.checkErrors();
    skate_fault |= frontControl.checkErrors() << 2; 
    sensor_data.skate_fault = skate_fault;
 
    sensor_data.position_filt_front = frontDrive.getPosition();
    sensor_data.position_filt_rear = rearDrive.getPosition();
    
    sensor_data.velocity_filt_front = frontDrive.getVelocity();
    sensor_data.velocity_filt_rear = rearDrive.getVelocity();

    sensor_data.velocity_cmd_front = frontVelCmd;
    sensor_data.velocity_cmd_rear = rearVelCmd; 

    sensor_data.skate_mode = frontControl.getMode() + (rearControl.getMode()<<2);
    
    sensor_data.controller_target = frontControl.getControllerTarget(); //Need value for Rear Control

    sensor_data.imu_accel_x = (float)frontControl.controlTimeDelta;
    sensor_data.imu_accel_y = (float)rearControl.controlTimeDelta;

    sensor_data.imu_rate_x = (float)spinDeltaTime;
    sensor_data.imu_rate_y = (float)frontDrive.onTime;
    sensor_data.imu_rate_z = (float)rearDrive.onTime;

    sensor_data.imu_quat_x = (float)frontDrive.updateTimeDelta;
    sensor_data.imu_quat_y = (float)frontDrive.commandTimeDelta;
    sensor_data.imu_quat_z = (float)rearDrive.updateTimeDelta;
    sensor_data.imu_quat_w = (float)rearDrive.commandTimeDelta;
    
    spinStartTimeStamp = micros();
    chatter.publish( &sensor_data );
    nh.spinOnce();
    spinDeltaTime = micros() - spinStartTimeStamp;
  }
}

void servo_cb(const morpheus_skates::skate_command& cmd_msg){
  //global_set_point = cmd_msg.command_target*(skate_fault==0);
  global_set_point = cmd_msg.command_target;
  master_time = millis();
  init_motors = 1;
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
