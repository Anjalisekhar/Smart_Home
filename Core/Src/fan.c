#include "fan.h"
#include "gpio.h"
#include "motor_driver.h"
#include "lcd.h"
#include "FreeRTOS.h"
#include "task.h"

bool fanRunning = false;
int fanSpeedPercent = 50;

void Fan_SetPWM(int dutyPercent) {
    if (dutyPercent < 0) dutyPercent = 0;
    if (dutyPercent > 100) dutyPercent = 100;
    uint32_t period = __HAL_TIM_GET_AUTORELOAD(&htim4);
    uint32_t compareValue = (period + 1) * dutyPercent / 100;
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, compareValue);
}

void Task_FanButton(void *pv) {
    for (;;) {
        if (!(GPIOA->IDR & (1u << 15))) { // Fan button pin PA15
            fanRunning = !fanRunning;
            if (fanRunning) { Fan_SetPWM(fanSpeedPercent); Motor_Enable(); }
            else { Fan_SetPWM(0); Motor_Disable(); }
            LCD_ShowTopLine();
            LCD_ShowBottomLine();
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
