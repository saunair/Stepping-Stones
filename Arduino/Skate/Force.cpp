/*
  Force.cpp - Library for force sensor interfacing
*/

#include "Arduino.h"
#include "Force.h"


void Force::startCycle() {
  currentChannel = chOuter;
  ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
  ADCSRA |= bit (ADSC) | bit (ADIE); //Trigger conversion to be thrown out
  conversionCount = 0;
}

void Force::serviceSensors(int adcVal) {
  if(conversionCount == 0) {
    ADCSRA |= bit (ADSC) | bit (ADIE);  
    conversionCount = 1;
  }

  else {  
    if(currentChannel == chOuter){
        adcOuter = adcVal;
        currentChannel = chInner;
        ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
        ADCSRA |= bit (ADSC) | bit (ADIE);  
        conversionCount = 0;
    }
    
    else if(currentChannel == chInner) {
        adcInner = adcVal;
        currentChannel = chRear;
        ADMUX  =  bit (REFS0) | (currentChannel & 0x07);
        ADCSRA |= bit (ADSC) | bit (ADIE);  
        conversionCount = 0;
    }
  
    else if(currentChannel == chRear) {
        adcRear = adcVal;
    }
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
