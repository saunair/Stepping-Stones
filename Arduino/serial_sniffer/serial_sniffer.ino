//Arduino TX (IMU-4) to RX1
//TX1 to IMU (IMU-4)
//IMU TX (IMU-3) to RX2
//TX2 to Arduino RX (IMU-3)

byte ser1_data;
byte ser2_data;

byte ser1_buffer[20] = {0};
byte ser2_buffer[100] = {0};

char ser1_idx = 0;
char ser2_idx = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  Serial1.begin(115200);
  Serial2.begin(115200);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()) {
    //Serial.write(Serial1.read());
    ser1_data = Serial1.read();
    Serial1.write(ser1_data);
    if(ser1_data == 's') {
      Serial.write('a');
      Serial.write(':');
      for(char i=0; i<ser1_idx; i++) {
        Serial.write(ser1_buffer[i]);
      }
      Serial.write(10);
      Serial.write(13);
      ser1_idx = 0;
    }
    ser1_buffer[ser1_idx++] = ser1_data;
  }

  if(Serial2.available()) {
    ser2_data = Serial2.read();
    Serial2.write(ser2_data);
    if(ser2_data == 's') {
      Serial.write('i');
      Serial.write(':');
      for(char i=0; i<ser2_idx; i++) {
        Serial.write(ser2_buffer[i]);
      }
      Serial.write(10);
      Serial.write(13);
      ser2_idx = 0;
    }
    ser2_buffer[ser2_idx++] = ser2_data;
  }
 }
