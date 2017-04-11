#!/usr/bin/env python
import time
from morpheus_skates.srv import *
import rospy
import tf
import roslib; roslib.load_manifest('morpheus_skates')

z_x = []
z_y = []
z_z = []
count = 0

def myhook():
      print "shutdown time!"

def handle_zero_point(req):
    global z_x, z_y, z_z 
    #print "Returning [%s + %s = %s]"%(z_x, z_y, z_z)
    print "Returning [%s, %s, %s]" % (z_x, z_y, z_z)
    rospy.set_param('z_x', z_x)
    rospy.set_param('z_y', z_y)
    rospy.set_param('z_z', z_z)
    #return {"zero_x":z_x, "zero_y":z_y, "zero_z":z_z}
    return zero_pointResponse(z_x, z_y, z_z)

def zero_point_server():
    rospy.init_node('kinect_zero')
    global z_x, z_y, z_z, count
    #irospy.init_node('zero_point_server')
    #while not rospy.is_shutdown(): 
    
    listener_trans = tf.TransformListener() 
    #rate = rospy.Rate(10.0)
    #waiting for transform!!!!
    listener_trans.waitForTransform("/openni_depth_frame", "/left_hip_1", rospy.Time(), rospy.Duration(0))
    while count<11:

        try:
            (trans1,rot1) = listener_trans.lookupTransform('openni_depth_frame', '/left_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
	    print "Waiting for left hip zero point"
            continue
    
        try:
            (trans2,rot2) = listener_trans.lookupTransform('openni_depth_frame', '/right_hip_1', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
	    print "Waiting for right hip zero point"
            continue
    
        try:
            if count<10:
                z_x.append((trans2[0] + trans1[0])/2)
                z_y.append((trans2[1] + trans1[1])/2)
                z_z.append((trans2[2] + trans1[2])/2)
                print "User Zero Point Sample %d" % (count)
            if count==10:
                z_x = float(sum(z_x))/len(z_x)
                z_y = float(sum(z_y))/len(z_y)
                z_z = float(sum(z_z))/len(z_z)
                rospy.set_param('zero_pos_x', z_x)
                rospy.set_param('zero_pos_y', z_y)
                rospy.set_param('zero_pos_z', z_z)
            count+=1
        except:
            z_x = 0
            z_y = 0
            z_z = 0
            pass
    print "Sending zero point"
    s = rospy.Service('zero_point', zero_point, handle_zero_point)
    #rate.sleep()
    rospy.spin()
    
    #stop the node maybe ?
    rospy.on_shutdown(myhook)


if __name__ == "__main__":
    time.sleep(20)
    zero_point_server()
