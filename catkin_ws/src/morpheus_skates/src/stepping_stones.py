#!/usr/bin/env python
# license removed for brevity
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

publish_rate = rospy.get_param("publish_rate")
skip_kinect = rospy.get_param('skip_kinect'); #Used for debugging controls/comms without Kinect functionality


left_skate_fault = 0
right_skate_fault = 0;


#state values
user_input = skate_command()
send_control = skate_command()
send_control_left = skate_command()
send_control_right = skate_command()
user_input.command_target = 0
position_control = 1
velocity_control = 2
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

skate_fault_annun = False
skate_power_annun = False


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
        user_input.command_target = data.command_target
    except:
        user_input.command_target = 0
        #print user_input.set_point


def stop_system_right(right):
    global send_control, previous_right_time, right_skate_fault
    right_skate_fault = right.skate_fault
    previous_right_time = rospy.get_time()

def stop_system_left(left):
    global send_control, previous_left_time, left_skate_fault
    left_skate_fault = left.skate_fault
    previous_left_time = rospy.get_time()


def check_timeout(current_time):
    global send_control, time_threshold, previous_left_time, previous_right_time, right_skate_fault, left_skate_fault
    global skate_fault_annun, skate
    if ((current_time - previous_left_time)>time_threshold ):
            #and (current_time - previous_right_time)>time_threshold):
        #print current_time, previous_left_time
        send_control.command_target = 0
	if not(skate_power_annun):
            print "One of the skates has timed out"
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




#main higher level control code
def send_controls():
    global send_control, previous_left_time, previous_right_time, send_control_left, send_control_right, publish_rate
    global z_x, z_y, z_z
    left_pub = rospy.Publisher('left_command', skate_command, queue_size=100)
    right_pub = rospy.Publisher('right_command', skate_command, queue_size=100)
    kin_pub = rospy.Publisher('user_position_offset', Float64, queue_size=100)
    rospy.init_node('stepping_stones', anonymous=True)
    previous_left_time  = rospy.get_time()
    previous_right_time  = rospy.Time.now()
    listener_trans = tf.TransformListener() 
    x_error = 0
    rate = rospy.Rate(publish_rate) # 100hz
    left_pub.publish(send_control_left)
    right_pub.publish(send_control_right)

    #subscribe to user inputs
    rospy.Subscriber("user_inputs", skate_command, process_input)
    rospy.Subscriber("right_feedback", skate_feedback, stop_system_right)
    rospy.Subscriber("left_feedback", skate_feedback, stop_system_left)
    
    while not rospy.is_shutdown():
        
        try:
            (trans1,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
	    pass
    
        try:
            (trans2,rot2) = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass

        try:
            (trans_left_foot,rot1)  = listener_trans.lookupTransform('/openni_depth_frame', '/left_foot_1', rospy.Time(0))
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_right_foot,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/right_foot_1', rospy.Time(0))
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
        try:
            (trans_COM,rot1)        = listener_trans.lookupTransform('/openni_depth_frame', '/centre_mass', rospy.Time(0))
        except(tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass
	
	try:
	    print trans1, trans2, trans_left_foot, trans_right_foot, trans_COM
        except:
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
        rate.sleep()

if __name__ == '__main__':
    global total_weight
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
        #total_weight = run_normalization_routine()  
        send_controls()
    except rospy.ROSInterruptException:
        pass
