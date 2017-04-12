#!/usr/bin/env python
##Author: Saurabh Nair
import numpy as np
import rospy
from sklearn.externals import joblib
from sklearn import svm
import pandas as pd
import sys
import pickle
import rospkg
from std_msgs.msg import *
from morpheus_skates.msg import *
from morpheus_skates.srv import *

### check this out properly
Double_Stance = 1 
Single_Stance_Left = 2 
Single_Stance_Right = 3


## copied one from double stance to initialize`
force_values = [0.0568256229, 0.1217591166, 0.3135216534, 0.0094473129, 0.1839496493, 0.3274969757, 0.5208939314, 0.4921063781, 1.0130003691]

imu_data_left = 0 
imu_data_right = 0
foot_positions = 0

## used for COM calculations
dist_rear  = -0.2*10 
dist_front = 0.8*10

#ask for user foot size
def ask_foot_size():
    rospy.wait_for_service('shoe_size')
    try:
        resp1 = rospy.ServiceProxy('shoe_size', user_shoe_size)
        #not passing one anymore to  move on from empty
        resp1 = resp1()
        return resp1.user_shoe_size
        #return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


### Distance calculations for polygon of support
def calculate_foot_points(foot_length):
    global dist_rear, dist_front
    dist_rear  = -0.2*foot_length 
    dist_front = 0.8*foot_length

def update_vector(msg):
    global force_values, imu_data_left, imu_data_right, foot_positions
    force_values = [msg.normalized_force.left_normal_front_outer, 
                    msg.normalized_force.left_normal_front_inner,
                    msg.normalized_force.left_normal_rear,
                    msg.normalized_force.right_normal_front_outer,
                    msg.normalized_force.right_normal_front_inner,
                    msg.normalized_force.right_normal_rear,
                    msg.normalized_force.right_normal_total,
                    msg.normalized_force.left_normal_total,
                    msg.normalized_force.normal_total]

    imu_data_left = [msg.left_feedback.imu_quat_x,
                     msg.left_feedback.imu_quat_y,
                     msg.left_feedback.imu_quat_z,
                     msg.left_feedback.imu_quat_w,
                     msg.left_feedback.imu_accel_x,
                     msg.left_feedback.imu_accel_y,
                     msg.left_feedback.imu_accel_z,
                     msg.left_feedback.imu_rate_x,
                     msg.left_feedback.imu_rate_y,
                     msg.left_feedback.imu_rate_z]

    imu_data_right = [msg.right_feedback.imu_quat_x,
                      msg.right_feedback.imu_quat_y,
                      msg.right_feedback.imu_quat_z,
                      msg.right_feedback.imu_quat_w,
                      msg.right_feedback.imu_accel_x,
                      msg.right_feedback.imu_accel_y,
                      msg.right_feedback.imu_accel_z,
                      msg.right_feedback.imu_rate_x,
                      msg.right_feedback.imu_rate_y,
                      msg.right_feedback.imu_rate_z]

    foot_positions = [msg.foot_left, msg.foot_right]
 

def check_polygon(state):   
    global force_values, imu_data_left, imu_data_right, foot_positions
    try:
        if state==Single_Stance_Left:
            force_front = (force_values[0] + force_values[1])
            force_rear = force_values[2]
            COM = float(force_front*dist_front - force_rear*dist_rear)/(force_front + force_rear)
    
        elif state==Single_Stance_Right:
            force_front = (force_values[2] + force_values[3])
            force_rear = force_values[4]
            COM = float(force_front*dist_front - force_rear*dist_rear)/(force_front + force_rear)

        elif state==Double_Stance:
            force_front = (force_values[0] + force_values[1])
            force_rear = force_values[2]
            COM = float(force_front*dist_front - force_rear*dist_rear)/(force_front + force_rear)
    except:
        rospy.logwarn('division by zero')

def state_machine(stance_classifier):
    global force_values, imu_data_left, imu_data_right, foot_positions
    while not rospy.is_shutdown():
        feature_temp = np.asarray(np.asarray(force_values))
	feature_temp = feature_temp.reshape(1,-1)
        static_state = stance_classifier.predict(feature_temp)
        print static_state 
        if static_state[0] == Double_Stance:
            motion = check_polygon(static_state) 
 
        elif static_state[0] == Single_Stance_Left:
            motion = check_polygon(static_state)
    
        elif static_state[0] == Single_Stance_Right:
            motion = check_polygon(static_state)


if __name__=='__main__':
    #rospack = rospkg.RosPack()
    #morpheus_path = rospack.get_path('morpheus_skates')
    #model_file = morpheus_path + '/src/svm.pkl'
    
    rospy.init_node('state_machine', anonymous=True)
    model_file = '/home/saurabh/Stepping-Stones/catkin_ws/src/morpheus_skates/src/svm.pkl'
    
    file = open(model_file, 'rb')
    stance_classifier = pickle.load(file)
    file.close()
    #stance_classifier = pickle.load(model_file) 
    rospy.Subscriber("total_message", integrated_message, update_vector)
    foot_length = ask_foot_size()
    calculate_foot_points(foot_length)
    state_machine(stance_classifier)