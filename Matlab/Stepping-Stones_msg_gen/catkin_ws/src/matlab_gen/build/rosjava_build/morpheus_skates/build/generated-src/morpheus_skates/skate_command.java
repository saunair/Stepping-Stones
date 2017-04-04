package morpheus_skates;

public interface skate_command extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/skate_command";
  static final java.lang.String _DEFINITION = "Header header\r\nfloat32 command_target\r\n\r\n";
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  float getCommandTarget();
  void setCommandTarget(float value);
}
