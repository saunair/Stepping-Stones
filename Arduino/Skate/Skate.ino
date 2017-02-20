//Revision 2/20/2017
#define LEFT_SKATE 0
#define RIGHT_SKATE 1

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define CTRL_PERIOD_MS 4.0
#define SAMP_PERIOD_MS 1.0

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

int global_state;
int global_set_point;
float master_time;
byte skate_fault = 0;

float posnGainsFront[] = {2,0,0};
float posnGainsRear[] = {1,0,0};
float velGainsFront[] = {0,0.001,0};
float velGainsRear[] = {0,0.001,0};


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

Drive frontDrive(ENC1_CHA_PIN,ENC1_CHB_PIN,ESC1_PIN,SAMPLE_NUM,SAMP_PERIOD_MS); 
Control frontControl(posnGainsFront,velGainsFront,LEFT_SKATE==true,CTRL_PERIOD_MS);

Drive rearDrive(ENC2_CHA_PIN,ENC2_CHB_PIN,ESC2_PIN,SAMPLE_NUM,SAMP_PERIOD_MS);
Control rearControl(posnGainsRear,velGainsRear,RIGHT_SKATE==true,CTRL_PERIOD_MS);

void setup() {
  //ROS Setup
  nh.initNode();   
  nh.getHardware()->setBaud(115200);
  nh.advertise(chatter);
  nh.subscribe(sub);

  while(!init_motors)
  {
      nh.spinOnce();
  }

  //Set Up Front Skate
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoderFrontChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoderFrontChB, CHANGE);

  //Set Up Rear Skate
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoderRearChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoderRearChB, CHANGE);

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

    if(RIGHT_SKATE == true) {
      frontDrive.setCommand(frontControl.computeCommand(target,frontDrive.getPosition(),frontDrive.getVelocity()));
      rearDrive.setCommand(rearControl.computeCommand(target,rearDrive.getPosition(),rearDrive.getVelocity()));
    }
    else {
      frontDrive.setCommand(-1*frontControl.computeCommand(target,frontDrive.getPosition(),frontDrive.getVelocity()));
      rearDrive.setCommand(-1*rearControl.computeCommand(target,rearDrive.getPosition(),rearDrive.getVelocity()));
    }

    skate_fault = rearControl.checkErrors();
    skate_fault |= frontControl.checkErrors() << 2; 
    sensor_data.skate_fault = skate_fault;
    
    sensor_data.velocity_filt_front = frontDrive.getVelocity();
    sensor_data.velocity_filt_rear = rearDrive.getVelocity();
     
    check_reset_system();
    nh.spinOnce();   
  }
}

void servo_cb(const morpheus_skates::skate_command& cmd_msg){
  global_set_point = cmd_msg.command_target*(skate_fault==0);
  master_time = millis();
  init_motors = 1;
  chatter.publish( &sensor_data );
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
