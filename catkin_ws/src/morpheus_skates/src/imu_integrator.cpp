#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "morpheus_skates/skate_feedback.h"
#include <stdlib.h>
#include <math.h>       /* atan2 */
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include "morpheus_skates/zero_point.h"


double velocity_x = 0;
double velocity_y = 0;
double velocity_z = 0;

double position_x = 0;
double position_y = 0;
double position_z = 0;

#define FORCE_FRONT_THRESHOLD 40
#define FORCE_REAR_THRESHOLD 40

static tf::StampedTransform transform_kinect;
static tf::TransformBroadcaster br;
double heading = 0, attitude = 0, bank = 0; 

double qw=0, qx=0, qy=0, qz=0;
float rotation[3][3] = {0}; 

/* Publish transform */
void poseCallback(const morpheus_skates::skate_feedback& msg) {
    static tf::TransformBroadcaster br;
    tf::Transform transform;
    
    /* Change this to kinect zero point  */
    transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
    tf::Quaternion q;
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "openn_depth_frame", "skate_pose"));
}

/* structure to save the  quarternions */
struct quat 
{
    double w,x,y,z;
};

/* quarternions to matrix function, uses a global mattrix to manipulate values */
void quatToMatrix( quat q)
{
    double sqw = q.w*q.w;
    double sqx = q.x*q.x;
    double sqy = q.y*q.y;
    double sqz = q.z*q.z;
    double m10, m01, m11, m22, m00, m12, m21, m20, m02;
    
    //invs (inverse square length) is only required if quaternion is not already normalised
    double invs = 1 / (sqx + sqy + sqz + sqw);
    m00 = ( sqx - sqy - sqz + sqw) * invs ; // since sqw + sqx + sqy + sqz =1/invs*invs
    m11 = (-sqx + sqy - sqz + sqw) * invs ;
    m22 = (-sqx - sqy + sqz + sqw) * invs ;
                        
    double tmp1 = q.x*q.y;
    double tmp2 = q.z*q.w;
    m10 = 2.0 * (tmp1 + tmp2)*invs;
    m01 = 2.0 * (tmp1 - tmp2)*invs;
                  
    tmp1 = q.x*q.z;
    tmp2 = q.y*q.w;
    m20 = 2.0 * (tmp1 - tmp2)*invs;
    m02 = 2.0 * (tmp1 + tmp2)*invs;
    tmp1 = q.y*q.z;
    tmp2 = q.x*q.w;
    m21 = 2.0 * (tmp1 + tmp2)*invs;
    m12 = 2.0 * (tmp1 - tmp2)*invs;      
    
    rotation[0][0] = m00;
    rotation[0][1] = m01;
    rotation[0][2] = m02;
    rotation[1][0] = m10;
    rotation[1][1] = m11;
    rotation[1][2]  = m12;
    rotation[2][0] = m20;
    rotation[2][1] = m21;
    rotation[2][2] = m22;
    

}

void left_integrate_values(const morpheus_skates::skate_feedback::ConstPtr& sensor_data)
{	

    /* The following condition might change dependent on the state classification code */
    if(((sensor_data->force_front_outer + sensor_data->force_front_outer) < FORCE_FRONT_THRESHOLD) || (sensor_data->force_rear < FORCE_REAR_THRESHOLD)) {
    	quat quaternions;
    	quaternions.w = sensor_data->imu_quat_w;
    	quaternions.x = sensor_data->imu_quat_x;
    	quaternions.y = sensor_data->imu_quat_y;
    	quaternions.z = sensor_data->imu_quat_z;


	double ax,ay,az, delta_t;
    	quatToMatrix( quaternions);
    	ax = rotation[0][0]*sensor_data->imu_accel_x + rotation[0][1]*sensor_data->imu_accel_y + rotation[0][2]*sensor_data->imu_accel_z;
    	ay = rotation[0][0]*sensor_data->imu_accel_x + rotation[1][1]*sensor_data->imu_accel_y + rotation[1][2]*sensor_data->imu_accel_z;
    	az = rotation[2][0]*sensor_data->imu_accel_x + rotation[2][1]*sensor_data->imu_accel_y + rotation[2][2]*sensor_data->imu_accel_z;
    	velocity_x = velocity_x + ax*delta_t;
    	position_x = position_x + velocity_x*delta_t; 
    	velocity_y = velocity_y + ay*delta_t;
    	position_y = position_y + velocity_y*delta_t;
    	velocity_z = velocity_z + az*delta_t;
    	position_z = position_z + velocity_z*delta_t;
    
    } else {
	 
	/* reset the positions to kinect positions*/
    	position_x = transform_kinect.getOrigin().x();
    	position_y = transform_kinect.getOrigin().y();
    	position_z = transform_kinect.getOrigin().z();
    	velocity_x = double(sensor_data->velocity_filt_front  + sensor_data->velocity_filt_front)/2;
    	velocity_y = 0;
    	velocity_z = 0;
    }
}

int main(int argc, char **argv)
{
    double previous_time = 0;


    double z_x, z_y, z_z;
    ros::init(argc, argv, "imu_integrator");
    ros::NodeHandle n;
    //ros::Publisher chatter_pub = n.advertise<::String>("skate_position", 1000);
    ros::Rate loop_rate(10);


    /*morpheus_skates::zero_point srv;
    srv.response.zero_x = atoll(argv[1]);
    srv.response.zero_y = atoll(argv[2]);
    srv.response.zero_z = atoll(argv[3]);
    */
    n.getParam("zero_pos_x", z_x);
    n.getParam("zero_pos_x", z_y);
    n.getParam("zero_pos_x", z_z);

    
    tf::TransformListener listener;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(z_x, z_y, z_z));
    tf::Quaternion quat;
    quat.setRPY(0,0,0);
    transform.setRotation(quat);
   
    //ros::ServiceClient client = n.serviceClient<morpheus_skates::zero_point>("kinect_zero");

    while (n.ok()){
       // subscribe to force sensor values and kinect positions in the world frame. 
       while(ros::ok()) {
           //chatter_pub.publish(msg);
           previous_time  = abs(ros::Time::now().toSec() - previous_time);
           ros::Subscriber sub = n.subscribe("left", 1000, left_integrate_values);
           try{
               listener.lookupTransform("/openni_depth_frame", "/left_foot",  
                                  ros::Time(0), transform_kinect);
           }
           catch (tf::TransformException ex){
               ROS_ERROR("%s",ex.what());
               ros::Duration(1.0).sleep();
           }  
      	   br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/openni_depth_frame", "skate_position")); 
           ros::spin();
       }
    }	
}
