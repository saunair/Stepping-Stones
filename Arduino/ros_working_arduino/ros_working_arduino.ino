//Revision 12/7/2016 - 11:05pm
#define LEFT_SKATE 1
#define RIGHT_SKATE 0

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define ONE_REV_DIST_MM (3.14*2.875*25.4)
#define CPR 360
#define PPR (CPR*4)

#define P_P_GAIN1 2
#define P_I_GAIN1 0
#define P_D_GAIN1 0

#define P_P_GAIN2 1
#define P_I_GAIN2 0
#define P_D_GAIN2 0

#define V_P_GAIN1 0.00
#define V_I_GAIN1 0.005
#define V_D_GAIN1 0.0

#define V_P_GAIN2 0
#define V_I_GAIN2 0.005
#define V_D_GAIN2 0

#define ACCEL_LIMIT 10.0

#define CTRL_PERIOD_MS 4.0
#define SAMP_PERIOD_MS 1.0

#define SAMPLE_NUM (int)(2*(CTRL_PERIOD_MS/SAMP_PERIOD_MS))

#define SPEED_LIM_MIN -30.0
#define SPEED_LIM_MAX 30.0
bool init_motors = 0;

enum States
{
  Position_Mode,
  Velocity_Mode
};

States system_state = Position_Mode;

#include <Servo.h>

volatile long encCount1 = 0;
volatile long encCount2 = 0;

boolean A1_set = false;
boolean B1_set = false;

boolean A2_set = false;
boolean B2_set = false;

float target = 0;

float wheelPositionArray[3][SAMPLE_NUM] = {{0}}; //Extra 1st index for 1-indexing
float wheelPositionAvg[3] = {0};
float wheelPositionAvgPrev[3] = {0};

float positionTarget = 0;

float positionError[3] = {0};
float positionErrorSum[3] = {0};
float positionErrorDiff[3] = {0};
float positionErrorPrev[3] = {0};

//float skateVelocity = 0;
//float wheelVelocity[3] = {0};
float wheelVelocityArray[3][SAMPLE_NUM] = {{0}};
float wheelVelocityAvg[3] = {0};

float velocityTarget = 0;
float velocityTargetLim = 0;
float velocityTargetLimPrev = 0;

float velocityError[3] = {0};
float velocityErrorSum[3] = {0};
float velocityErrorDiff[3] = {0};
float velocityErrorPrev[3] = {0};

float speedCommand[3] = {0};

long currentTimeStamp = 0;
long lastCtrlTimeStamp = 0;
long lastSampTimeStamp = 0;

Servo esc1; //Front
Servo esc2; //Back


//ROS Definitions
#define SERIAL_BUFFER_SIZE 256

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <ros/time.h>
//#include <motor/Num.h>
#include <motor/states.h>

int global_state;
int global_set_point;

std_msgs::Float64 myData;
ros::Publisher chatter("c", &myData);

void servo_cb( const motor::states& cmd_msg){
  global_state = cmd_msg.state;
  global_set_point = cmd_msg.set_point;
  init_motors = 1;
   chatter.publish( &myData );
}

ros::Subscriber<motor::states> sub("servo", servo_cb);
ros::NodeHandle  nh;


void setup() {
  //ROS Setup
  nh.initNode();   
  nh.getHardware()->setBaud(115200);
  nh.advertise(chatter);
  nh.subscribe(sub);

  while(!init_motors)
  {
      nh.spinOnce();
  }

  //Set Up Front Skate
  pinMode(ENC1_CHA_PIN, INPUT); 
  pinMode(ENC1_CHB_PIN, INPUT);
  pinMode(ESC1_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHA_PIN), doEncoder1A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC1_CHB_PIN), doEncoder1B, CHANGE);

  //Set Up Back Skate
  pinMode(ENC2_CHA_PIN, INPUT); 
  pinMode(ENC2_CHB_PIN, INPUT);
  pinMode(ESC2_PIN, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(ENC2_CHA_PIN), doEncoder2A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_CHB_PIN), doEncoder2B, CHANGE);
 
  //Enable Speed Controllers
  esc1.attach(ESC1_PIN,1000,2000);
  setSpeed(1,0.0); 
  esc2.attach(ESC2_PIN,1000,2000);
  setSpeed(2,0.0);

  //pinMode(50, OUTPUT);

  //Serial.begin(115200);
  //Serial.setTimeout(CTRL_PERIOD_MS);
  if(LEFT_SKATE == RIGHT_SKATE) {
    //Serial.println("Skate configuration error!");
    while(1);
  }
  else {
    //Serial.println("Standby...prepping alcubierre drive");
    //delay(8000);
    //Serial.println("Ready to roll!");
  }
}

