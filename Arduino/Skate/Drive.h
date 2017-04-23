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
//#define KI 200.0
//#define KI 100.0
//#define KI 50.0
//#define KI 20.0
#define KI 2.0
#include "Arduino.h"

// Communication commands
typedef enum {
  COMM_FW_VERSION = 0,
  COMM_JUMP_TO_BOOTLOADER,
  COMM_ERASE_NEW_APP,
  COMM_WRITE_NEW_APP_DATA,
  COMM_GET_VALUES,
  COMM_SET_DUTY,
  COMM_SET_CURRENT,
  COMM_SET_CURRENT_BRAKE,
  COMM_SET_RPM,
  COMM_SET_POS,
  COMM_SET_DETECT,
  COMM_SET_SERVO_POS,
  COMM_SET_MCCONF,
  COMM_GET_MCCONF,
  COMM_GET_MCCONF_DEFAULT,
  COMM_SET_APPCONF,
  COMM_GET_APPCONF,
  COMM_GET_APPCONF_DEFAULT,
  COMM_SAMPLE_PRINT,
  COMM_TERMINAL_CMD,
  COMM_PRINT,
  COMM_ROTOR_POSITION,
  COMM_EXPERIMENT_SAMPLE,
  COMM_DETECT_MOTOR_PARAM,
  COMM_DETECT_MOTOR_R_L,
  COMM_DETECT_MOTOR_FLUX_LINKAGE,
  COMM_DETECT_ENCODER,
  COMM_DETECT_HALL_FOC,
  COMM_REBOOT,
  COMM_ALIVE,
  COMM_GET_DECODED_PPM,
  COMM_GET_DECODED_ADC,
  COMM_GET_DECODED_CHUK,
  COMM_FORWARD_CAN,
  COMM_SET_CHUCK_DATA,
  COMM_CUSTOM_APP_DATA
} COMM_PACKET_ID;

class Drive {
  public:
    Drive(int,int,HardwareSerial*);
    void initializeDrive();
    void serviceEncoder(int);
    void updateState();
    void resetState();
    void setDutyCycle(float);
    void setCurrent(float);
    void resetTimeout();
    float getPosition();
    float getVelocity();
    float getVelocityEncoder();
    long updateTimeDelta;
    long lastUpdateTime;

  private:
    int encChaPin;
    int encChbPin;
    HardwareSerial* serial;
    uint8_t sendBuffer[30];
    int32_t sendIndex;
    void sendCommand();
    volatile long encCount;
    boolean A_set;
    boolean B_set;
    float wheelPositionEncoder;
    float wheelPositionEncoderPrev;
    float wheelPositionEstimate;
    float wheelVelocityEncoder;
    float wheelVelocityInteg; 
    float wheelVelocityEstimate;
    int commandLim;
};

#endif
