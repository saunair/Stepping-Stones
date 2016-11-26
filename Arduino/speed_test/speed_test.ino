/* 
     * rosserial Time and TF Example
     * Publishes a transform at current time
     */    
#include <UM.h>
#include <ros.h>
#include <ros/time.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Float64.h>
#include<motor/Num.h>

#include <sensor_msgs/Imu.h>
    
//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM imu;
sensor_msgs::Imu imu_msg;

std_msgs::Float64 myData;

//ros::Publisher imu_pub( "imu_data", &imu_msg);

ros::NodeHandle  nh;
geometry_msgs::TransformStamped t;

ros::Publisher chatter("c", &myData);


void setup()
{
  nh.initNode();
 nh.advertise(chatter);
  //nh.advertise(imu_pub);
  nh.getHardware()->setBaud(115200);
 // broadcaster.init(nh);
  Serial1.begin(115200);
}
   
void loop()
{  
  //if (Serial1.available() > 0) {
   //   if (imu.encode(Serial1.read())) {

         //myData.data = imu.quatx;
          myData.data = 0.6660000000000000;
         chatter.publish( &myData );

        nh.spinOnce();
   // }
 // }
}
