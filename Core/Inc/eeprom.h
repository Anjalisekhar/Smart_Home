#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f4xx_hal.h"

void EEPROM_Init(void);
void EEPROM_Write(uint16_t addr, uint8_t data);
uint8_t EEPROM_Read(uint16_t addr);

#endif
