/* 
 * rosserial Time and TF Example
 * Publishes a transform at current time
 */    


//#include <Wire.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Temperature.h>
#include <UM.h>
#include <ros/time.h>
//#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
    
//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM imu;
sensor_msgs::Imu imu_msg;

ros::Publisher imu_pub( "imu_data", &imu_msg);

ros::NodeHandle  nh;
//geometry_msgs::TransformStamped t;

//geometry_msgs/Vector3 linear_acceleration
//tf::TransformBroadcaster broadcaster;
   
char base_link[] = "/base_link";
char imu_frame[] = "/imu";

//Set up the ros node and publisher

sensor_msgs::Temperature force_msg1;
sensor_msgs::Temperature force_msg2;
//std_msgs::Float32 force_msg1;
//std_msgs::Float32 force_msg2;
ros::Publisher pub_force1("force1", &force_msg1);
ros::Publisher pub_force2("force2", &force_msg2);


//int sensorAddress = 0x91 >> 1;  // From datasheet sensor address is 0x91
                                // shift the address 1 bit right,
                                 //the Wire library only needs the 7
                                // most significant bits for the address

void setup()
{
  

  nh.initNode();
  nh.advertise(pub_force1);
  nh.advertise(pub_force2);
  nh.advertise(imu_pub);
  
 // broadcaster.init(nh);
  Serial1.begin(115200);

}

long publisher_timer = 0;

void loop()
{

//  if (millis() > publisher_timer) {
//  
//      force_msg1.header.stamp = nh.now();
//      force_msg2.header.stamp = nh.now();
//      force_msg1.temperature = analogRead(A0);
//      force_msg2.temperature = analogRead(A1);
//      
//      pub_force1.publish(&force_msg1);
//      pub_force2.publish(&force_msg2);
//    
//    
//
//      publisher_timer = millis(); //publish once a second
//  }
  if (Serial1.available() > 0) {
      if (imu.encode(Serial1.read())) {
        /* t.header.frame_id = odom;
        t.child_frame_id = base_link;
        t.transform.translation.x = 0.3; 
        t.transform.translation.z = 0.3; 
        t.transform.translation. y= 0.3; 
        t.transform.rotation.x = imu.roll;
        t.transform.rotation.y = imu.yaw; 
        t.transform.rotation.z = imu.pitch; 
        t.transform.rotation.w = 1.0;  
        t.header.stamp = nh.now();x
        */


        force_msg1.header.stamp = nh.now();
        force_msg2.header.stamp = nh.now();
        force_msg1.temperature = analogRead(A0);
        force_msg2.temperature = analogRead(A1);
      
        pub_force1.publish(&force_msg1);
        pub_force2.publish(&force_msg2);
        
        imu_msg.linear_acceleration.x = imu.accel_x;
        imu_msg.linear_acceleration.y = imu.accel_y;
        imu_msg.linear_acceleration.z = imu.accel_z;
        
       /* 
        imu_msg.linear_acceleration.x = imu.roll;
        imu_msg.linear_acceleration.y = imu.pitch 
        imu_msg.linear_acceleration.z = imu.yaw;
       */
        imu_msg.angular_velocity.x = imu.pitch_rate; // imu.pitch_rate, imu.yaw.rate>;
        imu_msg.angular_velocity.y = imu.yaw_rate;
        imu_msg.angular_velocity.z = imu.roll_rate;
//        imu_msg.orientation = imu.roll_rate;;

        imu_msg.orientation.x = imu.quatx;
        imu_msg.orientation.y =imu.quaty;
        imu_msg.orientation.z =imu.quatz;
        imu_msg.orientation.w = imu.quatw;
        
        imu_msg.header.frame_id =  imu_frame;
        imu_msg.header.stamp=nh.now();
        imu_pub.publish(&imu_msg);
        //imu_msg = imu;
        //broadcaster.sendTransform(t);
        //nh.spinOnce();
        //delay(10);
        Serial1.flush();
    }
  }

  

  nh.spinOnce();
}
