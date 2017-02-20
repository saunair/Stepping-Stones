/*
  Drive.cpp - Library for drive train interfacing
*/

#include "Arduino.h"
#include "Drive.h"


Drive::Drive(int ECA_pin,int ECB_pin,int ESC_pin,int sampleNum,int samplePeriod) {
  encChaPin = ECA_pin;
  encChbPin = ECB_pin;
  escPin = ESC_pin;
  sampleWindow = sampleNum;
  samplePeriodMs = samplePeriod;

  A_set = false;
  B_set = false;
  resetState();

  pinMode(encChaPin, INPUT); 
  pinMode(encChbPin, INPUT);
  pinMode(escPin, OUTPUT);

  Servo esc;
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
  //Update position sample buffer for moving average
  for(int sample = (sampleWindow-1); sample > 0; sample--) {
    wheelPositionArray[sample] = wheelPositionArray[sample-1];
  }    
  wheelPositionArray[0] = (float(encCount) / PPR) * ONE_REV_DIST_MM;

  //Update position moving average
  wheelPositionAvgPrev = wheelPositionAvg;
    
  wheelPositionAvg = 0;
  for(int sample = 0; sample < sampleWindow; sample++) {
    wheelPositionAvg = wheelPositionAvg + (wheelPositionArray[sample] / float(sampleWindow));
  }

  //Update velocity sample buffer for moving average
  for(int sample = (sampleWindow-1); sample > 0; sample--) {
    wheelVelocityArray[sample] = wheelVelocityArray[sample-1];
  }  
  wheelVelocityArray[0] = (wheelPositionAvg - wheelPositionAvgPrev)/(samplePeriodMs/1000.0);

  //Update velocity moving average  
  wheelVelocityAvg = 0;
  for(int sample = 0; sample < sampleWindow; sample++) {
    wheelVelocityAvg = wheelVelocityAvg + (wheelVelocityArray[sample] / float(sampleWindow));
  }  
}


void Drive::resetState() {
  encCount = 0;
  wheelPositionAvg = 0;
  wheelPositionAvgPrev = 0;
  wheelVelocityAvg = 0;  
  for(int i = 0;i<MAX_SAMPLES;i++) {
    wheelPositionArray[i] = 0;
    wheelVelocityArray[i] = 0;
  }
}


float Drive::getPosition() {
  return wheelPositionAvg;
}


float Drive::getVelocity() {
  return wheelVelocityAvg;
}

    
void Drive::setCommand(float command) {
  int commandLim = constrain((int)command,SPEED_LIM_MIN,SPEED_LIM_MAX);
  int onTime = 1500;
  
  if(commandLim > 0) {
    onTime = constrain(map(commandLim, 1, 100, 1520, 2000), 1520, 2000);
  }
  else {
    if(commandLim < 0) {
      onTime = constrain(map(commandLim, -100, -1, 1000, 1480), 1000, 1480);
    }
  }

  esc.writeMicroseconds(onTime);
}
