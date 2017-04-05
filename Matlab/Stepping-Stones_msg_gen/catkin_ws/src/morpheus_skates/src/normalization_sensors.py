#!/usr/bin/env python
# license removed for brevity
import rospy
import time
from std_msgs.msg import UInt16
import yaml
from motor.msg import Num
import os

#config_file = '~/catkin_ws/src/motor/config/calibration_values.yaml'

config_file = '/home/saurabh/catkin_ws/src/motor/config/calibration_values.yaml'
normalization_file = '/home/saurabh/catkin_ws/src/motor/config/normalized_values.yaml'

count_left = 0
count_right = 0

#Will have to change over time 
#macro values for max force values
MAX_F1 = 20
MAX_F2 = 20
MAX_F3 = 20

#set to values for checks during the code
w = -1
left_bias_f1 = -1
left_bias_f2 = -1
left_bias_f3 = -1

right_bias_f1 = -1
right_bias_f2 = -1
right_bias_f3 = -1

#set to values for checks during the code
def restart_routine():    
    global count_left, left_f1, left_f2, left_f3, left_f1, left_f2, left_f3, w
    w = -1
    left_f1 = -1
    left_f2 = -1
    left_f3 = -1

    right_f1 = -1
    right_f2 = -1
    right_f3 = -1

#this might raise an issue later as we are appending values; This will lead to having continuity issues
left_f1 = []
left_f2 = []
left_f3 = []

right__f1 = []
right_f2 = []
right_f3 = []

def left_values(data):
    
    global count_left
    #print os.path.exists(config_file), "here" 
    #rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.f1)
    
    if count_left==0:
        left_f1 = 0
        left_f2 = 0
        left_f3 = 0
        count_left+=1

    elif count_left<=200:
        left_f1 += data.f1
        left_f2 += data.f2
        left_f3 += data.f3
        count_left+=1

    elif count_left==201:
        left_f1/=200
        left_f2/=200
        left_f3/=200
        #put a check for the bias changes/values
        if left_f1 < MAX_F1:
            print "Left F1 load not corrected"
        if left_f2 < MAX_F2:
            print "Left F2 load not corrected"
        if left_f3 < MAX_F3:
            print "Left F3 load not corrected"
        
        if left_f1 < MAX_F1 and left_f2 < MAX_F2 and left_f3 < MAX_F3:
            w = input("input weight here")
            count_left+=1
        else:
            restart_routine()
        #rospy.sleep(100.0)

    if w!=-1:
    #keep appending for another 200 values
        if count_left<=400:
            left_gain_f1.append(2*(data.f1 - left_bias_f1)/w)
            left_gain_f2.append(2*(data.f2 - left_bias_f2)/w)
            left_gain_f3.append(2*(data.f3 - left_bias.f3)/w)
            count_left+=1
    
        elif count_left==401:
            print sum(left_gain_f1)
            left_gain_f1 = float(sum(left_gain_f1))/len(left_gain_f1)
            left_gain_f2 = float(sum(left_gain_f2))/len(left_gain_f2)
            left_gain_f3 = float(sum(left_gain_f3))/len(left_gain_f3)
            count_left+=1
            data_write()

def right_values(data):
    global count_right
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.f1)
    count_right+=1

    if count_right==0:
        right_f1 = 0
        right_f2 = 0
        right_f3 = 0
    
    if count_right<=200:
        right_f1 += data.f1
        right_f2 += data.f2
        right_f3 += data.f3

    elif count_right==201:
        right_f1/=200
        right_f2/=200
        right_f3/=200
        #put a check for the bias changes/values
        if right_f1 < MAX_F1:
            print "Right F1 load not corrected"
        if right_f2 < MAX_F2:
            print "Right F2 load not corrected"
        if right_f3 < MAX_F3:
            print "Right F3 load not corrected"
        
        if right_bias_f1 < MAX_F1 and  right_bias_f2 < MAX_F2 and right_bias_f3 < MAX_F3:
            w = input("input weight here")
            count_right+=1
        else:
            restart_routine()
    
    if w!=-1:
    #keep appending for another 200 values
        if count_right<=400:
            right_gain_f1.append(2*(data.f1 - right_bias_f1)/w)
            right_gain_f2.append(2*(data.f2 - right_bias_f2)/w)
            right_gain_f3.append(2*(data.f3 - right_bias_f3)/w)

        elif count_right==401:
            right_gain_f1 = float(sum(right_gain_f1))/len(right_gain_f1)
            right_gain_f2 = float(sum(right_gain_f2))/len(right_gain_f2)
            right_gain_f3 = float(sum(right_gain_f3))/len(right_gain_f3)
            data_write()   

