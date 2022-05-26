void setSpeed(float s, int rotation) {
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
