float buttonChangeStep(float var_Change, String Change_Oms) {
  var_Change = var_Change * 10;
  if (var_Change > 100.0 ) {var_Change = 1; }
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(String(var_Change));
  return var_Change;
}

float  buttonChangeUp(float var, float var_Change, String Change_Oms) {
  var += var_Change;
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(String(var));
  return var;
}

void buttonChangeSavePID() {
  save_PIDdatato_eeprom ();  
  resetPID();
  Println("Paramters stored to eeprom");
}

void buttonChangeRestart() {
  digitalWrite(ledpin, LOW);
  Println("Restarting ESP");
  setSpeed(0,0);
  delay(100);
  ESP.restart();
}