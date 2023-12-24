class RelayResponder {
  private:
    int pin;

    int getCurrentState() {
      int currentState = digitalRead(pin);

      return currentState;
    }

  public:
    RelayResponder(int pinValue) {
      pin = pinValue;
    }

    String generateResponse() {
      String message = "";
      bool currentState = getCurrentState();

      if (currentState) {
        message = "Relay is turned ON! Brah, we are poor!";
      } else {
        message = "It's turned OFF.. We're reach, brother.";
      }

      return message;
    }

    String generateStateResponse() {
      return String(getCurrentState());
    }

    void switchState() {
      int newRelayState = !getCurrentState();
      
      digitalWrite(pin, newRelayState);
    }
};