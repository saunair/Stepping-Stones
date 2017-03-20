//Revision 3/20/2017
#define LEFT_SKATE_IND_PIN 52
#define RIGHT_SKATE_IND_PIN 53

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3

#define CTRL_PERIOD_MS 1500.0
#define SAMP_PERIOD_MS 2.0
#define DISP_PERIOD_MS 10.0

#include "Drive.h"

typedef enum {
  INIT = 0,
  RAMP_UP_POS,
  BRAKE_ON_1,
  RAMP_UP_NEG,
  BRAKE_ON_2
} STATES;

STATES currentState = INIT;

long currentTimeStamp = 0;
long lastAliveTimeStamp = 0;

long lastCtrlTimeStamp = 0;
long lastSampTimeStamp = 0;
long lastDispTimeStamp = 0;

bool leftSkate = false;
bool rightSkate = false;

float dutyCycle = 0;

void doEncoderFrontChA();
void doEncoderFrontChB();
void doEncoderRearChA();
void doEncoderRearChB();

Drive frontDrive(ENC1_CHA_PIN,ENC1_CHB_PIN,&Serial2); 
Drive rearDrive(ENC2_CHA_PIN,ENC2_CHB_PIN,&Serial3);


void setup() {
  //Determine Skate Side
  pinMode(LEFT_SKATE_IND_PIN, INPUT_PULLUP);
  pinMode(RIGHT_SKATE_IND_PIN, INPUT_PULLUP);
  if(digitalRead(LEFT_SKATE_IND_PIN) == digitalRead(RIGHT_SKATE_IND_PIN)) {
    while(1);
  }
  if(digitalRead(LEFT_SKATE_IND_PIN) == LOW) {
    leftSkate = true; 
    Serial.println("Left Skate");   
  }
  if(digitalRead(RIGHT_SKATE_IND_PIN) == LOW) {
    rightSkate = true;
    Serial.println("Right Skate");
  }
  
  //Set Up Front Skate
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoderFrontChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoderFrontChB, CHANGE);
  frontDrive.initializeDrive();

  //Set Up Rear Skate
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoderRearChA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoderRearChB, CHANGE);
  rearDrive.initializeDrive();

  Serial.begin(115200);
  Serial.println("Duty Cycle,Front Velocity,Rear Velocity");
}

void loop(){ 
  //Send an "alive" message every 500ms to reset the comm timeout

  //State machine:
  //Command increasing duty cycles, apply brake at top, repeat behavior for opposite direction
  //At each duty cycle command, wait 500ms for velocity to stabilize, then begin transmitting data
  //On UART0, transmit "Duty Cycle,TL Velocity" at 100Hz for 1 second
  
  currentTimeStamp = micros();

  //Alive Loop
  if((currentTimeStamp - lastAliveTimeStamp) >= (500 * 1000)) {
    lastAliveTimeStamp = currentTimeStamp;
    
    frontDrive.resetTimeout();
    rearDrive.resetTimeout();
  }

  //Sampling Loop
  if((currentTimeStamp - lastSampTimeStamp) >= (SAMP_PERIOD_MS*1000)) {
    lastSampTimeStamp = currentTimeStamp;

    frontDrive.updateState();
    rearDrive.updateState();
  }

  //Display Loop
  if((currentTimeStamp - lastDispTimeStamp) >= (DISP_PERIOD_MS*1000)) {
    lastDispTimeStamp = currentTimeStamp;

    if(((currentTimeStamp - lastDispTimeStamp) >= (500 * 1000)) && ((currentState == RAMP_UP_POS) || (currentState == RAMP_UP_NEG))) {
      Serial.print(dutyCycle);
      Serial.print(",");
      Serial.print(frontDrive.getVelocity());
      Serial.print(",");
      Serial.println(rearDrive.getVelocity());
    }
  }

  //Control Loop
  if((currentTimeStamp - lastCtrlTimeStamp) >= (CTRL_PERIOD_MS*1000)) {
    lastCtrlTimeStamp = currentTimeStamp;

    switch(currentState) {
      case INIT:
        currentState = RAMP_UP_POS;      
        break;

      case RAMP_UP_POS:
        if(dutyCycle < 0.2) {
          dutyCycle = dutyCycle + 0.01;
        }
        else {
          currentState = BRAKE_ON_1;  
        }
        break;

      case BRAKE_ON_1:
        dutyCycle = 0;
        currentState = RAMP_UP_NEG;
        break;

      case RAMP_UP_NEG:
        if(dutyCycle > -0.2) {
          dutyCycle = dutyCycle - 0.01;
        }
        else {
          currentState = BRAKE_ON_2;  
        }
        break;

      case BRAKE_ON_2:
        dutyCycle = 0;
        break;
    }

    frontDrive.setDutyCycle(dutyCycle);
    rearDrive.setDutyCycle(dutyCycle);
  }
}

void doEncoderFrontChA() {
  frontDrive.serviceEncoder(1);
}

void doEncoderFrontChB() {
  frontDrive.serviceEncoder(2);
}

void doEncoderRearChA() {
  rearDrive.serviceEncoder(1);
}

void doEncoderRearChB() {
  rearDrive.serviceEncoder(2);
}

