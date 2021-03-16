void Task1code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;) {
//  handle all wifi requests in endless loop
//    server.handleClient();

  }
}

void setupTask1() {
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task. 0=idle, 1=lowest prio*/
                    &Task1,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 instead of default 0 */                  
   Serial.println("Second Core setup");
  
}

