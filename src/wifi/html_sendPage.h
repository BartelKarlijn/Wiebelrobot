  const char index_html[] PROGMEM = R"rawliteral(
    <!DOCTYPE html> <html>
    <head><meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no>
    <title>Wiebelrobot</title>
    <link rel="icon" href="data:,">
    <style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: left;}
    body{margin-top: 50px;}
    h1 {color: #444444;margin: 50px auto 30px; text-align: center;}
    h3 {color: #444444;margin-bottom: 50px; text-align: center;}
    .button {display: inline;width: 60px;background-color: #3498db;border: none;color: white;padding: 10px 10px;text-decoration: none;font-size: 25px;margin: 10px auto 25px;cursor: pointer;border-radius: 4px; margin-bottom: 50px;}
    .button-on {background-color: #3498db;}
    .button-on:active {background-color: #2980b9;}
    .button-of {background-color: #34495e;}
    .button-of:active {background-color: #2c3e50;}
    p {font-size: 20px;color: #888;margin-bottom: 30px;}
    </style>
    </head>
    <body>
      <h1>Wiebelrobot instellen</h1>
      %BUTTONPLACEHOLDER%
      <script>function toggleCheckbox(element) {
        var xhr = new XMLHttpRequest();
          if(element.checked){ xhr.open("GET", "/update?output="+element.id+"&state=1", true); }
          else { xhr.open("GET", "/update?output="+element.id+"&state=0", true); }
        xhr.send();
      }
    </script>
  </body>
  </html>
  )rawliteral";
  
// Onderstaand mag allemaal weg  
String html_sendPage () {
  String ptr = "<!DOCTYPE html> <html>\n";
  /*
  // Onderstaande tag maakt web pagina responsive in elke browser
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  // Title van het tabblad
  ptr +="<title>Wiebelrobot</title>\n";
  // Prevents request on the favicon, what we don't have.  Without next line, ESP32 would receive a request for favicon every time we access the web server
  ptr +="<link rel=\"icon\" href=\"data:,\">\n";
  // Adding CSS styles
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
  // finishing header
  ptr +="</head>\n";

  // body
  ptr += "<body>\n";
  ptr +="<h1>Wiebelrobot instellen</h1>\n";
  // Placeholder for buttons
  ptr += "%BUTTONPLACEHOLDER%\n";

  // Javascript to make a GET request when toggling buttons
  ptr += "<script>function toggleCheckbox(element) {";
  ptr += "var xhr = new XMLHttpRequest();";
  ptr += "if(element.checked){ xhr.open(\"GET\", \"/update?output=\"+element.id+\"&state=1\", true); }";
  ptr += "else { xhr.open(\"GET\", \"/update?output=\"+element.id+\"&state=0\", true); }";
  ptr += "xhr.send();";
  ptr += "}";
  ptr += "</script>";
  // closing everything
  ptr +="</body>\n";
  ptr +="</html>\n";
  */
  return ptr;
} 
 