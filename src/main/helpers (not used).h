
// on ESP32 Arduino constrain doesn't work
int16_t constr(int16_t value, int16_t mini, int16_t maxi) {
  if (value < mini) return mini;
  else if (value > maxi) return maxi;
  return value;
}
float constrf(float value, float mini, float maxi) {
  if (value < mini) return mini;
  else if (value > maxi) return maxi;
  return value;
}

boolean isValidJoystickValue(uint8_t joystick) {
  return joystick > 20 && joystick < 230;
}

