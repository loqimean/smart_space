#ifndef relays_connection_manager_h
#define relays_connection_manager_h

void initRelays() {
  for (int pin : RELAY_PINS) {
    pinMode(pin, OUTPUT);

    // TODO: add initRelays(); to setup LOW by default, or previous states
    digitalWrite(pin, LOW);
  }
}

#endif
