float mpu9250we_loop() {
  // xyzFloat gValue = myMPU9250.getGValues();
  // xyzFloat gyr = myMPU9250.getGyrValues();
  // float temp = myMPU9250.getTemperature();
  // float accAngle, deltaGyroAngle, filterAngle;
 
  float Angle = myMPU9250.getPitch();
  return Angle;

  // Serial.print("Acceleration in g (x,y,z):");
  // Serial.print(gValue.x);
  // Serial.print("   ");
  // Serial.print(gValue.y);
  // Serial.print("   ");
  // Serial.print(gValue.z);

  // Serial.print("  Gyroscope data in degrees/s: ");
  // Serial.print(gyr.x);
  // Serial.print("   ");
  // Serial.print(gyr.y);
  // Serial.print("   ");
  // Serial.print(gyr.z);

  // Serial.print("  Temperature in °C: ");
  // Serial.println(temp);

  // Serial.print("Roll - Pitch ");
  // Serial.print(myMPU9250.getRoll());
  // Serial.print("   ");
  // Serial.println(myMPU9250.getPitch());

}