#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
from morpheus_skates.msg import skate_command
from morpheus_skates.msg import skate_feedback
from morpheus_skates.msg import pounds_display

import numpy
from morpheus_skates.srv import *
import tf
import roslib; roslib.load_manifest('morpheus_skates')

display_weight = pounds_display()





right_force_front_outer = 0
right_force_front_inner = 0
right_force_rear        = 0

left_force_front_outer = 0
left_force_front_inner = 0
left_force_rear        = 0

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
def stop_system_right(right):
    global send_control, previous_right_time, right_bias_front_outer, right_bias_front_inner, right_bias_rear, right_gain_front_outer, right_gain_front_inner, right_gain_rear, right_preload_front_outer, right_preload_front_inner, right_preload_rear, total_weight, right_force_front_outer, right_force_front_inner, right_force_rear, display_weight

    right_force_front_outer = float(float(float(right.force_front_outer - right_bias_front_outer)/right_gain_front_outer) - right_preload_front_outer)
    right_force_front_inner = float(float(float(right.force_front_inner - right_bias_front_inner)/right_gain_front_inner) - right_preload_front_inner)
    right_force_rear        = float((float(right.force_rear - right_bias_rear)/right_gain_rear) - right_preload_rear)
    display_weight.right_force_front_outer = right_force_front_outer
    display_weight.right_force_front_inner = right_force_front_inner
    display_weight.right_force_rear        = right_force_rear

def stop_system_left(left):
    global send_control, previous_left_time, left_bias_front_outer, left_bias_front_inner, left_bias_rear, left_gain_front_outer, left_gain_front_inner, left_gain_rear, left_preload_front_outer, left_preload_front_inner, left_preload_rear, total_weight, left_force_front_outer, left_force_front_inner, left_force_rear, display_weight
    left_force_front_outer =  float(float(left.force_front_outer - left_bias_front_outer)/left_gain_front_outer - left_preload_front_outer)
    left_force_front_inner = float(float(left.force_front_inner - left_bias_front_inner)/left_gain_front_inner - left_preload_front_inner)
    left_force_rear        = float((float(left.force_rear - left_bias_rear)/left_gain_rear) - left_preload_rear)
    display_weight.left_force_front_outer = left_force_front_outer
    display_weight.left_force_front_inner = left_force_front_inner
    display_weight.left_force_rear        = left_force_rear



if __name__ == '__main__':
    global  display_weight
    rospy.init_node('pounds_display', anonymous=True)
    # total_weight = run_normalization_routine()
    #print total_weight
    #a = input('check')
    rospy.Subscriber("right", skate_feedback, stop_system_right)
    rospy.Subscriber("left", skate_feedback, stop_system_left)
    pub = rospy.Publisher('pounds_per_sensor', pounds_display, queue_size=100)
    while not rospy.is_shutdown():
    	pub.publish(display_weight)
        print "print"
        rospy.spin()
