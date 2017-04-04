/*
  Control.h - Library for position & velocity control
*/

#ifndef Control_h
#define Control_h

#define ACCEL_LIMIT 2000.0

#define POSN_ERROR_THRESHOLD 70
#define VEL_ERROR_THRESHOLD 10000

#include "Arduino.h"

enum Mode
{
  Position_Mode,
  Velocity_Mode
};

class Control {
  public:
    Control(float *,float *,int);
    void setInvertFlag(bool);
    float computeCommand(float,float,float);
    float computePositionCommand(float,float);
    float computeVelocityCommand(float,float);
    void resetIntegrators();
    int checkErrors();
    int getMode();
    bool checkModeTransition();
    float getControllerTarget();
    long lastControlTime;
    long controlTimeDelta;
  private:
    bool invertFlag;
    Mode controlMode;
    int controlPeriodMs;
    
    float posn_Kp;
    float posn_Ki;
    float posn_Kd;
    float vel_Kp;
    float vel_Ki;
    float vel_Kd;

    float positionTarget;
    float positionError;
    float positionErrorSum;
    float positionErrorDiff;
    float positionErrorPrev;

    float velocityTarget;
    float velocityTargetLim;
    float velocityTargetLimPrev;
    float velocityError;
    float velocityErrorSum;
    float velocityErrorDiff;
    float velocityErrorPrev;

    float motorCommand;

    bool modeTransitionFlag;
    int skate_fault;
};

#endif
