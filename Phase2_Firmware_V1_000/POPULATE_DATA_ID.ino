/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

uint8_t POPULATE_ID_BUFFER(void) {

  uint8_t buf_idx = 0;
  // Allocate SW01 to buffer
  if (I2C_PING(0x76)) {
    if (c.SW01_ACK) {
      for (uint8_t j = 0; j < sizeof(SW01_ID); j++) {
        if (SW01_ID[j] != NULL) {
          xCHIP_ID[buf_idx] = SW01_ID[j];
          buf_idx++;
        }
      }
    }
  } else {
    c.SW01_ACK = 0;
  }
  // Allocare SL01 to buffer
  if ((I2C_PING(0x10) && I2C_PING(0x29)) == true) {
    if (c.SL01_ACK) {
      for (uint8_t j = 0; j < sizeof(SL01_ID); j++) {
        if (SL01_ID[j] != NULL) {
          xCHIP_ID[buf_idx] = SL01_ID[j];
          buf_idx++;
        }
      }
    }
  } else {
    c.SL01_ACK = 0;
  }
  // Allocate SI01 to buffer
  if ((I2C_PING(0x1C) && I2C_PING(0x6A)) == true) {
    if (c.SI01_ACK) {
      for (uint8_t j = 0; j < sizeof(SI01_ID); j++) {
        if (SI01_ID[j] != NULL) {
          xCHIP_ID[buf_idx] = SI01_ID[j];
          buf_idx++;
        }
      }
    }
  } else {
    c.SI01_ACK = 0;
  }
  // Allocate SN01 to buffer
  if (I2C_PING(0x42)) {
    if (c.SN01_ACK && POLL_SN01()) {
      for (uint8_t j = 0; j < sizeof(SN01_ID); j++) {
        if (SN01_ID[j] != NULL) {
          xCHIP_ID[buf_idx] = SN01_ID[j];
          buf_idx++;
        }
      }
    }
  } else {
    c.SN01_ACK = 0;
  }
  return buf_idx;
}
