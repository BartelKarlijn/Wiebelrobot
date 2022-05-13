void printPIDparams () {
  float loop_duration;
  PrintPIDloopCounter += 1;

  if (PrintPIDloopCounter >= PrintPIDLoops) {
    Print(" AngleY ");
    Print(String(currentAngle));
    Print(" PID: ");
    Print(String(pidError));
    Print(" ");
    Print(String(integralErr));
    Print(" ");
    Print(String(errorDerivative));
    Print(" Output: ");
    Print(String(pidOutput));
    Print(" /max ");
    Println(String(MAX_PID_OUTPUT));

    loop_duration = (micros() - loop_timer) / PrintPIDloopCounter ;
    loop_timer = micros();
    Print("loop duration in us: ");
    Println(String(loop_duration)); 

    PrintPIDloopCounter = 0;
  }

}