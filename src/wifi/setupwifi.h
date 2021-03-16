void setupwifi() {
  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/",        handle_OnConnect);
  server.on("/butkpup", handle_Kpup);
  server.on("/butkpdo", handle_Kpdo);

  server.onNotFound    (handle_NotFound);

  server.begin();
}
