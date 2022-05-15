void forward(int16_t speed, int motorcha1, int motorcha2) {
  stepperL.setSpeed(Kp);
  stepperR.setSpeed(Kp);

  stepperL.runSpeed();
  stepperR.runSpeed();

}

void setSpeed(int16_t s, int16_t rotation) {
  // Links
  #ifdef StepperL_reverse
    stepperL.setSpeed(-pidOutput);
  #else 
    stepperL.setSpeed(pidOutput);
  #endif
  stepperL.runSpeed();

  // Rechts
  #ifdef StepperR_reverse
    stepperR.setSpeed(-pidOutput);
  #else 
    stepperR.setSpeed(pidOutput);
  #endif
  stepperR.runSpeed();

}
