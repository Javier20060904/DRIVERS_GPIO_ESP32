#include "gpio_drivers.h"

void GPIO_PORT_SET_OUT(uint8_t port, bool value){
    switch (value)
    {
        case ON: 
            GPIO_OUT_W1TS   -> REG_IO |= (value << port) * (port > 31 && port < 39);
            GPIO_OUT_1_W1TS -> REG_IO |= (value << (port-32)) * !(port > 31 && port < 39);
            break;
        case OFF:
            GPIO_OUT_W1TC   -> REG_IO |= (value << port) * (port > 31 && port < 39);
            GPIO_OUT_1_W1TC -> REG_IO |= (value << (port-32)) * !(port > 31 && port < 39);
            break;
    }
    return;
}

void GPIO_PORT_ENABLE(uint8_t port){
    GPIO_ENABLE -> REG_IO |= (1 << port) * (port > 31 && port < 39);
    GPIO_ENABLE_1 -> REG_IO |= (1 << (port-32)) * !(port > 31 && port < 39);
    return;
}

uint32_t GPIO_READ_PORT(){
    return 1;
}

void GPIO_SET_INTERRUPTION(){
    return;
}