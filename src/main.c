#include <stdio.h>
#include "drivers/gpio_drivers.h"


void app_main(void)
{
    GPIO_OUTPUT_ENABLE(IO5);
    GPIO_OUTPUT_SET(IO5, ON);
    for (size_t i = 0; i < 600000000; i++);

    GPIO_OUTPUT_SET(IO5, OFF);
}