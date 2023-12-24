#ifndef wifi_connection_manager_h
#define wifi_connection_manager_h

void connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
}

#endif