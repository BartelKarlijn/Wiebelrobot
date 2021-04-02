void testmotorPWM2() {
// Move the DC motor forward at maximum speed
int counter = 0;
  delay(500);

  Serial.println("Testing motor L");
  counter = 0;
  for (int16_t sp = 500; sp<MAX_SPEED; sp++) {
    ledcWrite(motorLcha1, sp);
    ledcWrite(motorLcha2, 0);
    delay(25);
    if (counter == 10 ) {
      counter = 0;
      Serial.print("L: ");
      Serial.println(sp);
    }
    counter += 1;
  }
  ledcWrite(motorLcha1, 0);
  ledcWrite(motorLcha2, 0);

  Serial.println("Testing motor R");
  counter = 0;
  for (int16_t sp = 500; sp<MAX_SPEED; sp++) {
    ledcWrite(motorRcha1, sp);
    ledcWrite(motorRcha2, 0);
    delay(25);
    if (counter == 10 ) {
      counter = 0;
      Serial.print("R: ");
      Serial.println(sp);
    }
    counter += 1;
  }
  ledcWrite(motorRcha1, 0);
  ledcWrite(motorRcha2, 0);
}