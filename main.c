/** @example 
*	Una demostracion de un uso basico del GPIO
**/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_drivers.h"

void app_main(void)
{
	/**
	*	Habilitacion de los puertos
	*/
    GPIO_OUTPUT_ENABLE(IO5);
    GPIO_OUTPUT_SET(IO5,ON);
    GPIO_INPUT_ENABLE(IO18, PULLUP);
    
    while (1)
    {
    	/**
		*	Cambio de estado y lectura de los puertos
		*/
        GPIO_OUTPUT_SET(IO5, OFF);
        vTaskDelay(pdMS_TO_TICKS(500));
        printf("%d \n", GPIO_INPUT_READ(IO18));
        GPIO_OUTPUT_SET(IO5, ON);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    
}

