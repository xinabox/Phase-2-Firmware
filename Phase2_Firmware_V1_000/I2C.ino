/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

/*
 * @brief, function to ping a given I2C device address
 * 
 * @param _address, uint8_t I2C address for MCU to ping
 * @ret, boolean state
 */
bool I2C_PING(uint8_t _address) {
  // Set flag status
  bool status = false;
  // Check the flag status to check if //OD01 is connected and ping was succesful
  for (byte i = 0; i < 10; i++) {
    Wire.beginTransmission(_address);
    if (Wire.endTransmission() == 0) { // Device is connected and ping successful
      status = true; // set flag
      break; // exit loop
    }
    else if (i == 9) { // Device not found cannot ping device address
      status = false; // set flag
      break; // exit loop
    }
    delay(1);
  }
  return status;
}



