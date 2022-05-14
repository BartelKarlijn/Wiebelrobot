void task2_async_code( void * pvParameters ) {
  Serial.print("Task2 running on core ");
  Serial.println(String(xPortGetCoreID()));

  setup_AsyncWebserver();
}

void setup_task2_async() {
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    task2_async_code,   /* Task function. */
                    "task2_async",      /* name of task. */
                    10000,                /* Stack size of task */
                    NULL,                 /* parameter of the task */
                    ASYNC_CORE_PRIO,    /* priority of the task. 0=idle, 1=lowest prio*/
                    &task2_async,       /* Task handle to keep track of created task */
                    ASYNC_CORE);        /* pin task to core 1 instead of default 0 */                  
   Print("Running AsyncWebserver on core ");
   Println(String(ASYNC_CORE));
}
