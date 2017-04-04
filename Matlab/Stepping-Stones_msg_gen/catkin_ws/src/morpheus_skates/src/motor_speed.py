#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16



def talker():
    pub = rospy.Publisher('servo', UInt16, queue_size=100)
    rospy.init_node('motor_control', anonymous=True)
    i = 0
    rate = rospy.Rate(30) # 1hz
    pub.publish(50)
    hello_str = "%d" % 50
    rospy.loginfo(hello_str)
    time.sleep(5)
    while not rospy.is_shutdown():
        i = i + 1
	if i<50:
	    	val = 30
		#pub.publish(50)
		rate.sleep()
		pub.publish(val)
        	rate.sleep()
	
	else:
		val = 65
		#pub.publish(50)
		rate.sleep()
		pub.publish(val)
        	rate.sleep()
	
	hello_str = "%d" % val
        rospy.loginfo(hello_str)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

