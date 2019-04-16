/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

/*
   @brief, start connected sensors if present on I2C BUs
*/

void START_SENSORS(void) {

  // Check OD01
  if (I2C_PING(0x3C)) {
    c.OD01_ACK = 0xFF;
    OLED.begin();
    OD01.clear();
  } else {
    c.OD01_ACK = 0;
  }
  // Check SW01
  if (I2C_PING(0x76)) {
    c.SW01_ACK = 0xFF;
    SW01.begin();
   sensor_count +=1;
  } else {
    c.SW01_ACK = 0;
  }

  // Check SL01
  if ((I2C_PING(0x10) && I2C_PING(0x29)) == true) {
    c.SL01_ACK = 0xFF;
    SL01.begin();
    sensor_count += 1;
  } else {
    c.SL01_ACK = 0;
  }

  // Check SI01
  if ((I2C_PING(0x1C) && I2C_PING(0x6A)) == true) {
    c.SI01_ACK = 0xFF;
    SI01.begin();
    sensor_count += 1;
  } else {
    c.SI01_ACK = 0;
  }

  // Check SN01
  if (I2C_PING(0x42)) {
    c.SN01_ACK = 0xFF;
    SN01.begin();
    sensor_count += 1;
  } else {
    c.SN01_ACK = 0;
  }
}




