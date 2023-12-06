#ifndef GPIO_MATRIX_H
#define GPIO_MATRIX_H

#include <stdint.h>

#define _I volatile const //Solo lectura (RO)
#define _O volatile //Solo escritura (WO)
#define _IO volatile //Escritura y lectura (R/W)

#define PERIFERAL_BASE          ((uint32_t) 0x3FF00000)

#define GPIO_BASE_DIR       ((uint32_t)0x3FF44004)
#define GPIO_OUT_DIR        (GPIO_BASE_DIR)
#define GPIO_OUT_W1TS_DIR   (GPIO_BASE_DIR + 0x0004)
#define GPIO_OUT_W1TC_DIR   (GPIO_BASE_DIR + 0x0008)
#define GPIO_OUT_1_DIR      (GPIO_BASE_DIR + 0x000C)
#define GPIO_OUT_1_W1TS_DIR (GPIO_BASE_DIR + 0x0010)
#define GPIO_OUT_1_W1TC_DIR (GPIO_BASE_DIR + 0x0014)
#define GPIO_ENABLE_DIR     (GPIO_BASE_DIR + 0x001C)
#define GPIO_ENABLE_1_DIR   (GPIO_BASE_DIR + 0x0028)

#define GPIO_STRAP_DIR      (GPIO_BASE_DIR + 0x0034)
#define GPIO_IN_DIR         (GPIO_BASE_DIR + 0x0038)
#define GPIO_INT_DIR        (GPIO_BASE_DIR + 0x0040)
#define GPIO_AC_PC_CPU_DIR  (GPIO_BASE_DIR + 0x005C)
#define GPIO_PIN_DIR        (GPIO_BASE_DIR + 0x0084)
#define GPIO_FUNC_IN_DIR    (GPIO_BASE_DIR + 0x012C)
#define GPIO_FUNC_OUT_DIR   (GPIO_BASE_DIR + 0x052C)


#define GPIO_OUT            ((GPIO_GENERIC_O_0*) GPIO_OUT_DIR)
#define GPIO_OUT_W1TS       ((GPIO_GENERIC_O_0*) GPIO_OUT_W1TS_DIR)
#define GPIO_OUT_W1TC       ((GPIO_GENERIC_O_0*) GPIO_OUT_W1TC_DIR)
#define GPIO_OUT_1          ((GPIO_GENERIC_O_1*) GPIO_OUT_1_DIR)
#define GPIO_OUT_1_W1TS     ((GPIO_GENERIC_O_0*) GPIO_OUT_1_W1TS_DIR)
#define GPIO_OUT_1_W1TC     ((GPIO_GENERIC_O_0*) GPIO_OUT_1_W1TC_DIR)


#define GPIO_ENABLE         ((GPIO_GENERIC_O_0*) GPIO_ENABLE_DIR)
#define GPIO_ENABLE_1       ((GPIO_GENERIC_O_1*) GPIO_ENABLE_1_DIR)

#define GPIO_STRAP_R        ((GPIO_STRAP*) GPIO_STRAP_DIR)
#define GPIO_IN             ((GPIO_GENERIC_I*) GPIO_IN_DIR)
#define GPIO_INT            ((GPIO_INT_STAT *) GPIO_INT_DIR)
#define GPIO_AC_PC_CPU      ((GPIO_PU *) GPIO_AC_PC_CPU_DIR)
#define GPIO_PIN(X)         ((GPIO_PIN_REG*) (GPIO_PIN_DIR + (4*X)))
#define GPIO_FUNC_IN(X)     ((GPIO_FUNC_IN_SEL_CFG_REG*) (GPIO_FUNC_IN_DIR + (4*X)))
#define GPIO_FUNC_OUT(X)    ((GPIO_FUNC_OUT_SEL_CFG_REG*) (GPIO_FUNC_IN_DIR + (4*X)))


#define IO0 0
#define IO1 1
#define IO2 2
#define IO3 3
#define IO4 4
#define IO5 5
#define IO6 6
#define IO7 7
#define IO8 8
#define IO9 9
#define IO10 10
#define IO11 11
#define IO12 12
#define IO13 13
#define IO14 14
#define IO15 15
#define IO16 16
#define IO17 17
#define IO18 18
#define IO19 19
#define IO20 20
#define IO21 21
#define IO22 22
#define IO23 23
#define IO24 24
#define IO25 25
#define IO26 26
#define IO27 27
#define IO28 28
#define IO29 29
#define IO30 30
#define IO31 31
#define IO32 32
#define IO33 33
#define IO34 34
#define IO35 35
#define IO36 36
#define IO37 37
#define IO38 38
#define IO39 39




//ESTRUCTURAS
//OUT, ENABLE
typedef struct 
{   
    _IO uint32_t    REG_IO;
}GPIO_GENERIC_O_0;

typedef struct
{;
    _IO uint32_t    REG_IO :7;
        uint32_t    RESERVED:24;
} GPIO_GENERIC_O_1;

//STRAPPING
typedef struct
{
    _I uint16_t STRAPPING;
    uint16_t RESERVED1;
}GPIO_STRAP;

//INPUT
typedef struct 
{   
    _I  uint32_t    REG_0_31;
    _I  uint8_t     REG_32_39;
    uint16_t    RESERVED1;
} GPIO_GENERIC_I;

//Interrupt
typedef struct
{
    _IO uint32_t    REG_STATUS_0_31;
    _O  uint32_t    REG_STATUS_W1TS_0_31;
    _O  uint32_t    REG_STATUS_W1TC_0_31;
    _IO uint8_t     REG_STATUS_32_39;
    uint16_t    RESERVED2;
    _O  uint8_t     REG_STATUS_W1TS_32_39;
    uint16_t    RESERVED3;
    _O  uint8_t     REG_STATUS_W1TC_32_39;
    uint16_t    RESERVED4;
}GPIO_INT_STAT;

//APP CPU Y PRO CPU
typedef struct
{
    _I uint32_t ACPU_INT_REG;
    _I uint32_t ACPU_NMI_INT_REG;
    _I uint32_t PCPU_INT_REG;
    _I uint32_t PCPU_NMI_INT_REG;
    _I  uint8_t ACPU_INT_REG_1;
    uint16_t    RESERVED1;
    _I  uint8_t ACPU_NMI_INT_REG_1;
    uint16_t    RESERVED2;
    _I  uint8_t PCPU_INT_REG_1;
    uint16_t    RESERVED3;
    _I  uint8_t PCPU_NMI_INT_REG_1;
    uint16_t    RESERVED4;
}GPIO_PU;


typedef struct 
{
    uint32_t RESERVED1 :2;
    _IO uint32_t PAD_DRIVER :1;
    uint32_t RESERVED2 :4;
    _IO uint32_t INT_TYPE :3;
    _IO uint32_t WAKEUP_ENABLE :1;
    uint32_t RESERVED3 :2;
    _IO uint32_t INT_ENA :5;
    uint32_t RESERVED4 :13;
}GPIO_PIN_REG;

typedef struct
{
    _IO uint32_t IN_SEL :6;
    _IO uint32_t IN_INV_SEL :1;
    _IO uint32_t SIG_IN_SEL :1;
    uint32_t RESERVED :23;  
}GPIO_FUNC_IN_SEL_CFG_REG;

typedef struct
{
    _IO uint32_t OUT_SEL :9;
    _IO uint32_t OUT_INV_SEL :1;
    _IO uint32_t OEN_SEL :1;
    _IO uint32_t OEN_INV_SEL :1;
    uint32_t RESERVED :19;  
}GPIO_FUNC_OUT_SEL_CFG_REG;
#endif