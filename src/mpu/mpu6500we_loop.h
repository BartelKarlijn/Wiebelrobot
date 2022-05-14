void mpu6500we_loop() {
  xyzFloat gValue = myMPU6500.getGValues();
  xyzFloat gyr = myMPU6500.getGyrValues();
  float temp = myMPU6500.getTemperature();
  float resultantG = myMPU6500.getResultantG(gValue);

  Println("Acceleration in g (x,y,z):");
  Print(String(gValue.x));
  Print("   ");
  Print(String(gValue.y));
  Print("   ");
  Println(String(gValue.z));
  Print("Resultant g: ");
  Println(String(resultantG));

  Println("Gyroscope data in degrees/s: ");
  Print(String(gyr.x));
  Print("   ");
  Print(String(gyr.y));
  Print("   ");
  Println(String(gyr.z));

  Print("Temperature in °C: ");
  Println(String(temp));

  Println("********************************************");

  delay(1000);
}