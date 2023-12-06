#include <stdio.h>
#include "drivers/gpio_drivers.h"


void app_main(void)
{
    GPIO_PORT_ENABLE(IO4);
    GPIO_PORT_ENABLE(IO16);
    GPIO_PORT_ENABLE(IO17);


    GPIO_PORT_SET_OUT(IO4, ON);
    GPIO_PORT_SET_OUT(IO17, ON);
    GPIO_PORT_SET_OUT(IO16, ON);

}