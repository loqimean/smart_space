// ************* Vars *************
#define LIGHT_SENSOR_PIN A0
#define SERVER_PORT 80

const int RELAY_PINS[] = {4};

const char* ssid = "lenovo";
const char* password = "04101999";
// const char* ssid = "TP-Link_E2B1";
// const char* password = "leeco&apple";

// ************ Libs ************
#include "dependencies.h"

// Connection managers
#include "connection_managers/wifi_connection_manager.h"
#include "connection_managers/relays_connection_manager.h"

// Sensors
#include "sensors/LIGHT_SENSOR.h"

// Responders
#include "responders/light_sensor_responder.h"
#include "responders/relay_responder.h"

// Configs
#include "config/routes.h"

WebServer server(SERVER_PORT);

void setup() {
  Serial.begin(9600);

  initRelays();

  connectToWiFi(ssid, password);

  setupRoutes(server);

  server.begin();
}

void loop() {
  server.handleClient(); // Handle client requests
}
