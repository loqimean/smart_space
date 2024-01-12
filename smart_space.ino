// TODO: move to separate files, like initialize.h in future
// ************* Vars *************
#define LIGHT_SENSOR_PIN A0
#define SERVER_PORT 80

#define DHTPIN 17
#define DHTTYPE DHT11

const int RELAY_PINS[] = {4};

const char* ssid = "TP-Link_E2B1";
const char* password = "leeco&apple";

// ************ Libs ************
#include "dependencies.h"

// Connection managers
#include "connection_managers/wifi_connection_manager.h"
#include "connection_managers/relays_connection_manager.h"

// Sensors
#include "sensors/light_sensor.h"
#include "sensors/temp_and_humidity_sensor.h"

// Responders
#include "responders/light_sensor_responder.h"
#include "responders/relay_responder.h"
#include "responders/temp_and_humidity_responder.h"

// Configs
#include "config/routes.h"

WebServer server(SERVER_PORT);

void setup() {
  Serial.begin(9600); // remove later

  initRelays();

  connectToWiFi(ssid, password);

  setupRoutes(server);

  server.begin();
}

void loop() {
  server.handleClient(); // Handle client requests
}
