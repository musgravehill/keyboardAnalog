void ENCODER_init() {
  attachInterrupt(0, ENCODER_interrupt, FALLING); //d2
}

void ENCODER_interrupt() {
  if (digitalRead(ENCODER_pin_2)) {
    ENCODER_val++;
  } else {
    ENCODER_val--;
  }
}
