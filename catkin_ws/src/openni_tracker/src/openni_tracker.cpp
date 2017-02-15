// openni_tracker.cpp


#include <ros/ros.h>
#include <ros/package.h>
#include <tf/transform_broadcaster.h>
#include <kdl/frames.hpp>
#include <XnOpenNI.h>
#include <XnCodecIDs.h>
#include <XnCppWrapper.h>
#include <ros/console.h>
#include <nav_msgs/Odometry.h>

#define head 0
#define trunk 1
#define thigh 2
#define foot 3
#define calves 4
#define forearms 5
#define upper_arm 6

using std::string;

xn::Context        g_Context;
xn::DepthGenerator g_DepthGenerator;
xn::UserGenerator  g_UserGenerator;

XnBool g_bNeedPose   = FALSE;
XnChar g_strPose[20] = "";
 


/* head-neck-trunk, upper extrimities, both upper arms, forarms and hands, forearms, hands, lower extremeties, thighs, calves and feet, calves, feet*/
float weight_link[] = {0.47, 0.13, 0.08, 0.06, 0.04, 0.01, 0.31, 0.18, 0.13, 0.11, 0.02};

/* head, trunk, thigh, foot, calves, forearms,upper arm */
float weight_broken[] = {0.0694, 0.4346, 0.105, 0.0143, 0.11, 0.0187, 0.0325};


float new_weight[] = {0.0694, 0.434,  0.10, 0.014, 0.10, 0.0187, 0.032};

void XN_CALLBACK_TYPE User_NewUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie) {
    ROS_INFO("New User %d", nId);
	//ROS_INFO("old User %d", nId);
	//ROS_INFO("very old User %d", nId);

	if (g_bNeedPose)
		g_UserGenerator.GetPoseDetectionCap().StartPoseDetection(g_strPose, nId);
	else
		g_UserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}

void XN_CALLBACK_TYPE User_LostUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie) {
	ROS_INFO("Lost user %d", nId);
}

void XN_CALLBACK_TYPE UserCalibration_CalibrationStart(xn::SkeletonCapability& capability, XnUserID nId, void* pCookie) {
	ROS_INFO("Calibration started for user %d", nId);
}

void XN_CALLBACK_TYPE UserCalibration_CalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess, void* pCookie) {
	if (bSuccess) {
		ROS_INFO("Calibration complete, start tracking user %d", nId);
		g_UserGenerator.GetSkeletonCap().StartTracking(nId);
	}
	else {
		ROS_INFO("Calibration failed for user %d", nId);
		if (g_bNeedPose)
			g_UserGenerator.GetPoseDetectionCap().StartPoseDetection(g_strPose, nId);
		else
			g_UserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
	}
}

void XN_CALLBACK_TYPE UserPose_PoseDetected(xn::PoseDetectionCapability& capability, XnChar const* strPose, XnUserID nId, void* pCookie) {
    ROS_INFO("Pose %s detected for user %d", strPose, nId);
	ROS_ERROR_STREAM("Hello Listen INFO " << nId);
    g_UserGenerator.GetPoseDetectionCap().StopPoseDetection(nId);
    g_UserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}

void publishTransform(XnUserID const& user, XnSkeletonJoint const& joint, string const& frame_id, string const& child_frame_id, double *x_temp, double *y_temp, double *z_temp) {
    static tf::TransformBroadcaster br;

    XnSkeletonJointPosition joint_position;
    g_UserGenerator.GetSkeletonCap().GetSkeletonJointPosition(user, joint, joint_position);
    double x = -joint_position.position.X / 1000.0;
    double y = joint_position.position.Y / 1000.0;
    double z = joint_position.position.Z / 1000.0;
    //printf("%f", x_cm);
    *x_temp = x;
    *y_temp = y;
    *z_temp = z;

    XnSkeletonJointOrientation joint_orientation;
    g_UserGenerator.GetSkeletonCap().GetSkeletonJointOrientation(user, joint, joint_orientation);

    XnFloat* m = joint_orientation.orientation.elements;
    KDL::Rotation rotation(m[0], m[1], m[2],
    					   m[3], m[4], m[5],
    					   m[6], m[7], m[8]);
    double qx, qy, qz, qw;
    rotation.GetQuaternion(qx, qy, qz, qw);

    char child_frame_no[128];
    snprintf(child_frame_no, sizeof(child_frame_no), "%s_%d", child_frame_id.c_str(), user);

    tf::Transform transform;
    transform.setOrigin(tf::Vector3(x, y, z));
    transform.setRotation(tf::Quaternion(qx, -qy, -qz, qw));

    // #4994
    tf::Transform change_frame;
    change_frame.setOrigin(tf::Vector3(0, 0, 0));
    tf::Quaternion frame_rotation;
    frame_rotation.setEulerZYX(1.5708, 0, 1.5708);
    change_frame.setRotation(frame_rotation);

    transform = change_frame * transform;

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), frame_id, child_frame_no));
}

