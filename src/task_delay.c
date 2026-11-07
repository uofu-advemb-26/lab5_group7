#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>

#include <FreeRTOS.h>
#include <task.h>
#include "gpio.h"

#define BUSY_WAIT 500000

void main_task(__unused void *params)
{
    int toggle = 0;
    while (1) {
        toggle = !toggle;
        gpio_put(OUT_PIN, toggle);

        vTaskDelay(1U);
    }
}

void second_task(__unused void *params)
{
    while(1){
        __nop();
    }
}
void third_task(__unused void *params)
{
    while(1){
        __nop();
    }
}
void fourth_task(__unused void *params)
{
    while(1){
        __nop();
    }
}

int main(void)
{
    stdio_init_all();
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    const char *rtos_name = "FreeRTOS";
    TaskHandle_t task;
    TaskHandle_t task2, task3, task4;
    xTaskCreate(main_task, "MainThread",
                configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1UL, &task);
    xTaskCreate(second_task, "SecondThread",
                configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1UL, &task2);
    xTaskCreate(third_task, "ThirdThread",
                configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1UL, &task3);
    xTaskCreate(fourth_task, "FOurthThread",
                configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1UL, &task4);

    vTaskStartScheduler();
    return 0;
}
