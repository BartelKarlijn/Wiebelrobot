const char config_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html> <html>
<head><title>Wiebelrobot</title>
<meta name="viewport" content="width=device-width, initial-scale=1", user-scalable=no>
<link rel="icon" href="data:,">
<style>
  html { font-family:Helvetica; display:inline-block; margin:50px auto; text-align:left;color:#444444;}
  body{margin-top:50px;}
  h1 {text-align:center;}
  h4 {text-align:right;}
  tr td {height:50px}
  .button {display: inline;width: 60px;background-color: #3498db;border: none;color: white;padding: 10px 10px;text-decoration: none;font-size: 25px;margin: 10px auto 25px;cursor: pointer;border-radius: 4px; margin-bottom: 50px;}
  .button-on {background-color: #3498db;}
  .button-on:active {background-color: #2980b9;}
  .button-of {background-color: #34495e;}
  .button-of:active {background-color: #2c3e50;}
</style>
</head>
<body>
  %BUTTONPLACEHOLDER%
<script>function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/knop?output="+element.id, true);
  xhr.send();
  setTimeout("location.reload()", 200);
}</script>
</body>
</html>
)rawliteral";
