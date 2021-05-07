void getRotation(int16_t* x, int16_t* y, int16_t* z) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR, 6);
  *x = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroX_offset;
  *y = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroY_offset;
  *z = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroZ_offset;
}

void getCalibrationParams() {
  gyroX_offset = gyroX_preset;
  gyroY_offset = gyroY_preset;
  gyroZ_offset = gyroZ_preset;
  
  Serial.print("gyroX_offset: ");
  Serial.println(gyroX_offset);
  Serial.print("gyroY_offset: ");
  Serial.println(gyroY_offset);
  Serial.print("gyroZ_offset: ");
  Serial.println(gyroZ_offset);
}

void calibrateGyro() {
  int32_t x = 0, y = 0, z = 0; // Compiler warning if not set.

  Serial.println("Calibrating gyro, please wait");

  for (int i = 0; i < gyroCalibrationLoops; i++) {
    getRotation(&gyroX, &gyroY, &gyroZ);
    x += gyroX;
    y += gyroY;
    z += gyroZ;
    delayMicroseconds(PERIOD); // simulate the main program loop time 
  }

  gyroX_offset = x / gyroCalibrationLoops;
  gyroY_offset = y / gyroCalibrationLoops;
  gyroZ_offset = z / gyroCalibrationLoops;

  Serial.print("last gyroX Y Z values ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(z);

  Serial.print("gyroX_offset: ");
  Serial.println(gyroX_offset);
  Serial.print("gyroY_offset: ");
  Serial.println(gyroY_offset);
  Serial.print("gyroZ_offset: ");
  Serial.println(gyroZ_offset);
}

// on ESP32 Arduino constrain doesn't work
int16_t constr(int16_t value, int16_t mini, int16_t maxi) {
  if (value < mini) return mini;
  else if (value > maxi) return maxi;
  return value;
}
float constrf(float value, float mini, float maxi) {
  if (value < mini) return mini;
  else if (value > maxi) return maxi;
  return value;
}

void getAcceleration(int16_t* x, int16_t* y, int16_t* z) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR, 6);
  *x = constr((((int16_t)Wire.read()) << 8) | Wire.read(), -ACC_SCALE_FACTOR, ACC_SCALE_FACTOR);
  *y = constr((((int16_t)Wire.read()) << 8) | Wire.read(), -ACC_SCALE_FACTOR, ACC_SCALE_FACTOR);
  *z = constr((((int16_t)Wire.read()) << 8) | Wire.read(), -ACC_SCALE_FACTOR, ACC_SCALE_FACTOR);
}

