void testmotorPWM2() {
// Move the DC motor forward at maximum speed
  Serial.println("Moving full");
  forwardL(MAX_SPEED);
  forwardR(MAX_SPEED);
  delay(2000);

  for (int16_t sp = -MAX_SPEED; sp<MAX_SPEED; sp++) {
    Serial.println(sp);
    forwardL(sp);
    forwardR(sp);
    delay(20);
  }

  Serial.println("Stop");
  forwardL(0);
  forwardR(0);
  delay(2000);

}