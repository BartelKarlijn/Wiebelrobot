void setup_mpu() {
  Wire.begin();
//  Wire.setClock(400000L);

  //By default the MPU-6050 sleeps. So we have to wake it up.
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);                     //We want to write to the PWR_MGMT_1 register (6B hex)
  Wire.write(0x00);                     //Set the register bits as 00000000 to activate the gyro
  Wire.endTransmission();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1B);                     //We want to write to the GYRO_CONFIG register (1B hex)
  Wire.write(GYRO_FULL_SCALE_RANGE);
  Wire.endTransmission();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1C);                     //We want to write to the ACCEL_CONFIG register (1A hex)
  Wire.write(ACC_FULL_SCALE_RANGE);
  Wire.endTransmission();
  //Set some filtering to improve the raw data.
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1A);                     //We want to write to the CONFIG register (1A hex)
  Wire.write(0x03);                     //Set the register bits as 00000011 (Set Digital Low Pass Filter to ~43Hz)
  Wire.endTransmission();
 
  calibrateGyro();
  Serial.println("Gyro calibrated");

}
