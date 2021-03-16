
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}
void handle_Kpup() {
  Kp = Kp + Kp_change;
}
void handle_Kpdo() {
  Kp = Kp - Kp_change;
}
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

