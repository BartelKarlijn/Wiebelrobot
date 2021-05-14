String html_buttonUpDown( String omschrijving, int IDrange, int IDup, int IDdown, float Kx, float Kx_change) {
  String ptr = "<p>";
  ptr += omschrijving;
  ptr += "<do class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\" "; 
  ptr += IDdown;
  ptr += "\">-  </do> \n" ;
  ptr += Kx;
  ptr += " <up class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\" "; 
  ptr += IDup;
  ptr += "\">+  </up> Stap=\n" ;
  ptr += Kx_change;
  ptr += " <ra class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\" "; 
  ptr += IDrange;
  ptr += "\"> x10 </ra><p>\n" ;


/*
String html_buttonSimple(int idKnop, String txtOpKnop, String txtVoorKnop) {
  String ptr = "<p>";
  ptr += txtVoorKnop;
  ptr += "<a class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\" "; 
  ptr += idKnop;
  ptr += "\">\n" ;
  ptr += txtOpKnop;
  ptr += "</a>";
  ptr += "</p>\n";
  return ptr;
*/


/*
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
  ptr += "\">1-10-100  </a>\n" ;
  */

  return ptr;
}
