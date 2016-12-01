/* 
 * rosserial Time and TF Example
 * Publishes a transform at current time
 */    

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

void setup()
{
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
}

long publisher_timer = 0;

void loop()
{
   
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

}
