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
velocity_predict = 1

#States:

class SingleStanceInPlaceLeft(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = SSPL

    def Enter(self, PrevID):
        #print 'Entering single stance in place...'
        velocity_l = 0.9*velocity_predict
        velocity_r = freewheeling
        return velocity_l, velocity_r        

    def Execute(self):
        #Do Controls Stuff
        velocity_l = velocity_predict
        velocity_r = freewheeling
        return velocity_l, velocity_r
    
    def Exit(self, NextID):
        #print 'Leaving single stance in place'

class SingleStanceInPlaceRight(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceRight'
        self.ID = SSPR
    
    def Enter(self, PrevID):
        #print 'Entering single stance in place...'
        velocity_l =  freewheeling
        velocity_r = 0.9*velocity_predict
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l =  freewheeling
        velocity_r = velocity_predict
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving single stance in place'


class SingleStanceInMotionLeft(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeft'
        self.ID = SSML

    def Enter(self, PrevID):
        #print 'Entering single stance in motion...'
        velocity_l = 0.9*velocity_predict
        velocity_r = freewheeling
        return velocity_l, velocity_r
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = velocity_predict
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving single stance in motion'

class SingleStanceInMotionRight(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRight'
        self.ID = SSMR

    def Enter(self, PrevID):
        #print 'Entering single stance in motion...'
        velocity_l = freewheeling
        velocity_r = 0.9*velocity_predict
        return velocity_l, velocity_r
        
    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = velocity_predict
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving single stance in motion'

class DoubleStanceInPlace(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInPlace'
        self.ID = DSP

    def Enter(self, PrevID):
        #print 'Entering double stance in place...'
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l = brake
        velocity_r = brake
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving double stance in place'

class DoubleStanceInMotion(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotion'
        self.ID = DSM

    def Enter(self, PrevID):
        #print 'Entering double stance in motion...'
        velocity_l = 0.9*velocity_predict
        velocity_r = 0.9*velocity_predict
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l = velocity_predict
        velocity_r = velocity_predict
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving double stance in motion'

class DoubleStanceInMotionBackward(object):
    def __init__(self, name, ID):
        self.name = 'DoubleStanceInMotionBackward'
        self.ID = DSM_B

    def Enter(self, PrevID):
        #print 'Entering double stance in motion...'
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving double stance in motion'

class SingleStanceInMotionLeftBackward(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionLeftBackward'
        self.ID = SSML_B

    def Enter(self, PrevID):
        #print 'Entering single stance in motion...'
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving single stance in motion'

class SingleStanceInMotionRightBackward(object):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInMotionRightBackward'
        self.ID = SSMR_B

    def Enter(self, PrevID):
        #print 'Entering single stance in motion...'
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Execute(self):
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling
        return velocity_l, velocity_r

    def Exit(self, NextID):
        #print 'Leaving single stance in motion'

class SkateControls(object):
    def __init__(self):
        self.states = {}
        self.states[SSPL] = SingleStanceInPlaceLeft(name = 'SingleSTanceInPlace_left', ID = SSPL)
        self.states[SSPR] = SingleStanceInPlaceRight(name = 'SingleSTanceInPlace_right', ID = SSPR)
        self.states[SSML] = SingleStanceInMotionLeft(name = 'SingleStanceInmotion_left', ID = SSML)
        self.states[SSMR] = SingleStanceInMotionRight(name = 'SingleStanceInmotion_right', ID = SSMR)
        self.states[DSP] = DoubleStanceInPlace(name = 'DoubleStanceInPlace', ID = DSP)
        self.states[DSM] = DoubleStanceInMotion(name = 'DoubleStanceInMotion', ID = DSM)
        self.states[DSM_B] = DoubleStanceInMotionBackward(name = 'DoubleStanceInMotionBackward', ID = DSM_B)
        self.states[SSML_B] = SingleStanceInMotionLeftBackward(name = 'SingleStanceInMotionLeftBackward', ID = SSML_B)
        self.states[SSMR_B] = SingleStanceInMotionRightBackward(name = 'SingleStanceInMotionRightBackward', ID = SSMR_B)
        self.CurrentStateID = DSP
        self.PreviousStateID = DSP
    
    def Enter(self, PrevID):
        self.states[self.CurrentStateID].Enter(PrevID)

    def Exit(self, NextID):
        self.states[self.CurrentStateID].Exit(NextID)

    def Execute(self):    
        self.states[self.CurrentStateID].Execute()
