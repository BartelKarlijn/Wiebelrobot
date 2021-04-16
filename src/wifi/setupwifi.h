void setupwifi() {
  
//  WiFi.softAP(ssid, password);
//  delay(100);
//  WiFi.softAPConfig(local_ip, gateway, subnet);
//  delay(100);

  server.on("/",        handle_OnConnect);
  //Kp
  server.on("/butkpup", handle_Kpup);
  server.on("/butkpdo", handle_Kpdo);
  server.on("/butkpch", handle_Kpch);
  //Kd
  server.on("/butkiup", handle_Kiup);
  server.on("/butkido", handle_Kido);
  //Ki
  server.on("/butkdup", handle_Kdup);
  server.on("/butkddo", handle_Kddo);
  //Angle
  server.on("/butAngleup", handle_Angleup);
  server.on("/butAngledo", handle_Angledo);
  
  //Rest
  server.on("/butShowAngle", handle_ShowAngle);
  server.on("/butSaveConfig", handle_SaveConfig);
  server.on("/butRestart", handle_Restart);
  
  server.onNotFound    (handle_NotFound);

  server.begin();
}
