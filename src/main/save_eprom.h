// Complete project details at https://RandomNerdTutorials.com/esp32-save-data-permanently-preferences/
// Start instance of Preferences


void get_datafrom_eeprom () {
  // Open Preferences with wiebelrobot namespace. Each application module, library, etc
  // has to use a namespace name to prevent key name collisions. We will open storage in
  // RW-mode (second parameter has to be false).
  // Note: Namespace name is limited to 15 chars.
  pref_eeprom.begin("wiebelrobot", false);

  // Get the counter value, if the key does not exist, return a default value of 0
  // Note: Key name is limited to 15 chars.
  float Kp_eeprom = pref_eeprom.getFloat("Kp_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Kp = ");
  Serial.println(Kp_eeprom);
  float Ki_eeprom = pref_eeprom.getFloat("Ki_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Ki = ");
  Serial.println(Ki_eeprom);
  float Kd_eeprom = pref_eeprom.getFloat("Kd_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Kd = ");
  Serial.println(Kd_eeprom);
  float Angle_eeprom = pref_eeprom.getFloat("Angle_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Angle = ");
  Serial.println(Angle_eeprom);
  String ssid_eeprom = pref_eeprom.getString("ssid_eeprom","");
  Serial.print("Uit eprom uitgelezen waarde voor SSID = ");
  Serial.println(ssid_eeprom);
  String pwd_eeprom = pref_eeprom.getString("pwd_eeprom","");
  Serial.print("Uit eprom uitgelezen waarde voor PWD = ");
  Serial.println(pwd_eeprom);
  

  // geen data van eeprom: neem uit code
  if(Kp_eeprom ==0) { Kp = BASE_Kp;   }
  else              { Kp = Kp_eeprom; }
  if(Ki_eeprom ==0) { Ki = BASE_Ki;   }
  else              { Ki = Ki_eeprom; }
  if(Kd_eeprom ==0) { Kd = BASE_Kd;   }
  else              { Kd = Kd_eeprom; }
  if(Angle_eeprom ==0) { selfBalanceAngleSetpoint = BASE_Angle;   }
  else              { selfBalanceAngleSetpoint = Angle_eeprom; }
}

void save_PIDdatato_eeprom () {
  pref_eeprom.putFloat("Kp_eeprom", Kp);
  pref_eeprom.putFloat("Ki_eeprom", Ki);
  pref_eeprom.putFloat("Kd_eeprom", Kd);
  pref_eeprom.putFloat("Angle_eeprom", selfBalanceAngleSetpoint);

  Serial.println("PID data saved");
}

void save_WIFIdatato_eeprom () {
  pref_eeprom.putString("ssid_eeprom", wifi_ssid);
  pref_eeprom.putString("pwd_eeprom" , wifi_pwd);

  Serial.println("Wifi data saved");
}