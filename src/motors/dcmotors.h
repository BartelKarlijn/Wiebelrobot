void forward(int16_t speed, int motorcha1, int motorcha2) {
  bool orBack = false;
  if (speed < 0) {
    speed = - speed;
    orBack = true;
  }
 
  // Zorg dat snelheid boven drempelwaarde zit, en onder MAX
  if (speed < RUST_SPEED) {
    speed = 0;
  }
  else if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  }

  // Hermap snelheid tussen MIN-MAX
  map(speed, 0, MAX_SPEED, MIN_SPEED, MAX_SPEED);

  // vooruit of achteruit
  if (orBack) {
    ledcWrite(motorcha1, 0);
    ledcWrite(motorcha2, speed);
  }
  else {
    ledcWrite(motorcha1, speed);
    ledcWrite(motorcha2, 0);
  }
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
