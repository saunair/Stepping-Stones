/*
  Drive.h - Library for drive train interfacing
*/
#ifndef Drive_h
#define Drive_h

#define ONE_REV_DIST_MM (3.14*2.875*25.4)
#define CPR 360
#define PPR (CPR*4)
#define SPEED_LIM_MIN -30.0
#define SPEED_LIM_MAX 30.0
#define KP 10.0
#define KI 200.0

#include "Arduino.h"
#include <Servo.h>

class Drive {
  public:
    Drive(int,int,int);
    void initializeDrive();
    void serviceEncoder(int);
    void updateState();
    void resetState();
    float getPosition();
    float getVelocity();
    void setCommand(float);
    int onTime;
    Servo esc;
    long updateTimeDelta;
    long lastUpdateTime;
    long commandTimeDelta;
    long lastCommandTime;

  private:
    int encChaPin;
    int encChbPin;
    int escPin;
    volatile long encCount;
    boolean A_set;
    boolean B_set;
    float wheelPositionEstimate;
    float wheelVelocityInteg; 
    float wheelVelocityEstimate;
    int commandLim;
};

#endif
