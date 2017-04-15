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

#Declare each State class:
class State(object): #State base class
    def __init__(self, ControlsStateMachine):
        self.ControlsStateMachine = ControlsStateMachine
        
    def Enter(self):
        pass
    def Execute(self):
        pass
    def Exit(self):
        pass

class SingleStanceInPlaceLeft(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInPlace,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInPlaceLeft'
        self.ID = 0

    def Enter(self):
        #print 'Entering single stance in place...'
        super(SingleStanceInPlace, self).Enter()

    def Execute(self):
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

    def Execute(self):
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

    def Execute(self):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = model.predict
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

    def Execute(self):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = model.predict

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

    def Execute(self):
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

    def Execute(self):
        #print "Double stance in motion"
        #Do Controls Stuff
        velocity_l = model.predict
        velocity_r = model.predict

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

    def Execute(self):
        #print "Double stance in motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = -1

    def Exit(self):
        #print 'Leaving double stance in motion'

class SingleStanceInMotionLeftBackward(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInMotion,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInMotionLeftBackward'
        self.ID = 7

    def Enter(self):
        #print 'Entering single stance in motion...'
        super(SingleStanceInMotion, self).Enter()

    def Execute(self):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = -1

    def Exit(self):
        #print 'Leaving single stance in motion'

class SingleStanceInMotionRightBackward(State):
    def __init__(self,ControlsStateMachine):
        #super().__init__(ControlsStateMachine) in python 3
        super(SingleStanceInMotion,self).__init__(ControlsStateMachine)
        self.name = 'SingleStanceInMotionRightBackward'
        self.ID = 8

    def Enter(self):
        #print 'Entering single stance in motion...'
        super(SingleStanceInMotion, self).Enter()

    def Execute(self):
        #print "Single stance in Motion"
        #Do Controls Stuff
        velocity_l = -1
        velocity_r = -1

    def Exit(self):
        #print 'Leaving single stance in motion'

###Transitions
class Transition(object):
    def __init__(self, toState):
        self.toState = toState
    def Execute(self):
        #print "Transitioning"


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
    def AddTransition(self, TransitionName, newtransition):
        self.transitions[TransitionName] = newtransition

    #Add new states if needed
    def AddState(self, StateName, newstate):
        self.states[StateName] = newstate

    #State setting function
    def SetState(self, StateID):
        self.PreviousState = self.CurrentState
        self.CurrentState = self.states[StateID] #Look for the passed state in the states dictionary
    
    #Sets the Transition state
    def SetTransition(self, SetTransitionID):
        self.trans = self.transitions[SetTransitionID] 
        #print self.trans

    def Execute(self):
        if (self.trans): #If there is a transition
            self.CurrentState.Exit() #Exit the current state
            self.trans.Execute() #Execute transition
            self.SetState(self.trans.toState) #Transition to the new state
            self.CurrentState.Enter() #Enter the new state
            self.trans = None #Reset transition variable
        self.CurrentState.Execute() #Execute the new state

###Use imported as parent class/character in place of class below
class ControlSkate(object):
    def __init__(self):
        self.ControlsStateMachine = ControlsStateMachine(self)

        ### Add all states to the dictionary for states:
        self.ControlsStateMachine.AddState(SSPL,   SingleStanceInPlaceLeft(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(SSPR,   SingleStanceInPlaceRight(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(SSML,   SingleStanceInMotionLeft(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(SSMR,   SingleStanceInMotionRight(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(DSP,    DoubleStanceInPlace(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(DSM,    DoubleStanceInMotion(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(DSM_B,  DoubleStanceInMotionBackward(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(SSML_B, SingleStanceInMotionLeftBackward(self.ControlsStateMachine))
        self.ControlsStateMachine.AddState(SSMR_B, SingleStanceInMotionRightBackward(self.ControlsStateMachine))

        ###Add all transitions to the dictionary for transitions:
        self.ControlsStateMachine.AddTransition("SingleStanceInPlaceLeft", Transition("SingleStanceInPlaceLeft"))
        self.ControlsStateMachine.AddTransition("SingleStanceInPlaceRight", Transition("SingleStanceInPlaceRight"))
        self.ControlsStateMachine.AddTransition("SingleStanceInMotionLeft", Transition("SingleStanceInMotionLeft"))
        self.ControlsStateMachine.AddTransition("SingleStanceInMotionRight", Transition("SingleStanceInMotionRight"))
        self.ControlsStateMachine.AddTransition("DoubleStanceInMotion", Transition("DoubleStanceInMotion"))
        self.ControlsStateMachine.AddTransition("DoubleStanceInPlace", Transition("DoubleStanceInPlace"))
	self.ControlsStateMachine.AddTransition("SingleStanceInMotionLeftBackward", Transition("SingleStanceInMotionLeftBackward"))
        self.ControlsStateMachine.AddTransition("SingleStanceInMotionRightBackward", Transition("SingleStanceInMotionRightBackward"))
        self.ControlsStateMachine.AddTransition("DoubleStanceInMotionBackward", Transition("DoubleStanceInMotionBackward"))

        ###Default State: Double Stance in Place
        self.ControlsStateMachine.SetState("DoubleStanceInPlace") #Always start in double stance in place

    def Execute(self):
        self.ControlsStateMachine.Execute()


###Test:
'''
if __name__=='__main__':
	statemachine = ControlSkate()
	while 1:
		State = input('Enter the state:')
		#1: DoubleStanceInPlace
		#2: SingleStanceInPlace
		#3: SingleStanceInMotion
		#4: DoubleStanceInMotion
		if not(State == statemachine.ControlsStateMachine.CurrentState.name):
			statemachine.ControlsStateMachine.SetTransition(State)
		statemachine.Execute()'''
