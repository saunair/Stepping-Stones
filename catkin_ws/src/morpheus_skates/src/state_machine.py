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

front_stepping = 1
back_stepping = -1
stance = 0

current_state = 1
state_queue = [1,1,1]

no_states = 6
SSPL = 0 
SSPR = 1 
SSML = 2 
SSMR = 3 
DSP  = 4 
DSM  = 5

DSM_B = 6
SSMR_B = 7
SSML_B = 8

markov_matrix =[[0.40, 0.05, 0.25, 0.05, 0.10, 0.15], 
                [0.05, 0.40, 0.05, 0.25, 0.10, 0.15],
                [0.05, 0.10, 0.40, 0.05, 0.15, 0.25],
                [0.10, 0.05, 0.05, 0.40, 0.15, 0.25],
                [0.20, 0.20, 0.125,0.125,0.30, 0.05],
                [0.20, 0.20, 0.125,0.125,0.05, 0.30]]



## copied one from double stance to initialize
force_values = [0.0568256229, 0.1217591166, 0.3135216534, 0.0094473129, 0.1839496493, 0.3274969757, 0.5208939314, 0.4921063781, 1.0130003691]

imu_data_left  = 0 
imu_data_right = 0
foot_positions = 0

## used for COM calculations
dist_rear  = -0.25*10 
dist_front = 0.75*10

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
    dist_rear  = -0.25*foot_length 
    dist_front = 0.75*foot_length

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

    foot_positions = [[msg.foot_left[0], msg.foot_left[1],msg.foot_left[2]], [msg.foot_right[0], msg.foot_right[1], msg.foot_right[2]]]
 
def markov_decision():
    score_list = no_states*[0] 
    for i in range(0,len(state_queue)):
        score_list[state_queue[i]] += makov_matrix[current_state][state_queue[i]];

    decision = score_list.index(max(score_list))
    return decision

def check_polygon(state):   
    global force_values, imu_data_left, imu_data_right, foot_positions
    global dist_rear, dist_front
    try:
        if state==Single_Stance_Left:
            force_front = (force_values[0] + force_values[1])
            force_rear = force_values[2]
            COM = float(force_front*dist_front + force_rear*dist_rear)/(force_front + force_rear)
    
        elif state==Single_Stance_Right:
            force_front = (force_values[2] + force_values[3])
            force_rear = force_values[4]
            COM = float(force_front*dist_front + force_rear*dist_rear)/(force_front + force_rear)

        elif state==Double_Stance:
            if(foot_positions[0][0] > foot_positions[1][0]):
                force_lead_front =  force_values[0] + force_values[1]
                force_lead_back  =  force_values[2]
                force_lag_front  =  force_values[3] + force_values[4]
                force_lag_rear   =  force_values[5]
            else:
                force_lag_front  =  force_values[0] + force_values[1]
                force_lag_back   =  force_values[2]
                force_lead_front =  force_values[3] + force_values[4]
                force_lead_rear  =  force_values[5]
             
            dist = np.linalg.norm(foot_positions[0], foot_positions[1])
            
            COM = (float(force_lead_front*(dist_front) +
                   force_lead_back*(dist_rear) +
                   force_lag_front*(dist_front - dist) +
                   force_lag_back*(dist_rear - dist))/(force_lead_front + front_lead_rear + 
                   force_lag_front + force_lag_rear))

        if COM > (dist_front + eps):    #tolerance
            motion = front_stepping
        elif COM < (dist_rear - eps):   #tolerance
            motion = back_stepping
        else:
            motion = 0


    except:
        rospy.logwarn('division by zero')
    return motion

def state_machine(stance_classifier):
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping. back_stepping, stance
    while not rospy.is_shutdown():
        feature_temp = np.asarray(np.asarray(force_values))
	feature_temp = feature_temp.reshape(1,-1)
        static_state = stance_classifier.predict(feature_temp)
        ##append the state and also delete the oldest state

        if static_state[0] == Double_Stance:
            if(check_polygon(static_state) == front_stepping):
                state = DSM 
            elif(check_polygon(static_state) == stance): 
                state = DSP
            elif(check_polygon(static_state) == back_stepping):
                state = DSM_B

        elif static_state[0] == Single_Stance_Left:
            if(check_polygon(static_state) == front_stepping):
                state = SSML
            elif(check_polygon(static_state) == stance):
                state = SSPL
            elif(check_polygon(static_state) == back_stepping):
                state = SSML_B

        elif static_state[0] == Single_Stance_Right:
            if(check_polygon(static_state) == front_stepping):
                state =  SSMR
            elif(check_polygon(static_state) == stance):
                state = SSPR
            elif(check_polygon(static_state) == back_stepping):
                state = SSMR_B
        
        current_state = markov_decision()
        del state_queue[0]

        ## append the latest prediction
        state_queue = state_queue.append(state) 
        

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
