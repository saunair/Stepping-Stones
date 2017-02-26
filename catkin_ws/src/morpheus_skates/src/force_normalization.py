#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
import yaml
from morpheus_skates.msg import skate_feedback
import os

#config_file = '~/catkin_ws/src/motor/config/calibration_values.yaml'

config_file = '/home/saurabh/catkin_ws/src/motor/config/calibration_values.yaml'
total_weight = 0


class skate(object):
    def __init__(self, name):
        self.name = name
        self.force_front_outer_temp = 0      
 	self.force_front_inner_temp = 0
 	self.force_rear_temp	    = 0
        self.force_front_outer      = 0
	self.force_front_inner      = 0
	self.force_rear_temp	    = 0
        self.counter = 0 
    
    def update_sensor_readings(self, message):
        if self.counter!=100:
	    self.force_front_outer_temp +=  message.force_front_outer
	    self.force_front_inner_temp +=  message.force_front_inner
	    self.force_rear_temp	+=  message.force_rear
	    self.counter                +=  1
   	elif self.counter==100:
	    self.force_front_outer =  float(self.force_front_outer_temp)/self.counter
            self.force_front_inner =  float(self.force_front_inner_temp)/self.counter 
            self.force_rear        =  float(self.force_rear_temp)/self.counter	
 
	
def myhook():
      print "shutdown time!"

def handle_norm_service(req):
    global total_weight
    print "sending the total weight"
    return sensor_normalizedResponse(total_weight)


def normalize_calculation(right_skate, left_skate):
    
    rospy.init_node('force_normalization')
    rospy.Subscriber("right", skate_feedback, right_skate.update_sensor_readings)
    rospy.Subscriber("left", skate_feedback, left_skate.update_sensor_readings)
    if(right_skate.counter == 100 and left_skate.counter==0):
	with open(config_file, 'r') as stream:
    	    try:
                calibration_data = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)
	#####use calibrated values for calculation########

	left_skate_force_front_outer = float(left_skate.force_front_outer - calibration_data.left_bias_front_outer)/calibration_data.left_bias_gain_outer - calibration_data.left_preload_front_outer
	left_skate_force_front_inner = float(left_skate.force_front_inner - calibration_data.left_bias_front_inner)/calibration_data.left_bias_gain_inner - calibration_data.left_preload_front_inner
	left_skate_force_rear        = float(left_skate.force_rear        - calibration_data.left_bias_rear)/calibration_data.left_gain_rear - calibration_data.left_preload_rear 
	
        right_skate_force_front_outer = float(right_skate.force_front_outer - calibration_data.right_bias_front_inner)/calibration_data.right_bias_gain_inner - calibration_data.right_preload_front_outer
	right_skate_force_front_inner = float(right_skate.force_front_inner - calibration_data.right_bias_front_outer)/calibration_data.right_bias_gain_outer - calibration_data.right_preload_front_inner
	right_skate_force_rear        = float(right_skate.force_rear        - calibration_data.right_bias_rear)/calibration_data.right_gain_rear - calibration_data.right_preload_inner 
	
	total_weight = left_skate_force_front_outer + left_skate_force_front_inner + left_skate_force_rear + right_skate_force_front_outer + right_skate_force_front_inner + right_skate_force_rear 


	##set it in parameter server as well!!!
	rospy.set_param("total_weight",total_weight)
    	s = rospy.Service('sensors_normalized', sensors_normalized, handle_norm_service)
    rospy.spin()
    rospy.on_shutdown(myhook)

if __name__ == '__main__':                           
    right_skate = skate('right')
    left_skate  = skate('left')
    #not sure if we need a delay
    #time.sleep(20)
    normalize_calculation(right_skate, left_skate)
