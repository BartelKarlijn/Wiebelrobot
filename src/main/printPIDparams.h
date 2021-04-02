void printPIDparams () {
  PrintPIDloopCounter += 1;

  if (PrintPIDloopCounter >= PrintPIDLoops) {
    Serial.print("PID: ");
    Serial.print(pidError);
    Serial.print(" ");
    Serial.print(integralErr);
    Serial.print(" ");
    Serial.print(errorDerivative);
    Serial.print(" Output: ");
    Serial.print(pidOutput);
    Serial.print(" /max ");
    Serial.println(MAX_PID_OUTPUT);
  
    PrintPIDloopCounter = 0;
  }

}