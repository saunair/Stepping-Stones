#!/usr/bin/env python
# license removed for brevity
#MRSD TEAM-H; Morpheus Skates
#Author: Saurabh Nair
#Edited By Brad Factor

import rospy
import time
from std_msgs.msg import UInt16
from std_msgs.msg import Float64

from morpheus_skates.msg import skate_command
from morpheus_skates.msg import skate_feedback
import numpy
from morpheus_skates.srv import *
import tf

import roslib; roslib.load_manifest('morpheus_skates')

skip_kinect = False; #Used for debugging controls/comms without Kinect functionality

publish_rate = rospy.get_param("publish_rate")

##### This node is the main master node that uses every service and controls most of the data flow. The command of the speed to the motor nodes is given by this file

left_skate_fault = 0
right_skate_fault = 0;


#state values
user_input = skate_command()
send_control = skate_command()
calibration = 0
user_input.calibration_enable = 0
user_input.command_target = 0
position_control = 1
velocity_control = 2
total_weight = 0


#velocity threshold! please decide!
velocity_threshold = 300

#time threshold
time_threshold = 20

send_control.calibration_enable = 0
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
kp = 50 # mm/s / m

def process_input(data):
    global user_input
    try:
        user_input.calibration_enable = data.calibration_enable
        user_input.command_target = data.command_target
    except:
        user_input.calibration_enable = 0
        user_input.command_target = 0

## The next teo methods check for the time of the latest message from the skates for stopping if timed out
def stop_system_right(right):
    global send_control, previous_right_time, right_skate_fault
    right_skate_fault = right.skate_fault
    previous_right_time = rospy.get_time()

def stop_system_left(left):
    global send_control, previous_left_time, left_skate_fault
    left_skate_fault = left.skate_fault
    previous_left_time = rospy.get_time()

## Check if the skate times out
def check_timeout(current_time):
    global send_control, time_threshold, previous_left_time, previous_right_time, right_skate_fault, left_skate_fault
    if ((current_time - previous_left_time)>time_threshold ):
        print current_time, previous_left_time
        send_control.command_target = 0
        print "One of the skates has timed out"
    #fault detected
    if not(left_skate_fault or right_skate_fault):
        send_control.command_target = 0
        print "fault detected"


#Ask for the zero point from the kinect
def ask_zero_point():
    #not waiting for 2 secs!!
    rospy.wait_for_service('zero_point')
    try:
        resp1 = rospy.ServiceProxy('zero_point', zero_point)
        resp1 = resp1()
        print "zero_point =" ,resp1
        return resp1.zero_x, resp1.zero_y, resp1.zero_z
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


## Ask for total weight of the user
def run_normalization_routine():
    rospy.wait_for_service('sensors_normalized')
    try:
        response = rospy.ServiceProxy('sensors_normalized', sensors_normalized)
        response = response()
        print "total_weight", response.total_weight
        return response.total_weight
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


## Ask for total weight of the user
def ask_shoe_size():
    rospy.wait_for_service('shoe_size')
    try:
        response = rospy.ServiceProxy('user_shoe_size', user_shoe_size)
        response = response()
        print "shoe_size", response.user_shoe_size
        return response.user_shoe_size
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


#main higher level control code
def send_controls():
    global send_control, previous_left_time, previous_right_time
    global z_x, z_y, z_z
    left_pub = rospy.Publisher('command_left', skate_command, queue_size=100)
    right_pub = rospy.Publisher('command_right', skate_command, queue_size=100)
    kin_pub = rospy.Publisher('user_position_offset', Float64, queue_size=100)
    
    rospy.init_node('stepping_stones', anonymous=True)
    previous_left_time  = rospy.get_time()
    previous_right_time  = rospy.Time.now()
    listener_trans = tf.TransformListener() 
    i = 0
    rate = rospy.Rate(publish_rate) # 100hz
    left_pub.publish(send_control)
    right_pub.publish(send_control)

    hello_str = "%d" % 50
    rospy.loginfo(hello_str)
    
    #subscribe to user inputs
    rospy.Subscriber("user_inputs", skate_command, process_input)
    rospy.Subscriber("right", skate_feedback, stop_system_right)
    rospy.Subscriber("left", skate_feedback, stop_system_left)
    
    while not rospy.is_shutdown():
        
        if not(user_input.calibration_enable):
            try:
                (trans1,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
		pass
    
            try:
                (trans2,rot2) = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
                pass
    
            #current kinect values 
            try:
                x_current = ((trans2[0] + trans1[0])/2)
                y_current = ((trans2[1] + trans1[1])/2)
                z_current = ((trans2[2] + trans1[2])/2)
                                                  
                x_error = z_x - x_current
                if user_input.command_target > 100:
                    send_control.command_target = user_input.command_target + kp*x_error
                else:
                    send_control.command_target = user_input.command_target
            except:
                send_control.command_target = user_input.command_target
		x_error = 0
                pass
        
        send_control.header.stamp = rospy.Time.now()	
        
        left_pub.publish(send_control)
        right_pub.publish(send_control)
        kin_pub.publish(x_error)
        rate.sleep()

if __name__ == '__main__':
    global total_weight, shoe_size
    if skip_kinect == False:
	    try:
		z_x, z_y, z_z = ask_zero_point()
		print "acquired zero point"
	    except rospy.ROSInterruptException:
		print "Sorry didn't acquire the zero position"
		pass
	    except:
		print "Sorry didn't acquire the zero position, going with default"
		z_x = 3.45787 
		z_y = 0.0881804
		z_z = 0.21108

    try:
        total_weight = run_normalization_routine() 
        shoe_size =  ask_shoe_size()
        send_controls()
    except rospy.ROSInterruptException:
        pass
