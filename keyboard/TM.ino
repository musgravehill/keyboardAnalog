void TM_loop() {
  uint32_t  TM_currMillis = millis();
  if ((TM_currMillis - TM_prev_21ms) > 21L) {
    TM_21ms();
    TM_prev_21ms = TM_currMillis;
  }
  if ((TM_currMillis - TM_prev_301ms) > 301L) {
    TM_301ms();
    TM_prev_301ms = TM_currMillis;
  }
}

void TM_21ms() {
 
}

void TM_301ms() {  
 
}


