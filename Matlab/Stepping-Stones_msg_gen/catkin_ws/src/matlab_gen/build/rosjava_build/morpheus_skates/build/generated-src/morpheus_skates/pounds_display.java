package morpheus_skates;

public interface pounds_display extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/pounds_display";
  static final java.lang.String _DEFINITION = "Header header\r\nfloat32 left_force_front_outer\r\nfloat32 left_force_front_inner\r\nfloat32 left_force_rear\r\nfloat32 right_force_front_outer\r\nfloat32 right_force_front_inner\r\nfloat32 right_force_rear\r\nfloat32 right_total\r\nfloat32 left_total\r\nfloat32 total\r\n";
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  float getLeftForceFrontOuter();
  void setLeftForceFrontOuter(float value);
  float getLeftForceFrontInner();
  void setLeftForceFrontInner(float value);
  float getLeftForceRear();
  void setLeftForceRear(float value);
  float getRightForceFrontOuter();
  void setRightForceFrontOuter(float value);
  float getRightForceFrontInner();
  void setRightForceFrontInner(float value);
  float getRightForceRear();
  void setRightForceRear(float value);
  float getRightTotal();
  void setRightTotal(float value);
  float getLeftTotal();
  void setLeftTotal(float value);
  float getTotal();
  void setTotal(float value);
}
