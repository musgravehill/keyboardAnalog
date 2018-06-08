
//================================== LCD ========================================================================
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//================================== TIMEMACHINE =================================================================
uint32_t TM_prev_21ms = 0L;
uint32_t TM_prev_301ms = 0L;

//================================== KEYBOARD ========================================================================
/*
  -----------GND VCC OUT ------------
  -----723 L ------------------- 0 R----
  --------------- 131 M---------------
  -----488 back ------------------ 321 select ---
*/

#define KEYBOARD_pin A0
#define KEYBOARD_menu 1
#define KEYBOARD_select 2
#define KEYBOARD_left 3
#define KEYBOARD_right 4
#define KEYBOARD_back 5

//======================================= MENU ========================================================================
uint8_t MENU_curr_btn = 0;


void setup() {
  Serial.begin(9600);
  LCDi2c_init();
}

void loop() {
  TM_loop();
}

uint8_t KEYBOARD_check() {
  uint16_t val = analogRead(KEYBOARD_pin);
  if (val < 50) return KEYBOARD_right;
  else if (val < 150) return KEYBOARD_menu;
  else if (val < 350) return KEYBOARD_select;
  else if (val < 500) return KEYBOARD_back;
  else if (val < 800) return KEYBOARD_left;
  else return 0;
}
