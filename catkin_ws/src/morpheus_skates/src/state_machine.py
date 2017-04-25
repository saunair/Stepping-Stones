#!/usr/bin/env python
##Author: Saurabh Nair
##Edited by: Aditya Ghadiali


import numpy as np
import rospy
from sklearn.externals import joblib
from sklearn import svm
import pandas as pd
import sys
import pickle
import rospkg
import sys
from std_msgs.msg import Int8
sys.path.append('/home/stepping/mrsd_team_H/Stepping-Stones/catkin_ws/src/morpheus_skates/src/')

import ExecuteFunctions as state_obj
from std_msgs.msg import *
from morpheus_skates.msg import *
from morpheus_skates.srv import *

publish_rate = rospy.get_param("publish_rate")
eps = 0.1

### check this out properly
Double_Stance = 1 
Single_Stance_Left = 2 
Single_Stance_Right = 3

front_stepping = 1
back_stepping = -1
stance = 0

current_state = 1
state_queue = [1,1,1]

no_states = 9

SSPL = 0
SSPR = 1
SSML = 2
SSMR = 3
DSP  = 4
DSM  = 5
DSM_B = 6
SSMR_B = 7
SSML_B = 8

markov_matrix =[[0.40, 0.05, 0.25, 0.05, 0.10, 0.15, 0.0, 0.0, 0.0], 
                [0.05, 0.40, 0.05, 0.25, 0.10, 0.15, 0.0, 0.0, 0.0],
                [0.05, 0.10, 0.40, 0.05, 0.15, 0.25, 0.0, 0.0, 0.0],
                [0.10, 0.05, 0.05, 0.40, 0.15, 0.25, 0.0, 0.0, 0.0],
                [0.20, 0.20, 0.125,0.125,0.30, 0.05, 0.0, 0.0, 0.0],
                [0.20, 0.20, 0.125,0.125,0.05, 0.30, 0.0, 0.0, 0.0],
                [0.0 , 0.0 , 0.0  ,0.0  ,0.0 , 0.0 , 0.0, 0.0, 0.0],
                [0.0 ,0.0  ,0.0   ,0.0  ,0.0 , 0.0 , 0.0, 0.0, 0.0],
                [0.0 ,0.0  ,0.0   ,0.0  ,0.0 , 0.0 , 0.0, 0.0, 0.0]]



## copied one from double stance to initialize
force_values = [0.0568256229, 0.1217591166, 0.3135216534, 0.0094473129, 0.1839496493, 0.3274969757, 0.5208939314, 0.4921063781, 1.0130003691]

imu_data_left  = 0 
imu_data_right = 0
foot_positions = 0

## used for COM calculations
dist_rear  = -0.25*8.5
dist_front = 0.75*8.5

#COM list
user_com = [0, 0, 0];

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

##Populator function 
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


## execute current state
def state_machine_execute(state):
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping, back_stepping, stance, state_queue
    state_machine = state_obj.ControlSkate()
    if not(state == statemachine.ControlsStateMachine.CurrentState.ID):
        statemachine.ControlsStateMachine.SetTransition(state)
    statemachine.Execute()



def markov_decision():
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping, back_stepping, stance, state_queue
    score_list = no_states*[0] 
    for i in range(0,len(state_queue)-1):
        score_list[state_queue[i]] += markov_matrix[current_state][state_queue[i]];

    decision = score_list.index(max(score_list))
    return decision

def centre_of_mass(state):   
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping, back_stepping, stance, state_queue
    global dist_rear, dist_front
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
            force_lead_rear  =  force_values[2]
            force_lag_front  =  force_values[3] + force_values[4]
            force_lag_rear   =  force_values[5]
        else:
            force_lag_front  =  force_values[0] + force_values[1]
            force_lag_rear   =  force_values[2]
            force_lead_front =  force_values[3] + force_values[4]
            force_lead_rear  =  force_values[5]
        
        #print foot_positions[0], foot_positions[1] 
        diff = np.subtract(foot_positions[0], foot_positions[1])
        dist = np.linalg.norm(diff)
        
        COM = (float(force_lead_front*(dist_front) +
               force_lead_rear*(dist_rear) +
               force_lag_front*(dist_front - dist) +
               force_lag_rear*(dist_rear - dist))/(force_lead_front + force_lead_rear + 
               force_lag_front + force_lag_rear))

    del user_com[0]
    user_com.append(COM)

def check_polygon():
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping, back_stepping, stance, state_queue
    average_COM = float(user_com[0] + user_com[1] + user_com[2])/3
    global dist_rear, dist_front
    
    if average_COM > (dist_front + eps):    #tolerance
        motion = front_stepping
    elif average_COM < (dist_rear - eps):   #tolerance
        motion = back_stepping
    else:
        motion = 0
    return motion

def state_machine_update(stance_classifier):
    global force_values, imu_data_left, imu_data_right, foot_positions, front_stepping, back_stepping, stance, state_queue
    
    rate = rospy.Rate(publish_rate) # 100hz
    pub_l = rospy.Publisher('left_state', Int16, queue_size=100)
    pub_r = rospy.Publisher('right_state', Int16, queue_size=100)
    pub_gait = rospy.Publisher('user_gait', Int16, queue_size=100)

    StateMachine = state_obj.SkateControls()
    while not rospy.is_shutdown():
        feature_temp = np.asarray(np.asarray(force_values))
	feature_temp = feature_temp.reshape(1,-1)
        static_state = stance_classifier.predict(feature_temp)
        ##append the state and also delete the oldest state

        if static_state[0] == Double_Stance:
            centre_of_mass(static_state[0])
            if(check_polygon() == front_stepping):
                state = DSM 
            elif(check_polygon() == stance): 
                state = DSP
            elif(check_polygon() == back_stepping):
                state = DSM_B

        elif static_state[0] == Single_Stance_Left:
            centre_of_mass(static_state[0])
            if(check_polygon() == front_stepping):
                state = SSML
            elif(check_polygon() == stance):
                state = SSPL
            elif(check_polygon() == back_stepping):
                state = SSML_B

        elif static_state[0] == Single_Stance_Right:
            centre_of_mass(static_state[0])
            if(check_polygon() == front_stepping):
                state =  SSMR
            elif(check_polygon() == stance):
                state = SSPR
            elif(check_polygon() == back_stepping):
                state = SSMR_B
       
	else:
            state = DSP 
        #current_state = markov_decision()
        del state_queue[0]

        ## append the latest prediction
        state_queue.append(state)
        
        if state != StateMachine.CurrentStateID:
            #StateMachine.Exit(state)
            StateMachine.CurrentStateID = state
            control_left, control_right = StateMachine.Enter(state_queue[2])
            pub_l.publish(control_left)
            pub_r.publish(control_right)
        
        control_left, control_right = StateMachine.Execute()
        pub_l.publish(control_left)
        pub_r.publish(control_right)
        pub_gait.publish(state)
        

if __name__=='__main__':
    #rospack = rospkg.RosPack()
    #morpheus_path = rospack.get_path('morpheus_skates')
    #model_file = morpheus_path + '/src/svm.pkl'
    
    rospy.init_node('state_machine', anonymous=True)
    model_file = '/home/stepping/mrsd_team_H/Stepping-Stones/catkin_ws/src/morpheus_skates/src/svm.pkl'
    
    file = open(model_file, 'rb')
    stance_classifier = pickle.load(file)
    file.close()
    #stance_classifier = pickle.load(model_file) 
    rospy.Subscriber("total_message", integrated_message, update_vector)
    foot_length = ask_foot_size()
    calculate_foot_points(foot_length)
    state_machine_update(stance_classifier)
