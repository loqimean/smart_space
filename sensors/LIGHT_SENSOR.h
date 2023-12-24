class LightSensor {
  private:
    int sensorPin;
    int sensorValue;
    int minValue;
    static int maxValue;
    // TODO: save later MIN and MAX values in Preferences

  public:
    LightSensor(int pin) {
      sensorPin = pin;
      sensorValue = 0;
      minValue = 1023;

      if(maxValue == 0) {
        maxValue = 0;
      }
    }

    int getData() {
      sensorValue = analogRead(sensorPin);

      if (sensorValue < minValue) {
        minValue = sensorValue;
      }
      if (sensorValue > maxValue) {
        maxValue = sensorValue;
      }

      int lightPercent = map(sensorValue, minValue, maxValue, 0, 100);

      return lightPercent;
    }
};

int LightSensor::maxValue = 0;
