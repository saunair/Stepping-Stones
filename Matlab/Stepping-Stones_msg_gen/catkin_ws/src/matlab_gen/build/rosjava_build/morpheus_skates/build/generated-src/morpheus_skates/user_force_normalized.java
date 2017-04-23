package morpheus_skates;

public interface user_force_normalized extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/user_force_normalized";
  static final java.lang.String _DEFINITION = "Header header\r\nfloat32 left_normal_front_outer\r\nfloat32 left_normal_front_inner\r\nfloat32 left_normal_rear\r\nfloat32 right_normal_front_outer\r\nfloat32 right_normal_front_inner\r\nfloat32 right_normal_rear\r\nfloat32 right_normal_total\r\nfloat32 left_normal_total\r\nfloat32 normal_total\r\n";
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  float getLeftNormalFrontOuter();
  void setLeftNormalFrontOuter(float value);
  float getLeftNormalFrontInner();
  void setLeftNormalFrontInner(float value);
  float getLeftNormalRear();
  void setLeftNormalRear(float value);
  float getRightNormalFrontOuter();
  void setRightNormalFrontOuter(float value);
  float getRightNormalFrontInner();
  void setRightNormalFrontInner(float value);
  float getRightNormalRear();
  void setRightNormalRear(float value);
  float getRightNormalTotal();
  void setRightNormalTotal(float value);
  float getLeftNormalTotal();
  void setLeftNormalTotal(float value);
  float getNormalTotal();
  void setNormalTotal(float value);
}
