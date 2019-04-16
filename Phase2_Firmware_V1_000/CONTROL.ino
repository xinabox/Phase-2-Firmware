/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

void command(void) {
  //setLED(g, HIGH);
  serial.println("Command menu begin.");
}

void thinsat(void) {
  setLED(LED_BUILTIN, HIGH);
  send_data();
}

void setLED(byte c, bool on) {
  digitalWrite(c, on);
}



