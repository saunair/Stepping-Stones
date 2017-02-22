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
#define MAX_SAMPLES 10 //Need a better way to allocate this memory

#include "Arduino.h"
#include <Servo.h>

class Drive {
  public:
    Drive(int,int,int,int,int);
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
    int sampleWindow;
    int samplePeriodMs;
    volatile long encCount;
    boolean A_set;
    boolean B_set;
    float wheelPositionArray[MAX_SAMPLES];
    float wheelPositionAvg;
    float wheelPositionAvgPrev;
    float wheelVelocityArray[MAX_SAMPLES];
    float wheelVelocityAvg;
    int commandLim;
};

#endif
