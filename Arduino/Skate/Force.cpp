/*
  Force.cpp - Library for force sensor interfacing
*/

#include "Arduino.h"
#include "Force.h"


bool Force::startCycle() {
  currentChannel = chOuter;
  ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
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
  if(currentChannel == chOuter){
      adcOuter = adcVal;
      currentChannel = chInner;
      ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
      nextConversionTime = micros() + 200;
      return true;
  }
  
  if(currentChannel == chInner) {
      adcInner = adcVal;
      currentChannel = chRear;
      ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
      nextConversionTime = micros() + 200;
      return true;
  }

  if(currentChannel == chRear) {
      adcRear = adcVal;
      return false;
  }

  return false;
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
