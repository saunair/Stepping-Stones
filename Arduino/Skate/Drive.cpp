/*
  Drive.cpp - Library for drive train interfacing
*/

#include "Arduino.h"
#include "Drive.h"
#include "buffer.h"
#include "crc.h"


Drive::Drive(int ECA_pin,int ECB_pin,HardwareSerial* port) {
  encChaPin = ECA_pin;
  encChbPin = ECB_pin;
  serial = port;
  
  commandLim = 0;

  A_set = false;
  B_set = false;
  resetState();

  lastUpdateTime = micros();
}

void Drive::initializeDrive() {
  pinMode(encChaPin, INPUT); 
  pinMode(encChbPin, INPUT);
  serial->begin(115200);
  setDutyCycle(0);  
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

  float dt, wheelPositionError;
  dt = (float)updateTimeDelta/(1000000);
  wheelPositionEncoderPrev = wheelPositionEncoder;
  wheelPositionEncoder = (float(encCount) / PPR) * ONE_REV_DIST_MM;
  wheelVelocityEncoder = (wheelPositionEncoder - wheelPositionEncoderPrev)/dt;
  
  wheelPositionEstimate = wheelPositionEstimate + wheelVelocityEstimate*dt;
  wheelPositionError = wheelPositionEncoder - wheelPositionEstimate;
  wheelVelocityInteg = wheelVelocityInteg + wheelPositionError*KI*dt;
  wheelVelocityEstimate = wheelPositionError*KP + wheelVelocityInteg;
}


void Drive::resetState() {
  encCount = 0;
  wheelPositionEncoder = 0;
  wheelPositionEncoderPrev = 0;
  wheelPositionEstimate = 0;
  wheelVelocityEncoder = 0;
  wheelVelocityInteg = 0;
  wheelVelocityEstimate = 0; 
}


float Drive::getPosition() {
  return wheelPositionEstimate;
}


float Drive::getVelocity() {
  return wheelVelocityEstimate;
}

float Drive::getVelocityEncoder() {
  return wheelVelocityEncoder;
}


void Drive::setDutyCycle(float dutyCycle) {
  unsigned short crc;
  sendIndex = 0;
  
  sendBuffer[sendIndex++] = COMM_SET_DUTY;
  buffer_append_float32(sendBuffer, dutyCycle, 100000.0, &sendIndex);
  crc = crc16(sendBuffer,sendIndex);
  buffer_append_uint16(sendBuffer, crc, &sendIndex);

  sendCommand();
}


void Drive::setCurrent(float current) {
  unsigned short crc;
  sendIndex = 0;

  sendBuffer[sendIndex++] = COMM_SET_CURRENT;
  buffer_append_float32(sendBuffer, current, 1000.0, &sendIndex);  
  crc = crc16(sendBuffer,sendIndex);
  buffer_append_uint16(sendBuffer, crc, &sendIndex);

  sendCommand();
}


void Drive::resetTimeout() {
  unsigned short crc;
  sendIndex = 0;

  sendBuffer[sendIndex++] = COMM_ALIVE;
  crc = crc16(sendBuffer,sendIndex);
  buffer_append_uint16(sendBuffer, crc, &sendIndex);

  sendCommand();
}


void Drive::sendCommand() {
  serial->write(2);
  serial->write(sendIndex-2);
  serial->write(sendBuffer,sendIndex);
  serial->write(3);
}
