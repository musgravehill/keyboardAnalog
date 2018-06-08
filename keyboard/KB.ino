uint8_t KEYBOARD_get() {
  uint16_t val = analogRead(KEYBOARD_pin);
  if (val < 50) return KEYBOARD_left;
  else if (val < 150) return KEYBOARD_menu;
  else if (val < 350) return KEYBOARD_right;
  else if (val < 500) return  KEYBOARD_plus;
  else if (val < 800) return KEYBOARD_minus;
  else return 0;
}
