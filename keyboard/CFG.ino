void CONFIG_load() {
  //MENU_item_value_pos[4] = {0, 0, 0, 0}; //0..255 for EEPROM storage. Item_0 real value = MENU_item_values_0[MENU_item_value_pos[0]]
  for (int address = 0; address < MENU_item_size; address++ ) {
    MENU_item_value_pos[address] = EEPROM.read(address);
  }
}

void CONFIG_save() {
  //0..255 for EEPROM storage. Item_0 real value = MENU_item_values_0[MENU_item_value_pos[0]]
  EEPROM.write(MENU_item_num_curr, MENU_item_value_pos[MENU_item_num_curr]);
}
