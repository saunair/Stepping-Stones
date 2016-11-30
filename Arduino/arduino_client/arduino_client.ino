/*
 * rosserial Service Client
 */

#include <ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <motor/yaml_values.h>


ros::NodeHandle  nh;

ros::ServiceClient<motor::yaml_values::Request, motor::yaml_values::Response> client("yaml_send");

std_msgs::Float64 str_msg;
ros::Publisher chatter("chatter", &str_msg);


void setup()
{
  nh.initNode();
  nh.serviceClient(client);
  nh.advertise(chatter);
  while(!nh.connected()) nh.spinOnce();
  nh.loginfo("Startup complete");
}

void loop()
{
  motor::yaml_values::Request req;
  motor::yaml_values::Response resp;
  client.call(req, resp);
  str_msg.data = resp.left_bias_f1;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(100);
}
