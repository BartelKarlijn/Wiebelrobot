void testgyro() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR, 6);

accX = Wire.read()<<8|Wire.read(); 
accY = Wire.read()<<8|Wire.read(); 
accZ = Wire.read()<<8|Wire.read(); 

Serial.print("accX ");
Serial.println(accX);
Serial.print("accY ");
Serial.println(accY);
Serial.print("accZ ");
Serial.println(accZ);

delay(500);
}