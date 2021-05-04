
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}
//Kp
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
void handle_Kpch() {
  buttonChangeStep(Kp_change, "Kp_change");
}
//Ki
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
void handle_Kich() {
  buttonChangeStep(Ki_change, "Ki_change");
}
//Kd
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
void handle_Kdch() {
  buttonChangeStep(Kd_change, "Kd_change");
}
//An
void handle_Anup() {
  selfBalanceAngleSetpoint += An_change;
  Serial.print("Changing via wifi Angle, new value ");
  Serial.println(selfBalanceAngleSetpoint);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Ando() {
  selfBalanceAngleSetpoint -= An_change;
  Serial.print("Changing via wifi Angle, new value ");
  Serial.println(selfBalanceAngleSetpoint);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Anch() {
  buttonChangeStep(An_change, "An_change");
}
// Gewone knoppen
void handle_ShowAngle() {
  Serial.println("Do nothing");
  server.send(200, "text/html", SendHTML()); 
}
void handle_SaveConfig() {
  save_datato_eeprom ();  
  resetPID();
  Serial.println("Paramters stored to eeprom");
  server.send(200, "text/html", SendHTML()); 
}
void handle_Restart() {
  digitalWrite(ledpin, LOW);
  Serial.println("Restarting ESP");
  forwardL(0);
  forwardR(0);
  delay(100);
  ESP.restart();
}
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

