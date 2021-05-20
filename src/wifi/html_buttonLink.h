String html_buttonLink(String txtOpKnop, String path) {
  String ptr = "<h4><a class=\"button button-of\" href=\"";
  ptr += path;
  ptr += "\">" ;
  ptr += txtOpKnop;
  ptr += "</a></h4>\n";

  return ptr;
}
