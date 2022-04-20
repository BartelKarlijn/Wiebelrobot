//https://github.com/bobboteck/JoyStick/blob/master/joy.js
const char html_joystickCode[] PROGMEM = R"rawliteral(
<script>
  JoyStick=function(t,e){var i=void 0===(e=e||{}).title?"joystick":e.title,n=void 0===e.width?0:e.width,o=void 0===e.height?0:e.height,r=void 0===e.internalFillColor?"#00AA00":e.internalFillColor,h=void 0===e.internalLineWidth?2:e.internalLineWidth,a=void 0===e.internalStrokeColor?"#003300":e.internalStrokeColor,d=void 0===e.externalLineWidth?2:e.externalLineWidth,f=void 0===e.externalStrokeColor?"#008000":e.externalStrokeColor,l=void 0===e.autoReturnToCenter||e.autoReturnToCenter,s=document.getElementById(t),c=document.createElement("canvas");c.id=i,0===n&&(n=s.clientWidth),0===o&&(o=s.clientHeight),c.width=n,c.height=o,s.appendChild(c);var u=c.getContext("2d"),g=0,v=2*Math.PI,p=(c.width-(c.width/2+10))/2,C=p+5,w=p+30,m=c.width/2,L=c.height/2,E=c.width/10,P=-1*E,S=c.height/10,k=-1*S,W=m,T=L;function G(){u.beginPath(),u.arc(m,L,w,0,v,!1),u.lineWidth=d,u.strokeStyle=f,u.stroke()}function x(){u.beginPath(),W<p&&(W=C),W+p>c.width&&(W=c.width-C),T<p&&(T=C),T+p>c.height&&(T=c.height-C),u.arc(W,T,p,0,v,!1);var t=u.createRadialGradient(m,L,5,m,L,200);t.addColorStop(0,r),t.addColorStop(1,a),u.fillStyle=t,u.fill(),u.lineWidth=h,u.strokeStyle=a,u.stroke()}"ontouchstart"in document.documentElement?(c.addEventListener("touchstart",function(t){g=1},!1),c.addEventListener("touchmove",function(t){t.preventDefault(),1===g&&t.targetTouches[0].target===c&&(W=t.targetTouches[0].pageX,T=t.targetTouches[0].pageY,"BODY"===c.offsetParent.tagName.toUpperCase()?(W-=c.offsetLeft,T-=c.offsetTop):(W-=c.offsetParent.offsetLeft,T-=c.offsetParent.offsetTop),u.clearRect(0,0,c.width,c.height),G(),x())},!1),c.addEventListener("touchend",function(t){g=0,l&&(W=m,T=L);u.clearRect(0,0,c.width,c.height),G(),x()},!1)):(c.addEventListener("mousedown",function(t){g=1},!1),c.addEventListener("mousemove",function(t){1===g&&(W=t.pageX,T=t.pageY,"BODY"===c.offsetParent.tagName.toUpperCase()?(W-=c.offsetLeft,T-=c.offsetTop):(W-=c.offsetParent.offsetLeft,T-=c.offsetParent.offsetTop),u.clearRect(0,0,c.width,c.height),G(),x())},!1),c.addEventListener("mouseup",function(t){g=0,l&&(W=m,T=L);u.clearRect(0,0,c.width,c.height),G(),x()},!1)),G(),x(),this.GetX=function(){return((W-m)/C*100).toFixed()},this.GetY=function(){return((T-L)/C*100*-1).toFixed()}};
</script>
)rawliteral";

const char html_joystickObject[] PROGMEM = R"rawliteral(
<div style="width:300px;height:350px;margin:auto">
<div id="joydiv" style="width:300px;height:300px;margin:auto"></div>
X :<input id="joy3X" type="text" /></br>
Y :<input id="joy3Y" type="text" />				
</div>
<script type="text/javascript">
var joyParam = { "title": "js" };
var Joy = new JoyStick('joydiv', joyParam);
var joyX = document.getElementById("joy3X");
var joyY = document.getElementById("joy3Y");
returnJoy(joyX);
setInterval(function(){ joyX.value=Joy.GetX(); }, 200);
setInterval(function(){ joyY.value=Joy.GetY(); }, 200);
</script>
)rawliteral";

String html_joystickObjectNew(int varX, int varY) {
  String ptr = "<div style=\"width:300px;height:350px;margin:auto\">\n";
  ptr += "<div id=\"joydiv\" style=\"width:300px;height:300px;margin:auto\"></div>";
  ptr += "X :<input id=\"joy3X\" type=\"text\" /></br>\n";
  ptr += "Y :<input id=\"joy3Y\" type=\"text\" />\n";
  ptr += "</div>\n";
  ptr += "<script type=\"text/javascript\">\n";
  ptr += "var joyParam = { \"title\": \"js\" };\n";
  ptr += "var Joy = new JoyStick('joydiv', joyParam);\n";
  ptr += "var joyX = document.getElementById(\"joy3X\");\n";
  ptr += "var joyY = document.getElementById(\"joy3Y\");\n";
  ptr += "setInterval(function(){ joyX.value=Joy.GetX(); }, 200);\n";
  ptr += "setInterval(function(){ joyY.value=Joy.GetY(); }, 200);\n";
  ptr += "</script>";

  return ptr;
}