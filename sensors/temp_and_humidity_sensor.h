class TempAndHumiditySensor {
  private:
    DHT dht;
    int pin;
    int type;
    const String HUMIDITY_KEY = "Humidity";
    const String HUMIDITY_UNIT = "%";
    const String TEMPERATURE_KEY = "Temperature";
    const String TEMPERATURE_UNIT = "°C";

  public:
    TempAndHumiditySensor(int pin, int type) : dht(pin, type) {
      dht.begin();
    }

    String getData() {
      float h = dht.readHumidity();
      float t = dht.readTemperature();

      DynamicJsonDocument doc(1024);

      if (isnan(h) || isnan(t)) {
        doc["error"] = "Failed to read from DHT sensor!";
      } else {
        JsonObject humidityObj = doc.createNestedObject(HUMIDITY_KEY);
        JsonObject temperatureObj = doc.createNestedObject(TEMPERATURE_KEY);

        humidityObj["value"] = h;
        temperatureObj["value"] = t;

        humidityObj["unit"] = HUMIDITY_UNIT;
        temperatureObj["unit"] = TEMPERATURE_UNIT;
      }

      String output;
      serializeJson(doc, output);

      return output;
    }
};
