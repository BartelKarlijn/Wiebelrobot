AsyncWebServer webServer(80);
DNSServer dnsServer;

void setupwifiManager () {
  Serial.print("\nStarting Async_AutoConnect_ESP32_minimal on " + String(ARDUINO_BOARD));
  Serial.println(ESP_ASYNC_WIFIMANAGER_VERSION);
  ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, "AutoConnectAP");
  //ESPAsync_wifiManager.resetSettings();   //reset saved settings
  ESPAsync_wifiManager.setAPStaticIPConfig(IPAddress(192,168,132,1), IPAddress(192,168,132,1), IPAddress(255,255,255,0));
  ESPAsync_wifiManager.autoConnect("AutoConnectAP");
  if (WiFi.status() == WL_CONNECTED) { Serial.print(F("Connected. Local IP: ")); Serial.println(WiFi.localIP()); }
  else { Serial.println(ESPAsync_wifiManager.getStatus(WiFi.status())); }

}