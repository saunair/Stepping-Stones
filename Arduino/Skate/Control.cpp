/*
  Control.cpp - Library for position & velocity control
*/

#include "Arduino.h"
#include "Control.h"

Control::Control(float *posnGains,float *velGains,int controlPeriod) {
  posn_Kp = posnGains[0];
  posn_Ki = posnGains[1];
  posn_Kd = posnGains[2];
  vel_Kp = velGains[0];
  vel_Ki = velGains[1];
  vel_Kd = velGains[2];
  controlPeriodMs = controlPeriod;
  modeTransitionFlag = false;
  lastControlTime = millis();

  resetIntegrators();
}


void Control::setInvertFlag(bool invert) {
  invertFlag = invert;
}


float Control::computeCommand(float target,float wheelPosition,float wheelVelocity) {
  controlTimeDelta = millis() - lastControlTime;
  lastControlTime = millis();
  
  //If the target velocity is 0 and the rate limited target velocity is low enough, switch to position control
  if((target == 0) && (abs(velocityTargetLim) < 5) && (controlMode == Velocity_Mode)) {
    controlMode = Position_Mode;
    resetIntegrators();
    modeTransitionFlag = true;
  }

  //If the target velocity is not 0, switch to velocity control
  if((target != 0) && (controlMode == Position_Mode)) {
    controlMode = Velocity_Mode;
    resetIntegrators();
    modeTransitionFlag = true; 
  }

  if(controlMode == Position_Mode) {
    return computePositionCommand(target,wheelPosition);
  }

  if(controlMode == Velocity_Mode) {
    return computeVelocityCommand(target,wheelVelocity);
  }
}


float Control::computePositionCommand(float target,float wheelPosition) {
  positionTarget = target;
  positionErrorPrev = positionError;
  positionError = positionTarget - wheelPosition;

  /*if(invertFlag == false) {
    positionError = constrain(positionError,0,abs(positionError));
  }
  else {  
    positionError = constrain(positionError,-1*abs(positionError),0);  
  }
      
  positionErrorSum = positionErrorSum + positionError;
  positionErrorDiff = positionError - positionErrorPrev;
     
  return posn_Kp*positionError + posn_Ki*positionErrorSum + posn_Kd*positionErrorDiff;*/
  return 0; //Just apply brake
}


float Control::computeVelocityCommand(float target,float wheelVelocity) {
  //Apply acceleration  limit
  velocityTarget = target;      
  velocityTargetLimPrev = velocityTargetLim;
  velocityTargetLim = constrain(velocityTarget,velocityTargetLimPrev-ACCEL_LIMIT*(controlPeriodMs/1000.0),velocityTargetLimPrev+ACCEL_LIMIT*(controlPeriodMs/1000.0));

  velocityErrorPrev = velocityError;   
  velocityError = velocityTargetLim - wheelVelocity;
  velocityErrorSum = velocityErrorSum + velocityError;
  velocityErrorDiff = velocityError - velocityErrorPrev;
      
  return ((vel_Kp*velocityError + vel_Ki*velocityErrorSum + vel_Kd*velocityErrorDiff) + (0.00036*velocityTargetLim + 0.0065));
}


void Control::resetIntegrators() {
  positionErrorSum = 0;
  velocityErrorSum = 0;
}

    
int Control::checkErrors() {
  int skate_fault = 0;
  if (positionError > POSN_ERROR_THRESHOLD) skate_fault |= 1<<0;   
  if (velocityErrorSum > VEL_ERROR_THRESHOLD) skate_fault |= 1<<1;

  return skate_fault;  
}

int Control::getMode() {
  return (int)controlMode + 1;
}

bool Control::checkModeTransition() {
  bool flagState;
  flagState = modeTransitionFlag;
  modeTransitionFlag = false;
  return flagState;  
}


float Control::getControllerTarget() {
  if(controlMode == Position_Mode){
    //return positionTarget;
    return 0;
  }
  else {
    return velocityTargetLim;
  }
}

