
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
  Kp_change = Kp_change * 10;
  if (Kp_change >= 100.0 ) {Kp_change = 0.1;}
  Serial.print("Changing via wifi Kp_Change, new value ");
  Serial.println(Kp_change);
  server.send(200, "text/html", SendHTML()); 
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
  Ki_change = Ki_change * 10;
  if (Ki_change >= 100.0 ) {Ki_change = 0.1;}
  Serial.print("Changing via wifi Ki_Change, new value ");
  Serial.println(Ki_change);
  server.send(200, "text/html", SendHTML()); 
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
  Kd_change = Kd_change * 10;
  if (Kd_change >= 100.0 ) {Kd_change = 0.1;}
  Serial.print("Changing via wifi Kd_Change, new value ");
  Serial.println(Kd_change);
  server.send(200, "text/html", SendHTML()); 
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
  An_change = An_change * 10;
  if (An_change >= 100.0 ) {An_change = 0.1;}
  Serial.print("Changing via wifi An_Change, new value ");
  Serial.println(An_change);
  server.send(200, "text/html", SendHTML()); 
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

