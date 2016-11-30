#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
import numpy
from motor.srv import *
import tf

import roslib; roslib.load_manifest('motor')


z_x= 3.45787 
z_y=0.0881804
z_z=0.211088


def ask_zero_point():
    rospy.wait_for_service('zero_point')
    try:
        resp1 = rospy.ServiceProxy('zero_point', zero_point)
        resp1 = resp1(1)
        print resp1, "here"
        return resp1.zero_x, resp1.zero_y, resp1.zero_z
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def talker():
    pub = rospy.Publisher('servo', UInt16, queue_size=100)
    rospy.init_node('stepping_stones', anonymous=True)
    listener_trans = tf.TransformListener() 
    i = 0
    rate = rospy.Rate(30) # 30hz
    pub.publish(50)
    hello_str = "%d" % 50
    rospy.loginfo(hello_str)
    #delay
    #time.sleep(5)
    rate = rospy.Rate(30.0)
    while not rospy.is_shutdown():
        try:
            (trans1,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            continue
    
        try:
            (trans2,rot2) = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            print "problem"
            continue
    
        z_x = ((trans2[0] + trans1[0])/2)
        z_y = ((trans2[1] + trans1[1])/2)
        z_z = ((trans2[2] + trans1[2])/2)
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
        print hello_str
        rate.sleep()

if __name__ == '__main__':
    try:
        z_x, z_y, z_z = ask_zero_point()
        print "acquired zero point"
    except rospy.ROSInterruptException:
        print "Sorry didn't acquire the zero position"
        pass
    except:
        print "Sorry didn't acquire the zero position, going with default"
        z_x = 3.45787 
        z_y = 0.0881804
        z_z = 0.21108

    try:
        talker()
    except rospy.ROSInterruptException:
        pass