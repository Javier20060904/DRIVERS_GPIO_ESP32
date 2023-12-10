/******************************************************************************
* Includes
*******************************************************************************/
#include "gpio_drivers.h"
#include "gpio_iomatrix.h"


/******************************************************************************
* Definicion de funciones
*******************************************************************************/

/*! 
* Funcion: GPIO_OUT_SET
* Pre-condiciones: El puerto debe estar habilitado
* Descripcion: Asigna un valor de salida (0 o 1) al puerto seleccionado 
* Valores de entrada: Puerto, Valor de salida 
* Valores de salida: Ninguno
*/  
void GPIO_OUTPUT_SET(uint8_t port, bool value){
    //Del puerto 34 al 39 no pueden ser salidas
    switch (value)
    {
        case ON: 
            GPIO_OUT_W1TS   -> REG_IO |= (value << port) * !(port > IO31 && port <= IO33);
            GPIO_OUT_1_W1TS -> REG_IO |= (value << (port- IO32)) * (port > IO31 && port <= IO33);
            break;
        case OFF:
            GPIO_OUT_W1TC   -> REG_IO |= (value << port) * !(port > IO31 && port <= IO33);
            GPIO_OUT_1_W1TC -> REG_IO |= (value << (port- IO32)) * (port > IO31 && port <= IO33);
            break;
    }
    return;
}

/*! 
* Funcion: GPIO_OUTPUT_ENABLE
* Pre-condiciones: Ninguna
* Descripcion: Habilita el puerto seleccionado
* Valores de entrada: Puerto
* Valores de salida: Ninguno
*/  
void GPIO_OUTPUT_ENABLE(uint8_t port){
    GPIO_ENABLE -> REG_IO   |= (1 << port) * !(port > IO31 && port <= IO39);
    GPIO_ENABLE_1 -> REG_IO |= (1 << (port - IO32)) * (port > IO31 && port <= IO39);
    return;
}

/*! 
* Funcion: GPIO_INPUT_ENABLE
* Pre-condiciones: Ninguna
* Descripcion: Lee el puerto seleccionado
* Valores de entrada: Puerto, tipo de resitencia
* Valores de salida: Ninguno
*/  
void GPIO_INPUT_ENABLE(uint8_t port, bool resistor){
    IO_MUX port_selected;
    port_selected.reg = ioMuxDirections[port]; //Seleccion del puerto
    port_selected.confirguration.FUN_IE = 1; //Habilitacion de la entrada
    port_selected.confirguration.FUN_WPU = !resistor; //Habilitacion del pullup
    port_selected.confirguration.FUN_WPU = resistor; //Habilitacion del pulldown
    return;
}

/*! 
* Funcion: GPIO_INPUT_READ
* Pre-condiciones: Ninguna
* Descripcion: Lee el puerto seleccionado
* Valores de entrada: Puerto
* Valores de salida: Valor de la lectura
*/  
bool GPIO_INPUT_READ(uint8_t port){
    bool lecture = 0;
    switch (port > IO31 && port <= IO39)
    {
        case true:
            lecture = (((GPIO_IN_1 -> REG_IO) >> (port - IO32))  & 0x01);
            break;
        case false:
            lecture = (((GPIO_IN -> REG_IO) >> port)  & 0x01);
            break;
    }
    return lecture;
}

/*************** FINAL DE LAS FUNCIONES ***************************************************************************/
