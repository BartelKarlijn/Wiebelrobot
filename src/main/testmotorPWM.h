void testmotorPWM() {
// Move the DC motor forward at maximum speed
  Serial.println("Moving full");
    ledcWrite(motorLcha1, MAX_SPEED);
    ledcWrite(motorLcha2, 0);
    ledcWrite(motorRcha1, 0);
    ledcWrite(motorRcha2, MAX_SPEED );
    delay(2000);

for (int i=MIN_SPEED; i<MAX_SPEED; i++) {
    Serial.println(i);
    ledcWrite(motorLcha1, 0);
    ledcWrite(motorLcha2, i);
    ledcWrite(motorRcha1, i);
    ledcWrite(motorRcha2, 0 );
    delay(20);
  }

  Serial.println("Stop");
    ledcWrite(motorLcha1, 0);
    ledcWrite(motorLcha2, 0);
    ledcWrite(motorRcha1, 0);
    ledcWrite(motorRcha2, 0);
    delay(2000);

  Serial.println("Min");
    ledcWrite(motorLcha1, MIN_SPEED);
    ledcWrite(motorLcha2, 0);
    ledcWrite(motorRcha1, MIN_SPEED);
    ledcWrite(motorRcha2, 0);
    delay(2000);
}
