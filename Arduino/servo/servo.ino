/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>


//Set up the ros node and publisher
std_msgs::UInt16 force_msg;

ros::Publisher pub_force("servo_reply", &force_msg);

ros::NodeHandle  nh;

Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg){

 servo.write(cmd_msg.data*180.0/100.0); //set servo angle, should be from 0-180 
  force_msg.data = cmd_msg.data*180.0/100.0;
  pub_force.publish(&force_msg);
  //servo.write(0);
  //servo.write(cmd_msg.data);
  //if(cmd_msg.data == 30) {
    digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
 // }

}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup(){
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub_force);
  servo.attach(9); //attach it to pin 9
  servo.write(50);
  delay(5000);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
