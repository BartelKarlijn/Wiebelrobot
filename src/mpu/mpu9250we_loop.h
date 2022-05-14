void mpu9250we_loop() {
  xyzFloat gValue = myMPU9250.getGValues();
  xyzFloat gyr = myMPU9250.getGyrValues();
  xyzFloat ang = myMPU9250.getAngles();
  float temp = myMPU9250.getTemperature();
  
  Serial.print("Acceleration in g (x,y,z):");
  Serial.print(gValue.x);
  Serial.print("   ");
  Serial.print(gValue.y);
  Serial.print("   ");
  Serial.print(gValue.z);

  Serial.print("  Gyroscope data in degrees/s: ");
  Serial.print(gyr.x);
  Serial.print("   ");
  Serial.print(gyr.y);
  Serial.print("   ");
  Serial.print(gyr.z);

  Serial.print("  Angles data in ?: ");
  Serial.print(ang.x);
  Serial.print("   ");
  Serial.print(ang.y);
  Serial.print("   ");
  Serial.print(ang.z);

  Serial.print("  Temperature in °C: ");
  Serial.println(temp);

  delay(1000);
}