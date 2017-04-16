import itertools
from morpheus_skates.msg import integrated_message
total_message = integrated_message()


class cow(object):
	def __init__(self):
		self.left_normal_front_outer=-0.02      
		self.left_normal_front_inner=-.05
		self.left_normal_rear=-.3
		self.right_normal_front_outer=-0.7
		self.right_normal_front_inner=-0.02
		self.right_normal_rear=-0.02
		self.right_normal_total=-0.02
		self.left_normal_total=-0.02
		self.normal_total=-0.04
	
def normalize_update(cow):
    global total_message
    total_message.normalized_force = cow
    print dir(total_message.normalized_force)

if __name__ == '__main__':
	cow = cow()
	normalize_update(cow)