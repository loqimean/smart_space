class TempAndHumiditySensorResponder {
  private:
    TempAndHumiditySensor sensor;

  public:
    TempAndHumiditySensorResponder(int pin, int type) : sensor(pin, type) {}

    String generateResponse() {
      return sensor.getData();
    }
};
