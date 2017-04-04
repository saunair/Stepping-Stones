package morpheus_skates;

public interface integrated_message extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/integrated_message";
  static final java.lang.String _DEFINITION = "Header header\r\nskate_feedback left_feedback\r\nskate_feedback right_feedback\r\nskate_command left_command\r\nskate_command right_command\r\nuser_force_normalized normalized_force\r\npounds_display pounds_values\r\nfloat64[3] centre_of_mass_kinect\r\nfloat64[3] hip_left\r\nfloat64[3] hip_right\r\nfloat64[3] foot_left\r\nfloat64[3] foot_right\r\nfloat64[3] kinect_zero\r\nfloat64 user_position_offset\r\n";
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  morpheus_skates.skate_feedback getLeftFeedback();
  void setLeftFeedback(morpheus_skates.skate_feedback value);
  morpheus_skates.skate_feedback getRightFeedback();
  void setRightFeedback(morpheus_skates.skate_feedback value);
  morpheus_skates.skate_command getLeftCommand();
  void setLeftCommand(morpheus_skates.skate_command value);
  morpheus_skates.skate_command getRightCommand();
  void setRightCommand(morpheus_skates.skate_command value);
  morpheus_skates.user_force_normalized getNormalizedForce();
  void setNormalizedForce(morpheus_skates.user_force_normalized value);
  morpheus_skates.pounds_display getPoundsValues();
  void setPoundsValues(morpheus_skates.pounds_display value);
  double[] getCentreOfMassKinect();
  void setCentreOfMassKinect(double[] value);
  double[] getHipLeft();
  void setHipLeft(double[] value);
  double[] getHipRight();
  void setHipRight(double[] value);
  double[] getFootLeft();
  void setFootLeft(double[] value);
  double[] getFootRight();
  void setFootRight(double[] value);
  double[] getKinectZero();
  void setKinectZero(double[] value);
  double getUserPositionOffset();
  void setUserPositionOffset(double value);
}
