#include <stdio.h>
#include "drivers/gpio_drivers.h"

void app_main(void)
{
    GPIO_PORT_ENABLE(IO4);
    GPIO_PORT_ENABLE(IO2);

    GPIO_PORT_SET_OUT(IO2, ON);
    GPIO_PORT_SET_OUT(IO4, ON);
}