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

class SingleStanceInPlaceLeft(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = SSPL

    def Enter(self, PrevID):
        print 'Entering single stance in place...'
        

    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = freewheeling
    
    def Exit(self, NextID):
        print 'Leaving single stance in place'

class SingleStanceInPlaceRight(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceRight'
        self.ID = SSPR
    
    def Enter(self, PrevID):
        print 'Entering single stance in place...'

    def Execute(self):
        #Do Controls Stuff
        velocity_l =  freewheeling
        velocity_r =  model.predict

    def Exit(self, NextID):
        print 'Leaving single stance in place'


class SingleStanceInMotionLeft(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeft'
        self.ID = SSML

    def Enter(self, PrevID):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = freewheeling

    def Exit(self, NextID):
        print 'Leaving single stance in motion'

class SingleStanceInMotionRight(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRight'
        self.ID = SSMR

    def Enter(self, PrevID):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = model.predict

    def Exit(self, NextID):
        print 'Leaving single stance in motion'

class DoubleStanceInPlace(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInPlace'
        self.ID = DSP

    def Enter(self, PrevID):
        print 'Entering double stance in place...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = brake
        velocity_r = brake

    def Exit(self, NextID):
        print 'Leaving double stance in place'

class DoubleStanceInMotion(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotion'
        self.ID = DSM

    def Enter(self, PrevID):
        print 'Entering double stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = model.predict

    def Exit(self, NextID):
        print 'Leaving double stance in motion'

class DoubleStanceInMotionBackward(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotionBackward'
        self.ID = DSM_B

    def Enter(self, PrevID):
        print 'Entering double stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self, NextID):
        print 'Leaving double stance in motion'

class SingleStanceInMotionLeftBackward(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeftBackward'
        self.ID = SSML_B

    def Enter(self, PrevID):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self, NextID):
        print 'Leaving single stance in motion'

class SingleStanceInMotionRightBackward(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRightBackward'
        self.ID = SSMR_B

    def Enter(self, PrevID):
        print 'Entering single stance in motion...'
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self, NextID):
        print 'Leaving single stance in motion'

class SkateControls(object):
    def __init__(self):
        self.states = {}
        states[SSPL] = SingleStanceInPlaceLeft()
        states[SSPR] = SingleStanceInPlaceRight()
        states[SSML] = SingleStanceInMotionLeft()
        states[SSMR] = SingleStanceInMotionRight()
        states[DSP] = DoubleStanceInPlace()
        states[DSM] = DoubleStanceInMotion()
        states[DSM_B] = DoubleStanceInMotionBackward()
        states[SSML_B] = SingleStanceInMotionLeftBackward()
        states[SSMR_B] = SingleStanceInMotionRightBackward()
        self.CurrentStateID = DSP
        self.PreviousStateID = DSP
    
    def Enter(self, PrevID):
        states[self.CurrentStateID].Enter(PrevID)

    def Exit(self, NextID):
        states[self.CurrentStateID].Exit(NextID)

    def Execute(self):    
        states[self.CurrentStateID].Execute()