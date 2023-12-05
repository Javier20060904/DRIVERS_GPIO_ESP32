#include "gpio_drivers.h"

void GPIO_SET_OUT_PORT(uint8_t port, bool value){
    switch (value)
    {
        case ON:
            GPIO_OUT -> REG_0_31_OUTSET     |= (value << port);
            GPIO_OUT -> REG_0_31_CLEARSET   |= (value << port);
            break;
        case OFF:
            GPIO_OUT -> REG_0_31_OUTSET     &= (value << port);
            GPIO_OUT -> REG_0_31_CLEARSET   &= (value << port);
            break;
    }
    return;
}

void GPIO_PORT_ENABLE(uint8_t port){
    GPIO_ENABLE -> REG_0_31    |=  (1 << port);
    return;
}

uint32_t GPIO_READ_PORT(){
    return 1;
}

void GPIO_SET_INTERRUPTION(){
    return;
}