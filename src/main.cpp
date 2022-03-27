
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
  setupSerial();          // Serial communicatie opzetten
  setupIntledStart();     // Intern LED lampje
  setup_steppers();       // Motors afzetten
  setupwifiManager();     // Autoconfiguratie als nieuwe wifi
  setup_AsyncWebserver(); // webserver om html te tonen 
  #ifdef flag_calibrateMPU 
    calibrateMPUsetup();  // als je MPU wil callibreren
  #else
    setupMPU();           // MPU en de DMP opstarten
  #endif

  loop_timer = micros() + PERIOD;
  get_datafrom_eeprom ();
  setupIntledAllOK();
}

void loop() {
  #ifdef flag_calibrateMPU 
    calibrateMPUloop();
  #else
    loopMPU();
  #endif

  // apply PID algo
  currentAngle = - ypr[1] * 180 / PI;
  pidError = currentAngle - angleSetpoint - selfBalanceAngleSetpoint;     // het P gedeelte
  integralErr += pidError;                                         // het I gedeelte  
  integralErr = constrf(integralErr, -MAXintegralErr, MAXintegralErr);           // zorgen dat het de spuigaten niet uitloopt
  errorDerivative = pidError - pidLastError;                       // het D gedeelte
  pidLastError = pidError;

  pidOutput = Kp*pidError + Ki*integralErr + Kd*errorDerivative;
  delay(500);
  //printPIDparams();


// zorgen dat we vaste loop lengte hebben
//  delay(10);
//  if (loop_timer <= micros()) Serial.println("ERROR loop too short !");
//  while (loop_timer > micros());
//  loop_timer += PERIOD;
//  stepperL.moveTo(Kp);
//  stepperL.run();
  digitalWrite(motorLpinDIR, HIGH);
  digitalWrite(motorLpinSTEP, LOW);
  delay(2000);
  digitalWrite(motorLpinDIR, LOW);
  digitalWrite(motorLpinSTEP, LOW);
  delay(2000);
  digitalWrite(motorLpinDIR, HIGH);
  digitalWrite(motorLpinSTEP, HIGH);
  delay(2000);
  digitalWrite(motorLpinDIR, LOW);
  digitalWrite(motorLpinSTEP, LOW);
  delay(2000);
  Serial.println("rondje gelopen");

 //  setSpeed(constrf(pidOutput, -MAX_PID_OUTPUT, MAX_PID_OUTPUT) * (MAX_SPEED / MAX_PID_OUTPUT), rotation);

}
