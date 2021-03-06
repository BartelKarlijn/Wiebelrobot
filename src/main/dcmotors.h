void forwardL(int16_t speed) {
  bool orBack = false;
  if (speed < 0) {
    speed = - speed;
    orBack = true;
  }
 
  // Zorg dat snelheid in toegelaten gebied zit
  if (speed < MIN_SPEED) {
    speed = 0;
  }
  else if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  }
  // vooruit of achteruit
  if (orBack) {
    ledcWrite(motorLcha1, speed);
    ledcWrite(motorLcha2, 0);
  }
  else {
    ledcWrite(motorLcha1, 0);
    ledcWrite(motorLcha2, speed);
  }
}

void forwardR(int16_t speed) {
  bool orBack = false;
  if (speed < 0) {
    speed = - speed;
    orBack = true;
  }
 
  // Zorg dat snelheid in toegelaten gebied zit
  if (speed < MIN_SPEED) {
    speed = 0;
  }
  else if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  }
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