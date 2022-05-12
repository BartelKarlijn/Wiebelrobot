void setupIntledStart() {
  // Onboard ledje enkele keren laten pinken.  Pas als alles OK is, dit weer uitzetten.
  pinMode(ledpin, OUTPUT);
  startupError = false;
  
  digitalWrite(ledpin, LOW);    //ledje uitzetten, en pas aanzetten nadat alles is opgestart
  delay(200);
  for (int i = 0; i < ledstartblink; i++)
  {
    digitalWrite(ledpin, HIGH); 
    delay(200);
    digitalWrite(ledpin, LOW); 
    delay(200);
  }
  
}

void setupIntledAllOK() {
  if ( not startupError ) {
    digitalWrite(ledpin, HIGH);
  }
  Println("Alles opgestart");
}