void check_fuse_bits(void)
{
  uint32_t old_fusebits[2];
  uint32_t new_fusebits[2];
  read_fuse_bits(old_fusebits);
  //  delay(2000);
  //  //OD01.clear();
  //  //OD01.println("Current NVM :");
  //  //OD01.println(old_fusebits[0], HEX);
  //  //OD01.println(old_fusebits[1], HEX);
  if ((old_fusebits[0] != 0xD8E0E7FF) || (old_fusebits[1] != 0xFFFFFD5D)) {
    //    //OD01.println("Fixing...");
    fix_fuses();
    //    //OD01.println("New NVM :");
    read_fuse_bits(new_fusebits);
    //    //OD01.println(new_fusebits[0], HEX);
    //    //OD01.println(new_fusebits[1], HEX);
    //  } else {
    //    //OD01.println("Fuse Bits Correct.");
  }
}

static void read_fuse_bits(uint32_t *data)
{
  /* Make sure the module is ready */
  /* Wait for NVM command to complete */
  while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));
  /* Read the fuse settings in the user row, 64 bit */
  data[0] = *((uint32_t *)NVMCTRL_AUX0_ADDRESS);
  data[1] = *(((uint32_t *)NVMCTRL_AUX0_ADDRESS) + 1);
}
void fix_fuses(void)
{
#define NVM_COMMAND_ERASE_AUX_ROW 0x05
#define NVM_COMMAND_PAGE_BUFFER_CLEAR 0x44
#define NVM_COMMAND_WRITE_AUX_ROW 0x06
  uint32_t new_fusebits[2];
  new_fusebits[0] = 0xD8E0E7FF; // Default values BOD33 set to 2.7V
  new_fusebits[1] = 0xFFFFFD5D; // Enable BOD33 hystersis
  /* Auxiliary space cannot be accessed if the security bit is set */
  if (NVMCTRL->STATUS.reg & NVMCTRL_STATUS_SB) {
    return;
  }
  /* Disable Cache */
  uint32_t temp = NVMCTRL->CTRLB.reg;
  NVMCTRL->CTRLB.reg = temp | NVMCTRL_CTRLB_CACHEDIS;
  /* Clear error flags */
  NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;
  /* Set address, command will be issued elsewhere */
  NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;
  /* Erase the user page */
  NVMCTRL->CTRLA.reg = NVM_COMMAND_ERASE_AUX_ROW | NVMCTRL_CTRLA_CMDEX_KEY;
  /* Wait for NVM command to complete */
  while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));
  /* Clear error flags */
  NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;
  /* Set address, command will be issued elsewhere */
  NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;
  /* Erase the page buffer before buffering new data */
  NVMCTRL->CTRLA.reg = NVM_COMMAND_PAGE_BUFFER_CLEAR | NVMCTRL_CTRLA_CMDEX_KEY;
  /* Wait for NVM command to complete */
  while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));
  /* Clear error flags */
  NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;
  /* Set address, command will be issued elsewhere */
  NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;
  *((uint32_t *)NVMCTRL_AUX0_ADDRESS) = new_fusebits[0];
  *(((uint32_t *)NVMCTRL_AUX0_ADDRESS) + 1) = new_fusebits[1];
  /* Write the user page */
  NVMCTRL->CTRLA.reg = NVM_COMMAND_WRITE_AUX_ROW | NVMCTRL_CTRLA_CMDEX_KEY;
  /* Restore the settings */
  NVMCTRL->CTRLB.reg = temp;
}