void loop(){ 
  currentTimeStamp = millis();

  //Sampling Loop
  if((currentTimeStamp - lastSampTimeStamp) >= SAMP_PERIOD_MS) {
    lastSampTimeStamp = currentTimeStamp;

    //Update position sample buffer for moving average
    for(int sample = (SAMPLE_NUM-1); sample > 0; sample--) {
      wheelPositionArray[1][sample] = wheelPositionArray[1][sample-1];
      wheelPositionArray[2][sample] = wheelPositionArray[2][sample-1];
    }    
    wheelPositionArray[1][0] = (float(encCount1) / PPR) * ONE_REV_DIST_MM;
    wheelPositionArray[2][0] = (float(encCount2) / PPR) * ONE_REV_DIST_MM;

    //Update position moving average
    wheelPositionAvgPrev[1] = wheelPositionAvg[1];
    wheelPositionAvgPrev[2] = wheelPositionAvg[2];
    
    wheelPositionAvg[1] = 0;
    wheelPositionAvg[2] = 0;
    for(int sample = 0; sample < SAMPLE_NUM; sample++) {
      wheelPositionAvg[1] = wheelPositionAvg[1] + (wheelPositionArray[1][sample] / float(SAMPLE_NUM));
      wheelPositionAvg[2] = wheelPositionAvg[2] + (wheelPositionArray[2][sample] / float(SAMPLE_NUM));
    }

    //Update velocity sample buffer for moving average
    for(int sample = (SAMPLE_NUM-1); sample > 0; sample--) {
      wheelVelocityArray[1][sample] = wheelVelocityArray[1][sample-1];
      wheelVelocityArray[2][sample] = wheelVelocityArray[2][sample-1];
    }  
    wheelVelocityArray[1][0] = (wheelPositionAvg[1] - wheelPositionAvgPrev[1])/(CTRL_PERIOD_MS/1000.0);
    wheelVelocityArray[2][0] = (wheelPositionAvg[2] - wheelPositionAvgPrev[2])/(CTRL_PERIOD_MS/1000.0);

    //Update velocity moving average  
    wheelVelocityAvg[1] = 0;
    wheelVelocityAvg[2] = 0;
    for(int sample = 0; sample < SAMPLE_NUM; sample++) {
      wheelVelocityAvg[1] = wheelVelocityAvg[1] + (wheelVelocityArray[1][sample] / float(SAMPLE_NUM));
      wheelVelocityAvg[2] = wheelVelocityAvg[2] + (wheelVelocityArray[2][sample] / float(SAMPLE_NUM));
    }

    /*if(LEFT_SKATE == 1) {
      wheelVelocityAvg[1] = -1*wheelVelocityAvg[1];
      wheelVelocityAvg[2] = -1*wheelVelocityAvg[2];
    }*/
  }
  
  if((currentTimeStamp - lastCtrlTimeStamp) >= CTRL_PERIOD_MS) {
    //digitalWrite(50,!digitalRead(50));
    lastCtrlTimeStamp = currentTimeStamp;

    target = global_set_point;

    //If the target velocity is 0 and the rate limited target velocity is low enough, switch to position control
    if((target == 0) && (abs(velocityTargetLim) < 5) && (system_state == Velocity_Mode)) {
      system_state = Position_Mode;
      encCount1 = 0;
      encCount2 = 0;
      positionErrorSum[1] = 0;
      positionErrorSum[2] = 0;
      velocityErrorSum[1] = 0;
      velocityErrorSum[2] = 0;
    }

    //If the target velocity is not 0, switch to velocity control
    if((target != 0) && (system_state == Position_Mode)) {
      system_state = Velocity_Mode;
      encCount1 = 0;
      encCount2 = 0;
      positionErrorSum[1] = 0;
      positionErrorSum[2] = 0;
      velocityErrorSum[1] = 0;
      velocityErrorSum[2] = 0;
    }
    
    //Position Control
    if(system_state == Position_Mode) {  
      positionTarget = target;
         
      positionErrorPrev[1] = positionError[1];
      positionErrorPrev[2] = positionError[2];

      positionError[1] = positionTarget - wheelPositionAvg[1];
      positionError[2] = positionTarget - wheelPositionAvg[2];

      if(RIGHT_SKATE == 1) {
        positionError[1] = constrain(positionError[1],0,abs(positionError[1]));  
        positionError[2] = constrain(positionError[2],-1*abs(positionError[2]),0);  
      }

      if(LEFT_SKATE == 1) {
        positionError[1] = constrain(positionError[1],-1*abs(positionError[1]),0);
        positionError[2] = constrain(positionError[2],0,abs(positionError[2]));    
      }
      
      positionErrorSum[1] = positionErrorSum[1] + positionError[1];
      positionErrorSum[2] = positionErrorSum[2] + positionError[2];
      
      positionErrorDiff[1] = positionError[1] - positionErrorPrev[1];
      positionErrorDiff[2] = positionError[2] - positionErrorPrev[2];
      
      speedCommand[1] = constrain(P_P_GAIN1*positionError[1] + P_I_GAIN1*positionErrorSum[1] + P_D_GAIN1*positionErrorDiff[1],SPEED_LIM_MIN,SPEED_LIM_MAX);
      speedCommand[2] = constrain(P_P_GAIN2*positionError[2] + P_I_GAIN2*positionErrorSum[2] + P_D_GAIN2*positionErrorDiff[2],SPEED_LIM_MIN,SPEED_LIM_MAX);
  
      /*//Serial.print("Enc=[");
      Serial.print(encCount1, DEC);
      Serial.print(",");
      Serial.print(encCount2, DEC);
      //Serial.print("], Posn=[");
      Serial.print(",");
      Serial.print((int)wheelPositionAvg[1], DEC);
      Serial.print(",");
      Serial.print((int)wheelPositionAvg[2], DEC);
      Serial.print(",");
      //Serial.print("], Tgt=");
      Serial.print((int)target, DEC);
      Serial.print(",");
      //Serial.print(", Cmd=[");
      Serial.print((int)speedCommand[1], DEC);
      Serial.print(",");
      Serial.println((int)speedCommand[2], DEC);
      //Serial.println("");*/

      setSpeed(1,speedCommand[1]);
      setSpeed(2,speedCommand[2]);
    }

    //Velocity Control
    if(system_state == Velocity_Mode) {

      //Apply acceleration  limit
      velocityTarget = target;
      if(LEFT_SKATE == 1) velocityTarget = -1*velocityTarget;
      
      velocityTargetLimPrev = velocityTargetLim;
      velocityTargetLim = constrain(velocityTarget,velocityTargetLimPrev-ACCEL_LIMIT*(CTRL_PERIOD_MS/1000.0),
          velocityTargetLimPrev+ACCEL_LIMIT*(CTRL_PERIOD_MS/1000.0));

      velocityErrorPrev[1] = velocityError[1];
      velocityErrorPrev[2] = velocityError[2];
      
      velocityError[1] = velocityTargetLim - wheelVelocityAvg[1];
      velocityError[2] = velocityTargetLim - wheelVelocityAvg[2];
      
      velocityErrorSum[1] = velocityErrorSum[1] + velocityError[1];
      velocityErrorSum[2] = velocityErrorSum[2] + velocityError[2];
      
      velocityErrorDiff[1] = velocityError[1] - velocityErrorPrev[1];
      velocityErrorDiff[2] = velocityError[2] - velocityErrorPrev[2];
      
      speedCommand[1] = constrain(V_P_GAIN1*velocityError[1] + V_I_GAIN1*velocityErrorSum[1] + V_D_GAIN1*velocityErrorDiff[1],SPEED_LIM_MIN,SPEED_LIM_MAX);
      speedCommand[2] = constrain(V_P_GAIN2*velocityError[2] + V_I_GAIN2*velocityErrorSum[2] + V_D_GAIN2*velocityErrorDiff[2],SPEED_LIM_MIN,SPEED_LIM_MAX);

      /*//Serial.print("Enc=[");
      Serial.print(encCount1, DEC);
      Serial.print(",");
      Serial.print(encCount2, DEC);
      Serial.print(",");
      //Serial.print("], Vel=[");
      Serial.print((int)wheelVelocityAvg[1], DEC);
      Serial.print(",");
      Serial.print((int)wheelVelocityAvg[2], DEC);
      //Serial.print("], Tgt=[");
      //Serial.print(target, DEC);
      Serial.print(",");
      Serial.print((int)velocityTargetLim, DEC);
      Serial.print(",");
      //Serial.print("], Cmd=[");
      Serial.print((int)speedCommand[1], DEC);
      Serial.print(",");
      Serial.println((int)speedCommand[2], DEC);
      //Serial.println("]");*/

      setSpeed(1,speedCommand[1]);
      setSpeed(2,speedCommand[2]); 
    } 
     nh.spinOnce();   
  }

  //myData.data = wheelVelocityAvg[1];
  myData.data = velocityTarget;
 

 
  
  /*if (Serial.available()) {
    target = (float)Serial.parseInt();
  }*/
}


