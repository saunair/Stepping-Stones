#Import SVM Output
try:
    from stepping_stones import MorpheusSkate #import morpheus skate parent class
    from stepping_stones import SVM_Out_State #SVM Output
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
    def __init__(self, fromState, toState):
        self.toState = toState
        self.fromState = fromState
    def Execute(self):
        print "Transitioning"


###State Machine

class ControlsStateMachine:
    def __init__(self, char):
        self.char = char
        self.states = {} #Dictionary for states
        self.transitions = {} #Dictionary for transitions
        self.CurrentState = None #Current State
        self.PreviousState = None #Previous State, duh.
        self.trans = None #Current transition

    #Add new transitions if needed
    def AddTransition(self, TransitionName, newtransition)
        self.transitions[TransitionName] = newtransition

    #Add new states if needed
    def AddState(self, StateName, newstate)
        self.states[StateName] = newstate

    #State setting function
    def SetState(self, StateName)
        self.PreviousState = self.CurrentState
        self.CurrentState = self.states[StateName] #Look for the passed state in the states dictionary
    
    #Transition function
    def ToTransition(self, ToTransitionName)
        self.trans = self.transitions[ToTransitionName] #Repeat for transition

    def Execute(self):
        if (self.trans): #If there is a transition
            self.CurrentState.Exit() #Exit the current state
            self.Transition.Execute() #Execute transition
            self.SetState(self.Transition.toState) #Transition to the new state
            self.CurrentState.Enter() #Enter the new state
            self.trans = None #Reset transition variable
        self.CurrentState.Execute() #Execute the new state

###Use imported as parent class/character in place of class below
char  = type("char", (object,){})
class ControlSkate(char):
    def __init__(self):
        self.ControlsStateMachine = ControlsStateMachine(self)

        ### Add all states:
        self.ControlsStateMachine.AddState("SingleStanceInPlace", SingleStanceInPlace(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState("SingleStanceInMotion", SingleStanceInMotion(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState("DoubleStanceInPlace", DoubleStanceInPlace(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState("DoubleStanceInMotion", DoubleStanceInMotion(self.ControlsStateMachine))

        ###Add all transitions:
        self.ControlsStateMachine.AddTransition("FromDoubleStanceInPlaceToSingleStanceInPlace", Transition("SingleStanceInPlace"))
        self.ControlsStateMachine.AddTransition("FromSingleStanceInPlaceToSingleStanceInMotion", Transition("SingleStanceInMotion"))
        self.ControlsStateMachine.AddTransition("FromSingleStanceInMotionToDoubleStanceInMotion", Transition("DoubleStanceInMotion"))
        self.ControlsStateMachine.AddTransition("FromDoubleStanceInMotionToDoubleStanceInPlace", Transition("DoubleStanceInPlace"))
        self.ControlsStateMachine.AddTransition("FromDoubleStanceInMotionToSingleStanceInPlace", Transition("SingleStanceInPlace"))
        self.ControlsStateMachine.AddTransition("FromDoubleStanceInMotionToSingleStanceInMotion", Transition("SingleStanceInMotion"))       

        '''self.ControlsStateMachine.AddTransition("FromDoubleStanceInPlaceToSingleStanceInMotion", Transition(""))
        self.ControlsStateMachine.AddTransition("FromDoubleStanceInPlaceToSingleStanceInPlace", Transition(""))'''

        ###Default State: Double Stance in Place
        self.ControlsStateMachine.SetState("DoubleStanceInPlace") #Always start in double stance in place

        def Execute(self):
            self.ControlsStateMachine.Execute()
