/*************************************************************
  This is an examples for the SL01 & SN01 running on RTOS
  The sensor communicates over the I2C Bus.
*************************************************************/

/*
     @brief, convert uint16_t to 2 uint8_t

    @param data, unsigned 16 bit input
    @ret, none
*/
void convert_sig_data(int16_t data) {
  if (data_buf[DATABUFSIZE - 2] == *c.ptr_id) { // test for ID in second last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID and following byte with 0x00
    data_buf[++i] = 0x00;
  }    else if (data_buf[DATABUFSIZE - 1] == *c.ptr_id) { // test for ID in last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID with 0x00
  } else { // split 16 bit values into two bytes
    byte array[2];
    array[0] = data & 0xFF;
    array[1] = (data >> 8);
    data_buf[++i] = array[0];
    data_buf[++i] = array[1];
  }
}

/*
    @brief, convert int16_t to 2 uint8_t

    @param data, signed 16 bit input
    @ret, none
*/
void convert_unsig_data(uint16_t data) {
  if (data_buf[DATABUFSIZE - 2] == *c.ptr_id) { // test for ID in second last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID and following byte with 0x00
    data_buf[++i] = 0x00;
  }   else if (data_buf[DATABUFSIZE - 1] == *c.ptr_id) { // test for ID in last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID with 0x00
  } else { // split 16 bit values into two bytes
    byte array[2];
    array[0] = data & 0xFF;
    array[1] = (data >> 8);
    data_buf[++i] = array[0];
    data_buf[++i] = array[1];
  }
}
void convert_sig32_data(int32_t data) {
  if (data_buf[DATABUFSIZE - 4] == *c.ptr_id) { // test for ID in second last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID and following byte with 0x00
    data_buf[++i] = 0x00;
    data_buf[++i] = 0x00;
    data_buf[++i] = 0x00;
  } else if (data_buf[DATABUFSIZE - 3] == *c.ptr_id) { // test for ID in last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID with 0x00
    data_buf[++i] = 0x00;
    data_buf[++i] = 0x00;
  }
  else if (data_buf[DATABUFSIZE - 2] == *c.ptr_id) { // test for ID in last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID with 0x00
    data_buf[++i] = 0x00;
  }
  else if (data_buf[DATABUFSIZE - 1] == *c.ptr_id) { // test for ID in last byte of the data buffer
    --c.ptr_id;
    data_buf[i] = 0x00; // replace ID with 0x00
  } else {
    byte array[4];
    array [0] = data >> 24;
    array[1] = data >> 16;
    array[2] = data >> 8;
    array[3] = data;
    data_buf[++i] = array[0];
    data_buf[++i] = array[1];
    data_buf[++i] = array[2];
    data_buf[++i] = array[3];
  }
}

/*
    @brief, popoulates uint8_t data type into buffer
            and checks whether ID occurs in the
            byte
    @param data, unsigned 8 bit input
    @ret, none
*/
void unsig_byte_data(uint8_t data) {
  if (data_buf[DATABUFSIZE - 1] == *c.ptr_id) {
    --c.ptr_id;
    data_buf[i] = 0x00;
  } else {
    data_buf[++i] = data;
  }
}

/*
    @brief, popoulates int8_t data type into buffer
            and checks whether ID occurs in the
            byte
    @param data, signed 8 bit input
    @ret, none
*/
void sig_byte_data(int8_t data) {
  if (data_buf[DATABUFSIZE - 1] == *c.ptr_id) {
    --c.ptr_id;
    data_buf[i] = 0x00;
  } else {
    data_buf[++i] = data;
  }
}


