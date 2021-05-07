
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
//MPU6050 mpu;   // staat in main
//MPU6050 mpu(0x69); // <-- use for AD0 high

// to see yaw/pitch/roll angles (in degrees) calculated from the quaternions coming
// from the FIFO. Note this also requires gravity vector calculations.
// Also note that yaw/pitch/roll angles suffer from gimbal lock (for
// more info, see: http://en.wikipedia.org/wiki/Gimbal_lock)

// join I2C bus (I2Cdev library doesn't do this automatically)
void setupMPUdmp() {
  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties

  // initialize device
  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();

  // start message
  Serial.println("\nMPU6050 Calibration Sketch");
  delay(2000);
  Serial.println("\nYour MPU6050 should be placed in horizontal position, with package letters facing up. \nDon't touch it until you see a finish message.\n");
  delay(3000);

  // verify connection
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  delay(1000);

  // load and configure the DMP
  Serial.println(F("Initializing DMP..."));
  delay(500);
  devStatus = mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(preset_XGyroOffset);
  mpu.setYGyroOffset(preset_YGyroOffset);
  mpu.setZGyroOffset(preset_ZGyroOffset);
  mpu.setXAccelOffset(preset_XAccelOffset);
  mpu.setYAccelOffset(preset_YAccelOffset);
  mpu.setZAccelOffset(preset_ZAccelOffset);


}