void publishTransforms(const std::string& frame_id) {



    XnUserID users[15];
    XnUInt16 users_count = 15;
    g_UserGenerator.GetUsers(users, users_count);


	ros::NodeHandle n_;
        ros::Subscriber odom_sub_; ///< members are suffixed with '_'
        tf::TransformBroadcaster tf_broadcaster_;

    for (int i = 0; i < users_count; ++i) {
	double x_cm, y_cm, z_cm, x_temp, y_temp, z_temp, x_temp1, y_temp1, z_temp1;
        XnUserID user = users[i];
        if (!g_UserGenerator.GetSkeletonCap().IsTracking(user))
            continue;

	
        publishTransform(user, XN_SKEL_HEAD,           frame_id, "head", &x_temp, &y_temp, &z_temp);
        x_cm  += new_weight[head]*x_temp;
	y_cm  += new_weight[head]*y_temp;
        z_cm  += new_weight[head]*z_temp; 
	publishTransform(user, XN_SKEL_NECK,           frame_id, "neck",  &x_temp, &y_temp, &z_temp);
        publishTransform(user, XN_SKEL_TORSO,          frame_id, "torso", &x_temp, &y_temp, &z_temp);
	
        x_cm  += new_weight[trunk]*x_temp;
	y_cm  += new_weight[trunk]*y_temp;
        z_cm  += new_weight[trunk]*z_temp; 

	
        publishTransform(user, XN_SKEL_LEFT_SHOULDER,  frame_id, "left_shoulder", &x_temp, &y_temp, &z_temp);
        publishTransform(user, XN_SKEL_LEFT_ELBOW,     frame_id, "left_elbow", &x_temp1, &y_temp1, &z_temp1);
    
	x_temp += x_temp1;  
	y_temp += y_temp1;  
	z_temp += z_temp1;

	
	x_temp /= 2;
	y_temp /= 2;
	z_temp /= 2;
        
	x_cm  += new_weight[upper_arm]*x_temp;
	y_cm  += new_weight[upper_arm]*y_temp;
        z_cm  += new_weight[upper_arm]*z_temp; 
	  
        publishTransform(user, XN_SKEL_LEFT_HAND,      frame_id, "left_hand", &x_temp, &y_temp, &z_temp);

	x_temp1 += x_temp;
	y_temp1 += y_temp;
	z_temp1 += z_temp;
	
	x_temp1 /= 2;
	y_temp1 /= 2;
	z_temp1 /= 2;

	x_cm  += new_weight[forearms]*x_temp1;
	y_cm  += new_weight[forearms]*y_temp1;
        z_cm  += new_weight[forearms]*z_temp1; 

        publishTransform(user, XN_SKEL_RIGHT_SHOULDER, frame_id, "right_shoulder", &x_temp, &y_temp, &z_temp);
        publishTransform(user, XN_SKEL_RIGHT_ELBOW,    frame_id, "right_elbow", &x_temp1, &y_temp1, &z_temp1);
	
	x_temp1 += x_temp;
	x_temp1 /=2;
	y_temp1 += y_temp;
	y_temp1 /=2;
	z_temp1 += z_temp;
	z_temp1 /=2;
        
	x_cm  += new_weight[upper_arm]*x_temp;
	y_cm  += new_weight[upper_arm]*y_temp;
        z_cm  += new_weight[upper_arm]*z_temp; 
       
        

	publishTransform(user, XN_SKEL_RIGHT_HAND,     frame_id, "right_hand", &x_temp, &y_temp, &z_temp);
	x_temp1 += x_temp;
	x_temp1 /=2;
	y_temp1 += y_temp;
	y_temp1 /=2;
	z_temp1 += z_temp;
	z_temp1 /=2;

	x_cm  += new_weight[forearms]*x_temp1;
	y_cm  += new_weight[forearms]*y_temp1;
        z_cm  += new_weight[forearms]*z_temp1; 


        publishTransform(user, XN_SKEL_LEFT_HIP,       frame_id, "left_hip", &x_temp, &y_temp, &z_temp);
        publishTransform(user, XN_SKEL_LEFT_KNEE,      frame_id, "left_knee", &x_temp1, &y_temp1, &z_temp1);
        
	x_temp += x_temp1;
	x_temp /=2;
	y_temp += y_temp1;
	y_temp /=2;
	z_temp += z_temp1;
	z_temp /=2;

	x_cm  += new_weight[thigh]*x_temp;
	y_cm  += new_weight[thigh]*y_temp;
        z_cm  += new_weight[thigh]*z_temp; 

	publishTransform(user, XN_SKEL_LEFT_FOOT,      frame_id, "left_foot", &x_temp, &y_temp, &z_temp);

	
	x_temp += x_temp1;
	x_temp /=2;
	y_temp += y_temp1;
	y_temp /=2;
	z_temp += z_temp1;
	z_temp /=2;

	x_cm  += new_weight[calves]*x_temp;
	y_cm  += new_weight[calves]*y_temp;
        z_cm  += new_weight[calves]*z_temp; 

        publishTransform(user, XN_SKEL_RIGHT_HIP,      frame_id, "right_hip", &x_temp, &y_temp, &z_temp);
        publishTransform(user, XN_SKEL_RIGHT_KNEE,     frame_id, "right_knee", &x_temp1, &y_temp1, &z_temp1);
        
	x_temp += x_temp1;
	x_temp /=2;
	y_temp += y_temp1;
	y_temp /=2;
	z_temp += z_temp1;
	z_temp /=2;

	x_cm  += new_weight[thigh]*x_temp;
	y_cm  += new_weight[thigh]*y_temp;
        z_cm  += new_weight[thigh]*z_temp; 
	publishTransform(user, XN_SKEL_RIGHT_FOOT,     frame_id, "right_foot", &x_temp, &y_temp, &z_temp);
	x_temp1 += x_temp;
	x_temp1 /=2;
	y_temp1 += y_temp;
	y_temp1 /=2;
	z_temp1 += z_temp;
	z_temp1 /=2;

	x_cm  += new_weight[calves]*x_temp1;
	y_cm  += new_weight[calves]*y_temp1;
        z_cm  += new_weight[calves]*z_temp1;


    float temp;
    temp = z_cm;    
    z_cm = x_cm;
    x_cm = temp;   
    
    temp  = z_cm;
    z_cm = y_cm; 
    y_cm = temp;   

    
    //ROS_INFO("x_cm =%f, y_cm =%f, z_cm = %f", x_cm, y_cm, z_cm);
	
	geometry_msgs::TransformStamped base_link_tf; 
        base_link_tf.header.stamp = ros::Time::now();
        base_link_tf.header.frame_id = "openni_depth_frame";
        base_link_tf.child_frame_id = "centre_mass";

/*	base_link_tf.transform.rotation.x = 0;
	base_link_tf.transform.rotation.y = 0;
	base_link_tf.transform.rotation.z = 0;
	base_link_tf.transform.rotation.w = 0;

	base_link_tf.transform.translation.x = x_cm;
        base_link_tf.transform.translation.y = y_cm;
        base_link_tf.transform.translation.z = z_cm;

*/
/*	double qx, qy, qz, qw;
	qx = 0.499999999997;
        qy =0.500001836603;
        qz = 0.499999999997;
        qw=  0.499998163397;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(0, 0, 0));
    transform.setRotation(tf::Quaternion(qx, -qy, -qz, qw));
    std::cout << x_cm <<" "<< y_cm << " " << z_cm<<"\n";
    ROS_INFO("Pose hehe detected for user %d", x_cm);
    
	// #4994
    tf::Transform change_frame;
    change_frame.setOrigin(tf::Vector3(x_cm, y_cm, z_cm));
    tf::Quaternion frame_rotation;
    frame_rotation.setEulerZYX(1.5708, 0, 1.5708);
    change_frame.setRotation(frame_rotation);

    transform = change_frame * transform;
*/
 
    static tf::TransformBroadcaster br;
    tf::Transform transform;
    transform.setOrigin( tf::Vector3(x_cm, y_cm, z_cm) );
    tf::Quaternion q;
    q.setRPY(0, 0, 0);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "openni_depth_frame", "/centre_mass"));
