#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
from morpheus_skates.msg import skate_command
from morpheus_skates.msg import user_force_normalized
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


normalized_force_values = user_force_normalized()

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
    global send_control, previous_right_time, right_bias_front_outer, right_bias_front_inner, right_bias_rear, right_gain_front_outer, right_gain_front_inner, right_gain_rear, right_preload_front_outer, right_preload_front_inner, right_preload_rear, total_weight, right_force_front_outer, right_force_front_inner, right_force_rear, normalized_force_values

    right_force_front_outer = float(float(float(right.force_front_outer - right_bias_front_outer)/right_gain_front_outer) - right_preload_front_outer)
    right_force_front_inner = float(float(float(right.force_front_inner - right_bias_front_inner)/right_gain_front_inner) - right_preload_front_inner)
    right_force_rear        = float(float(float(right.force_rear - right_bias_rear)/right_gain_rear) - right_preload_rear)
    normalized_force_values.right_normal_front_outer = right_force_front_outer/total_weight   
    normalized_force_values.right_normal_front_inner = right_force_front_inner/total_weight
    normalized_force_values.right_normal_rear = right_force_rear/total_weight
    normalized_force_values.right_normal_total = normalized_force_values.right_normal_front_outer +  normalized_force_values.right_normal_front_inner + normalized_force_values.right_normal_rear



def stop_system_left(left):
    global send_control, previous_left_time, left_bias_front_outer, left_bias_front_inner, left_bias_rear, left_gain_front_outer, left_gain_front_inner, left_gain_rear, left_preload_front_outer, left_preload_front_inner, left_preload_rear, total_weight, left_force_front_outer, left_force_front_inner, left_force_rear, normalized_force_values
    left_force_front_outer =  float(float(float(left.force_front_outer - left_bias_front_outer)/left_gain_front_outer) - left_preload_front_outer)
    left_force_front_inner =  float(float(float(left.force_front_inner - left_bias_front_inner)/left_gain_front_inner) - left_preload_front_inner)
    left_force_rear        =  float(float(float(left.force_rear - left_bias_rear)/left_gain_rear) - left_preload_rear)
    normalized_force_values.left_normal_front_outer = left_force_front_outer/total_weight 
    normalized_force_values.left_normal_front_inner = left_force_front_inner/total_weight
    normalized_force_values.left_normal_rear = left_force_rear/total_weight
    normalized_force_values.left_normal_total = normalized_force_values.left_normal_front_outer +  normalized_force_values.left_normal_front_inner + normalized_force_values.left_normal_rear

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
    global right_force_front_outer,right_force_front_inner,right_force_rear,left_force_front_inner,left_force_front_outer,left_force_rear, total_weight, normalized_force_values

    left_foot_on_ground = (float((left_force_rear + left_force_front_inner + left_force_front_outer)*total_weight) > left_single_stance_threshold)
    right_foot_on_ground = (float((right_force_front_inner + right_force_front_outer + right_force_rear)*total_weight) > right_single_stance_threshold)

    normalized_force_values.normal_total =  normalized_force_values.left_normal_total +  normalized_force_values.right_normal_total
    #print "gait deter node"
    '''
    if(left_foot_on_ground and right_foot_on_ground):
        print "Double Stance"

    if(left_foot_on_ground and not right_foot_on_ground):
        print "Single Stance on Left Foot"

    if(right_foot_on_ground and not left_foot_on_ground):
        print "Single Stance on Right Foot"

    if(not left_foot_on_ground and not right_foot_on_ground):
        print "In Air"
    '''
  

if __name__ == '__main__':
    
    global total_weight, normalized_force_values
    rospy.init_node('normalization_display', anonymous=True)
    total_weight = run_normalization_routine()
    rospy.Subscriber("right_feedback", skate_feedback, stop_system_right)
    rospy.Subscriber("left_feedback", skate_feedback, stop_system_left)
    pub = rospy.Publisher('normalized_force_per_sensor', user_force_normalized, queue_size=100)
    r = rospy.Rate(50) 
    while not rospy.is_shutdown():
        gait_determination()
        pub.publish(normalized_force_values)
        #rospy.spin()
        #print "working"
        r.sleep()


        

