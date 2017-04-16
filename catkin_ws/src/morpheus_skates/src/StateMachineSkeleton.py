import warnings
from time import clock
import numpy

#States
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
brake = 0
freewheeling = -1

#State class:
class State(object): #State base class
    def __init__(self, name, ID):
        self.StateID
        self.name
        self.featurevector
        self.PreviousState
        self.FutureState

    def Enter(self):
        pass
    def Execute(self):
        pass
    def Exit(self):
        pass



class SingleStanceInPlaceLeft(State):
    def __init__(self, name, ID):
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = SSPL

    def Enter(self):
        print 'Entering single stance in place...'
        

    def Execute(self):
        #print "Single stance in Place"
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
        #print "Single stance in Place"
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
        #print "Single stance in Motion"
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
        #print "Single stance in Motion"
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
        #print "Double stance in place"
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
        #print "Double stance in motion"
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
        #print "Double stance in motion"
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
        #print "Single stance in Motion"
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
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = freewheeling
        velocity_r = freewheeling

    def Exit(self):
        print 'Leaving single stance in motion'

###Use imported as parent class/character in place of class below
'''class ControlSkate(object):
    def __init__(self):
        self. name, ID =  name, ID(self)

        ### Add all states to the dictionary for states:
        self. name, ID.AddState(SSPL,   SingleStanceInPlaceLeft(self. name, ID))
        self. name, ID.AddState(SSPR,   SingleStanceInPlaceRight(self. name, ID))
        self. name, ID.AddState(SSML,   SingleStanceInMotionLeft(self. name, ID))
        self. name, ID.AddState(SSMR,   SingleStanceInMotionRight(self. name, ID))
        self. name, ID.AddState(DSP,    DoubleStanceInPlace(self. name, ID))
        self. name, ID.AddState(DSM,    DoubleStanceInMotion(self. name, ID))
        self. name, ID.AddState(DSM_B,  DoubleStanceInMotionBackward(self. name, ID))
        self. name, ID.AddState(SSML_B, SingleStanceInMotionLeftBackward(self. name, ID))
        self. name, ID.AddState(SSMR_B, SingleStanceInMotionRightBackward(self. name, ID))

        ###Add all transitions to the dictionary for transitions:
        self. name, ID.AddTransition(SSPL, Transition("SingleStanceInPlaceLeft"))
        self. name, ID.AddTransition("SingleStanceInPlaceRight", Transition("SingleStanceInPlaceRight"))
        self. name, ID.AddTransition("SingleStanceInMotionLeft", Transition("SingleStanceInMotionLeft"))
        self. name, ID.AddTransition("SingleStanceInMotionRight", Transition("SingleStanceInMotionRight"))
        self. name, ID.AddTransition("DoubleStanceInMotion", Transition("DoubleStanceInMotion"))
        self. name, ID.AddTransition("DoubleStanceInPlace", Transition("DoubleStanceInPlace"))
        self. name, ID.AddTransition("SingleStanceInMotionLeftBackward", Transition("SingleStanceInMotionLeftBackward"))
        self. name, ID.AddTransition("SingleStanceInMotionRightBackward", Transition("SingleStanceInMotionRightBackward"))
        self. name, ID.AddTransition("DoubleStanceInMotionBackward", Transition("DoubleStanceInMotionBackward"))

        ###Default State: Double Stance in Place
        self. name, ID.SetState(DSP) #Always start in double stance in place

    def Execute(self):
        self. name, ID.Execute()

###Test:

if __name__=='__main__':
    statemachine = ControlSkate()
    while 1:
        State = input('Enter state ID:')
        if not(State == statemachine. name, ID.CurrentState.name):
            statemachine. name, ID.SetTransition(State)
        statemachine.Execute()
'''