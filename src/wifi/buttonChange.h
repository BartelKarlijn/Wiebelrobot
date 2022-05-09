float buttonChangeStep(float var_Change, String Change_Oms) {
  var_Change = var_Change * 10;
  if (var_Change > 100.0 ) {var_Change = 1; }
  Serial.print("Changing ");
  Serial.print(Change_Oms);
  Serial.print(", new value ");
  Serial.println(var_Change);
  return var_Change;
}

float  buttonChangeUp(float var, float var_Change, String Change_Oms) {
  var += var_Change;
  Serial.print("Changing ");
  Serial.print(Change_Oms);
  Serial.print(", new value ");
  Serial.println(var);
  return var;
}

void buttonChangeSavePID() {
  save_PIDdatato_eeprom ();  
  resetPID();
  Serial.println("Paramters stored to eeprom");
}

void buttonChangeRestart() {
  digitalWrite(ledpin, LOW);
  Serial.println("Restarting ESP");
  setSpeed(0,0);
  delay(100);
  ESP.restart();
}