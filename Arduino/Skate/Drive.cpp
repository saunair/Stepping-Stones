/*
  Drive.cpp - Library for drive train interfacing
*/

#include "Arduino.h"
#include "Drive.h"


Drive::Drive(int ECA_pin,int ECB_pin,int ESC_pin) {
  encChaPin = ECA_pin;
  encChbPin = ECB_pin;
  escPin = ESC_pin;
  onTime = 1500;
  commandLim = 0;

  A_set = false;
  B_set = false;
  resetState();

  lastUpdateTime = micros();
  lastCommandTime = micros();
}

void Drive::initializeDrive() {
  pinMode(encChaPin, INPUT); 
  pinMode(encChbPin, INPUT);
  pinMode(escPin, OUTPUT);

  esc.attach(escPin,1000,2000);
  setCommand(0);  
}


void Drive::serviceEncoder(int chId) {
  switch(chId) {
    case 1:
      A_set = digitalRead(encChaPin) == HIGH;     
      encCount += (A_set != B_set) ? +1 : -1; //increment counter if A leads B
      break;
    case 2:
      B_set = digitalRead(encChbPin) == HIGH;
      encCount += (A_set == B_set) ? +1 : -1;  //increment counter if B follows A
      break;
  }
}


void Drive::updateState(){
  updateTimeDelta = micros() - lastUpdateTime;
  lastUpdateTime = micros();

  float dt, wheelPositionEncoder, wheelPositionError;
  dt = (float)updateTimeDelta/(1000000);
  wheelPositionEncoder = (float(encCount) / PPR) * ONE_REV_DIST_MM;
  
  wheelPositionEstimate = wheelPositionEstimate + wheelVelocityEstimate*dt;
  wheelPositionError = wheelPositionEncoder - wheelPositionEstimate;
  wheelVelocityInteg = wheelVelocityInteg + wheelPositionError*KI*dt;
  wheelVelocityEstimate = wheelPositionError*KP + wheelVelocityInteg;
}


void Drive::resetState() {
  encCount = 0;
  wheelPositionEstimate = 0;
  wheelVelocityInteg = 0;
  wheelVelocityEstimate = 0; 
}


float Drive::getPosition() {
  return wheelPositionEstimate;
}


float Drive::getVelocity() {
  return wheelVelocityEstimate;
}

    
void Drive::setCommand(float command) {
  commandTimeDelta = micros() - lastCommandTime;
  lastCommandTime = micros();
  
  commandLim = constrain(command,-100,100);
  onTime = 1500;
  
  if(commandLim > 0) {
    onTime = (int)map(commandLim, 0, 100, 1520, (2000-1520)*(SPEED_LIM_MAX/100)+1520);
  }
  else {
    if(commandLim < 0) {
      onTime = (int)map(commandLim, -100, 0, (1480-1000)*(SPEED_LIM_MIN/100)+1480, 1480);
    }
  }

  esc.writeMicroseconds(onTime);
}
