void setSpeed(int16_t s, int16_t rotation) {
  // Links
  #ifdef StepperL_reverse
    stepperL.setSpeed(-s);
  #else 
    stepperL.setSpeed(s);
  #endif

  // Rechts
  #ifdef StepperR_reverse
    stepperR.setSpeed(-s);
  #else 
    stepperR.setSpeed(s);
  #endif

}
