##Author: Saurabh Nair
import numpy
from sklearn.externals import joblib
from sklearn import svm
import pandas
import sys
import pickle


### check this out properly
Double_Stance = 1 
Single_Stance_left = 2 
Single_Stance_Right = 3


def update_vector(msg):
    force_values = [msg.force_normalized.left_normal_front_outer msg.force_normalized.left_normal_front_inner msg.force_normalized.left_normal_rear msg.force_normalized.right_normal_front_outer msg.force_normalized.right_normal_front_inner msg.force_normalized.right_normal_rear msg.force_normalized.right_normal_total msg.force_normalized.left_normal_total msg.force_normalized.normal_total]

    imu_data_left = [msg.left_feedback.imu_quat_x msg.left_feedback.imu_quat_y msg.left_feedback.imu_quat_z msg.left_feedback.imu_quat_w msg.left_feedback.imu_accel_x msg.left_feedback.imu_accel_y msg.left_feedback.imu_accel_z msg.left_feedback.imu_rate_x msg.left_feedback.imu_rate_y msg.left_feedback.imu_rate_z]

    imu_data_right = [msg.right_feedback.imu_quat_x msg.right_feedback.imu_quat_y msg.right_feedback.imu_quat_z msg.right_feedback.imu_quat_w msg.right_feedback.imu_accel_x msg.right_feedback.imu_accel_y msg.right_feedback.imu_accel_z msg.right_feedback.imu_rate_x msg.right_feedback.imu_rate_y msg.right_feedback.imu_rate_z]

     foot_positions = [msg.foot_left msg.foot_right]

 

def check_polygon(feature_vector, state):   
    

    


def state_machine(stance_classifier):
    static_state = stance_classifier.predict(feature_vector)
    if static_state == Double_Stance:
         motion = check_polygon(trimmed_data, static_stance) 
 
    elif static_stance == Single_Stance_Left:
         motion = check_polygon(trimmed_data, static_stance)
    
    elif static_stance == Single_Stance_Right:
         motion = check_polygon(trimmed_data, static_stance)





if __name__=='__main__':
    stance_classifier = pickle.load(open("svm.pkl", "rb"))
    rospy.Subscriber("total_message", integrated_message, update_vector)
