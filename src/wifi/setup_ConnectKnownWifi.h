void setup_ConnectKnownWifi(){
  Serial.println();
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  delay(100);
  WiFi.mode(WIFI_STA);    // connect to network
  
  WiFi.begin(wifi_ssid.c_str(), wifi_pwd.c_str());

  // Dit houden we zo'n 10 sec vol, als het dan niet lukt AP opzetten.
  Serial.println("Connecting to wifi");
    for (int i = 0; i < 100; i++) {
    if ((WiFi.status() == WL_CONNECTED)) {
      Serial.println(".");
      Serial.print("Connected successfully to ");
      Serial.println(wifi_ssid);
      Serial.print("Local IP: ");
      Serial.println(WiFi.localIP());
      break;
    }
    else {
      Serial.print(".");
      delay(100);
    }
  }
  Serial.println(".");
}