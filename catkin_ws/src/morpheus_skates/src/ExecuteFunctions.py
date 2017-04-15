## Author: Aditya Ghadiali
## Edited by Saurabh Nair
import warnings
from time import clock
import numpy

#State IDs:

SSPL = 0
SSPR = 1
SSML = 2
SSMR = 3
DSP  = 4
DSM  = 5
DSM_B = 6
SSMR_B = 7
SSML_B = 8

#Control Variables:

freewheeling = -1
brake = 0

#States:

class SingleStanceInPlaceLeft(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = SSPL

    def Enter(self):
        print 'Entering single stance in place...'
        

    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = freewheeling
    
    def Exit(self):
        print 'Leaving single stance in place'

class SingleStanceInPlaceRight(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceRight'
        self.ID = SSPR
    
    def Enter(self):
        print 'Entering single stance in place...'

    def Execute(self):
        #Do Controls Stuff
        velocity_l =  freewheeling
        velocity_r =  model.predict

    def Exit(self):
        print 'Leaving single stance in place'


class SingleStanceInMotionLeft(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeft'
        self.ID = SSML

    def Enter(self):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = freewheeling

    def Exit(self):
        print 'Leaving single stance in motion'

class SingleStanceInMotionRight(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRight'
        self.ID = SSMR

    def Enter(self):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = model.predict

    def Exit(self):
        print 'Leaving single stance in motion'

class DoubleStanceInPlace(State):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInPlace'
        self.ID = DSP

    def Enter(self):
        print 'Entering double stance in place...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = brake
        velocity_r = brake

    def Exit(self):
        print 'Leaving double stance in place'

class DoubleStanceInMotion(State):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotion'
        self.ID = DSM

    def Enter(self):
        print 'Entering double stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = model.predict

    def Exit(self):
        print 'Leaving double stance in motion'

class DoubleStanceInMotionBackward(State):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotionBackward'
        self.ID = DSM_B

    def Enter(self):
        print 'Entering double stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self):
        print 'Leaving double stance in motion'

class SingleStanceInMotionLeftBackward(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeftBackward'
        self.ID = SSML_B

    def Enter(self):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self):
        print 'Leaving single stance in motion'

class SingleStanceInMotionRightBackward(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRightBackward'
        self.ID = SSMR_B

    def Enter(self):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self):
        print 'Leaving single stance in motion'