// Interrupt on 1A changing state
void doEncoder1A(){
  // Test transition
  A1_set = digitalRead(ENC1_CHA_PIN) == HIGH;
  // and adjust counter + if A leads B
  encCount1 += (A1_set != B1_set) ? +1 : -1;
}

// Interrupt on 1B changing state
void doEncoder1B(){
  // Test transition
  B1_set = digitalRead(ENC1_CHB_PIN) == HIGH;
  // and adjust counter + if B follows A
  encCount1 += (A1_set == B1_set) ? +1 : -1;
}

// Interrupt on 2A changing state
void doEncoder2A(){
  // Test transition
  A2_set = digitalRead(ENC2_CHA_PIN) == HIGH;
  // and adjust counter + if A leads B
  encCount2 += (A2_set != B2_set) ? +1 : -1;
}

// Interrupt on 2B changing state
void doEncoder2B(){
  // Test transition
  B2_set = digitalRead(ENC2_CHB_PIN) == HIGH;
  // and adjust counter + if B follows A
  encCount2 += (A2_set == B2_set) ? +1 : -1;
}

void setSpeed(int escNum,float _speed)
{
  //float angle = map(_speed, -100, 100, 0, 180);
  //angle = constrain(angle, 0, 180); 
  int speedLim = constrain((int)_speed,SPEED_LIM_MIN,SPEED_LIM_MAX);
  int onTime = 1500;
  
  /*if(speedLim == 0) {
    onTime = 1500;
  }
  else {*/
  if(speedLim > 0) {
    onTime = constrain(map(speedLim, 1, 100, 1520, 2000), 1520, 2000);
  }
  else {
    if(speedLim < 0) {
      onTime = constrain(map(speedLim, -100, -1, 1000, 1480), 1000, 1480);
    }
  }

  //onTime = constrain(map(speedLim, -100, 100, 1000, 2000),1000,2000);
  
  switch(escNum) {
    case 1:
      esc1.writeMicroseconds(onTime);
      break;
    case 2:
      esc2.writeMicroseconds(onTime);
      break;
    default:
      break;
  }
}
