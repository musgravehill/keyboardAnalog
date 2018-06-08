void MENU_keyboard_check() {
  uint8_t btn_code = KEYBOARD_get();

  switch (btn_code) {
    case KEYBOARD_menu:
      MENU_btn_menu();
      break;
    case KEYBOARD_left:
      MENU_item_num--;
      if (MENU_item_num < 0) {
        MENU_item_num = MENU_item_size - 1;
      }
      break;
    case KEYBOARD_right:
      MENU_item_num++;
      if (MENU_item_num >= MENU_item_size) {
        MENU_item_num = 0;
      }
      break;
    case KEYBOARD_minus:

      break;
    case KEYBOARD_plus:

      break;

  }
}

void MENU_btn_menu() {
  MENU_is_menu = (MENU_is_menu) ? false : true;
}


void MENU_render_menu() {
  lcd.setCursor(0, 0);
  lcd.print(MENU_item_name[MENU_item_num]);
  lcd.setCursor(0, 1);
  lcd.print("< curr_val >");

}

