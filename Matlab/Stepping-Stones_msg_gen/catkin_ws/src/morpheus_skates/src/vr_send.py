#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Int32

def talker():
    pub = rospy.Publisher('chatter', Int32, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        a = 200
        rospy.loginfo(a)
        pub.publish(a)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

