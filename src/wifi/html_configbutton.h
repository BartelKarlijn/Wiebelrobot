
String html_configbutton( String omschrijving, float Kx, String handlecodeUp, String handlecodeDo, float Kx_change, String handleChange) {
  String ptr = "<p>";
  ptr += omschrijving;
  ptr += " <a class=\"button button-of\" href=\"/" ; 
  ptr += handlecodeUp;
  ptr += "\">-  </a> " ;
  ptr += Kx;
  ptr += " <a class=\"button button-of\" href=\"/" ; 
  ptr += handlecodeDo;
  ptr += "\">+  </a> Stap= " ;
  ptr += Kx_change;
  ptr += " <a class=\"button button-of\" href=\"/" ; 
  ptr += handleChange;
  ptr += "\">0.1-1-10  </a>\n" ;
  
  return ptr;
}
