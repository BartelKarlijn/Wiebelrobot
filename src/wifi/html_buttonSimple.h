String html_buttonSimple(int idKnop, String txtOpKnop, String txtVoorKnop) {
  String ptr = "<tr><td>\n";
  ptr += txtVoorKnop;
  ptr += "</td><td><a class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += idKnop;
  ptr += "\">" ;
  ptr += txtOpKnop;
  ptr += "</a></td></tr>\n";
  return ptr;
}
