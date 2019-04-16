void DEBUG_OD01(void) {
  OD01.clear();
  OD01.println("    DEBUG PHASE 2");
  OD01.println("=======================");
  if (c.SW01_ACK) {
    OD01.print("SW01 Temp: ");
    OD01.print(((5 * (float)data.tempC) / 8) - 40);
    OD01.println(" C");
  } else {
    OD01.println("SW01 N/A");
  }
  if (c.SL01_ACK) {
    OD01.print("SL01 Lux : ");
    OD01.println((uint16_t)data.lux * 4);
  } else {
    OD01.println("SL01 N/A");
  }
  if (c.SN01_ACK) {
    if (POLL_SN01()) {
      OD01.print("SN01 Lat : ");
      OD01.println((float)data.latitude / 10000000, 4);
    } else {
      OD01.println("SN01 No Fix");
    }
  } else {
    OD01.println("SN01 N/A");
  }
  if (c.SI01_ACK) {
    OD01.print("SI01 Roll: ");
    OD01.print(data.roll);
    OD01.println(" degrees");
  } else {
    OD01.println("SI01 N/A");
  }

  if (c.count_request == 1) {
    OD01.println("Payload Packet Sent");
    OD01.print("Verifying...");
  } else if (c.count_request > 1) {
    OD01.println("Data Transmitted");
    OD01.print("EM PASS");
  } else {
    OD01.println("Awaiting request");
    OD01.print("from EM....");
  }
}

uint16_t DEBUG_LED(void) {
  uint16_t led_period;
  for (int i = 0; i <= sensor_count; i ++) {
    led_period = map(i, i, 0, (i * 500) + 300, 0);
  }
  return led_period;
}


