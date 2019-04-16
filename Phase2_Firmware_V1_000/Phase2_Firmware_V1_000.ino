/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

/********************Library Includes************************/
#include <vaSL01.h>
#include <vaSN01.h>
#include <vaSW01.h>
#include <vaSI01.h>
#include "vaDATA.h"
#include "vaCTRL.h"
#include <FlashAsEEPROM.h>
#include <xOD01.h>

/*********************|Global Defines************************/
#define LED_BUILTIN 13
#define serial  Serial1
#define SERIAL SerialUSB
#define DATABUFSIZE 34
#define PREBUFSIZE 4

/***********************GLOBAL STATE*************************/
vaSL01 SL01;
vaSN01 SN01;  
vaSW01 SW01;
vaSI01 SI01;

FlashStorage(count_store, byte);
FlashStorage(id_store, uint8_t*);
FlashStorage(last_id_flag_store, bool);

struct CC03_CTRL c;
struct TIMER_CTRL t;
bool state;

uint16_t sensor_count = 0;
char data_buf[DATABUFSIZE];
char pre_buf[PREBUFSIZE];
int i;

uint8_t xCHIP_ID[65];

// enter required IDs and change array size
uint8_t SW01_ID[3] = {1, 2, 3};
uint8_t SL01_ID[2] = {4, 5};
uint8_t SI01_ID[8] = {8, 9, 10, 14, 15, 16, 17, 18};
uint8_t SN01_ID[4] = {20, 21, 22, 24};

/**********************Sketch Code***************************/
void setup() {
  check_fuse_bits();
  // Start Serial Monitor
  serial.begin(9600);
  SERIAL.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  // Start the I2C Bus
  Wire.begin();

  // Start Connected Sensors
  //while(!serial);
  START_SENSORS();
  c.count = count_store.read();
  c.ptr_id = id_store.read();

  // prevents ID pointer from pointing to random memory location after upload
  if (c.ptr_id == NULL) {
    c.last_id_flag = true;
  } else {
    c.last_id_flag = last_id_flag_store.read();
  }

  t.tick_POLL = millis();
  t.tick_UART = millis();
  t.tick_BUFFER = millis();
  t.tick_SN01 = millis();
  t.tick_LED = millis();
  t.tick_OLED = millis();
}

void loop() {
  VASPACE_PHASE2();
}


