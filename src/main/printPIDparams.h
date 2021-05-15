void printPIDparams () {
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
  
    /*
    Serial.print("gyroY ");
    Serial.print(gyroY);
    Serial.print(" currAngl ");
    Serial.print(currentAngle);
    Serial.print(" AngleX ");
    Serial.print(AngleX);
    Serial.print(" AngleY ");
    Serial.print(AngleY);
    Serial.print(" AngleZ ");
    Serial.println(AngleZ);
    */
  
    PrintPIDloopCounter = 0;
  }

}