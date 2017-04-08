#!/usr/bin/env python
# license removed for brevity
import rospy
import time
import copy
import numpy
import tf
import roslib; roslib.load_manifest('morpheus_skates')

from std_msgs.msg import *
from morpheus_skates.msg import *
from morpheus_skates.srv import *

publish_rate = rospy.get_param("publish_rate")
skip_kinect = rospy.get_param('skip_kinect'); #Used for debugging controls/comms without Kinect functionality

left_skate_fault = 0
right_skate_fault = 0;
PreloadThreshold = -0.06
preload_right_loose = 0
preload_left_loose = 0
announce_right_loose = 0
announce_left_loose = 0
skate_fault_annun = False
skate_power_annun = False

user_input = skate_command()
send_control = skate_command()
send_control_left = skate_command()
send_control_right = skate_command()
total_message = integrated_message()
user_input.command_target = 0
total_weight = 0

#previous_left_time  = rospy.Time.now() 
#previous_right_time = rospy.Time.now()

#velocity threshold! please decide!
velocity_threshold = 300

#time threshold
time_threshold = 2

send_control.command_target = 0

#default zero points
z_x= 3.45787 
z_y=0.0881804
z_z=0.211088


### required gains from the rosparam server
left_bias_front_outer = rospy.get_param('left_bias_front_outer')
left_bias_front_inner = rospy.get_param('left_bias_front_inner')
left_bias_rear = rospy.get_param('left_bias_rear')
left_gain_front_outer = rospy.get_param('left_gain_front_outer')
left_gain_front_inner = rospy.get_param('left_gain_front_inner')
left_gain_rear = rospy.get_param('left_gain_rear')
left_preload_front_outer = rospy.get_param('left_preload_front_outer')
left_preload_front_inner = rospy.get_param('left_preload_front_inner')
left_preload_rear = rospy.get_param('left_preload_rear')

right_bias_front_outer = rospy.get_param('right_bias_front_outer')
right_bias_front_inner = rospy.get_param('right_bias_front_inner')
right_bias_rear = rospy.get_param('right_bias_rear')
right_gain_front_outer = rospy.get_param('right_gain_front_outer')
right_gain_front_inner = rospy.get_param('right_gain_front_inner')
right_gain_rear = rospy.get_param('right_gain_rear')
right_preload_front_outer = rospy.get_param('right_preload_front_outer')
right_preload_front_inner = rospy.get_param('right_preload_front_inner')
right_preload_rear = rospy.get_param('right_preload_rear')

#Kinect-based controller values
kp = 100 # mm/s / m

def process_input(data):
    global user_input
    try:
        user_input.command_target = data.command_target
    except:
        user_input.command_target = 0
        #print user_input.set_point


def left_update(left):
    global total_message, previous_left_time, left_skate_fault
    left_skate_fault = left.skate_fault
    previous_left_time = rospy.get_time()
    total_message.left_feedback = left


def right_update(right):
    global total_message, previous_right_time, right_skate_fault
    right_skate_fault = right.skate_fault
    previous_right_time = rospy.get_time()
    total_message.right_feedback = right


def pounds_update(data):
    global total_message
    total_message.pounds_values = data


def position_offset_update(data):
    global total_message
    total_message.user_position_offset = data.data


def check_timeout(current_time):
    global send_control, time_threshold, previous_left_time, previous_right_time, right_skate_fault, left_skate_fault
    global skate_fault_annun, skate_power_annun
    if ((current_time - previous_left_time)>time_threshold ) or ((current_time - previous_right_time)>time_threshold):
        #print current_time, previous_left_time
        send_control.command_target = 0
	if not(skate_power_annun):
            print "One of the skates has timed out!"
 	    skate_power_annun = True
    #fault detected
    if (left_skate_fault or right_skate_fault):
        send_control.command_target = 0
	if not(skate_fault_annun):
            print "Internal skate fault detected!"
	    skate_fault_annun = True


#ask for the zero point from the kinect
def ask_zero_point():
    #not waiting for 2 secs!!
    rospy.wait_for_service('zero_point')
    try:
        resp1 = rospy.ServiceProxy('zero_point', zero_point)
        #not passing one anymore to  move on from empty
        resp1 = resp1()
        print "zero_point =" ,resp1
        return resp1.zero_x, resp1.zero_y, resp1.zero_z
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def run_normalization_routine():
   
    rospy.wait_for_service('sensors_normalized')
    try:
        response = rospy.ServiceProxy('sensors_normalized', sensors_normalized)
        #not passing one anymore to  move on from empty
        response = response()
        print "total_weight", response.total_weight
        return response.total_weight
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def normalize_update(data1):  
    data = copy.deepcopy(data1)
    global total_message, preload_left_loose, preload_right_loose, announce_left_loose, announce_right_loose
   
    if data.left_normal_front_outer<=0:
    	if data.left_normal_front_outer<PreloadThreshold:
    	   preload_left_loose = True
    	data.left_normal_front_outer=0

    if data.left_normal_front_inner<=0:
	if data.left_normal_front_inner<PreloadThreshold:
            preload_left_loose = True
        data.left_normal_front_inner=0

    if data.left_normal_rear<=0:
	if data.left_normal_rear<PreloadThreshold:
    	    preload_left_loose = True	
    	data.left_normal_rear=0
	
    if data.right_normal_front_outer<=0:
	if data.right_normal_front_outer<PreloadThreshold:
    	    preload_right_loose = True
	data.right_normal_front_outer=0
	
    if data.right_normal_front_inner<=0:
        if data.right_normal_front_inner<PreloadThreshold:
    	    preload_right_loose = True
    	data.right_normal_front_inner=0
	
    if data.right_normal_rear<=0:
        if data.right_normal_rear<PreloadThreshold:
    	    preload_right_loose = True
    	data.right_normal_rear=0

    if preload_right_loose and not(announce_right_loose):
        rospy.logwarn("Fix preload for right")
	announce_right_loose = 1
    if preload_left_loose and not(announce_left_loose):
        rospy.logwarn("Fix preload for left")
	announce_left_loose = 1

    total_message.header.stamp = rospy.get_rostime()	
    total_message.normalized_force = data