//   tf_broadcaster_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), frame_id, "centre_mass"));


//	tf_broadcaster_.sendTransform(base_link_tf); 
 //   tf_broadcaster.sendTransform(tf::StampedTransform(transform, ros::Time::now(), frame_id, "centre_mass"));
    }
}

#define CHECK_RC(nRetVal, what)										\
	if (nRetVal != XN_STATUS_OK)									\
	{																\
		ROS_ERROR("%s failed: %s", what, xnGetStatusString(nRetVal));\
		return nRetVal;												\
	}

int main(int argc, char **argv) {
    ros::init(argc, argv, "openni_tracker");
    ros::NodeHandle nh;

    string configFilename = ros::package::getPath("openni_tracker") + "/openni_tracker.xml";
    XnStatus nRetVal = g_Context.InitFromXmlFile(configFilename.c_str());
    CHECK_RC(nRetVal, "InitFromXml");

    nRetVal = g_Context.FindExistingNode(XN_NODE_TYPE_DEPTH, g_DepthGenerator);
    CHECK_RC(nRetVal, "Find depth generator");

	nRetVal = g_Context.FindExistingNode(XN_NODE_TYPE_USER, g_UserGenerator);
	if (nRetVal != XN_STATUS_OK) {
		nRetVal = g_UserGenerator.Create(g_Context);
	    if (nRetVal != XN_STATUS_OK) {
		    ROS_ERROR("NITE is likely missing: Please install NITE >= 1.5.2.21. Check the readme for download information. Error Info: User generator failed: %s", xnGetStatusString(nRetVal));
            return nRetVal;
	    }
	}

	if (!g_UserGenerator.IsCapabilitySupported(XN_CAPABILITY_SKELETON)) {
		ROS_INFO("Supplied user generator doesn't support skeleton");
		return 1;
	}

    XnCallbackHandle hUserCallbacks;
	g_UserGenerator.RegisterUserCallbacks(User_NewUser, User_LostUser, NULL, hUserCallbacks);

	XnCallbackHandle hCalibrationCallbacks;
	g_UserGenerator.GetSkeletonCap().RegisterCalibrationCallbacks(UserCalibration_CalibrationStart, UserCalibration_CalibrationEnd, NULL, hCalibrationCallbacks);

	if (g_UserGenerator.GetSkeletonCap().NeedPoseForCalibration()) {
		g_bNeedPose = TRUE;
		if (!g_UserGenerator.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION)) {
			ROS_INFO("Pose required, but not supported");
			return 1;
		}

		XnCallbackHandle hPoseCallbacks;
		g_UserGenerator.GetPoseDetectionCap().RegisterToPoseCallbacks(UserPose_PoseDetected, NULL, NULL, hPoseCallbacks);

		g_UserGenerator.GetSkeletonCap().GetCalibrationPose(g_strPose);
	}

	g_UserGenerator.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

	nRetVal = g_Context.StartGeneratingAll();
	CHECK_RC(nRetVal, "StartGenerating");

	ros::Rate r(30);

        
        ros::NodeHandle pnh("~");
        string frame_id("openni_depth_frame");
        pnh.getParam("camera_frame_id", frame_id);
                
	while (ros::ok()) {
		g_Context.WaitAndUpdateAll();
		publishTransforms(frame_id);
		r.sleep();
	}

	g_Context.Shutdown();
	return 0;
}
