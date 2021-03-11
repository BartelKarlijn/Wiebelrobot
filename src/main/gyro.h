void getRotation(int16_t* x, int16_t* y, int16_t* z) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR, 6);
  *x = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroX_calibration;
  *y = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroY_calibration;
  *z = ((((int16_t)Wire.read()) << 8) | Wire.read()) - gyroZ_calibration;
}


void calibrateGyro() {
  int32_t x = 0, y = 0, z = 0; // Compiler warning if not set.

  for (int i = 0; i < 500; i++) {
    getRotation(&gyroX, &gyroY, &gyroZ);
    x += gyroX;
    y += gyroY;
    z += gyroZ;
    delayMicroseconds(PERIOD); // simulate the main program loop time ??
  }
  gyroX_calibration = x / 500;
  gyroY_calibration = y / 500;
  gyroZ_calibration = z / 500;

Serial.print("gyroX_calibration: ");
Serial.println(x );
Serial.print("gyroY_calibration: ");
Serial.println(y );
Serial.print("gyroZ_calibration: ");
Serial.println(z );
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

