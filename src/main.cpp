
/**
   Copyright 2017 Dan Oprescu
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
 
#include <Arduino.h>

#include <setup\include.h>


//////// MAIN //////////

void setup() {
  Serial.begin(SerialSpeed);
  delay(100);
  Serial.println("Starting");
  setup_intled();
  setupwifiManager();  // Autoconfiguratie 
  setupwifi();         // handles en dergelijke
//  i2cscan_setup();
  setupTask1();
  setup_mpu();
  setup_dcmotors();
  loop_timer = micros() + PERIOD;
  print_timer = micros() + PRINT_PERIOD;
  get_datafrom_eeprom ();

  digitalWrite(ledpin, HIGH);
  Serial.println("Started");
}

boolean isValidJoystickValue(uint8_t joystick) {
  return joystick > 20 && joystick < 230;
}

void loop() {
// i2cscan();       // used to find I2C port of gyro
// testmotor();     // used to test DC motors (on/off)
// testmotorPWM(); // used to understand ledc for driving motors
// testmotorPWM2();  // driving motor with function
// testgyro();
//  getAcceleration(&accX, &accY, &accZ);
//  rollAcc = asin((float)accX / ACC_SCALE_FACTOR) * RAD_TO_DEG;
//  pitchAcc = asin((float)accY / ACC_SCALE_FACTOR) * RAD_TO_DEG;
  getRotation(&gyroX, &gyroY, &gyroZ);
  // roll vs pitch depends on how the MPU is installed in the robot
  currentAngle -= gyroY * GYRO_RAW_TO_DEGS;

  getAcceleration(&accX, &accY, &accZ);
  AngleX = RAD_TO_DEG * (atan2(-accY, -accZ)+PI);
  AngleY = RAD_TO_DEG * (atan2(-accX, -accZ)+PI);
  AngleZ = RAD_TO_DEG * (atan2(-accY, -accX)+PI);
Serial.print("gyroY ");
Serial.print(gyroY);
Serial.print(" currAngl ");
Serial.print(currentAngle);
Serial.print(" AngleX ");
Serial.print(AngleX);
Serial.print(" AngleY ");
Serial.print(AngleY);
Serial.print(" AngleZ ");
Serial.print(AngleZ);


  // apply PID algo
  pidError = currentAngle - angleSetpoint - selfBalanceAngleSetpoint;     // het P gedeelte
  integralErr += pidError;                                         // het I gedeelte  
  integralErr = constrf(integralErr, -MAXintegralErr, MAXintegralErr);           // zorgen dat het de spuigaten niet uitloopt
  errorDerivative = (pidError - pidLastError)*10;                       // het D gedeelte
  pidLastError = pidError;

  pidOutput = Kp*pidError + Ki*integralErr + Kd*errorDerivative;

  printPIDparams();

// zorgen dat we vaste loop lengte hebben
  if (loop_timer <= micros()) Serial.println("ERROR loop too short !");
  while (loop_timer > micros());
  loop_timer += PERIOD;
  setSpeed(pidOutput, rotation);
//  setSpeed(constrf(pidOutput, -MAX_PID_OUTPUT, MAX_PID_OUTPUT) * (MAX_SPEED / MAX_PID_OUTPUT), rotation);


  
/*
  roll -= gyroY * GYRO_RAW_TO_DEGS;
  pitch += gyroY * GYRO_RAW_TO_DEGS;
  //sin() has to be applied on radians
  roll += pitch * sin((float)gyroZ * GYRO_RAW_TO_DEGS * DEG_TO_RAD);
  pitch -= roll * sin((float)gyroZ * GYRO_RAW_TO_DEGS * DEG_TO_RAD);

  roll = roll * 0.999 + rollAcc * 0.001;
  pitch = pitch * 0.999 + pitchAcc * 0.001;
//Serial.print("roll X Y Z: ");
//Serial.print(gyroX * GYRO_RAW_TO_DEGS );
//Serial.print("  ");
//Serial.print(gyroY* GYRO_RAW_TO_DEGS);
//Serial.print("  ");
//Serial.println(gyroZ * GYRO_RAW_TO_DEGS);
//delay(1000);

  // apply PID algo
  // The selfBalanceAngleSetpoint variable is automatically changed to make sure that the robot stays balanced all the time.
  positionErr = constrf(currentPos / (float)1000, -MAX_CONTROL_OR_POSITION_ERR, MAX_CONTROL_OR_POSITION_ERR);
  serialControlErr = 0;
  if (isValidJoystickValue(joystickY)) {
    serialControlErr = constrf((joystickY - 130) / (float)15, -MAX_CONTROL_OR_POSITION_ERR, MAX_CONTROL_OR_POSITION_ERR);
    // this control has to change slowly/gradually to avoid shaking the robot
    if (serialControlErr < prevSerialControlErr) {
      serialControlErr = max(serialControlErr, prevSerialControlErr - MAX_CONTROL_ERR_INCREMENT);
    } else {
      serialControlErr = min(serialControlErr, prevSerialControlErr + MAX_CONTROL_ERR_INCREMENT);
    }
    prevSerialControlErr = serialControlErr;
  }
  pidError = pitch - angleSetpoint - selfBalanceAngleSetpoint;
  // either no manual / serial control -> try to keep the position or follow manual control
  if (abs(serialControlErr) > MIN_CONTROL_ERR) {
    pidError += serialControlErr > 0 ? serialControlErr - MIN_CONTROL_ERR : serialControlErr + MIN_CONTROL_ERR;
    // re-init position so it doesn't try to go back when getting out of manual control mode
    currentPos = 0;
  } else {
    pidError += positionErr;
  }
  integralErr = constrf(integralErr + Ki * pidError, -MAX_PID_OUTPUT, MAX_PID_OUTPUT);
  errorDerivative = pidError - pidLastError;
  pidOutput = Kp * pidError + integralErr + Kd * errorDerivative;
  if (pidOutput < 5 && pidOutput > -5) pidOutput = 0; //Create a dead-band to stop the motors when the robot is balanced
  if (pitch > 30 || pitch < -30) {   //If the robot tips over
    pidOutput = 0;
    integralErr = 0;
    selfBalanceAngleSetpoint = 0;
  }
  // store error for next loop
  pidLastError = pidError;
  int16_t rotation = 0;
  if (isValidJoystickValue(joystickX)) {
    rotation = constrf((float)(joystickX - 130), -MAX_PID_OUTPUT, MAX_PID_OUTPUT) * (MAX_SPEED / MAX_PID_OUTPUT);
  }
  if (micros() >= print_timer) {
    //Serial.print(positionErr); Serial.print("  -  "); Serial.print(rotation); Serial.print(" / "); Serial.println(serialControlErr);
//even onderstaand uitgesterd    
//    Serial.print(pitch); Serial.print(" / "); Serial.print(errorDerivative); Serial.print(" - "); Serial.println(selfBalanceAngleSetpoint);
    //Serial.print(accX); Serial.print(" / "); Serial.print(accY); Serial.print(" / "); Serial.print(accZ); Serial.print(" / "); Serial.print(gyroX); Serial.print(" / "); Serial.print(gyroY); Serial.print(" / "); Serial.println(gyroZ);
    print_timer += PRINT_PERIOD;
  }

  //The self balancing point is adjusted when there is not forward or backwards movement from the transmitter. This way the robot will always find it's balancing point
  if (angleSetpoint == 0) {                                 //If the setpoint is zero degrees
    if (pidOutput < 0) selfBalanceAngleSetpoint -= 0.0015;  //Increase the self_balance_pid_setpoint if the robot is still moving forward
    if (pidOutput > 0) selfBalanceAngleSetpoint += 0.0015;  //Decrease the self_balance_pid_setpoint if the robot is still moving backward
  }
  setSpeed(constrf(pidOutput, -MAX_PID_OUTPUT, MAX_PID_OUTPUT) * (MAX_SPEED / MAX_PID_OUTPUT), rotation);
  // The angle calculations are tuned for a loop time of PERIOD milliseconds.
  // To make sure every loop is exactly that, a wait loop is created by setting the loop_timer

  if (loop_timer <= micros()) Serial.println("ERROR loop too short !");
  while (loop_timer > micros());
  loop_timer += PERIOD;
*/


}
