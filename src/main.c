#include <stdio.h>
#include "drivers/gpio_drivers.h"


void app_main(void)
{
    GPIO_OUTPUT_ENABLE(IO4);
    GPIO_OUTPUT_ENABLE(IO16);
    GPIO_OUTPUT_ENABLE(IO17);

    GPIO_OUTPUT_SET(IO4, ON);
    GPIO_OUTPUT_SET(IO17, ON);
    GPIO_OUTPUT_SET(IO16, ON);
}