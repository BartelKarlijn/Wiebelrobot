
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kpup() {
  Kp += Kp_change;
  Serial.print("Changing via wifi Kp, new value ");
  Serial.println(Kp);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kpdo() {
  Kp += - Kp_change;
  Serial.print("Changing via wifi Kp, new value ");
  Serial.println(Kp);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kiup() {
  Ki += Ki_change;
  Serial.print("Changing via wifi Ki, new value ");
  Serial.println(Ki);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kido() {
  Ki += - Ki_change;
  Serial.print("Changing via wifi Ki, new value ");
  Serial.println(Ki);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kdup() {
  Kd += Kd_change;
  Serial.print("Changing via wifi Kd, new value ");
  Serial.println(Kd);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kddo() {
  Kd += - Kd_change;
  Serial.print("Changing via wifi Kd, new value ");
  Serial.println(Kd);
  server.send(200, "text/html", SendHTML()); 
}
void handle_SaveConfig() {
  save_datato_eeprom ();  
  Serial.println("Paramters stored to eeprom");
  server.send(200, "text/html", SendHTML()); 
}
void handle_CalibrateGyro() {
  pidError = 0;
  integralErr = 0;
  errorDerivative = 0;
  Serial.println("Gyro calibrated aka PID waarden op 0 gezet");
  server.send(200, "text/html", SendHTML()); 
}
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

