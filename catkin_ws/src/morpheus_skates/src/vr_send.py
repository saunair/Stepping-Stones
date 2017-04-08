#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Floatt32

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

publish_rate = rospy.get_param("vr_refresh_rate")
left_skate_velocity, right_skate_velocity = 0,0

def left_update(left):
    global left_skate_velocity
    left_skate_velocity = left.command_target

def rightt_update(right):
    global right_skate_velocity
    right_skate_velocity = right.command_target

def talker():
    rospy.Subscriber("right_command", skate_command, right_input)
    rospy.Subscriber("left_command", skate_command, left_update)
    
    
    rospy.init_node('vr_talker', anonymous=True)
    pub = rospy.Publisher('walking_speed', Float32, queue_size=10)
    rate = rospy.Rate(publish_rate) # 10hz
    a = 0
    while not rospy.is_shutdown():
        a = max(left_skate_velocity, right_skate_velocity)
        rospy.loginfo(a)
        #b = ceil(a/100.0)
        pub.publish(a)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

