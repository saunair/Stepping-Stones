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

class skate(object):

    def __init__(self, name):
	self.name = name
	

        ########### set appropriate values ########
	self.MAX_BIAS_F1 = 150
        self.MAX_BIAS_F2 = 20
        self.MAX_BIAS_F3 = 20
    	
	########### initialize variables ##########
	self.w = -1
    	self.bias_front_outer = -1
        self.bias_front_inner = -1
    	self.bias_rear = -1
        self.gain_front_outer = []
        self.gain_front_inner = []
        self.gain_rear = []
        self.count = 0
        self.sensor_no = -1

    ###### restart routine for new sensors ############ 
    def restart_routine():    
    	self.w = -1
    	self.bias_front_outer = -1
        self.bias_front_inner = -1
    	self.bias_rear = -1
        self.gain_front_outer = []
        self.gain_front_inner = []
        self.gain_rear = []
        self.count = 0
        self.sensor_no = -1

    def values(data):
       rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.force_front_outer)

       if self.count==0:
           self.bias_front_outer = 0
           self.bias_front_inner = 0
           self.bias_rear        = 0
   	   self.count           += 1
   
       if self.count<=200:
           self.bias_front_outer += data.force_front_outer
   	   self.bias_front_inner += data.force_front_inner
   	   self.bias_rear 	 += data.force_rear
   	   self.count            += 1

       elif self.count==201:
   	   self.bias_front_outer/=200
   	   self.bias_front_inner/=200
   	   self.bias_rear/=200
   	   #put a check for the bias changes/values
       
           if self.bias_front_outer > self.MAX_BIAS_F1:
       	   	print "Front outer load not corrected"
           if self.bias_front_inner > self.MAX_BIAS_F2:
       	       print "Front inner load not corrected"
           if self.bias_rear > self.MAX_BIAS_F3:
       	       print "Rear load not corrected"
   
           if self.bias_front_outer < self.MAX_BIAS_F1 and  self.bias_front_inner < self.MAX_BIAS_F2 and self.bias_rear < self.MAX_BIAS_F3:
       	       self.w = input("input weight here")
       	       self.count += 1
   	       ####### add the skate name in the input
       	       self.sensor_number = input("enter skate sensor number for gain calibration")
           else:
       	       self.count = 0
       	       self.restart_routine()
   
       if self.w!=-1:
           #keep appending for another n values
           if self.count>=1200 and self.count<1400:
       	   	self.gain_front_outer.append(2*(data.force_front_outer - right_bias_front_outer)/self.w)
           	self.gain_front_inner.append(2*(data.force_front_inner - right_bias_front_inner)/self.w)
       	   	self.gain_rear.append(2*(data.force_rear - self.bias_rear)/self.w)
		self.count += 1
           
           ###### end of routine for this sensor number##########
	   elif self.count==1400:
            	self.w = -1
       	   	self.gain_front_outer = float(sum(self.gain_front_outer))/len(self.gain_front_outer)
       		self.gain_front_inner = float(sum(self.gain_front_inner))/len(self.gain_front_inner)
       		self.gain_rear = float(sum(self.gain_rear))/len(self.gain_rear)
       		data_write(self.sensor_number)  
           	self.count = 0
            	self.restart_routine() 
	    
	    ###### ignore these values for sync!!!! ######### 
	   elif self.count<1200:
                self.count_ += 1



def start(left_skate_start, right_skate_start):
    rospy.init_node('bias', anonymous=True)
    rospy.Subscriber("left" , skate_feedback, left_skate_start.values)
    rospy.Subscriber("right", skate_feedback, right_skate_start.values)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

