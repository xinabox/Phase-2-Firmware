/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/
#ifndef vaCTRL_h
#define vaCTRL_h
/************************************************************/

struct CC03_CTRL {
  bool cmd  = true;
  bool ts   = true;
  uint8_t BUF_IDX;
  uint8_t *ptr_id;
  uint8_t last_id_flag = true;
  uint8_t count = 0;
  uint16_t count_request = 0;

  uint8_t SW01_ACK;
  uint8_t SL01_ACK;
  uint8_t SN01_ACK;
  uint8_t SI01_ACK;
  uint8_t OD01_ACK;
};

struct TIMER_CTRL {
  unsigned long  tick_POLL;
  unsigned long  tick_UART;
  unsigned long  tick_BUFFER;
  unsigned long  tick_SN01;
  unsigned long  tick_LED;
  unsigned long  tick_status;
  unsigned long  tick_OLED;
};

/************************************************************/
#endif



