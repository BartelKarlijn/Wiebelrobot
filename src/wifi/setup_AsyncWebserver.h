void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  AsyncElegantOTA.begin(&webserver);

  // Route for Wifi Passwoord onderhoud
  webserver.on(hdlWifiPWD, HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("Wifi config pagina");
    request->send_P(200, "text/html", config_html, html_processorWifi);
  });

  // Opvangen als wifi data bewaard worden
  webserver.on(hdlWifiSave, HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("Wifi connection parameters");
    if (request->hasParam(PARAM_ssid)) {
      wifi_ssid = request->getParam(PARAM_ssid)->value();
    }
    else {
      wifi_ssid = "";
    }
    if (request->hasParam(PARAM_pwd)) {
      wifi_pwd = request->getParam(PARAM_pwd)->value();
    }
    else {
      wifi_pwd = "";
    }
    save_WIFIdatato_eeprom (); 
    Serial.println("Wifi SSID and PWD saved; please reboot ESP32");
    request->send_P(200, "text/html", config_html, html_processorWifi);
  });


  // Route for root / web page (controller)
  webserver.on(hdlController, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", config_html, html_processorController);
  });

  // Route for configuration
  webserver.on(hdlConfig, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", config_html, html_processorConfig);
  });

// Verwerk joystick
  webserver.on(hdlJoystick, HTTP_PUT, [](AsyncWebServerRequest *request) {
    // PUT request binnen gelezen
    String IDknopString;
    if (request->hasParam(PARAM_joyX)) {
      IDknopString = request->getParam(PARAM_joyX)->value();
      joystickX = IDknopString.toInt();
    }
    else {
      joystickX = 0;
    }
    if (request->hasParam(PARAM_joyY)) {
      IDknopString = request->getParam(PARAM_joyY)->value();
      joystickY = IDknopString.toInt();
    }
    else {
      joystickY = 0;
    }
    request->send(200, "text/plain", "OK");
  });

  // Verwerk als er op een knop wordt gedrukt
  webserver.on(hdlKnop, HTTP_GET, [](AsyncWebServerRequest *request) {
    String IDknopString;
    int IDknop;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_output)) {
      IDknopString = request->getParam(PARAM_output)->value();
      IDknop = IDknopString.toInt();
    }
    else {
      IDknop = 0;
    }

    Serial.print("knop= ");
    Serial.println(IDknop);
    switch (IDknop) {
    //Kp
    case id_Kpdo:
      Kp = buttonChangeUp(Kp, -Kp_change, "Kp");
      break;
    case id_Kpup:
      Kp = buttonChangeUp(Kp, +Kp_change, "Kp");
      break;
    case id_Kpra:
      Kp_change = buttonChangeStep(Kp_change, "Kp step");
      break;
    //Ki
    case id_Kido:
      Ki = buttonChangeUp(Ki, -Kp_change, "Ki");
      break;
    case id_Kiup:
      Ki = buttonChangeUp(Ki, +Kp_change, "Ki");
      break;
    case id_Kira:
      Ki_change = buttonChangeStep(Ki_change, "Ki step");
      break;
    //Kd
    case id_Kddo:
      Kd = buttonChangeUp(Kd, -Kd_change, "Kd");
      break;
    case id_Kdup:
      Kd = buttonChangeUp(Kd, +Kd_change, "Kd");
      break;
    case id_Kdra:
      Kd_change = buttonChangeStep(Kd_change, "Kd step");
      break;
    //An
    case id_Ando:
      selfBalanceAngleSetpoint = buttonChangeUp(selfBalanceAngleSetpoint, -An_change, "Angle");
      break;
    case id_Anup:
      selfBalanceAngleSetpoint = buttonChangeUp(selfBalanceAngleSetpoint, +An_change, "Angle");
      break;
    case id_Anra:
      An_change = buttonChangeStep(An_change, "Angle step");
      break;
    //Gemeten hoek
    case id_ShowAngle:
      Serial.println("Do nothing");
      break;
    //Save PID
    case id_SaveConfig:
      buttonChangeSavePID();
      break;
    //Restart
    case id_Restart:
      buttonChangeRestart();
      break;

    default:
      break;
    }  // einde switch
    
    request->send(200, "text/plain", "OK");

  });

  // Start server
  webserver.begin();
}