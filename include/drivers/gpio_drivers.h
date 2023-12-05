#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "gpio_matrix.h" 


extern void     GPIO_SET_PORT();
extern uint32_t GPIO_READ_PORT();
extern void     GPIO_SET_INTERRUPTION();
#endif