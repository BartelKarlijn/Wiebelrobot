void i2cscan_setup() {
  Wire.begin();
  Println("\nI2C Scanner");
}
 
void i2cscan() {
  byte error, address;
  int nDevices;
  Println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Println("No I2C devices found\n");
  }
  else {
    Println("done\n");
  }
  delay(5000);          
}