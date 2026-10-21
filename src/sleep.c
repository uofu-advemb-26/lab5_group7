#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>
#include "gpio.h"
#define BUSY_WAIT 500000


int main(void)
{
    int toggle = 0;
    stdio_init_all();
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);

    while (true) {
        for (int i = 0; i < BUSY_WAIT; i++)
            __nop();
        toggle = !toggle;
        gpio_put(OUT_PIN, toggle);
        sleep_ms(DELAY_MS);
    }
}
