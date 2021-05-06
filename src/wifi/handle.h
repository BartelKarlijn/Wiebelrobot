
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}
//Kp
void handle_Kpup() {
  buttonUp(Kp, Kp_change, "Kp");
}
void handle_Kpdo() {
  buttonUp(Kp, -Kp_change, "Kp");
}
void handle_Kpch() {
  buttonChangeStep(Kp_change, "Kp_change");
}
//Ki
void handle_Kiup() {
  buttonUp(Ki, Ki_change, "Ki");
}
void handle_Kido() {
  buttonUp(Ki, -Ki_change, "Ki");
}
void handle_Kich() {
  buttonChangeStep(Ki_change, "Ki_change");
}
//Kd
void handle_Kdup() {
  buttonUp(Kd, Kd_change, "Kd");
}
void handle_Kddo() {
  buttonUp(Kd, -Kd_change, "Kd");
}
void handle_Kdch() {
  buttonChangeStep(Kd_change, "Kd_change");
}
//An
void handle_Anup() {
  buttonUp(selfBalanceAngleSetpoint, An_change, "Angle");
}
void handle_Ando() {
  buttonUp(selfBalanceAngleSetpoint, -An_change, "Angle");
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

