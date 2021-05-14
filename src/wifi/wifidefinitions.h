// Wifi
// SSID settings
const char* ssid = mySSID;
const char* password = myPASSWORD;

//const char* ssid = "WiebelRobot";  // Enter SSID here
//const char* password = "wiebelrobot";  //Enter Password here

/* Put IP Address details */
//IPAddress local_ip(192,168,1,1);
//IPAddress gateway(192,168,1,1);
//IPAddress subnet(255,255,255,0); 

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
//WebServer server(80);
