#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "stm32f4xx_hal.h"

void MotorDriver_Init(void);
void MotorDriver_Forward(void);
void MotorDriver_Backward(void);
void MotorDriver_Stop(void);

#endif
