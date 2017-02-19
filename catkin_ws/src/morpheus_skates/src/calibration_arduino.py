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

def write_into_file(d,name):
    global config_file
    if(name =='right'):
	d['left_bias_front_outer']     =   rospy.get_param('left_bias_front_outer')
        d['left_bias_front_inner']     =   rospy.get_param('left_bias_front_inner')
        d['left_bias_rear']            =   rospy.get_param('left_bias_rear')
	d['left_preload_front_outer']  =   rospy.get_param('left_preload_front_outer')
        d['left_prelaod_front_inner']  =   rospy.get_param('left_preload_front_inner')
        d['left_preload_rear']         =   rospy.get_param('left_preload_rear')
    elif(name == 'left'):
	d['right_preload_front_outer'] =   rospy.get_param('right_preload_front_outer')
        d['right_preload_front_inner'] =   rospy.get_param('right_preload_front_inner')
        d['right_preload_rear']        =   rospy.get_param('right_preload_rear')
	d['right_preload_front_outer']  =   rospy.get_param('right_preload_front_outer')
        d['right_prelaod_front_inner']  =   rospy.get_param('right_preload_front_inner')
        d['right_preload_rear']         =   rospy.get_param('right_preload_rear')

    stream = file(config_file, 'w')
    yaml.dump(d, stream)

class skate(object):

    def __init__(self, name):
	self.name = name
        
        ########### set appropriate values ########
	self.MAX_preload_F1 = 2
        self.MAX_preload_F2 = 2
        self.MAX_preload_F3 = 2
    	
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
    	self.preload_front_outer = -1
        self.preload_front_inner = -1
    	self.preload_rear = -1

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
    	self.preload_front_outer = -1
        self.preload_front_inner = -1
    	self.preload_rear = -1

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
       
   
       	   self.w = input("input weight here")
       	   self.count += 1
   	   ####### add the skate name in the input
       	   self.sensor_number = input("enter skate sensor number for gain calibration")
   
       if self.w!=-1:
           #keep appending for another n values
           if self.count>=1200 and self.count<1400:
       	   	self.gain_front_outer.append(2*(data.force_front_outer - right_bias_front_outer)/self.w)
           	self.gain_front_inner.append(2*(data.force_front_inner - right_bias_front_inner)/self.w)
       	   	self.gain_rear.append(2*(data.force_rear - self.bias_rear)/self.w)
		self.count += 1
           
	   ###### ignore these values for sync!!!! ######### 
	   elif self.count<1200:
                self.count_ += 1
           ###### end of routine for this sensor number##########
	   elif self.count==1400:
            	self.w = -1
       	   	self.gain_front_outer = float(sum(self.gain_front_outer))/len(self.gain_front_outer)
       		self.gain_front_inner = float(sum(self.gain_front_inner))/len(self.gain_front_inner)
       		self.gain_rear = float(sum(self.gain_rear))/len(self.gain_rear)
	    
	   ###### ignore these values for sync!!!! ######### 
	   elif self.count <1800 and self.count>1400:

                self.count_ += 1
	   
	   elif self.count > 1800 and self.count < 2200:
    		g = input("press a key if ready to test mechanical preload")
		self.preload_front_outer.append((data.force_front_outer - right_bias_front_outer)*self.gain_front_outer) 
        	self.preload_front_inner.append((data.force_front_inner - right_bias_front_inner)*self.gain_front_inner)
    		self.preload_rear.append(((data.force_read - right_bias_front_outer)/self.gain_read))
                self.count += 1 
           elif self.count == 2200:
       	   	self.preload_front_outer = float(sum(self._front_outer))/len(self.preload_front_outer)
       		self.preload_front_inner = float(sum(self._front_inner))/len(self.preload_front_inner)
       		self.preload_rear = float(sum(self._rear))/len(self.preload_rear)
                
           	if self.preload_front_outer > self.MAX_preload_F1:
       	   	    print "Front outer load not corrected"
		    self.count = 1401 
           	if self.preload_front_inner > self.MAX_preload_F2:
       	            print "Front inner load not corrected"
		    self.count = 1401 
           	if self.preload_rear > self.MAX_preload_F3:
       	            print "Rear load not corrected"
		    self.count = 1401 

	   elif self.count == 2201:
   		self.count = 0 
                if self.preload_front_outer < self.MAX_preload_F1 and  self.preload_front_inner < self.MAX_preload_F2 and self.preload_rear < self.preload_BIAS_F3:
       		    self.data_update(self.sensor_number)  
            	    self.restart_routine() 
	        else:
       	            #### go back to preload routine
	            self.count = 1401
       	            #self.restart_routine()
           elif self.count > 2201:
		self.restart_routine()
    ########### update the dictionary for this particular skate
    def data_update(sensor_number):
	
        bias_front_outer = self.name + "_bias_front_outer"
        bias_front_inner = self.name + "_bias_front_inner"
        bias_rare        = self.name + "_bias_rare"
        
	gain_front_outer = self.name + "_gain_front_outer"
        gain_front_inner = self.name + "_gain_front_inner"
        gain_rare        = self.name + "_gain_rare"

	preload_front_outer = self.name + "_preload_front_outer"
        preload_front_inner = self.name + "_preload_front_inner"
        preload_rare        = self.name + "_preload_rare"
        
        if self.bias_front_outer != -1: 
            d[bias_front_outer] = self.bias_front_outer
            d[bias_front_inner] = self.bias_front_inner
            d[bias_rear]        = self.bias_rear
            if self.sensor_no==1:
                d[gain_front_outer] = self.gain_front_outer
                d[gain_front_inner] = rospy.get_param(gain_front_inner)
                d[gain_rare       ] = rospy.get_param(gain_rear)
            
	    elif self.sensor_no==2:
                d[gain_front_inner] = self.gain_front_inner
                d[gain_front_outer] = rospy.get_param(gain_front_outer)
                d[gain_rear]        = rospy.get_param(gain_rear)
        
            elif self.sensor_no==3:
                d[gain_rear]        = self.gain_rear
                d[gain_front_outer] = rospy.get_param(gain_front_outer)
                d[gain_front_inner] = rospy.get_param(gain_front_inner)
        else:
            d[bias_front_outer] = rospy.get_param(bias_front_outer)
            d[bias_front_inner] = rospy.get_param(bias_front_inner)
            d[bias_rear]        = rospy.get_param(bias_rear)
            d[gain_front_outer] = rospy.get_param(gain_front_outer)
            d[gain_front_inner] = rospy.get_param(gain_front_inner)
            d[gain_rear]        = rospy.get_param(gain_rear)

        rospy.set_param(bias_front_outer,d[bias_front_outer])
        rospy.set_param(bias_front_inner,d[bias_front_inner])
        rospy.set_param(bias_rear,       d[bias_rear]) 
        rospy.set_param(gain_front_outer,d[gain_front_outer])
        rospy.set_param(gain_front_inner,d[left_gain_front_inner])
        rospy.set_param(gain_rear,       d[left_gain_rear])
       
        ##### call the function that dumps the dictionary into a yaml file which is our config file### 
	write_into_file(d, self.name)
        
	a = raw_input("Confirm restart by pressing enter")
        self.restart_routine()

def start(left_skate_start, right_skate_start):
    rospy.init_node('bias', anonymous=True)
    rospy.Subscriber("left" , skate_feedback, left_skate_start.values)
    rospy.Subscriber("right", skate_feedback, right_skate_start.values)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':                           
    right_skate = skate('right_skate')
    left_skate =  skate('left_skate')
    start(left_skate, right_skate)
