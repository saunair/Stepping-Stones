#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
from morpheus_skates.msg import skate_command
from morpheus_skates.msg import skate_feedback
import numpy
from morpheus_skates.srv import *
import tf
import roslib; roslib.load_manifest('morpheus_skates')

total_weight = 0

###change these!
right_single_stance_threshold = 10
#right_double_stance_threshold = 0.4

left_single_stance_threshold = 10
#left_double_stance_threshold = 0.4

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
    global send_control, previous_right_time, right_bias_front_outer, right_bias_front_inner, right_bias_rear, right_gain_front_outer, right_gain_front_inner, right_gain_rear, right_preload_front_outer, right_preload_front_inner, right_preload_rear, total_weight, right_force_front_outer, right_force_front_inner, right_force_rear

    print "right_force_front_outer", float(float(float(right.force_front_outer - right_bias_front_outer)/right_gain_front_outer) - right_preload_front_outer)/total_weight
    print "right_force_front_inner", float(float(float(right.force_front_inner - right_bias_front_inner)/right_gain_front_inner) - right_preload_front_inner)/total_weight
    print "right_force_rear",        float((float(right.force_rear - right_bias_rear)/right_gain_rear) - right_preload_rear)/total_weight
    right_force_front_outer = float(float(float(right.force_front_outer - right_bias_front_outer)/right_gain_front_outer) - right_preload_front_outer)/total_weight
    right_force_front_inner = float(float(float(right.force_front_inner - right_bias_front_inner)/right_gain_front_inner) - right_preload_front_inner)/total_weight
    right_force_rear        = float((float(right.force_rear - right_bias_rear)/right_gain_rear) - right_preload_rear)/total_weight


def stop_system_left(left):
    global send_control, previous_left_time, left_bias_front_outer, left_bias_front_inner, left_bias_rear, left_gain_front_outer, left_gain_front_inner, left_gain_rear, left_preload_front_outer, left_preload_front_inner, left_preload_rear, total_weight, left_force_front_outer, left_force_front_inner, left_force_rear
    
    print "left_force_front_outer", float(float(left.force_front_outer - left_bias_front_outer)/left_gain_front_outer - left_preload_front_outer)/total_weight
    print "left_force_front_inner", float(float(left.force_front_inner - left_bias_front_inner)/left_gain_front_inner - left_preload_front_inner)/total_weight
    print "left_force_rear",        float(((left.force_rear - left_bias_rear)/left_gain_rear) - left_preload_rear)/total_weight
    left_force_front_outer =  float(float(left.force_front_outer - left_bias_front_outer)/left_gain_front_outer - left_preload_front_outer)/total_weight
    left_force_front_inner = float(float(left.force_front_inner - left_bias_front_inner)/left_gain_front_inner - left_preload_front_inner)/total_weight
    left_force_rear        = float(((left.force_rear - left_bias_rear)/left_gain_rear) - left_preload_rear)/total_weight

def run_normalization_routine():

    rospy.wait_for_service('sensors_normalized', 60)
    try:
        resp = rospy.ServiceProxy('sensors_normalized', sensors_normalized)
        #not passing one anymore to  move on from empty
        resp = resp()
        print "total_weight", resp.total_weight
        return resp.total_weight
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

  
def gait_determination():
    global total_weight
    if total_weight!=0:
        if (float(left_force_front_outer + left_force_front_inner + left_force_rear) < left_single_stance_threshold):
            print "state:left foot is in swing phase"

        elif (float(right_force_front_outer + right_force_front_inner + right_force_rear) < right_single_stance_threshold):
            print "state:right foot is in swing phase"

        #elif (float(left_force_front_outer + left_force_front_inner + left_force_rear)/total_weight > left_double_stance_threshold) and (float(right_force_front_outer + right_force_front_inner + right_force_rear)/total_weight) > right_double_stance_threshold:
        else:
            print "state:double stance"

if __name__ == '__main__':
    global total_weight
    rospy.init_node('normalization_display', anonymous=True)
    total_weight = run_normalization_routine()
    print total_weight
    a = input('check')
    rospy.Subscriber("right", skate_feedback, stop_system_right)
    rospy.Subscriber("left", skate_feedback, stop_system_left)
    
    while not rospy.is_shutdown():
        gait_determination()
        rospy.spin()
        #print "working"
        #rate.sleep()


        

