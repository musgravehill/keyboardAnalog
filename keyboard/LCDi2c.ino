void LCDi2c_init() {
  lcd.init();
  lcd.backlight();
  lcd.print("MAIN SCREEN");
}
void LCDi2c_render() {
  if (MENU_is_menu) {
    MENU_render_menu();
  } else {
    LCDi2c_render_mainScreen();
  }
}

void LCDi2c_render_mainScreen() {
  lcd.setCursor(0, 0);
  lcd.print("MAIN SCREEN");
  lcd.setCursor(0, 1);
  lcd.print("PRESS M for menu");
}
