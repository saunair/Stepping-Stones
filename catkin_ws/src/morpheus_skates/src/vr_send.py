#!/usr/bin/env python
# license removed for brevity
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

velocity_history = [0, 0, 0, 0] 

# def left_update(left):
#     global left_skate_velocity
#     left_skate_velocity = left.left_command.command_target

# def right_update(right):
#     global right_skate_velocity
#     right_skate_velocity = right.right_command.command_target

def check_stop(target_vel):
    del velocity[0]
    velocity_history.append(target_vel)
    d1 = velocity[3] - velocity[2]
    d2 = velocity[2] - velocity[1]
    d3 = velocity[1] - velocity[0]

    if((d3 < d2) and (d2 < d1) and (d1 < d0)):
       vr_velocity = 0 
       del velocity[0]
       velocity_history.append(vr_velocity)
    return np.average(vr_velocity)

def update(skate):
    global left_skate_velocity,right_skate_velocity
    left_skate_velocity = skate.left_command.command_target
    right_skate_velocity = skate.right_command.command_target


def talker():
    global left_skate_velocity,right_skate_velocity
    rospy.Subscriber("total_message", integrated_message, update)
    # rospy.Subscriber("total_message", skate_command, left_update)
    
    rospy.init_node('vr_talker', anonymous=True)
    pub = rospy.Publisher('walking_speed', Float32, queue_size=10)
    rate = rospy.Rate(publish_rate) # 10hz
    a = 0
    while not rospy.is_shutdown():
        a = max(left_skate_velocity, right_skate_velocity)
        velocity = check_stop(a)

        #rospy.loginfo(a)
        pub.publish(velocity)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
