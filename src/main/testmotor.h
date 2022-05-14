void testmotor() {
// Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motorLpin1, LOW);
  digitalWrite(motorLpin2, HIGH); 
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, LOW); 
  delay(2000);

// stop
  Serial.println("Stop");
  digitalWrite(motorLpin1, LOW);
  digitalWrite(motorLpin2, LOW); 
  digitalWrite(motorRpin1, HIGH);
  digitalWrite(motorRpin2, LOW); 
  delay(2000);

// Move the DC motor backward at maximum speed
  Serial.println("Moving backward");
  digitalWrite(motorLpin1, HIGH); 
  digitalWrite(motorLpin2, LOW);
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, LOW); 
  delay(2000);

// stop
  Serial.println("Stop2");
  digitalWrite(motorLpin2, LOW);
  digitalWrite(motorLpin1, LOW); 
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, HIGH); 
  delay(2000);

}
