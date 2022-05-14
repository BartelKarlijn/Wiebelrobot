void i2cscan() {
  byte error, address;
  int nDevices;

  Wire.begin();
  Println("\nI2C Scanner");
  Println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Print("I2C device found at address 0x");
      if (address<16) {
        Print("0");
      }
      Println(String(address,HEX));
      nDevices++;
    }
    else if (error==4) {
      Print("Unknow error at address 0x");
      if (address<16) {
        Print("0");
      }
      Println(String(address,HEX));
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