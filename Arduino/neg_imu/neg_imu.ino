/* 
 * rosserial Time and TF Example
 * Publishes a transform at current time
 */    

#define SERIAL_BUFFER_SIZE 256
//#include <Wire.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Temperature.h>
#include <UM.h>
#include <ros/time.h>
//#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <motor/Num.h>
    
//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM imu;


ros::NodeHandle  nh;

//Set up the ros node and publisher

motor::Num total_sensor;

ros::Publisher left("left", &total_sensor);

void setup()
{
  nh.initNode();
  nh.advertise(left);    
  nh.getHardware()->setBaud(115200);
  
  Serial1.begin(115200);
}

long publisher_timer = 0;

void loop()
{
  
 
  if (Serial1.available() > 0) {
     
      if (imu.encode(Serial1.read())) {
         

        total_sensor.header.stamp = nh.now();
        

        total_sensor.f1 = analogRead(A0);
        total_sensor.f2 = analogRead(A1);
        total_sensor.f3 = analogRead(A2);
      
        
        total_sensor.ax = imu.accel_x;
        total_sensor.ay = imu.accel_y;
        total_sensor.az = imu.accel_z;
        
       
        total_sensor.rp = imu.gyro_x; 
        total_sensor.ry = imu.gyro_y;
        total_sensor.rr = imu.gyro_z;


        total_sensor.qx = imu.quatx;
        total_sensor.qy =imu.quaty;
        total_sensor.qz =imu.quatz;
        total_sensor.qw = imu.quatw;




        left.publish(&total_sensor);
          


       
    
    }
  }
   
  nh.spinOnce();

}
