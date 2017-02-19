#!/usr/bin/env python
import rospy
from morpheus_skates.msg import skate_command


def keyboard_input():
    try:
        state = input("Please input the state")
        set_point = input("please input the set_point")
    except:
        state = 0
        set_point = 0
    return state, set_point

def state_publisher():
    pub = rospy.Publisher('user_inputs', skate_command, queue_size=10)
    rospy.init_node('user_input', anonymous=True)
    rate = rospy.Rate(100) # 100hz
    message = skate_command()
    while not rospy.is_shutdown():
        state, value = keyboard_input()
        message.calibration_enable = state
        message.command_target = value
        #rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()

if __name__ == '__main__':
    try:
        state_publisher()
    except rospy.ROSInterruptException:
        pass
