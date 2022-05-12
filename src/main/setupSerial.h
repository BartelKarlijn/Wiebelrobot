void setupSerial () {
  Serial.begin(SerialSpeed);
  delay(100);
  Serial.println("Starting ESP32");
  Serial.print("Setup running on core: ");
  Serial.println(xPortGetCoreID());
}