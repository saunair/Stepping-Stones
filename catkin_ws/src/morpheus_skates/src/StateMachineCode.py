#Import SVM Output
try:
    from stepping_stones import MorpheusSkate #import morpheus skate parent class
    from stepping_stones import Current_State #SVM Output
except ImportError:
    print "hag diya"
    print ImportError
    pass

#Warnings:
import warnings
logger = logging.getLogger(__name__)
logger.addHandler(logging.NullHandler())
#Other useful packages:
from time import clock
import numpy

###All States

#Declare each State class:
class State(object): #State base class
    def __init__(self, ControlsStateMachine):
        self.ControlsStateMachine = ControlsStateMachine
        self.timer = 0
        self.startTime = 0
    def Enter(self):
        self.startTime = int(clock())
    def Execute(self):
        pass
    def Exit(self):
        pass

class SingleStanceInPlace(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInPlace,self).__init__(ControlsStateMachine)

    def Enter(self):
        print 'Entering single stance in place...'
        super(SingleStanceInPlace, self).Enter()

    def Execute(self):
        print "Single stance in Place"
        #Do Controls Stuff

    def Exit(self):
        print 'Leaving single stance in place'

class SingleStanceInMotion(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInMotion,self).__init__(ControlsStateMachine)

    def Enter(self):
        print 'Entering single stance in motion...'
        super(SingleStanceInMotion, self).Enter()

    def Execute(self):
        print "Single stance in Motion"
        #Do Controls Stuff

    def Exit(self):
        print 'Leaving single stance in motion'

class DoubleStanceInPlace(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(DoubleStanceInPlace,self).__init__(ControlsStateMachine)

    def Enter(self):
        print 'Entering double stance in place...'
        super(DoubleStanceInPlace, self).Enter()

    def Execute(self):
        print "Double stance in place"
        #Do Controls Stuff

    def Exit(self):
        print 'Leaving double stance in place'

class DoubleStanceInMotion(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(DoubleStanceInMotion,self).__init__(ControlsStateMachine)

    def Enter(self):
        print 'Entering double stance in motion...'
        super(DoubleStanceInMotion, self).Enter()

    def Execute(self):
        print "Double stance in motion"
        #Do Controls Stuff

    def Exit(self):
        print 'Leaving double stance in motion'


###Transitions

class Transition(object):
    def __init__(self,toState):
        self.toState = toState
    def Execute(self):
        print "Transitioning"


###State Machine

class ControlsStateMachine:
    def __init__(self, char):
        self.char = char
        self.states = {default} #Dictionary for states
        self.transitions = {} #Dictionary for transitions
        self.CurrentState = default #Current State
        self.trans = None #Current transition

    #State setting function
    def SetState(self, StateName)
        self.CurrentState = self.states[StateName] #Look for the passed state in the states dictionary
    #Transition function
    def Transition(self, TransitionName)
        self.trans = self.transitions[TransitionName] #Repeat for transition

    def Execute(self):
        if (self.trans): #If there is a transition
            self.trans.Execute() #Execute transition
            self.SetState(self.trans.toState) #Transition to the new state
            self.trans = None #Reset transition variable
        self.CurrentState.Execute() #Execute the new state

###Use imported as parent class/character
