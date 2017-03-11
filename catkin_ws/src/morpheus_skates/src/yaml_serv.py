#!/usr/bin/env python

from motor.srv import *
import rospy
import tf
import roslib; roslib.load_manifest('morpheus_skates')


def myhook():
      print "shutdown time!"

def handle_yaml_send(req):
    #return {"zero_x":z_x, "zero_y":z_y, "zero_z":z_z}
    left_bias_f1  = rospy.get_param("left_bias_front_outer")
    left_bias_f2  = rospy.get_param("left_bias_front_inner")
    left_bias_f3  = rospy.get_param("left_bias_rear")
    left_gain_f1  = rospy.get_param("left_gain_front_outer")
    left_gain_f2  = rospy.get_param("left_gain_front_inner")
    left_gain_f3  = rospy.get_param("left_gain_rear")
    right_bias_f1 = rospy.get_param("right_bias_front_outer")
    right_bias_f2 = rospy.get_param("right_bias_front_inner")
    right_bias_f3 = rospy.get_param("right_bias_rear")
    right_gain_f1 = rospy.get_param("right_gain_front_outer")
    right_gain_f2 = rospy.get_param("right_gain_front_inner")
    right_gain_f3 = rospy.get_param("right_gain_rear")
    
    print "Returning [%s + %s = %s]"%(right_gain_f1, right_gain_f2, right_gain_f3)
    
    return yaml_valuesResponse(left_bias_f1, left_bias_f2 , left_bias_f3 , left_gain_f1 ,left_gain_f2,left_gain_f3 ,right_bias_f1,right_bias_f2,right_bias_f3,right_gain_f1,right_gain_f2,right_gain_f3)

def yaml_send_server():
    rospy.init_node('yaml_serv')
    print "Sending yaml values"
    s = rospy.Service('yaml_send', yaml_values, handle_yaml_send)
    rospy.spin()
    
if __name__ == "__main__":
    yaml_send_server()
