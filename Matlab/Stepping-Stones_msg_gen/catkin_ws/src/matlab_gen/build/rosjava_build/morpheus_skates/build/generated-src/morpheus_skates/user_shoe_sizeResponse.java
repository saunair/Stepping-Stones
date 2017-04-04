package morpheus_skates;

public interface user_shoe_sizeResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/user_shoe_sizeResponse";
  static final java.lang.String _DEFINITION = "float64 user_shoe_size\r";
  double getUserShoeSize();
  void setUserShoeSize(double value);
}
