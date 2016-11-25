//This code can be used for any purpose.

#include <Servo.h>
 Servo ESC1;
int pos = 0; //Sets position variable


void arm()
{
  setSpeed(0); //Sets speed variable delay(1000);
}

void setSpeed(int speed)
{ 
  int angle = map(speed, 0, 100, 0, 180); //Sets servo positions to different speeds ESC1.write(angle);
  ESC1.write(angle);
}

void setup() 
{
  
  
  ESC1.attach(9); //Adds ESC to certain pin. arm();
  //int speed; //Implements speed variable
  //int speed; //Implements speed variable
  setSpeed(0); //Creates variable for speed to be used in in for loop
  delay(4000);
  setSpeed(40);
}

void loop() 
{
  
}



