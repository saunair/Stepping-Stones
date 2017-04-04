package morpheus_skates;

public interface sensors_normalizedResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "morpheus_skates/sensors_normalizedResponse";
  static final java.lang.String _DEFINITION = "float64 total_weight\r";
  double getTotalWeight();
  void setTotalWeight(double value);
}
