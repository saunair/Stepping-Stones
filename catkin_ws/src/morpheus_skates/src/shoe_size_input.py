#!/usr/bin/env python
#Author Saurabh Nair

import rospy
from morpheus_skates.srv import user_shoe_size

### Server for taking the user shoe size input and then sending it to stepping stones. 
### This vlaue will be crucial for COM and polygon of support calculations

shoe_size = 11.2
def keyboard_input():
    global shoe_size
    try:
        shoe_size = input("Please input the user shoe size in inches")
    except:
        shoe_size = 11.2
    rospy.set_param('user_shoe_size', shoe_size)
    return shoe_size

def handle_service(req):
    global shoe_size
    return shoe_size

def shoe_size_server():
    global shoe_size
    rospy.init_node('shoe_size_input', anonymous=True)
    shoe_size = keyboard_input()
    s = rospy.Service('shoe_size', user_shoe_size, handle_service)
    rospy.spin()

if __name__ == '__main__':
    shoe_size_server()
