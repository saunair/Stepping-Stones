/*
  Force.h - Library for force sensor interfacing
*/
#ifndef Force_h
#define Force_h

#include "Arduino.h"

class Force {
  const int chOuter;
  const int chInner;
  const int chRear;
  public:
    Force(int outer,int inner,int rear):chOuter(outer),chInner(inner),chRear(rear) {currentChannel = chOuter;}
    bool startCycle();
    bool checkReady();
    bool serviceSensors(int);
    int getAdcOuter();
    int getAdcInner();
    int getAdcRear();

  private:
    int currentChannel;

    int adcOuter;
    int adcInner;
    int adcRear;

    long nextConversionTime;
};

#endif
