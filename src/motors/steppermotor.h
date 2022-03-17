void forward(int16_t speed, int motorcha1, int motorcha2) {
  stepperL.setSpeed(Kp);
  stepperR.setSpeed(Kp);

  stepperL.runSpeed();
  stepperR.runSpeed();

}

void setSpeed(int16_t s, int16_t rotation) {
  int16_t sL = s - rotation;
  int16_t sR = s + rotation;

  // set the new speed
  if(FlagNotMotor) {
    sL = 0;
    sR = 0;
  }
  forward(sL, motorLcha1, motorLcha2);
  forward(sR, motorRcha1, motorRcha2);
 
}
