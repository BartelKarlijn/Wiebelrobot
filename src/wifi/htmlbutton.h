String htmlbutton( bool status, String omschrijving, String handlecode) {
  String ptr = "<p>";
  if (status) {
    ptr += "<a class=\"button button-of\" href=\"/" ; 
    ptr += handlecode;
    ptr += "\">ON  </a>\n" ;
    }
  else {
    ptr += "<a class=\"button button-on\" href=\"/" ; 
    ptr += handlecode;
    ptr += "\">OFF</a>\n" ;
  }
  ptr += omschrijving;
  ptr += "</p>\n";
  return ptr;
}
