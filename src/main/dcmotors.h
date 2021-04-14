void forwardL(int16_t speed) {
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
  map(speed, 0, MAX_SPEED, MIN_SPEEDL, MAX_SPEED);

  // vooruit of achteruit
  if (orBack) {
    ledcWrite(motorLcha1, 0);
    ledcWrite(motorLcha2, speed);
  }
  else {
    ledcWrite(motorLcha1, speed);
    ledcWrite(motorLcha2, 0);
  }
}

void forwardR(int16_t speed) {
  bool orBack = false;
  if (speed < 0) {
    speed =  -speed;
    orBack = true;
  }
 
  // Zorg dat snelheid in toegelaten gebied zit
  if (speed < RUST_SPEED) {
    speed = 0;
  }
  else if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  }

  // Hermap snelheid tussen MIN-MAX
  map(speed, 0, MAX_SPEED, MIN_SPEEDR, MAX_SPEED);

  // vooruit of achteruit
  if (orBack) {
    ledcWrite(motorRcha1, speed);
    ledcWrite(motorRcha2, 0);
  }
  else {
    ledcWrite(motorRcha1, 0);
    ledcWrite(motorRcha2, speed);
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
  forwardL(sL);
  forwardR(sR);
  
}
