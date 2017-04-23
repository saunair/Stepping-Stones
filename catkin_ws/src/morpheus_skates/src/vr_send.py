#!/usr/bin/env python
# Author: Saurabh Nair
import rospy
from std_msgs.msg import Float32

import rospy
import time
import copy
import numpy
import tf
import roslib; roslib.load_manifest('morpheus_skates')
import math
from std_msgs.msg import *
from morpheus_skates.msg import *
from morpheus_skates.srv import *
import numpy as np

publish_rate = rospy.get_param("vr_refresh_rate")
left_skate_velocity, right_skate_velocity = 0,0
number_samples = 100

SPL = 0
SSPR = 1
SSML = 2
SSMR = 3
DSP  = 4
DSM  = 5
DSM_B = 6
SSMR_B = 7
SSML_B = 8
DoubleStance = 100

velocity_history = number_samples*[0]
state_history = number_samples*[DSP]
# def left_update(left):
#     global left_skate_velocity
#     left_skate_velocity = left.left_command.command_target

# def right_update(right):
#     global right_skate_velocity
#     right_skate_velocity = right.right_command.command_target

def state_update(current_state):
    global state_history
    del state_history[0]
    state_history.append(current_state.data)

def static_stance_check():
    global state_history


def check_stop(target_vel):
    global velocity_history, state_historyi, DSP
    del velocity_history[0]
    '''
    d1 = velocity_history[3] - velocity_history[2]
    d2 = velocity_history[2] - velocity_history[1]
    d3 = velocity_history[1] - velocity_history[0]
    deceleration_check = (d3 < d2) and (d2 < d1) and (d1 < d0)
    '''
    static_stance_check = all(x==DSP for x in state_history)
    dynamic_stance_check = all(x==DSM for x in state_history)
    if(static_stance_check or dynamic_stance_check):
       vr_velocity = 0 
       del velocity_history[0]
       velocity_history.append(vr_velocity)
    else:
    	velocity_history.append(target_vel)
    return np.average(velocity_history)

def update(skate):
    global left_skate_velocity,right_skate_velocity
    left_skate_velocity = skate.left_command.command_target
    right_skate_velocity = skate.right_command.command_target


#publish_rate = rospy.get_param("publish_rate")
publish_rate = 30

def talker():
<<<<<<< HEAD
    a = 0
    pub = rospy.Publisher('chatter', Int32, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(publish_rate) # 100hz
    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        a += 1
        rospy.loginfo(a)
        pub.publish(a)
=======
    global left_skate_velocity,right_skate_velocity
    rospy.Subscriber("total_message", integrated_message, update)
    rospy.Subscriber("user_gait", Int16, state_update)
    
    rospy.init_node('vr_talker', anonymous=True)
    pub = rospy.Publisher('walking_speed', Float32, queue_size=10)
    rate = rospy.Rate(publish_rate) # 10hz
    drag_velocity = 0
    while not rospy.is_shutdown():
        drag_velocity = max(left_skate_velocity, right_skate_velocity)
        velocity = check_stop(drag_velocity)

        #rospy.loginfo(a)
        pub.publish(velocity)
>>>>>>> test
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
