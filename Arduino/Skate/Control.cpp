/*
  Control.cpp - Library for position & velocity control
*/

#include "Arduino.h"
#include "Control.h"

Control::Control(float[3] posnGains,float[3] velGains,bool invert) {
  posn_Kp = posnGains[0];
  posn_Ki = posnGains[1];
  posn_Kd = posnGains[2];
  vel_Kp = velGains[0];
  vel_Ki = velGains[1];
  vel_Kd = velGains[2];
  invertFlag = invert;

  resetIntegrators();
}


float Control::computeCommand(float target,float wheelPosition,float wheelVelocity) {
  //If the target velocity is 0 and the rate limited target velocity is low enough, switch to position control
  if((target == 0) && (abs(velocityTargetLim) < 5) && (controlMode == Velocity_Mode)) {
    controlMode = Position_Mode;
    resetIntegrators();
  }

  //If the target velocity is not 0, switch to velocity control
  if((target != 0) && (controlMode == Position_Mode)) {
    controlMode = Velocity_Mode;
    resetIntegrators();
  }

  if(controlMode == Position_Mode) {
    return computePositionCommand(target,wheelPosition)
  }

  if(controlMode == Velocity_Mode) {
    return computeVelocityCommand(target,wheelVelocity)
  }
}


float Control::computePositionCommand(float target,float wheelPosition) {
  positionErrorPrev = positionError;
  positionError = target - wheelPosition;

  if(invertFlag == False) {
    positionError = constrain(positionError,0,abs(positionError));
  else {  
    positionError = constrain(positionError,-1*abs(positionError),0);  
  }
      
  positionErrorSum = positionErrorSum + positionError;
  positionErrorDiff = positionError - positionErrorPrev;
     
  return constrain(posn_Kp*positionError + posn_Ki*positionErrorSum + posn_Kd*positionErrorDiff,SPEED_LIM_MIN,SPEED_LIM_MAX);
}


float Control::computeVelocityCommand(float target,float wheelVelocity) {
  //Apply acceleration  limit
  velocityTarget = target;
      
  velocityTargetLimPrev = velocityTargetLim;
  velocityTargetLim = constrain(velocityTarget,velocityTargetLimPrev-ACCEL_LIMIT*(CTRL_PERIOD_MS/1000.0),
  velocityTargetLimPrev+ACCEL_LIMIT*(CTRL_PERIOD_MS/1000.0));

  velocityErrorPrev = velocityError;   
  velocityError = velocityTargetLim - wheelVelocity;
  velocityErrorSum = velocityErrorSum + velocityError;
  velocityErrorDiff = velocityError - velocityErrorPrev;
      
  return constrain(vel_Kp*velocityError + vel_Ki*velocityErrorSum + vel_Kd*velocityErrorDiff,SPEED_LIM_MIN,SPEED_LIM_MAX);
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
