#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
from motor.msg import states
import numpy
from motor.srv import *
import tf

import roslib; roslib.load_manifest('motor')

#state values
send_control = states()
calibration = 0
position_control = 1
velocity_control = 2

send_control.state = calibration
send_control.set_point = 0

#default zero points
z_x= 3.45787 
z_y=0.0881804
z_z=0.211088

#change the message values to be sent to the arduino
def change_state(data):
    global send_control
    try:
        send_control.state = data.state
        send_control.set_point = data.set_point
    except:
        send_control.state = 0
        send_control.set_point = 0

#ask for the zero point from the kinect
def ask_zero_point():
    #wait for 20 secs and then continue
    rospy.wait_for_service('zero_point', 20)
    try:
        resp1 = rospy.ServiceProxy('zero_point', zero_point)
        resp1 = resp1(1)
        print "zero_point =" ,resp1
        return resp1.zero_x, resp1.zero_y, resp1.zero_z
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

#main higher level control code
def send_controls():
  
    global send_control
    global z_x, z_y, z_z
    pub = rospy.Publisher('servo', states, queue_size=100)
    
    rospy.init_node('stepping_stones', anonymous=True)
    listener_trans = tf.TransformListener() 
    i = 0
    rate = rospy.Rate(15) # 30hz
    pub.publish(send_control)
    hello_str = "%d" % 50
    rospy.loginfo(hello_str)
    #delay
    #time.sleep(5)
    #rate = rospy.Rate(30.0)
    
    #subscribe to user inputs
    rospy.Subscriber("user_inputs", states, change_state)
    
    while not rospy.is_shutdown():
        
        if send_control.state==velocity_control:
            try:
                (trans1,rot1) = listener_trans.lookupTransform('/openni_depth_frame', '/left_hip_1', rospy.Time(0))
            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
                #continue
                pass
    
            try:
                (trans2,rot2) = listener_trans.lookupTransform('/openni_depth_frame', '/right_hip_1', rospy.Time(0))
            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
                #print "problem"
                #continue
                pass
    

            #current kinect values 
            try:
                x_current = ((trans2[0] + trans1[0])/2)
                y_current = ((trans2[1] + trans1[1])/2)
                z_current = ((trans2[2] + trans1[2])/2)
            except:
                pass

        send_control.header.stamp = rospy.Time.now()	
        pub.publish(send_control)
	
	#hello_str = "state = %d; set_point" % (send_control.state, send_control.set_point)
        print send_control.state, send_control.set_point
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
        send_controls()
    except rospy.ROSInterruptException:
        pass
