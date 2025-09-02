#ifndef IR_REMOTE_H
#define IR_REMOTE_H

#include "stm32f4xx_hal.h"

void IR_Init(void);
uint32_t IR_ReadCode(void);

#endif
