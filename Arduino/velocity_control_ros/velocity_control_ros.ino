// ROS Stuff

#define SERIAL_BUFFER_SIZE 256
//#include <Wire.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Temperature.h>
#include <UM.h>
#include <ros/time.h>
//#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <motor/Num.h>
#include <motor/states.h>

#include <motor/yaml_values.h>
int global_state, global_set_point;

void servo_cb( const motor::states& cmd_msg){

  //servo.write(cmd_msg.data*180.0/100.0); //set servo angle, should be from 0-180 
  //force_msg.data = cmd_msg.data*180.0/100.0;
  //pub_force.publish(&force_msg);
  //servo.write(0);
  //servo.write(cmd_msg.data);
  //if(cmd_msg.data == 30) {
    global_state = cmd_msg.state;
    global_set_point = cmd_msg.set_point;
    
    digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
 // }

}

ros::Subscriber<motor::states> sub("servo", servo_cb);
    
//Connect the RX pin on the UM7 to TX1 (pin 18) on the DUE
//Connect the TX pin on the UM7 to RX1 (pin 19) on the DUE

UM imu;

float left_bias_f1, left_bias_f2, left_bias_f3, right_bias_f1, right_bias_f2, right_bias_f3, left_gain_f1, left_gain_f2, left_gain_f3, right_gain_f1, right_gain_f2, right_gain_f3;

ros::NodeHandle  nh;

//Set up the ros node and publisher

motor::Num total_sensor;

ros::Publisher left("left", &total_sensor);

ros::ServiceClient<motor::yaml_values::Request, motor::yaml_values::Response> client("yaml_send");

// ROS Stuff ends

#define LEFT_SKATE 0
#define RIGHT_SKATE 1

#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20
#define ESC1_PIN 7 

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9

#define ONE_REV_DIST_MM (3.14*2.875*25.4)
#define CPR 360
#define PPR (CPR*4)

#define P_P_GAIN 2
#define P_I_GAIN 0
#define P_D_GAIN 0.4

#define V_P_GAIN 0.01
#define V_I_GAIN 0
#define V_D_GAIN 0

#define ACCEL_LIMIT 125000

#define PERIOD_MS 20.0

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

float skatePosition = 0;
float positionTarget = 0;
float positionError = 0;
float positionErrorSum = 0;
float positionErrorDiff = 0;
float positionErrorPrev = 0;

float skateVelocity = 0;
float skatePositionPrev = 0;
float velocityTarget = 0;
float velocityTargetLim = 0;
float velocityError = 0;
float velocityErrorSum = 0;
float velocityErrorDiff = 0;
float velocityErrorPrev = 0;

float speedCommand = 0;
float esc1Command = 0;
float esc2Command = 0;

long lastTimeStamp = 0;
long currentTimeStamp = 0;

Servo esc1; //Front
Servo esc2; //Back



void setup() {
  
  // ROS Stuff

  nh.initNode();
  nh.advertise(left);    
  nh.getHardware()->setBaud(115200);
  nh.serviceClient(client);
  Serial1.begin(115200);
  nh.subscribe(sub);
  delay(5000);

  motor::yaml_values::Request req;
  motor::yaml_values::Response resp;
  client.call(req, resp);
  left_bias_f1 = resp.left_bias_f1;
  left_bias_f2 = resp.left_bias_f2;
  left_bias_f3 = resp.left_bias_f3;
  left_gain_f1 = resp.left_gain_f1;
  left_gain_f2 = resp.left_gain_f2;
  left_gain_f3 = resp.left_gain_f3;

  right_bias_f1 = resp.right_bias_f1;
  right_bias_f2 = resp.right_bias_f2;
  right_bias_f3 = resp.right_bias_f3;
  right_gain_f1 = resp.right_gain_f1;
  right_gain_f2 = resp.right_gain_f2;
  right_gain_f3 = resp.right_gain_f3;

  // ROS Stuff ends

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
  esc1.attach(ESC1_PIN);
  setSpeed(1,0.0); 
  esc2.attach(ESC2_PIN);
  setSpeed(2,0.0);

  //pinMode(50, OUTPUT);

  Serial.begin(115200);
  Serial.println("Standby...prepping alcubierre drive");
  delay(8000);
  Serial.println("Ready to roll!");
}

// ROS stuff
long publisher_timer = 0;
// ROS sutff ends

