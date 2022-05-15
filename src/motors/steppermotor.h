void forward(int16_t speed, int motorcha1, int motorcha2) {
  stepperL.setSpeed(Kp);
  stepperR.setSpeed(Kp);

  stepperL.runSpeed();
  stepperR.runSpeed();

}

void setSpeed(int16_t s, int16_t rotation) {
  // Links
  #ifdef StepperL_reverse
    stepperL.setSpeed(-s);
  #else 
    stepperL.setSpeed(s);
  #endif
  stepperL.runSpeed();

  // Rechts
  #ifdef StepperR_reverse
    stepperR.setSpeed(-s);
  #else 
    stepperR.setSpeed(s);
  #endif
  stepperR.runSpeed();

}
