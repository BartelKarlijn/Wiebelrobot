void mpu9250we_loop() {
  xyzFloat accRaw;
  xyzFloat gyrRaw;
  xyzFloat corrAccRaw;
  xyzFloat corrGyrRaw;
  accRaw = myMPU9250.getAccRawValues();
  gyrRaw = myMPU9250.getGyrRawValues();
  corrAccRaw = myMPU9250.getCorrectedAccRawValues();
  corrGyrRaw = myMPU9250.getCorrectedGyrRawValues();
  
  Print("Acceleration raw:");
  Print(String(accRaw.x));
  Print("   ");
  Print(String(accRaw.y));
  Print("   ");
  Print(String(accRaw.z));

  Print("Gyroscope raw:");
  Print(String(gyrRaw.x));
  Print("   ");
  Print(String(gyrRaw.y));
  Print("   ");
  Println(String(gyrRaw.z));

//  Println("Acceleration raw values with offset:");
//  Print(String(corrAccRaw.x));
//  Print("   ");
//  Print(String(corrAccRaw.y));
//  Print("   ");
//  Println(String(corrAccRaw.z));
//
//  Println("Gyroscope raw values with offset:");
//  Print(String(corrGyrRaw.x));
//  Print("   ");
//  Print(String(corrGyrRaw.y));
//  Print("   ");
//  Println(String(corrGyrRaw.z)); 
  delay(1000);
}