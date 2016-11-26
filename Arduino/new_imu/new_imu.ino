/* 
     * rosserial Time and TF Example
     * Publishes a transform at current time
     */    
#include <UM.h>
#include <ros.h>
#include <ros/time.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
    
//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM imu;
sensor_msgs::Imu imu_msg;

ros::Publisher imu_pub( "imu_data", &imu_msg);

ros::NodeHandle  nh;
geometry_msgs::TransformStamped t;

//geometry_msgs/Vector3 linear_acceleration
tf::TransformBroadcaster broadcaster;
   
char base_link[] = "/base_link";
char imu_frame[] = "/imu";
   
void setup()
{
  nh.initNode();
 
  nh.advertise(imu_pub);
  
 // broadcaster.init(nh);
  Serial1.begin(115200);
}
   
void loop()
{  
  if (Serial1.available() > 0) {
      if (imu.encode(Serial1.read())) {
//         t.header.frame_id = imu_frame;
//        t.child_frame_id = base_link;
//        t.transform.translation.x = 0.3; 
//        t.transform.translation.z = 0.3; 
//        t.transform.translation. y= 0.3; 
//        t.transform.rotation.x = imu.roll;
//        t.transform.rotation.y = imu.yaw; 
//        t.transform.rotation.z = imu.pitch; 
//        t.transform.rotation.w = 1.0;  
//        t.header.stamp = nh.now();


        imu_msg.linear_acceleration.x = imu.accel_x;
        imu_msg.linear_acceleration.y = imu.accel_y;
        imu_msg.linear_acceleration.z = imu.accel_z;
        
       

        imu_msg.angular_velocity.x = imu.pitch_rate; // imu.pitch_rate, imu.yaw.rate>;
        imu_msg.angular_velocity.y = imu.yaw_rate;
        imu_msg.angular_velocity.z = imu.roll_rate;
      //  imu_msg.orientation = 1.0;
        imu_msg.header.frame_id =  imu_frame;
        imu_msg.header.stamp=nh.now();
        imu_pub.publish(&imu_msg);
//        imu_msg = imu;
        //broadcaster.sendTransform(t);
        nh.spinOnce();
        //delay(10);
    }
  }
}