void loop(){ 

  // ROS Stuff

  if (Serial1.available() > 0) {
     
      if (imu.encode(Serial1.read())) {
         
        
        total_sensor.header.stamp = nh.now();
        

        total_sensor.f1 = analogRead(A0);
        total_sensor.f2 = analogRead(A1);
        total_sensor.f3 = analogRead(A2);
      
        
        total_sensor.ax = imu.accel_x;
        total_sensor.ay = imu.accel_y;
        total_sensor.az = imu.accel_z;
        
       
        total_sensor.rp = imu.gyro_x; 
        total_sensor.ry = imu.gyro_y;
        total_sensor.rr = imu.gyro_z;


        total_sensor.qx = imu.quatx;
        total_sensor.qy =imu.quaty;
        total_sensor.qz =imu.quatz;
        total_sensor.qw = imu.quatw;


        left.publish(&total_sensor);
           
    }
  }
   
  nh.spinOnce();

  // ROS Stuff ends
  
  currentTimeStamp = millis();
  
  if((currentTimeStamp - lastTimeStamp) >= PERIOD_MS) {
    //digitalWrite(50,!digitalRead(50));
    lastTimeStamp = currentTimeStamp;

    //If the target velocity is 0 and the velocity is low enough, switch to position control
    if((target == 0) && (abs(skateVelocity) < 50) && (system_state == Velocity_Mode)) {
      system_state = Position_Mode;
      encCount1 = 0;
      encCount2 = 0;
      positionErrorSum = 0;
      velocityErrorSum = 0;
    }

    //If the target velocity is not 0, switch to velocity control
    if((target != 0) && (system_state == Position_Mode)) {
      system_state = Velocity_Mode;
      encCount1 = 0;
      encCount2 = 0;
      positionErrorSum = 0;
      velocityErrorSum = 0;
    }

    //Common Mode Information
    skatePositionPrev = skatePosition;
    skatePosition = ((0.5*float(encCount1 + encCount2)) / PPR) * ONE_REV_DIST_MM;
    
    //Position Control
    if(system_state == Position_Mode) {  
      positionTarget = target;
         
      positionErrorPrev = positionError;
      positionError = positionTarget - skatePosition;
      positionErrorSum = positionErrorSum + positionError;
      positionErrorDiff = positionError - positionErrorPrev;
      
      speedCommand = P_P_GAIN*positionError + P_I_GAIN*positionErrorSum + P_D_GAIN*positionErrorDiff;
      speedCommand = constrain(speedCommand,-90,90);
  
      Serial.print("E1 Idx:");
      Serial.print(encCount1, DEC);
      Serial.print(", E2 Idx:");
      Serial.print(encCount2, DEC);
      Serial.print(" , Posn:");
      Serial.print(skatePosition, DEC);
      Serial.print(" , Command:");
      Serial.print(speedCommand, DEC);
  
      
      if(speedCommand == 0) {
        setSpeed(1,0);
        setSpeed(2,0);
      }
      if(speedCommand > 0) {
        if(RIGHT_SKATE) {
          setSpeed(1,speedCommand);
          setSpeed(2,0);
        }
        if(LEFT_SKATE) {
          setSpeed(2,speedCommand);
          setSpeed(1,0);       
        }
      }
      if(speedCommand < 0) {
        if(RIGHT_SKATE) {
          setSpeed(1,0);
          setSpeed(2,speedCommand);
        }
        if(LEFT_SKATE) {
          setSpeed(2,0);
          setSpeed(1,speedCommand);       
        }
      }
      Serial.println("");
    }

    //Velocity Control
    if(system_state == Velocity_Mode) {
      skateVelocity = (skatePosition - skatePositionPrev)/(PERIOD_MS/1000.0);

      //Apply acceleration  limit
      velocityTarget = target;
     velocityTargetLim = constrain(velocityTarget,skateVelocity-ACCEL_LIMIT*(PERIOD_MS/1000.0),
          skateVelocity+ACCEL_LIMIT*(PERIOD_MS/1000.0));


      //velocityTargetLim = velocityTarget;  
      velocityErrorPrev = velocityError;
      velocityError = velocityTargetLim - skateVelocity;
      velocityErrorSum = velocityErrorSum + velocityError;
      velocityErrorDiff = velocityError - velocityErrorPrev;
      speedCommand = V_P_GAIN*velocityError + V_I_GAIN*velocityErrorSum + V_D_GAIN*velocityErrorDiff;
      speedCommand = constrain(speedCommand,-90,90);


      Serial.print("target_velocity_constrai: ");
      Serial.print(velocityTargetLim, DEC);
      Serial.print("E1 Idx:");
      Serial.print(encCount1, DEC);
      Serial.print(", E2 Idx:");
      Serial.print(encCount2, DEC);
      Serial.print(" , Vel:");
      Serial.print(skateVelocity, DEC);
      Serial.print(" , Command:");
      Serial.print(speedCommand, DEC);

      setSpeed(1,speedCommand);
      setSpeed(2,speedCommand);
    } 
    Serial.println("");   
  }
  
  if (Serial.available()) {
    target = Serial.parseFloat();
    //Serial.println("Reset to zero");
  }
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
  float angle = map(_speed, -100, 100, 0, 180);
  angle = constrain(angle, 0, 180); 
  switch(escNum) {
    case 1:
      esc1.write(angle);
      Serial.print(" , ESC1:");
      Serial.print(_speed, DEC);
      break;
    case 2:
      esc2.write(angle);
      Serial.print(" , ESC2:");
      Serial.print(_speed, DEC);
      break;
    default:
      break;
  }
}
