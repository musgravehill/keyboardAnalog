
//0..255 DEC
void EEPROM24C_writeByte(int deviceAddress, byte address, byte data) { //8bit
  Wire.beginTransmission(deviceAddress);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.write(data);
  delay(10);
  Wire.endTransmission();
}

//0..255 DEC
byte EEPROM24C_readByte(int deviceAddress, byte address) { //8bit
  Wire.beginTransmission(deviceAddress);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (byte)1);
  byte data = 0;
  if (Wire.available())    {
    data = Wire.read();
  }
  delay(10);
  return data;
}
