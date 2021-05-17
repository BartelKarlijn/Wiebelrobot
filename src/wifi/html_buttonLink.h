String html_buttonLink(String txtOpKnop, String path) {
  String ptr = "<p>";
  ptr += "<h4><a class=\"button button-of\" href=\"";
  ptr += path;
  ptr += "\">" ;
  ptr += txtOpKnop;
  ptr += "</a></h4>\n";
  ptr += "</p>\n";

  return ptr;
}
