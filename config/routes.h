#ifndef routes_h
#define routes_h

#include <WebServer.h>

void setupRoutes(WebServer& server) {
  // ********** Sensors **********
  // * Light sensor
  server.on("/sensors/light", HTTP_GET, [&]() {
    LightSensorResponder responder(LIGHT_SENSOR_PIN);

    server.send(200, "text/plain", responder.generateResponse());
  });


  // ********** Relays **********
  for (int pin_index = 0; pin_index < sizeof(RELAY_PINS); pin_index++) {
    // * Switch relay
    server.on("/relays/" + String(pin_index) + "/switch", HTTP_GET, [&]() {
      RelayResponder responder(RELAY_PINS[pin_index]);

      responder.switchState();

      server.send(200, "text/plain", String(responder.generateResponse()));
    });

    // * Get relay state
    server.on("/relays/" + String(pin_index) + "/state", HTTP_GET, [&]() {
      RelayResponder responder(RELAY_PINS[pin_index]);

      server.send(200, "text/plain", String(responder.generateStateResponse()));
    });
  }
}

#endif
