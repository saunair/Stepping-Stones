#!/usr/bin/env python
#Author: Saurabh Nair
#Edited BY Aditya Ghadiali and Koushuik 
import roslib; roslib.load_manifest('morpheus_skates')
import rospy
from std_msgs.msg import *
from morpheus_skates.msg import *
import tf
import copy
import time
publish_rate = rospy.get_param("publish_rate")
PreloadThreshold = -0.06

preload_right_loose = 0
preload_left_loose = 0
announce_right_loose = 0
announce_left_loose = 0

total_message = integrated_message()

def left_update(data):
    global total_message
    total_message.left_feedback = data

def right_update(data):
    global total_message
    total_message.right_feedback = data

def pounds_update(data):
    global total_message
    total_message.pounds_values = data

def position_offset_update(data):
    global total_message
    total_message.user_position_offset = data.data

def normalize_update(data1):
    
    data = copy.deepcopy(data1)
    global total_message, preload_left_loose, preload_right_loose, announce_left_loose, announce_right_loose
   
    if data.left_normal_front_outer<0:
    	if data.left_normal_front_outer<PreloadThreshold:
    		preload_left_loose = True
    	data.left_normal_front_outer=0
    

	if data.left_normal_front_inner<0:
	    if data.left_normal_front_inner<PreloadThreshold:
                preload_left_loose = True
    	data.left_normal_front_inner=0
    	

	if data.left_normal_rear<0:
	    if data.left_normal_rear<PreloadThreshold:
    		preload_left_loose = True	
    	data.left_normal_rear=0
    	
	
	if data.right_normal_front_outer<0:
	    if data.right_normal_front_outer<PreloadThreshold:
    		preload_right_loose = True
	data.right_normal_front_outer=0
		
	
	if data.right_normal_front_inner<0:
	    if data.right_normal_front_inner<PreloadThreshold:
    		preload_right_loose = True
    	data.right_normal_front_inner=0
   
	
	if data.right_normal_rear<0:
            if data.left_normal_rear<PreloadThreshold:
    		preload_right_loose = True
    	data.right_normal_rear=0


    if preload_right_loose and not(announce_right_loose):
        rospy.logwarn("Fix preload for right")
	announce_right_loose = 1
    if preload_left_loose and not(announce_left_loose):
        rospy.logwarn("Fix preload for left")
	announce_left_loose = 1
	
    total_message.normalized_force = data

def agg_message_publish():
    global total_message, publish_rate
    pub = rospy.Publisher('total_message', integrated_message, queue_size=10)
    rospy.init_node('feature_integrator', anonymous=True)
    rate = rospy.Rate(publish_rate) # 100hz
    listener_trans = tf.TransformListener()

    rospy.Subscriber("left_feedback", skate_feedback, left_update)
    rospy.Subscriber("right_feedback", skate_feedback, right_update)
    rospy.Subscriber("pounds_per_sensor", pounds_display, pounds_update)
    rospy.Subscriber("normalized_force_per_sensor", user_force_normalized, normalize_update)
    rospy.Subscriber("user_position_offset", Float64, position_offset_update)
    acquire_zero_point = 1
    while(acquire_zero_point):
        try:
            z_x = rospy.get_param("zero_pos_x")
            z_y = rospy.get_param("zero_pos_y")
            z_z = rospy.get_param("zero_pos_z")
            acquire_zero_point = 0
            print "acquired"
        except:
            continue

    while not rospy.is_shutdown():
	try:
            (trans_left_hip,rot1)   = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
	    total_message.hip_left[0] = trans_left_hip[0] - z_x 
            total_message.hip_left[1] = trans_left_hip[1] - z_y
            total_message.hip_left[2] = trans_left_hip[2] - z_z
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_right_hip,rot1)  = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
            total_message.hip_right[0] = trans_right_hip[0] - z_x
            total_message.hip_right[1] = trans_right_hip[1] - z_y
            total_message.hip_right[2] = trans_right_hip[2] - z_z 
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_left_foot,rot1)  = listener_trans.lookupTransform('/openni_depth_frame', '/left_foot_1', rospy.Time(0))
            total_message.foot_left[0] = trans_left_foot[0] - z_x
            total_message.foot_left[1] = trans_left_foot[1] - z_y
            total_message.foot_left[2] = trans_left_foot[2] - z_z
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_right_foot,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/right_foot_1', rospy.Time(0))
            total_message.foot_right[0] = trans_right_foot[0] - z_x
            total_message.foot_right[1] = trans_right_foot[1] - z_y
            total_message.foot_right[2] = trans_right_foot[2] - z_z 	
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_COM,rot1)        = listener_trans.lookupTransform('/openni_depth_frame', '/centre_mass', rospy.Time(0))
            total_message.centre_of_mass_kinect[0] = trans_COM[0] - z_x
            total_message.centre_of_mass_kinect[1] = trans_COM[1] - z_y
            total_message.centre_of_mass_kinect[2] = trans_COM[2] - z_z 
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass


        total_message.header.stamp = rospy.get_rostime()
        pub.publish(total_message)
        
        rate.sleep()

if __name__ == '__main__':
    try:
        agg_message_publish()
    except rospy.ROSInterruptException:
        pass

