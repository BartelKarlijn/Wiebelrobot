void setupIntled() {

  pinMode(ledpin, OUTPUT);
  startupError = false;
  
  digitalWrite(ledpin, LOW);    //ledje uitzetten, en pas aanzetten nadat alles is opgestart
  delay(200);
  digitalWrite(ledpin, HIGH); 
  delay(200);
  digitalWrite(ledpin, LOW); 
  delay(200);
  digitalWrite(ledpin, HIGH); 
  delay(250);
  digitalWrite(ledpin, LOW); 
}