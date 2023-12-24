class LightSensorResponder {
  private:
    LightSensor sensor;

  public:
    LightSensorResponder(int pin) : sensor(pin) {}

    String generateResponse() {
      int lightPercent = sensor.getData();
      String message = "Current light percentage: " + String(lightPercent);

      return message;
    }
};