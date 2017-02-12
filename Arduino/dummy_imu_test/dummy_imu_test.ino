//#include <Wire.h>
#include <ros.h>
#include <std_msgs/Int32.h>
//#include <sensor_msgs/Temperature.h>


//Set up the ros node and publisher



//sensor_msgs::Temperature force_msg1;
//sensor_msgs::Temperature force_msg2;
std_msgs::Int32 force_msg1;
//std_msgs::Float32 force_msg2;
ros::Publisher pub_force1("force1", &force_msg1);
//ros::Publisher pub_force2("force2", &force_msg2);
ros::NodeHandle nh;

//int sensorAddress = 0x91 >> 1;  // From datasheet sensor address is 0x91
                                // shift the address 1 bit right,
                                 //the Wire library only needs the 7
                                // most significant bits for the address

void setup()
{
  //Wire.begin();        // join i2c bus (address optional for master)

  nh.initNode();
  //force_msg1.header.stamp;
  nh.advertise(pub_force1);
  //nh.advertise(pub_force2);

}

//long publisher_timer = 0;
long currentTime = 0;
long lastTime = 0;
int count = 0;

void loop()
{
  currentTime = millis();

  if(currentTime - lastTime >= 1) {
     lastTime = currentTime;

  //if (millis() >= publisher_timer) {
  
      //force_msg1.header.stamp = nh.now();
      //force_msg2.header.stamp = nh.now();
        force_msg1.data = count;
      //force_msg1.temperature = analogRead(A0);
      //force_msg2.temperature = analogRead(A2);
      
      pub_force1.publish(&force_msg1);
      //pub_force2.publish(&force_msg2);
    
    count ++;

  //publisher_timer = millis() + 1; //publish once a second
  }

  nh.spinOnce();
}
