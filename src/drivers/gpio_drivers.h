/*******************************************************************************
* Title                 :   gpio drivers  
* Filename              :   gpio_drivers.h
* Author                :   Javier Perez Macias
* Origin Date           :   04/12/2023
* Version               :   1.0.0
* Compiler              :   CMAKE
* Target                :   ESP32
*
******************************************************************************/

/** @file gpio_drivers.h
 *  @brief Funciones y declaraciones para el manejo del GPIO
 */
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "gpio_matrix.h"
#include <stdbool.h>

/******************************************************************************
* Constantes del preprocesador
*******************************************************************************/
#define IN  0
#define OUT 1
#define OFF IN
#define ON OUT


/******************************************************************************
* Prototipo de funciones
*******************************************************************************/
extern void     GPIO_PORT_SET_OUT(uint8_t port, bool value);
extern void     GPIO_PORT_ENABLE(uint8_t port);
extern uint32_t GPIO_READ_PORT();
extern void     GPIO_SET_INTERRUPTION();
#endif