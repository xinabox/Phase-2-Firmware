/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/
#ifndef vaDATA_h
#define vaDATA_h
/************************************************************/

struct SENSORS_DATA {
  byte tempC = 0;
  byte humidity = 0;
  uint16_t pressure = 0;

  uint16_t lux = 0;
  uint16_t uva = 0;
  uint16_t uvb = 0;
  byte uvi = 0;

  int16_t accex = 0;
  int16_t accey = 0;
  int16_t accez = 0;

  int16_t gyrox = 0;
  int16_t gyroy = 0;
  int16_t gyroz = 0;

  int16_t magx = 0;
  int16_t magy = 0;
  int16_t magz = 0;

  int8_t roll = 0;
  int8_t pitch = 0;
  int8_t yaw = 0;

  int16_t altitude = 0;
  int32_t latitude = 0;
  int32_t longitude = 0;
  float hdop = 0;
  int16_t cog = 0;
} data, *ptr;

/************************************************************/
#endif



