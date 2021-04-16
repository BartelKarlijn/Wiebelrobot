
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
void handle_Kpch() {
  Kp_change = Kp_change * 10;
  if (Kp_change > 100.0 ) {Kp_change = 1;}
  Serial.print("Changing via wifi Kp_Change, new value ");
  Serial.println(Kp_change);
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
void handle_Angleup() {
  selfBalanceAngleSetpoint += Angle_change;
  Serial.print("Changing via wifi Angle, new value ");
  Serial.println(selfBalanceAngleSetpoint);
  server.send(200, "text/html", SendHTML()); 
}
void handle_Angledo() {
  selfBalanceAngleSetpoint -= Angle_change;
  Serial.print("Changing via wifi Angle, new value ");
  Serial.println(selfBalanceAngleSetpoint);
  server.send(200, "text/html", SendHTML()); 
}
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

