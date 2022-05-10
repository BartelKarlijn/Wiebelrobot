void setup_CreateAccessPoint(){
  // Als nog altijd geen connectie, AccessPoint opzetten
  if ((WiFi.status() != WL_CONNECTED)) {
    Serial.println("Not connected to wifi; setup up Accespoint");
    Serial.println("Scanning Networks");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0)
      Serial.println("no networks found");
    else
    {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i)
      {
        // Print SSID and RSSI for each network found
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.println(")");
        delay(10);
      }
    }
  Serial.println("");    

  wifi_scan = "<ol>";
  for (int i = 0; i < n; ++i)
  {
    // Print SSID and RSSI for each network found
    wifi_scan += "<li>";
    wifi_scan += WiFi.SSID(i);
    wifi_scan += " (";
    wifi_scan += WiFi.RSSI(i);
    wifi_scan += ")";
    //st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    wifi_scan += "</li>";
  }
  wifi_scan += "</ol>";

  WiFi.softAP(autoConnectAP, "");
  Serial.println("Local IP: http://192.168.4.1/");
  
  }

}