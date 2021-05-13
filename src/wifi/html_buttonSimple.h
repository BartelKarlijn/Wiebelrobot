String html_buttonSimple(int idKnop, String txtOpKnop, String txtNaKnop) {
  String ptr = "<p>";
  
  ptr += "<a class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\" "; 
  ptr += idKnop;
  ptr += "\">\n" ;
  ptr += txtOpKnop;
  ptr += "</a>";
  ptr += txtNaKnop;
  ptr += "</p>\n";
  return ptr;
}