def data_write(right, left):
    d = {}
    print "check", rospy.get_param("left_gain_rear")

    if right.bias_front_outer != -1: 
        d["right_bias_front_outer"] = right.bias_front_outer
        d["right_bias_front_inner"] = right.bias_front_inner
        d["right_bias_rear"] 	    = right.bias_rear
        if right.sensor_no==1:
            d["right_gain_front_outer"] = right.gain_front_outer
            print right.gain_front_outer, "right_gain_front_outer"
            d["right_gain_front_inner"] = rospy.get_param("right_gain_front_inner")
            d["right_gain_rear"] = rospy.get_param("right_gain_rear")
        elif right.sensor_no==2:
            d["right_gain_front_inner"] = right.gain_front_inner
            print right.gain_front_inner, "right_gain_front_inner"
            d["right_gain_front_inner"] = rospy.get_param("right_gain_front_inner")
            d["right_gain_rear"] = rospy.get_param("right_gain_rear")
        elif right.sensor_no==3:
            d["right_gain_rear"] = right.gain_rear
            print right.gain_rear, "right_gain_rear"
            d["right_gain_front_outer"] = rospy.get_param("right_gain_front_outer")
            d["right_gain_front_inner"] = rospy.get_param("right_gain_front_inner")
        
    else:
        d["right_bias_front_outer"] = rospy.get_param("right_bias_front_outer")
        d["right_bias_front_inner"] = rospy.get_param("right_bias_front_inner")
        d["right_bias_rear"] = rospy.get_param("right_bias_rear")
        d["right_gain_front_outer"] = rospy.get_param("right_gain_front_outer")
        d["right_gain_front_inner"] = rospy.get_param("right_gain_front_inner")
        d["right_gain_rear"] = rospy.get_param("right_gain_rear")
    
    if left.bias_front_outer != -1: 
        d["left_bias_front_outer"] = left.bias_front_outer
        d["left_bias_front_inner"] = left.bias_front_inner
        d["left_bias_rear"]        = left.bias_rear
        if left.sensor_no==1:
            d["left_gain_front_outer"] = left.gain_front_outer
            print left.gain_front_outer, "left_gain_front_outer"
            d["left_gain_front_inner"] = rospy.get_param("left_gain_inner")
            d["left_gain_rear"] = rospy.get_param("left_gain_rear")
        
        elif left.sensor_no==2:
            d["left_gain_front_inner"] = left.gain_front_inner
            print left_gain_front_inner, "left_gain_front_inner"
            d["left_gain_front_outer"] = rospy.get_param("left_gain_front_outer")
            d["left_gain_rear"] = rospy.get_param("left_gain_rear")
        
        elif left.sensor_no==3:
            d["left_gain_rear"] = left.gain_rear
            print left.gain_rear, "left_gain_rear"
            d["left_gain_front_outer"] = rospy.get_param("left_gain_front_outer")
            d["left_gain_front_inner"] = rospy.get_param("left_gain_front_inner")
    else:
        d["left_bias_front_outer"] = rospy.get_param("left_bias_front_outer")
        d["left_bias_front_inner"] = rospy.get_param("left_bias_front_inner")
        d["left_bias_rear"] = rospy.get_param("left_bias_rear")
        d["left_gain_front_outer"] = rospy.get_param("left_gain_front_outer")
        d["left_gain_front_inner"] = rospy.get_param("left_gain_front_inner")
        d["left_gain_rear"] = rospy.get_param("left_gain_rear")
   
    rospy.set_param("left_bias_front_outer",d["left_bias_front_outer"])
    rospy.set_param("left_bias_front_inner",d["left_bias_front_inner"])
    rospy.set_param("left_bias_rear",d["left_bias_rear"]) 
    rospy.set_param("left_gain_front_outer",d["left_gain_front_outer"])
    rospy.set_param("left_gain_front_inner",d["left_gain_front_inner"])
    rospy.set_param("left_gain_rear",d["left_gain_rear"])
    rospy.set_param("right_bias_front_outer",d["right_bias_front_outer"])
    rospy.set_param("right_bias_front_inner",d["right_bias_front_inner"])
    rospy.set_param("right_bias_rear",d["right_bias_rear"])
    rospy.set_param("right_gain_front_outer",d["right_gain_front_outer"])
    rospy.set_param("right_gain_front_inner",d["right_gain_front_inner"])
    rospy.set_param("right_gain_rear",d["right_gain_rear"])
   

    stream = file(config_file, 'w')
    yaml.dump(d, stream)
    print "Written the values in YAML!!!!"
    a = raw_input("confirm")
    left.restart_routine()
    right.restart_routine()

if __name__ == '__main__':                           
    right_skate = skate('right_skate')
    left_skate =  skate('left_skate')
    start(left_skate, right_skate)
