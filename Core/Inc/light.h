#ifndef LIGHT_H
#define LIGHT_H

#include <stdint.h>
#include <stdbool.h>
#include "tim.h"

void Light_SetPWM(int dutyPercent);
void Task_LightButton(void *pv);

extern bool lightRunning;
extern int lightLevelPercent;

#endif
