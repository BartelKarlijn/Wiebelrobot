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
  Serial.println(Kp);
  float Ki_eeprom = pref_eeprom.getFloat("Ki_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Ki = ");
  Serial.println(Ki);
  float Kd_eeprom = pref_eeprom.getFloat("Kd_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor Kd = ");
  Serial.println(Kd);

  
  // geen data van eeprom: neem uit code
  if(Kp_eeprom ==0) {  
      Kp = BASE_Kp;
  }
  if(Ki_eeprom ==0) {
      Ki = BASE_Ki;
  }
  if(Kd_eeprom ==0) {
      Kd_eeprom = BASE_Kd;
  }
}

void save_datato_eeprom () {
  pref_eeprom.putFloat("Kp_eeprom", Kp);
  pref_eeprom.putFloat("Ki_eeprom", Ki);
  pref_eeprom.putFloat("Kd_eeprom", Kd);

  Serial.println("Data opgeslagen, nu uitlezen");
  pref_eeprom.end();
  pref_eeprom.begin("wiebelrobot", false);
  float Kp_TEST;
  Kp_TEST = 9999;
  Kp_TEST = pref_eeprom.getFloat("Kp_eeprom", 0);
  Serial.print("Data uitlezen----------------Kp=");
  Serial.println(Kp_TEST);
}