#main higher level control code
def send_controls():
    global send_control, previous_left_time, previous_right_time, send_control_left, send_control_right, publish_rate
    global z_x, z_y, z_z
    global total_message

    previous_left_time  = rospy.get_time()
    previous_right_time  = rospy.get_time()
    listener_trans = tf.TransformListener() 
    x_error = 0
    rate = rospy.Rate(publish_rate) # 100hz
    left_pub.publish(send_control_left)
    right_pub.publish(send_control_right)
    total_pub = rospy.Publisher('total_message', integrated_message, queue_size=10)
    #subscribe to user inputs
    rospy.Subscriber("user_inputs", skate_command, process_input)
    rospy.Subscriber("left_feedback", skate_feedback, left_update)
    rospy.Subscriber("right_feedback", skate_feedback, right_update)
    rospy.Subscriber("pounds_per_sensor", pounds_display, pounds_update)
    rospy.Subscriber("normalized_force_per_sensor", user_force_normalized, normalize_update)
    rospy.Subscriber("user_position_offset", Float64, position_offset_update)
    
    while not rospy.is_shutdown():
        
        try:
            (trans_left_hip,rot_left_hip) = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
            total_message.hip_left[0] = trans_left_hip[0] - z_x 
            total_message.hip_left[1] = trans_left_hip[1] - z_y
            total_message.hip_left[2] = trans_left_hip[2] - z_z
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
	    	pass
    
        try:
            (trans_right_hip,rot_right_hip) = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
            total_message.hip_right[0] = trans_right_hip[0] - z_x
            total_message.hip_right[1] = trans_right_hip[1] - z_y
            total_message.hip_right[2] = trans_right_hip[2] - z_z 
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass

        try:
            (trans_left_foot,rot_left_foot)  = listener_trans.lookupTransform('/openni_depth_frame', '/left_foot_1', rospy.Time(0))
            total_message.foot_left[0] = trans_left_foot[0] - z_x
            total_message.foot_left[1] = trans_left_foot[1] - z_y
            total_message.foot_left[2] = trans_left_foot[2] - z_z
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_right_foot,rot_right_foot) = listener_trans.lookupTransform('/openni_depth_frame', '/right_foot_1', rospy.Time(0))
            total_message.foot_right[0] = trans_right_foot[0] - z_x
            total_message.foot_right[1] = trans_right_foot[1] - z_y
            total_message.foot_right[2] = trans_right_foot[2] - z_z 	
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_COM,rot_COM)        = listener_trans.lookupTransform('/openni_depth_frame', '/centre_mass', rospy.Time(0))
            total_message.centre_of_mass_kinect[0] = trans_COM[0] - z_x
            total_message.centre_of_mass_kinect[1] = trans_COM[1] - z_y
            total_message.centre_of_mass_kinect[2] = trans_COM[2] - z_z
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
	

    
        #current kinect values 
        try:
            x_current = ((trans_right_hip[0] + trans_left_hip[0])/2)
            y_current = ((trans_right_hip[1] + trans_left_hip[1])/2)
            z_current = ((trans_right_hip[2] + trans_left_hip[2])/2)
                                              
            x_error = z_x - x_current
            if user_input.command_target > 100:
                send_control.command_target = user_input.command_target + kp*x_error
            else:
                send_control.command_target = user_input.command_target
        except:
            pass
        if skip_kinect==True:
            send_control.command_target = user_input.command_target
		
        
        send_control.header.stamp = rospy.Time.now()	
        check_timeout(rospy.get_time()) 
        send_control_left = send_control
        send_control_right = send_control
    	left_pub.publish(send_control_left)
    	right_pub.publish(send_control_right)	
        kin_pub.publish(x_error)
        total_message.header.stamp = rospy.get_rostime()
        total_pub.publish(total_message)

        rate.sleep()



if __name__ == '__main__':
    global total_weight
    if skip_kinect == False:
	    try:
		z_x, z_y, z_z = ask_zero_point()
		print "Acquired zero point"
	    except rospy.ROSInterruptException:
		print "Zero point not acquired!"
		pass
	    except:
		print "Zero point not acquired! Using default values"
		z_x = 3.45787 
		z_y = 0.0881804
		z_z = 0.21108

    left_pub = rospy.Publisher('left_command', skate_command, queue_size=100)
    right_pub = rospy.Publisher('right_command', skate_command, queue_size=100)
    kin_pub = rospy.Publisher('user_position_offset', Float64, queue_size=100)
    rospy.init_node('stepping_stones', anonymous=True)

    try: 
        send_controls()

    except rospy.ROSInterruptException:
        pass

        
