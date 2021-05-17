void printPIDparams () {
  float loop_duration;
  PrintPIDloopCounter += 1;

  if (PrintPIDloopCounter >= PrintPIDLoops) {
    Serial.print(" AngleY ");
    Serial.print(currentAngle);
    Serial.print(" PID: ");
    Serial.print(pidError);
    Serial.print(" ");
    Serial.print(integralErr);
    Serial.print(" ");
    Serial.print(errorDerivative);
    Serial.print(" Output: ");
    Serial.print(pidOutput);
    Serial.print(" /max ");
    Serial.println(MAX_PID_OUTPUT);

    loop_duration = (micros() - loop_timer) / PrintPIDloopCounter ;
    loop_timer = micros();
    Serial.print("loop duration in us: ");
    Serial.println(loop_duration); 

    PrintPIDloopCounter = 0;
  }

}