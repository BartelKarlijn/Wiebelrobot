void  setup_steppers() {
  //http://fabacademy.org/2020/labs/zoi/files/machine%20design/datasheet%20M42STH47.pdf
  // M42STH47-1684S :
  //   Voltage:          2.8V
  //   Current/phase:    1.68A
  //   Resistance/phase: 1.65 Ohm
  // Vref = CurrentLimit * (8 x Rcs)
  //           Rcs = 0.050Ohm o 0.068Ohm
  //           Formule is valid for MICROSTEPPING; for FULLSTEP multipy by 1.4
  // Vref = 1.68 x 8 x 0.068 = 0.67V

  // Motoren aan of af zetten
  pinMode(motorPinENA, OUTPUT);
  digitalWrite(motorPinENA, HIGH );  // Motoren af zetten

  // Set the maximum speed in steps per second:
  stepperL.setMaxSpeed(MAX_STEPPERSPEED);
  stepperR.setMaxSpeed(MAX_STEPPERSPEED);

  stepperL.setAcceleration(MAX_STEPPERACCEL);
  stepperL.setAcceleration(MAX_STEPPERACCEL);  
}