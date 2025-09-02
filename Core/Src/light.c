#include "light.h"
#include "gpio.h"
#include "lcd.h"
#include "FreeRTOS.h"
#include "task.h"

bool lightRunning = false;
int lightLevelPercent = 50;

void Light_SetPWM(int dutyPercent) {
    if (dutyPercent < 0) dutyPercent = 0;
    if (dutyPercent > 100) dutyPercent = 100;
    uint32_t period = __HAL_TIM_GET_AUTORELOAD(&htim1);
    uint32_t compareValue = (period + 1) * dutyPercent / 100;
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, compareValue);
}

void Task_LightButton(void *pv) {
    for (;;) {
        if (!(GPIOB->IDR & (1u << 7))) { // Light button pin PB7
            lightRunning = !lightRunning;
            if (lightRunning) Light_SetPWM(lightLevelPercent);
            else Light_SetPWM(0);
            LCD_ShowTopLine();
            LCD_ShowBottomLine();
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
