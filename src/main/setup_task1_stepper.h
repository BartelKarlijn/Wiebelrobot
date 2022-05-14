void task1_stepper_code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Println(String(xPortGetCoreID()));

  for(;;) {
  stepperL.setSpeed(Kp*100);
  stepperL.runSpeed();

  stepperR.setSpeed(Ki*100);
  stepperR.runSpeed();
  }
}

void setup_task1_stepper() {
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    task1_stepper_code,   /* Task function. */
                    "task1_stepper",      /* name of task. */
                    10000,                /* Stack size of task */
                    NULL,                 /* parameter of the task */
                    STEPPER_CORE_PRIO,    /* priority of the task. 0=idle, 1=lowest prio*/
                    &Task1_stepper,       /* Task handle to keep track of created task */
                    STEPPER_CORE);        /* pin task to core 1 instead of default 0 */                  
   Print("Running Steppers on core ");
   Println(String(STEPPER_CORE));
}
