
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
 
#include <main\include.h>


//////// MAIN //////////

void setup() {
  setupSerial();          // Serial communicatie opzetten
  setupIntledStart();     // Intern LED lampje
  setup_steppers();       // Motors afzetten
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
//  setupwifiManager();     // Autoconfiguratie als nieuwe wifi
  setup_ConnectKnownWifi();  // Aan gekende wifi connecteren
  setup_AsyncWebserver();    // webserver om html te tonen 
  setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.
  #ifdef flag_calibrateMPU 
    calibrateMPUsetup();  // als je MPU wil callibreren
  #else
    setupMPU();           // MPU en de DMP opstarten
  #endif

  loop_timer = micros() + PERIOD;
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


// zorgen dat we vaste loop lengte hebben
//  delay(10);
//  if (loop_timer <= micros()) Println("ERROR loop too short !");
//  while (loop_timer > micros());
//  loop_timer += PERIOD;

  stepperL.setSpeed(Kp*100);
  stepperL.runSpeed();

  stepperR.setSpeed(Ki*100);
  stepperR.runSpeed();

 //  setSpeed(constrf(pidOutput, -MAX_PID_OUTPUT, MAX_PID_OUTPUT) * (MAX_SPEED / MAX_PID_OUTPUT), rotation);

}
