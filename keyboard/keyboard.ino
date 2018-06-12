//#include "EEPROM.h"

//================================== LCD ========================================================================
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//================================== TIMEMACHINE =================================================================
uint32_t TM_prev_511ms = 0L;
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
bool MENU_is_menu = false; //show menu or mainScreen

/* Меню состоит из параметров в количестве MENU_item_size
    каждый параметр может принимать значения из соответствующего массива MENU_item_*_values
    в EEPROM для каждого параметра хранится позиция в массиве значений
    Например, параметр_0 хранит в ЕЕПРОМ-ячейке по адресу 0 число 2
    Значит параметр_0== MENU_item_0_values[2] =="SAE"
    Например, параметр_1 хранит в ЕЕПРОМ-ячейке по адресу 1 число 0
    Значит параметр_1== MENU_item_1_values[0] ==3
*/

int8_t MENU_item_num_curr = 0; //curr item num
#define MENU_item_size 4 //count items in menu
String MENU_item_name[MENU_item_size] = {"FISH TYPE", "FEED SECONDS", "FEED COUNT/DAY", "UDO ML/DAY"};
int8_t MENU_item_value_pos[MENU_item_size] = {0, 0, 0, 0}; //Не uint, чтобы делать ротацию по кругу. Хотя 0..255 for EEPROM storage. Item_0 real value = MENU_item_values_0[MENU_item_value_pos[0]]
uint8_t MENU_item_value_pos_size[MENU_item_size] = {3, 5, 3, 7};

//значения параметров, позиция в массиве хранится в ЕЕПРОМ
String MENU_item_0_values[3] = {"NEON", "GUPPI", "SAE"};
uint8_t MENU_item_1_values[5] = {3, 6, 12, 24, 30};
uint8_t MENU_item_2_values[3] = {1, 2, 3};
uint8_t MENU_item_3_values[7] = {1, 2, 3, 4, 6, 8, 10};
// array length = sizeof(myarr)/sizeof(int)  if myarr = array of int => too hard!

//============================== encoder ======================================================
#define ENCODER_pin_1 2 //interrupt
#define ENCODER_pin_2 3
int8_t ENCODER_val = 0;

//========================== EEPROM AT24C32N = 32k bit /8 = 4096 bytes? But address is byte, max 255 :-) =======================================================
#define EEPROM24C_device 0x57 //Адрес устройства

void setup() {
  Wire.begin();
  //LCDi2c_init();
  //CONFIG_load();
  //ENCODER_init();
  Serial.begin(9600);

  EEPROM24C_writeByte(EEPROM24C_device, 1, 1);
  EEPROM24C_writeByte(EEPROM24C_device, 2, 1);
  EEPROM24C_writeByte(EEPROM24C_device, 3, 0);
  EEPROM24C_writeByte(EEPROM24C_device, 4, 118);

  Serial.println(EEPROM24C_readByte(EEPROM24C_device, 1), DEC);
  Serial.println(EEPROM24C_readByte(EEPROM24C_device, 2), DEC);
  Serial.println(EEPROM24C_readByte(EEPROM24C_device, 3), DEC);
  Serial.println(EEPROM24C_readByte(EEPROM24C_device, 4), DEC);



}

void loop() {
  TM_loop();
}


