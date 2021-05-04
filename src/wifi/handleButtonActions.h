void buttonChangeStep(float var_Change, char* Change_Oms) {
  var_Change = var_Change * 10;
  if (var_Change >= 1000.0 ) {var_Change = 1; }
  Serial.print("Changing via wifi ");
  Serial.print(Change_Oms);
  Serial.print(", new value ");
  Serial.println(var_Change);
  server.send(200, "text/html", SendHTML()); 
}

void buttonUp(float var, float var_Change, char* var_Oms) {
  var += var_Change;
  Serial.print("Changing via wifi ");
  Serial.print(var_Oms);
  Serial.print(", new value ");
  Serial.println(var);
  server.send(200, "text/html", SendHTML()); 
}
