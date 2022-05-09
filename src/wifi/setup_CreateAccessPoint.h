void setup_CreateAccessPoint(){
  // Als nog altijd geen connectie, AccessPoint opzetten
  if ((WiFi.status() != WL_CONNECTED)) {
    Serial.println("Not connected to wifi; setup up Accespoint");
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

  wifi_st = "<ol>";
  for (int i = 0; i < n; ++i)
  {
    // Print SSID and RSSI for each network found
    wifi_st += "<li>";
    wifi_st += WiFi.SSID(i);
    wifi_st += " (";
    wifi_st += WiFi.RSSI(i);
    wifi_st += ")";
    //st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    wifi_st += "</li>";
  }
  wifi_st += "</ol>";

  WiFi.softAP(autoConnectAP, "");
  Serial.println("Local IP: http://192.168.4.1/");
  
  }

}