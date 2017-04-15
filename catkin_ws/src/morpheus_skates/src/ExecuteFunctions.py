## Author: Aditya Ghadiali
## Edited by Saurabh Nair
import warnings
from time import clock
import numpy

SSPL = 0
SSPR = 1
SSML = 2
SSMR = 3
DSP  = 4
DSM  = 5
DSM_B = 6
SSMR_B = 7
SSML_B = 8

class SingleStanceInPlaceLeft(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInPlace,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = 0

    def Enter(self):
        #print 'Entering single stance in place...'
        super(SingleStanceInPlace, self).Enter()

    def Execute(self, feature_vector):
        #print "Single stance in Place"
        #Do Controls Stuff
        velocity_l =  model.predict
        velocity_r = -1
    
    def Exit(self):
        #print 'Leaving single stance in place'

class SingleStanceInPlaceRight(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInPlace,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInPlaceRight'
        self.ID = 1
    
    def Enter(self):
        #print 'Entering single stance in place...'
        super(SingleStanceInPlace, self).Enter()

    def Execute(self, feature_vector):
        #print "Single stance in Place"
        #Do Controls Stuff
        velocity_l =  -1
        velocity_r =  model.predict

    def Exit(self):
        #print 'Leaving single stance in place'


class SingleStanceInMotionLeft(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInMotion,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInMotionLeft'
        self.ID = 2

    def Enter(self):
        #print 'Entering single stance in motion...'
        super(SingleStanceInMotion, self).Enter()

    def Execute(self, feature_vector):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = model.predict(feature_vector)
        velocity_r = -1

    def Exit(self):
        #print 'Leaving single stance in motion'

class SingleStanceInMotionRight(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInMotion,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInMotionRight'
        self.ID = 3

    def Enter(self):
        #print 'Entering single stance in motion...'
        super(SingleStanceInMotion, self).Enter()

    def Execute(self, feature_vector):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = model.predict(feature_vector)

    def Exit(self):
        #print 'Leaving single stance in motion'

class DoubleStanceInPlace(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(DoubleStanceInPlace,self).__init__(ControlsStateMachine)
        self.name = 'DoubleStanceInPlace'
        self.ID = 4

    def Enter(self):
        #print 'Entering double stance in place...'
        super(DoubleStanceInPlace, self).Enter()

    def Execute(self, feature_vector):
        #print "Double stance in place"
        #Do Controls Stuff
        velocity_l = 0
        velocity_r = 0

    def Exit(self):
        #print 'Leaving double stance in place'

class DoubleStanceInMotion(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(DoubleStanceInMotion,self).__init__(ControlsStateMachine)
        self.name = 'DoubleStanceInMotion'
    	self.ID = 5

    def Enter(self):
        #print 'Entering double stance in motion...'
        super(DoubleStanceInMotionLeft, self).Enter()

    def Execute(self, feature_vector):
        #print "Double stance in motion"
        #Do Controls Stuff
        vel = model.predict(feature_vector)
        velocity_l = vel
        velocity_r = vel

    def Exit(self):
        #print 'Leaving double stance in motion'

class DoubleStanceInMotionBackward(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(DoubleStanceInMotionRight,self).__init__(ControlsStateMachine)
        self.name = 'DoubleStanceInMotionBackward'
    	self.ID = 6

    def Enter(self):
        #print 'Entering double stance in motion...'
        super(DoubleStanceInMotionBackward, self).Enter()

    def Execute(self, feature_vector):
        #print "Double stance in motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = -1

    def Exit(self):
        #print 'Leaving double stance in motion'

class SingleStanceInMotionLeftBackward(State):
    def __init__(self,ControlsStateMachine):
        self.name = 'SingleStanceInMotionLeftBackward'
        self.ID = 7

    def Enter(self):
        super(SingleStanceInMotion, self).Enter()

    def Execute(self):
        velocity_l = -1
        velocity_r = -1

    def Exit(self):
        #print 'Leaving single stance in motion'

class SingleStanceInMotionRightBackward(State):
    def __init__(self, name, ):
        self.name = 'SingleStanceInMotionRightBackward'
        self.ID = 8

    def Enter(self):
        #print 'enter state'
    def Execute(self, feature_vector):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = -1
        return velocity_l, velocity_r
    def Exit(self):
        #print 'Leaving single stance in motion'
