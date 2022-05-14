void setupwifi() {
  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/",        handle_OnConnect);

  server.on("/butkpup", handle_Kpup);
  server.on("/butkpdo", handle_Kpdo);
  server.on("/butkiup", handle_Kiup);
  server.on("/butkido", handle_Kido);
  server.on("/butkdup", handle_Kdup);
  server.on("/butkddo", handle_Kddo);

  server.on("/butSave", handle_Save);
  
  server.onNotFound    (handle_NotFound);

  server.begin();
}
