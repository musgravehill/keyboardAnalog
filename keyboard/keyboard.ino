
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
#define KEYBOARD_plus 2
#define KEYBOARD_left 3
#define KEYBOARD_right 4
#define KEYBOARD_minus 5

//======================================= MENU ========================================================================
bool MENU_is_menu = false;
uint8_t MENU_item_num = 0;

#define MENU_item_size 3
String MENU_item_name[3] = {"UDO count ml", "FEEDER feed seconds", "FEEDER count feed"};


void setup() {
  Serial.begin(9600);
  LCDi2c_init();
}

void loop() {
  TM_loop();
}


