void setupSerial () {
  Serial.begin(SerialSpeed);
  delay(100);
  Serial.println("Starting ESP32");
}