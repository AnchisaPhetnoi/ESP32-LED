#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

extern "C" void app_main(void);

#include "driver/ledc.h"

void app_main(void)
{
    LED leds[] = { LED(5), LED(17), LED(18), LED(19) }; // เชื่อมต่อ LED หลายตัวที่ GPIO ต่าง ๆ
    int numLeds = sizeof(leds) / sizeof(LED);

    while(1)
    {
        // วิ่งจากซ้ายไปขวา
        for (int i = 0; i < numLeds; i++) {
            leds[i].ON();
            vTaskDelay(100 / portTICK_PERIOD_MS);
            leds[i].OFF();
        }
        // วิ่งจากขวาไปซ้าย
        for (int i = numLeds - 2; i > 0; i--) {
            leds[i].ON();
            vTaskDelay(100 / portTICK_PERIOD_MS);
            leds[i].OFF();
        }
    }
}
