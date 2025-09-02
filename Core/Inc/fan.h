#ifndef FAN_H
#define FAN_H

#include <stdint.h>
#include <stdbool.h>
#include "tim.h"

void Fan_SetPWM(int dutyPercent);
void Task_FanButton(void *pv);

extern bool fanRunning;
extern int fanSpeedPercent;

#endif
