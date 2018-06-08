void MENU_keyboard_check() {
  uint8_t btn_code = KEYBOARD_get();

  if (btn_code > 0) {
    lcd.clear();
  }

  switch (btn_code) {
    case KEYBOARD_menu:
      MENU_btn_menu();
      break;
    case KEYBOARD_left:
      MENU_btn_left();
      break;
    case KEYBOARD_right:
      MENU_btn_right();
      break;
    case KEYBOARD_minus:
      MENU_btn_minus();
      break;
    case KEYBOARD_plus:
      MENU_btn_plus();
      break;
  }
}

void MENU_btn_left() {
  MENU_item_num_curr--;
  if (MENU_item_num_curr < 0) {
    MENU_item_num_curr = MENU_item_size - 1;
  }
}
void MENU_btn_right() {
  MENU_item_num_curr++;
  if (MENU_item_num_curr >= MENU_item_size) {
    MENU_item_num_curr = 0;
  }
}
void MENU_btn_menu() {
  MENU_is_menu = (MENU_is_menu) ? false : true;
}
void MENU_render_menu() {
  lcd.setCursor(0, 0);
  lcd.print("<");
  lcd.setCursor(1, 0);
  lcd.print(MENU_item_name[MENU_item_num_curr]);
  lcd.setCursor(15, 0);
  lcd.print(">");

  lcd.setCursor(0, 1);
  lcd.print("-");
  lcd.setCursor(7, 1);
  lcd.print(MENU_item_value_pos[MENU_item_num_curr]);
  lcd.setCursor(15, 1);
  lcd.print("+");
}

void MENU_btn_plus() {
  MENU_item_value_pos[MENU_item_num_curr]++;
  if (MENU_item_value_pos[MENU_item_num_curr] >= MENU_item_value_pos_size[MENU_item_num_curr]) {
    MENU_item_value_pos[MENU_item_num_curr] = 0;
  }
  CONFIG_save();
}

void MENU_btn_minus() {
  MENU_item_value_pos[MENU_item_num_curr]--;
  if (MENU_item_value_pos[MENU_item_num_curr] < 0) {
    MENU_item_value_pos[MENU_item_num_curr] = 0;
  }
  CONFIG_save();
}

 






