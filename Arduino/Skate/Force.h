/*
  Force.h - Library for force sensor interfacing
*/
#ifndef Force_h
#define Force_h

#include "Arduino.h"

class Force {
  public:
    Force(int,int,int);
    bool startCycle();
    bool checkReady();
    bool serviceSensors(int);
    int getAdcOuter();
    int getAdcInner();
    int getAdcRear();

  private:
    int chOuter;
    int chInner;
    int chRear;

    int currentChannel;

    int adcOuter;
    int adcInner;
    int adcRear;

    long nextConversionTime;
};

#endif
