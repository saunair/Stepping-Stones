/*#define ESC1_PIN 7 
#define ENC1_CHA_PIN 21
#define ENC1_CHB_PIN 20

#define ENC2_CHA_PIN 2
#define ENC2_CHB_PIN 3
#define ESC2_PIN 9*/

#define ENC_CHA_PIN 2
#define ENC_CHB_PIN 3
#define ESC_PIN 9

#define SAMP_PERIOD_MS 1.0

#include <Servo.h>

volatile long encCount1 = 0;
long encCount1prev = 0;
int serialCmd = 0;

boolean A1_set = false;
boolean B1_set = false;

long currentTimeStamp = 0;
long lastTimeStamp = 0;

Servo esc;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENC_CHA_PIN, INPUT); 
  pinMode(ENC_CHB_PIN, INPUT);
  pinMode(ESC_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_CHA_PIN), doEncoder1A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_CHB_PIN), doEncoder1B, CHANGE);

  esc.attach(ESC_PIN,1000,2000);
  esc.writeMicroseconds(1500);
  
  Serial.begin(115200);
  Serial.setTimeout(1);
  Serial.println("Ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTimeStamp = millis();

  int onTime = 1500;
  
  if(Serial.available()) {
    serialCmd = Serial.parseInt();
      if(serialCmd > 0) {
        onTime = constrain(map(serialCmd, 1, 100, 1520, 2000), 1520, 2000);
      }
      else {
        if(serialCmd < 0) {
          onTime = constrain(map(serialCmd, -100, -1, 1000, 1480), 1000, 1480);
        }
    }
    esc.writeMicroseconds(onTime);
  }

  if((currentTimeStamp - lastTimeStamp) >= SAMP_PERIOD_MS) {
    lastTimeStamp = currentTimeStamp;

    Serial.print(serialCmd, DEC);
    Serial.print(",");
    Serial.println(encCount1, DEC);
  }
}

// Interrupt on 1A changing state
void doEncoder1A(){
  // Test transition
  A1_set = digitalRead(ENC_CHA_PIN) == HIGH;
  // and adjust counter + if A leads B
  encCount1 += (A1_set != B1_set) ? +1 : -1;
}

// Interrupt on 1B changing state
void doEncoder1B(){
  // Test transition
  B1_set = digitalRead(ENC_CHB_PIN) == HIGH;
  // and adjust counter + if B follows A
  encCount1 += (A1_set == B1_set) ? +1 : -1;
}
