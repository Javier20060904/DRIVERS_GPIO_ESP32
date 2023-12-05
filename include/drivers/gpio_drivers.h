#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "gpio_matrix.h"
#include <stdbool.h>

#define IN  0
#define OUT 1

#define OFF 0
#define ON 1

extern void     GPIO_SET_OUT_PORT(uint8_t port, bool value);
extern void     GPIO_PORT_ENABLE(uint8_t port);
extern uint32_t GPIO_READ_PORT();
extern void     GPIO_SET_INTERRUPTION();
#endif