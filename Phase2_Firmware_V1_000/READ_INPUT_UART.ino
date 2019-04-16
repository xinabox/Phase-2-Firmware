/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

/*
   @brief, read incoming data from UART/Serial1.
*/
void READ_INPUT(void) {
  //setLED(LED_BUILTIN, HIGH);
  for (byte j = 0; j < 3; j++) {
    byte inp = serial.read();
    SERIAL.println(inp, HEX);
    c.ts = (inp == 0x49) & c.ts;
    c.cmd = (inp == 0x4A) & c.cmd;
  }
  while (serial.available()) {
    serial.read();
  }
  serial.flush();
}


