package morpheus_skates;

public interface zero_pointResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/zero_pointResponse";
  static final java.lang.String _DEFINITION = "float64 zero_x\r\nfloat64 zero_y\r\nfloat64 zero_z\r";
  double getZeroX();
  void setZeroX(double value);
  double getZeroY();
  void setZeroY(double value);
  double getZeroZ();
  void setZeroZ(double value);
}
