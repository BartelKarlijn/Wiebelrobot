void mpu9250we_loop() {
  xyzFloat accRaw;
  xyzFloat gyrRaw;
  xyzFloat corrAccRaw;
  xyzFloat corrGyrRaw;
  accRaw = myMPU9250.getAccRawValues();
  gyrRaw = myMPU9250.getGyrRawValues();
  corrAccRaw = myMPU9250.getCorrectedAccRawValues();
  corrGyrRaw = myMPU9250.getCorrectedGyrRawValues();
  
  Serial.println("Acceleration raw values without offset:");
  Serial.print(accRaw.x);
  Serial.print("   ");
  Serial.print(accRaw.y);
  Serial.print("   ");
  Serial.println(accRaw.z);

  Serial.println("Gyroscope raw values without offset:");
  Serial.print(gyrRaw.x);
  Serial.print("   ");
  Serial.print(gyrRaw.y);
  Serial.print("   ");
  Serial.println(gyrRaw.z);

  Serial.println("Acceleration raw values with offset:");
  Serial.print(corrAccRaw.x);
  Serial.print("   ");
  Serial.print(corrAccRaw.y);
  Serial.print("   ");
  Serial.println(corrAccRaw.z);

  Serial.println("Gyroscope raw values with offset:");
  Serial.print(corrGyrRaw.x);
  Serial.print("   ");
  Serial.print(corrGyrRaw.y);
  Serial.print("   ");
  Serial.println(corrGyrRaw.z); delay(10000);
}