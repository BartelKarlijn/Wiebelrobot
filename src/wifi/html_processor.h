String html_processorConfig(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>Wiebelrobot instellen</h1><table>";
    buttons += html_buttonUpDown(oms_Kp, id_Kpra, id_Kpup, id_Kpdo, Kp, Kp_change);
    buttons += html_buttonUpDown(oms_Ki, id_Kira, id_Kiup, id_Kido, Ki, Ki_change);
    buttons += html_buttonUpDown(oms_Kd, id_Kdra, id_Kdup, id_Kddo, Kd, Kd_change);
    buttons += html_buttonUpDown(oms_An, id_Anra, id_Anup, id_Ando, selfBalanceAngleSetpoint, An_change);

    buttons += html_buttonSimple(id_ShowAngle, String(currentAngle), oms_ShowAngle);
    buttons += html_buttonSimple(id_SaveConfig, "SAVE", oms_SaveConfig);
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += "</table>";
    
    buttons += html_buttonLink("Terug naar Controller", hdlController);
    buttons += html_buttonLink("Wifi Management", hdlWifiPWD);
    buttons += html_buttonLink("Firmware update", hdlUpdate);
    
    return buttons;
  }
  return String();
}

String html_processorController(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += html_joystickCode;
    buttons += "<h1>Wiebelrobot controller</h1>";
    buttons += html_joystickObject;
    buttons += html_buttonLink("naar Configuratie", hdlConfig);
    return buttons;
  }
  return String();
}

String html_processorWifi(const String& var){
// Replaces placeholder with wifi section
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>Wifi instellen</h1>";
    buttons += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value=\"scan\"></form>";
    buttons += wifi_st;
    buttons += "</p><form method='get' action='setting'><label>SSID: </label><input name='ssid' length=32><input name='pass' length=64><input type='submit'></form>";
    buttons += html_buttonLink("naar Configuratie", hdlConfig);
    return buttons;
  }
  return String();
}
