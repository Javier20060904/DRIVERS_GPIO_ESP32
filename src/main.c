#include <stdio.h>
#include "drivers/gpio_drivers.h"


void app_main(void)
{
    GPIO_OUTPUT_ENABLE(IO12);

    GPIO_OUTPUT_SET(IO12, ON);

}
    
