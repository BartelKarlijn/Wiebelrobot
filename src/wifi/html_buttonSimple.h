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
}
