#!/usr/bin/env python
import rospy
from motor.msg import states


def keyboard_input():
    try:
        state = input("Please input the state")
        set_point = input("please input the set_point")
    except:
        state = 0
        set_point = 0
    return state, set_point

def state_publisher():
    pub = rospy.Publisher('user_inputs', states, queue_size=10)
    rospy.init_node('user_input', anonymous=True)
    rate = rospy.Rate(100) # 100hz
    message = states()
    while not rospy.is_shutdown():
        state, value = keyboard_input()
        message.state = state
        message.set_point = value
        #rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()

if __name__ == '__main__':
    try:
        state_publisher()
    except rospy.ROSInterruptException:
        pass
