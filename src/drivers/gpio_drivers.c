/******************************************************************************
* Includes
*******************************************************************************/
#include "gpio_drivers.h"


/******************************************************************************
* Definicion de funciones
*******************************************************************************/

/*! 
* Funcion: GPIO_PORT_SET_OUT
* Pre-condiciones: El puerto debe estar habilitado
* Descripcion: Asigna un valor de salida (0 o 1) al puerto seleccionado 
* Valores de entrada: Puerto, Valor de salida 
* Valores de salida: Ninguno
*/  
void GPIO_PORT_SET_OUT(uint8_t port, bool value){
    //Del puerto 34 al 39 no pueden ser salidas
    switch (value)
    {
        case ON: 
            GPIO_OUT_W1TS   -> REG_IO |= (value << port) * !(port > 31 && port < 33);
            GPIO_OUT_1_W1TS -> REG_IO |= (value << (port-32)) * (port > 31 && port < 33);
            break;
        case OFF:
            GPIO_OUT_W1TC   -> REG_IO |= (value << port) * !(port > 31 && port < 33);
            GPIO_OUT_1_W1TC -> REG_IO |= (value << (port-32)) * (port > 31 && port < 33);
            break;
    }
    return;
}

/*! 
* Funcion: GPIO_PORT_ENABLE
* Pre-condiciones: Ninguna
* Descripcion: Habilita el puerto seleccionado
* Valores de entrada: Puerto
* Valores de salida: Ninguno
*/  
void GPIO_PORT_ENABLE(uint8_t port){
    GPIO_ENABLE -> REG_IO   |= (1 << port) * !(port > 31 && port < 39);
    GPIO_ENABLE_1 -> REG_IO |= (1 << (port-32)) * (port > 31 && port < 39);
    return;
}

bool GPIO_PORT_READ(uint8_t port){
    bool lecture;
    if (port > 31 && port <= 39){
        lecture = (((GPIO_IN_1 -> REG_IO) >> (port - 32))  & 0x01);
        return lecture;
    }
    lecture = (((GPIO_IN -> REG_IO) >> port)  & 0x01);
    return lecture;
}

void GPIO_SET_INTERRUPTION(){
    return;
}
/*************** FINAL DE LAS FUNCIONES ***************************************************************************/
