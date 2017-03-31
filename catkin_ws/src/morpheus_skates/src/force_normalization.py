#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
from morpheus_skates.srv import *
import yaml
from morpheus_skates.msg import skate_feedback
import os
import roslib; roslib.load_manifest('morpheus_skates')

#config_file = '~/catkin_ws/src/motor/config/calibration_values.yaml'

#config_file = '/home/stepping/mrsd_team_H/Stepping-Stones/catkin_ws/src/morpheus_skates/config/calibration_values.yaml'
total_weight = 0
total_weight_left = 0
total_weight_right = 0
total_weight_left_front = 0
total_weight_right_front =0
###change these!
right_single_stance_threshold = 10
#right_double_stance_threshold = 0.4

left_single_stance_threshold = 10
#left_double_stance_threshold = 0.4

### required gains from the rosparam server
left_bias_front_outer = rospy.get_param('left_bias_front_outer')
left_bias_front_inner = rospy.get_param('left_bias_front_inner')
left_bias_rear = rospy.get_param('left_bias_rear')
left_gain_front_outer = rospy.get_param('left_gain_front_outer')
left_gain_front_inner = rospy.get_param('left_gain_front_inner')
left_gain_rear = rospy.get_param('left_gain_rear')
left_preload_front_outer = rospy.get_param('left_preload_front_outer')
left_preload_front_inner = rospy.get_param('left_preload_front_inner')
left_preload_rear = rospy.get_param('left_preload_rear')

right_bias_front_outer = rospy.get_param('right_bias_front_outer')
right_bias_front_inner = rospy.get_param('right_bias_front_inner')
right_bias_rear = rospy.get_param('right_bias_rear')
right_gain_front_outer = rospy.get_param('right_gain_front_outer')
right_gain_front_inner = rospy.get_param('right_gain_front_inner')
right_gain_rear = rospy.get_param('right_gain_rear')
right_preload_front_outer = rospy.get_param('right_preload_front_outer')
right_preload_front_inner = rospy.get_param('right_preload_front_inner')
right_preload_rear = rospy.get_param('right_preload_rear')


class skate(object):
	def __init__(self, name):
		self.name = name
		self.force_front_outer_temp = 0      
		self.force_front_inner_temp = 0
		self.force_rear_temp	    = 0
		self.force_front_outer      = 0
		self.force_front_inner      = 0
		self.force_rear	    		= 0
		self.counter = 0 

	def update_sensor_readings(self, message):
		if self.counter<50:
			self.force_front_outer_temp +=  message.force_front_outer
			self.force_front_inner_temp +=  message.force_front_inner
			self.force_rear_temp	+=  message.force_rear
			self.counter                +=  1
		elif self.counter==50:
			self.force_front_outer =  float(self.force_front_outer_temp)/self.counter
			self.force_front_inner =  float(self.force_front_inner_temp)/self.counter 
			self.force_rear        =  float(self.force_rear_temp)/self.counter
			self.counter +=1
		else:
			self.force_front_outer = message.force_front_outer
			self.force_front_inner = message.force_front_inner
			self.force_rear =  message.force_rear
 
	
def myhook():
	print "shutdown time!"

def handle_norm_service(req):
	global total_weight
	print "sending the total weight"
	#return total_weight
	return sensors_normalizedResponse(total_weight)


def normalize_calculation(right_skate, left_skate):
	global total_weight,total_weight_right,total_weight_left,total_weight_left_front,total_weight_right_front,calibration_data
	global left_bias_front_outer,left_bias_front_inner,left_bias_rear
	global left_gain_front_outer,left_gain_front_inner,left_gain_rear 
	global left_preload_front_outer,left_preload_front_inner,left_preload_rear
	global right_bias_front_outer,right_bias_front_inner,right_bias_rear
	global right_gain_front_outer,right_gain_front_inner,right_gain_rear
	global right_preload_front_outer,right_preload_front_inner,right_preload_rear
	rospy.init_node('normalization')

	while(right_skate.counter <= 51 and left_skate.counter <= 51):

		if(right_skate.counter == 51 and left_skate.counter==51):
			right_skate.counter = 52
			left_skate.counter = 52
			#path = os.path.join(config_file,os.path.dirname(__file__))
			#print path
			#with open(path, 'r') as stream:
			#	try:
			#		calibration_data = yaml.load(stream)
			#		print"yaml file loaded"
			#		
			#		print calibration_data['left_gain_front_outer'] 
			#	except yaml.YAMLError as exc:
			#		print(exc)
			#####use calibrated values for calculation########
			left_skate_force_front_outer = float(float(left_skate.force_front_outer - left_bias_front_outer)/left_gain_front_outer) - left_preload_front_outer
			left_skate_force_front_inner = float(float(left_skate.force_front_inner - left_bias_front_inner)/left_gain_front_inner) - left_preload_front_inner
			left_skate_force_rear        = float(float(left_skate.force_rear        - left_bias_rear)/left_gain_rear) - left_preload_rear 

			right_skate_force_front_outer = float(float(right_skate.force_front_outer - right_bias_front_outer)/right_gain_front_outer) - right_preload_front_outer
			right_skate_force_front_inner = float(float(right_skate.force_front_inner - right_bias_front_inner)/right_gain_front_inner) - right_preload_front_inner
			right_skate_force_rear        = float(float(right_skate.force_rear        - right_bias_rear)/right_gain_rear) - right_preload_rear 


			total_weight = left_skate_force_front_outer + left_skate_force_front_inner + left_skate_force_rear + right_skate_force_front_outer + right_skate_force_front_inner + right_skate_force_rear 
			total_weight_left = left_skate_force_front_outer + left_skate_force_front_inner + left_skate_force_rear
			total_weight_right = right_skate_force_front_outer + right_skate_force_front_inner + right_skate_force_rear 
			total_weight_left_front = left_skate_force_front_outer + left_skate_force_front_inner 
			total_weight_right_front = right_skate_force_front_outer + right_skate_force_front_inner  

			##set it in parameter server as well!!!

			rospy.set_param("total_weight",total_weight)
			s = rospy.Service('sensors_normalized', sensors_normalized, handle_norm_service)
			rospy.spin()
			 
			# return None
	

if __name__ == '__main__':                           
	right_skate = skate('right')
	left_skate  = skate('left')
	rospy.Subscriber("right_feedback", skate_feedback, right_skate.update_sensor_readings)
	rospy.Subscriber("left_feedback", skate_feedback, left_skate.update_sensor_readings)
	normalize_calculation(right_skate, left_skate)
