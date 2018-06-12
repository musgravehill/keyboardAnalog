void TM_loop() {
  uint32_t  TM_currMillis = millis();
  if ((TM_currMillis - TM_prev_511ms) > 511L) {
    TM_511ms();
    TM_prev_511ms = TM_currMillis;
  }
  if ((TM_currMillis - TM_prev_301ms) > 301L) {
    TM_301ms();
    TM_prev_301ms = TM_currMillis;
  }
}

void TM_511ms() {
  //Serial.println(ENCODER_val/4);
}

void TM_301ms() {
  MENU_keyboard_check();
  LCDi2c_render();
}


