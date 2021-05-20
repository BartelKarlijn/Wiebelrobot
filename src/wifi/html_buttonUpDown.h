String html_buttonUpDown( String omschrijving, int IDrange, int IDup, int IDdown, float Kx, float Kx_change) {
/*
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
*/

  String ptr = "<tr><td>\n";
  ptr += omschrijving;
  ptr += "</td><td><do class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += IDdown;
  ptr += "\"> - </do></td><td>\n" ;
  ptr += Kx;
  ptr += "</td><td><up class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += IDup;
  ptr += "\"> + </up></td><td> Stap= </td><td>" ;
  ptr += Kx_change;
  ptr += "</td><td> <ch class=\"button button-on\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += IDrange;
  ptr += "\"> 1-10-100 </ch></td></tr>\n" ;

  return ptr;
}
