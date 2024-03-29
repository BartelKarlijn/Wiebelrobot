String SendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  // Title
  ptr +="<title>Wiebelrobot</title>\n";
  // CSS to style the on/off buttons 
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: left;}\n";
  ptr +="body{margin-top: 50px;}\n";
  ptr +="h1 {color: #444444;margin: 50px auto 30px; text-align: center;}\n";
  ptr +="h3 {color: #444444;margin-bottom: 50px; text-align: center;}\n";
  ptr +=".button {display: inline;width: 60px;background-color: #3498db;border: none;color: white;padding: 10px 10px;text-decoration: none;font-size: 25px;margin: 10px auto 25px;cursor: pointer;border-radius: 4px; margin-bottom: 50px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-of {background-color: #34495e;}\n";
  ptr +=".button-of:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 20px;color: #888;margin-bottom: 30px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
// bodytitel
  ptr += "<body>\n";
  ptr +="<h1>Wiebelrobot instellen</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode on ESP32</h3>\n";

//knoppen
  ptr +=html_configbutton(oms_Kp, Kp, hdl_Kpdo, hdl_Kpup);
  ptr +=html_configbutton(oms_Ki, Ki, hdl_Kido, hdl_Kiup);
  ptr +=html_configbutton(oms_Kd, Kd, hdl_Kddo, hdl_Kdup);
  ptr +=htmlbutton(true, oms_Save, hdl_Save);

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
