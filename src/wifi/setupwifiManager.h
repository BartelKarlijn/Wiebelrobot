AsyncWebServer webServer(80);
DNSServer dnsServer;

void setupwifiManager () {
  Serial.print("\nStarting AutoConnect to wifi on " + String(ARDUINO_BOARD));
  Serial.println(ESP_ASYNC_WIFIMANAGER_VERSION);
  
  ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, autoConnectAP);

  if (autoConnectReset) {
    ESPAsync_wifiManager.resetSettings();   //reset saved settings
  }

  ESPAsync_wifiManager.setAPStaticIPConfig(autoConnectIP, autoConnectIP, autoConnectSN);
  ESPAsync_wifiManager.autoConnect(autoConnectName);
  if (WiFi.status() == WL_CONNECTED) { 
      Serial.print(F("Connected. Local IP: ")); 
      Serial.println(WiFi.localIP()); 
      Serial.print("naam van apparaat");
      Serial.println(autoConnectName);
  }
  else { 
    Serial.println(ESPAsync_wifiManager.getStatus(WiFi.status())); 
    startupError = true;
  }

}