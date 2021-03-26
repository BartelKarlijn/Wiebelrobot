
String html_configbutton( String omschrijving, float Kx, String handlecodeUp, String handlecodeDo) {
  String ptr = "<p>";
  ptr += omschrijving;
  ptr += " <a class=\"button button-of\" href=\"/" ; 
  ptr += handlecodeUp;
  ptr += "\">-  </a> " ;
  ptr += Kx;
  ptr += " <a class=\"button button-of\" href=\"/" ; 
  ptr += handlecodeDo;
  ptr += "\">+  </a>\n" ;
  
  return ptr;
}
