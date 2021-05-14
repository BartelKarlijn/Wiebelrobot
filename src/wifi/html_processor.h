String html_processor(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += html_buttonUpDown(oms_Kp, id_Kpra, id_Kpup, id_Kpdo, Kp, Kp_change);
    buttons += html_buttonUpDown(oms_Ki, id_Kira, id_Kiup, id_Kido, Ki, Ki_change);
    buttons += html_buttonUpDown(oms_Kd, id_Kdra, id_Kdup, id_Kddo, Kd, Kd_change);
    buttons += html_buttonUpDown(oms_An, id_Anra, id_Anup, id_Ando, selfBalanceAngleSetpoint, An_change);
    buttons += html_buttonSimple(id_ShowAngle, String(currentAngle), oms_ShowAngle);
    buttons += html_buttonSimple(id_SaveConfig, "", oms_SaveConfig);
    buttons += html_buttonSimple(id_Restart, "", oms_Restart);
    
    return buttons;
  }
  return String();
}
