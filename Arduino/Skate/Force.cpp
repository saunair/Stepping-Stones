/*
  Force.cpp - Library for force sensor interfacing
*/

#include "Arduino.h"
#include "Force.h"


Force::Force(int outer, int inner, int rear) {
  chOuter = outer;
  chInner = inner;
  chRear = rear;
  currentChannel = 0;
}

bool Force::startCycle() {
  currentChannel = 0;
  nextConversionTime = micros() + 100;
  return true;
}

bool Force::checkReady() {
  if(micros() >= nextConversionTime) {
    ADCSRA |= bit (ADSC) | bit (ADIE);
    return false;  
  }
  return true;
}

bool Force::serviceSensors(int adcVal) {
  switch(currentChannel) {
    case 0:
      adcOuter = adcVal;
      currentChannel = 1;
      ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
      nextConversionTime = micros() + 100;
      return true;
    case 1:
      adcInner = adcVal;
      currentChannel = 2;
      ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
      nextConversionTime = micros() + 100;
      return true;
    case 2:
      adcRear = adcVal;
      return false;
    default:
      return false;
  }
}

int Force::getAdcOuter() {
  return adcOuter;
}


int Force::getAdcInner() {
  return adcInner;
}


int Force::getAdcRear() {
  return adcRear;
}
