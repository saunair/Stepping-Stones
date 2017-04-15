#!/usr/bin/env python
# license removed for brevity

##Author: Saurabh Nair
import rospy
import time
from std_msgs.msg import UInt16
import yaml
from morpheus_skates.msg import skate_feedback
import os
import rospkg


#config_file = '~/catkin_ws/src/motor/config/calibration_values.yaml'

#config_file = '/home/stepping/mrsd_team_H/Stepping-Stones/catkin_ws/src/morpheus_skates/config/calibration_values.yaml'



rospack = rospkg.RosPack()

morpheus_path = rospack.get_path('morpheus_skates')

config_file = morpheus_path + '/config/calibration_values.yaml'


class skate(object):

    def __init__(self, name):
	

	self.data = []
	self.name = name
        
        ########### set appropriate values ########
	self.MAX_preload_F1 = 50
        self.MAX_preload_F2 = 50
        self.MAX_preload_F3 = 100
    	
	########### initialize variables ##########
	self.w = -1
    	self.bias_front_outer = -1
        self.bias_front_inner = -1
    	self.bias_rear = -1
        self.gain_front_outer = []
        self.gain_front_inner = []
        self.gain_rear = []
        self.count = 0
        self.sensor_number = -1
    	self.preload_front_outer = []
        self.preload_front_inner = []
    	self.preload_rear        = []
	self.d = {}
    ###### restart routine for new sensors ############ 
    def restart_routine(self):    
    	self.w = -1
    	self.bias_front_outer = -1
        self.bias_front_inner = -1
    	self.bias_rear = -1
        self.gain_front_outer = []
        self.gain_front_inner = []
        self.gain_rear        = []
        self.count = 0
        self.sensor_number = -1
    	self.preload_front_outer = []
        self.preload_front_inner = []
    	self.preload_rear =        []

    def update_values(self,data):
	self.data = data 
	
    def run(self):
	previous_sequence = 0
        while(1):
            if(self.data!=[]):
                if((self.data.header.seq != previous_sequence)):
                    self.calculate_values(self.data)
                    previous_sequence = self.data.header.seq

    def calculate_values(self, data):
       if self.count==0:
           self.bias_front_outer = 0
           self.bias_front_inner = 0
           self.bias_rear        = 0
   	   self.count           += 1
  	   self.w = input("input mode here, -2 for preload, 1 for gain and bias")

       if self.w>0:
       #print data.header.stamp
           if self.count<=200:
               self.bias_front_outer += self.data.force_front_outer
   	       self.bias_front_inner += self.data.force_front_inner
   	       self.bias_rear 	     += self.data.force_rear
   	       self.count            += 1

           elif self.count==201:
   	       self.bias_front_outer/=200
   	       self.bias_front_inner/=200
   	       self.bias_rear/=200
       	       self.count += 1
           elif self.count == 202: 
       	       self.sensor_number = input("enter skate sensor number for gain calculation")
       	       self.w = input("input weight here")
       	       self.count += 1
   	   ####### add the skate name in the input
   
       if self.w>0:
	   ###### ignore these values for sync!!!! ######### 
	   if self.count<1200 and self.count > 202:
                self.count += 1
		
	   elif self.count==1200:
		
		if self.sensor_number == 1:
        		self.gain_front_outer = []
		elif self.sensor_number == 2:
        		self.gain_front_inner = []
		elif self.sensor_number == 3:
        		self.gain_rear        = []
                self.count += 1
		
           #keep appending for another n values
           elif self.count>1200 and self.count<1400:
       	   	
		if self.sensor_number == 1:
		    self.gain_front_outer.append(float(self.data.force_front_outer - self.bias_front_outer)/self.w)
		    #print "check for sanjay", (data.force_front_outer - self.bias_front_outer), self.w
		elif self.sensor_number == 2:
           	    self.gain_front_inner.append(float(self.data.force_front_inner - self.bias_front_inner)/self.w)
		elif self.sensor_number == 3:
       	   	    self.gain_rear.append(float(self.data.force_rear - self.bias_rear)/self.w)
		self.count += 1
           
           ###### end of routine for this sensor number##########
	   elif self.count==1400:
		if self.sensor_number == 1:
		    #print self.gain_front_outer
       	   	    self.gain_front_outer = float(sum(self.gain_front_outer))/len(self.gain_front_outer)
		    #print "check", self.gain_front_outer
		elif self.sensor_number == 2:
       		    self.gain_front_inner = float(sum(self.gain_front_inner))/len(self.gain_front_inner)
		elif self.sensor_number == 3:
		    self.gain_rear = float(sum(self.gain_rear))/len(self.gain_rear)
	   	self.count +=1
	   elif self.count == 1401: 
	        if(self.gain_rear==[] or self.gain_front_inner==[] or self.gain_front_outer==[]):
		    ##### go back to gain calculations
		    self.count = 202
		else:
		    self.count += 1


	   ####label: sync
	   ###### ignore these values for sync!!!! ######### 
	   elif self.count <1800 and self.count>1401:
    	        self.preload_front_outer = []
        	self.preload_front_inner = []
    		self.preload_rear =        []
		self.count += 1
	   

	   elif self.count == 1800:
    		g = input("press a key if ready to test mechanical preload")
                self.count += 1
	   ############ mechanical preload code ################ 
	   elif self.count > 1800 and self.count < 2200:
		self.preload_front_outer.append(float(self.data.force_front_outer - self.bias_front_outer)/self.gain_front_outer) 
        	self.preload_front_inner.append(float(self.data.force_front_inner - self.bias_front_inner)/self.gain_front_inner)
    		self.preload_rear.append((float(self.data.force_rear - self.bias_rear)/self.gain_rear))
                self.count += 1 
           elif self.count == 2200:
       	   	self.preload_front_outer = float(sum(self.preload_front_outer))/len(self.preload_front_outer)
       		self.preload_front_inner = float(sum(self.preload_front_inner))/len(self.preload_front_inner)
       		self.preload_rear = float(sum(self.preload_rear))/len(self.preload_rear)
                

		#### go to sync if preload is above the threshold 
           	if self.preload_front_outer > self.MAX_preload_F1:
       	   	    print "Front outer load not corrected", self.preload_front_outer
		    self.count = 1401 
           	if self.preload_front_inner > self.MAX_preload_F2:
       	            print "Front inner load not corrected",  self.preload_front_inner
		    self.count = 1401
           	if self.preload_rear > self.MAX_preload_F3:
       	            print "Rear load not corrected", self.preload_rear
		    self.count = 1401

		if (self.preload_front_outer < self.MAX_preload_F1 and self.preload_front_inner < self.MAX_preload_F2 and self.preload_rear < self.MAX_preload_F3): 
		    self.count += 1

	   elif self.count == 2201:
   		self.count = 0 
                if self.preload_front_outer < self.MAX_preload_F1 and  self.preload_front_inner < self.MAX_preload_F2 and self.preload_rear < self.MAX_preload_F3:
       		    self.data_update()  
            	    self.restart_routine() 
	        else:
       	            #### go back to preload routine
	            print "Wrong bias: Go though preloading routine again"
		    self.count = 1401
       	            #self.restart_routine()
           #elif self.count > 2201:
		#self.restart_routine()
    ########### update the dictionary for this particular skate
       elif self.w==-2:
	    print "koushik"
	    ### go to this preload directly ###
	    self.count = 1700
	    #### to get into the loop ####
	    self.w = 1
            self.bias_front_outer =  rospy.get_param(self.name + "_bias_front_outer")
            self.bias_front_inner =  rospy.get_param(self.name + "_bias_front_inner")
            self.bias_rear        =  rospy.get_param(self.name + "_bias_rear")
            self.gain_front_outer =  rospy.get_param(self.name + "_gain_front_outer")
            self.gain_front_inner =  rospy.get_param(self.name + "_gain_front_inner")
            self.gain_rear        =  rospy.get_param(self.name + "_gain_rear")
	    
    def data_update(self):
	
        bias_front_outer = self.name + "_bias_front_outer"
        bias_front_inner = self.name + "_bias_front_inner"
        bias_rear        = self.name + "_bias_rear"
        
	gain_front_outer = self.name + "_gain_front_outer"
        gain_front_inner = self.name + "_gain_front_inner"
        gain_rear        = self.name + "_gain_rear"

	preload_front_outer = self.name + "_preload_front_outer"
        preload_front_inner = self.name + "_preload_front_inner"
        preload_rear        = self.name + "_preload_rear"
        
        if self.bias_front_outer != -1: 
            self.d[bias_front_outer] = self.bias_front_outer
            self.d[bias_front_inner] = self.bias_front_inner
            self.d[bias_rear]        = self.bias_rear
            self.d[gain_front_outer] = self.gain_front_outer
            self.d[gain_front_inner] = self.gain_front_inner
            self.d[gain_rear]        = self.gain_rear
            self.d[preload_front_outer] = self.preload_front_outer
            self.d[preload_front_inner] = self.preload_front_inner
            self.d[preload_rear]        = self.preload_rear
        else:
            self.d[bias_front_outer] = rospy.get_param(bias_front_outer)
            self.d[bias_front_inner] = rospy.get_param(bias_front_inner)
            self.d[bias_rear]        = rospy.get_param(bias_rear)
            self.d[gain_front_outer] = rospy.get_param(gain_front_outer)
            self.d[gain_front_inner] = rospy.get_param(gain_front_inner)
            self.d[gain_rear]        = rospy.get_param(gain_rear)
            self.d[preload_front_outer] = rospy.get_param(preload_front_outer)
            self.d[preload_front_inner] = rospy.get_param(preload_front_inner)
            self.d[preload_rear]        = rospy.get_param(preload_rear)
	
        rospy.set_param(bias_front_outer   ,self.d[bias_front_outer])
        rospy.set_param(bias_front_inner   ,self.d[bias_front_inner])
        rospy.set_param(bias_rear          ,self.d[bias_rear]) 
        rospy.set_param(gain_front_outer   ,self.d[gain_front_outer])
        rospy.set_param(gain_front_inner   ,self.d[gain_front_inner])
        rospy.set_param(gain_rear          ,self.d[gain_rear])
        rospy.set_param(preload_front_outer,self.d[preload_front_outer])
        rospy.set_param(preload_front_inner,self.d[preload_front_inner])
        rospy.set_param(preload_rear       ,self.d[preload_rear])
	    
        ##### call the function that dumps the dictionary into a yaml file which is our config file### 
        self.write_into_file()
        
    def write_into_file(self):
        global config_file
        if(self.name =='right'):
	    self.d['left_bias_front_outer']     =   rospy.get_param('left_bias_front_outer')
            self.d['left_bias_front_inner']     =   rospy.get_param('left_bias_front_inner')
            self.d['left_bias_rear']            =   rospy.get_param('left_bias_rear')
	    self.d['left_preload_front_outer']  =   rospy.get_param('left_preload_front_outer')
            self.d['left_preload_front_inner']  =   rospy.get_param('left_preload_front_inner')
            self.d['left_preload_rear']         =   rospy.get_param('left_preload_rear')
            self.d['left_gain_rear']         =   rospy.get_param('left_gain_rear')
	    self.d['left_gain_front_outer']  =   rospy.get_param('left_gain_front_outer')
            self.d['left_gain_front_inner']  =   rospy.get_param('left_gain_front_inner')
        elif(self.name == 'left'):
	    self.d['right_bias_front_outer'] =   rospy.get_param('right_bias_front_outer')
            self.d['right_bias_front_inner'] =   rospy.get_param('right_bias_front_inner')
            self.d['right_bias_rear']        =   rospy.get_param('right_bias_rear')
	    self.d['right_preload_front_outer']  =   rospy.get_param('right_preload_front_outer')
            self.d['right_preload_front_inner']  =   rospy.get_param('right_preload_front_inner')
            self.d['right_preload_rear']         =   rospy.get_param('right_preload_rear')
            self.d['right_gain_rear']         =   rospy.get_param('right_gain_rear')
	    self.d['right_gain_front_outer']  =   rospy.get_param('right_gain_front_outer')
            self.d['right_gain_front_inner']  =   rospy.get_param('right_gain_front_inner')

        stream = file(config_file, 'w')
        yaml.dump(self.d, stream)
	a = raw_input("Confirm restart for preload by pressing enter")
        self.count = 1402
	#self.restart_routine()

def start(left_skate_start, right_skate_start, skate_side):
    rospy.init_node('bias', anonymous=True)
    
    if(skate_side == 1):
        rospy.Subscriber("left_feedback" , skate_feedback, left_skate_start.update_values)
        left_skate_start.run()
    elif(skate_side == 2):
        rospy.Subscriber("right_feedbakc", skate_feedback, right_skate_start.update_values)
        right_skate_start.run()
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':                           
    right_skate = skate('right')
    left_skate =  skate('left')
    skate_side = input("enter 1 for left, 2 for right")

    start(left_skate, right_skate, skate_side)