def bias():
    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('bias', anonymous=True)
    rospy.Subscriber("left_feedback", Num, left_values)
    rospy.Subscriber("right_feedback", Num, right_values)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

def data_write():
    d = {}
    global config_file, right_bias_f1, right_bias_f2, right_bias_f3, right_gain_f1,right_gain_f2,right_gain_f3, left_bias_f1, left_bias_f2, left_bias_f3, left_gain_f1,left_gain_f2,left_gain_f3
    print "check", rospy.get_param("left_gain_f3")

    if right_bias_f1 != -1: 
        d["right_bias_f1"] = right_bias_f1
        d["right_bias_f2"] = right_bias_f2
        d["right_bias_f3"] = right_bias_f3
        if sensor_number==1:
            d["right_gain_f1"] = right_gain_f1
            print right_gain_f1, "right_gain_f1"
            d["right_gain_f2"] = rospy.get_param("right_gain_f2")
            d["right_gain_f3"] = rospy.get_param("right_gain_f3")
        elif sensor_number==2:
            d["right_gain_f2"] = right_gain_f2
            print right_gain_f2, "right_gain_f2"
            d["right_gain_f1"] = rospy.get_param("right_gain_f1")
            d["right_gain_f3"] = rospy.get_param("right_gain_f3")
        elif sensor_number==3:
            d["right_gain_f3"] = right_gain_f3
            print right_gain_f3, "right_gain_f3"
            d["right_gain_f2"] = rospy.get_param("right_gain_f2")
            d["right_gain_f1"] = rospy.get_param("right_gain_f1")
        
    else:
        d["right_bias_f1"] = rospy.get_param("right_bias_f1")
        d["right_bias_f2"] = rospy.get_param("right_bias_f2")
        d["right_bias_f3"] = rospy.get_param("right_bias_f3")
        d["right_gain_f1"] = rospy.get_param("right_gain_f1")
        d["right_gain_f2"] = rospy.get_param("right_gain_f2")
        d["right_gain_f3"] = rospy.get_param("right_gain_f3")
    
    if left_bias_f1 != -1: 
        
        d["left_bias_f1"] = left_bias_f1
        d["left_bias_f2"] = left_bias_f2
        d["left_bias_f3"] = left_bias_f3
        if sensor_number==1:
            d["left_gain_f1"] = left_gain_f1
            print left_gain_f1, "left_gain_f1"
            d["left_gain_f2"] = rospy.get_param("left_gain_f2")
            d["left_gain_f3"] = rospy.get_param("left_gain_f3")
        
        elif sensor_number==2:
            d["left_gain_f2"] = left_gain_f2
            print left_gain_f2, "left_gain_f2"
            d["left_gain_f1"] = rospy.get_param("left_gain_f1")
            d["left_gain_f3"] = rospy.get_param("left_gain_f3")
        
        elif sensor_number==3:
            d["left_gain_f3"] = left_gain_f3
            print right_gain_f3, "right_gain_f3"
            d["left_gain_f1"] = rospy.get_param("left_gain_f1")
            d["left_gain_f2"] = rospy.get_param("left_gain_f2")
    else:
        d["left_bias_f1"] = rospy.get_param("left_bias_f1")
        d["left_bias_f2"] = rospy.get_param("left_bias_f2")
        d["left_bias_f3"] = rospy.get_param("left_bias_f3")
        d["left_gain_f1"] = rospy.get_param("left_gain_f1")
        d["left_gain_f2"] = rospy.get_param("left_gain_f2")
        d["left_gain_f3"] = rospy.get_param("left_gain_f3")
   
    rospy.set_param("left_bias_f1",d["left_bias_f1"])
    rospy.set_param("left_bias_f2",d["left_bias_f2"])
    rospy.set_param("left_bias_f3",d["left_bias_f3"]) 
    rospy.set_param("left_gain_f1",d["left_gain_f1"])
    rospy.set_param("left_gain_f2",d["left_gain_f2"])
    rospy.set_param("left_gain_f3",d["left_gain_f3"])
    rospy.set_param("right_bias_f1",d["right_bias_f1"])
    rospy.set_param("right_bias_f2",d["right_bias_f2"])
    rospy.set_param("right_bias_f3",d["right_bias_f3"])
    rospy.set_param("right_gain_f1",d["right_gain_f1"])
    rospy.set_param("right_gain_f2",d["right_gain_f2"])
    rospy.set_param("right_gain_f3",d["right_gain_f3"])
   

    stream = file(config_file, 'w')
    yaml.dump(d, stream)
    print left_gain_f2
    print rospy.get_param("Written the values in YAML!!!!")
    restart_routine():    

if __name__ == '__main__':                           
    bias()