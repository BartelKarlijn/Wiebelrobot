void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten
  AsyncElegantOTA.begin(&webserver);
  
  // Route for root / web page
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html, html_processor);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  webserver.on("/knop", HTTP_GET, [](AsyncWebServerRequest *request) {
    String IDknopString;
    int IDknop;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1)) {
      IDknopString = request->getParam(PARAM_INPUT_1)->value();
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