// TODO: move to separate files, like initialize.h in future
// TODO: create framework for Arduino servers

// Libs
#include "dependencies.h"

// Sensors
#include "sensors/light_sensor.h"
#include "sensors/temp_and_humidity_sensor.h"

// Responders
#include "responders/light_sensor_responder.h"
#include "responders/relay_responder.h"
#include "responders/temp_and_humidity_responder.h"

// Configs
#include "config/credentials.h"
#include "config/routes.h"

// Connection managers
#include "connection_managers/wifi_connection_manager.h"
#include "connection_managers/relays_connection_manager.h"

WebServer server(SERVER_PORT);

void setup() {
  Serial.begin(9600);

  initRelays();
  connectToWiFi(SSID, PASSWORD);
  setupRoutes(server);

  server.begin();
}

void loop() {
  server.handleClient();
}
