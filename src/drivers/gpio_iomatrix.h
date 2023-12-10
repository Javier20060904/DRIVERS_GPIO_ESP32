#ifndef GPIO_IOMATRIX_H
#define GPIO_IOMATRIX_H

#include <stdint.h>

/**
 * Tipo de registro
 */
#define _I volatile const //Solo lectura (RO)
#define _IO volatile //Escritura y lectura (R/W)
#define _O _IO //Solo escritura (WO)

#define IO_MUX_GPIO0_REG    (0x3FF49044)
#define IO_MUX_GPIO2_REG    (0x3FF49040)
#define IO_MUX_GPIO4_REG    (0x3FF49048)
#define IO_MUX_GPIO5_REG    (0x3FF4906C)
#define IO_MUX_GPIO16_REG   (0x3FF4904C)
#define IO_MUX_GPIO17_REG   (0x3FF49050)
#define IO_MUX_GPIO18_REG   (0x3FF49070)
#define IO_MUX_GPIO19_REG   (0x3FF49074)
#define IO_MUX_GPIO20_REG   (0x3FF49078)
#define IO_MUX_GPIO21_REG   (0x3FF4907C)
#define IO_MUX_GPIO22_REG   (0x3FF49080)
#define IO_MUX_GPIO23_REG   (0x3FF4908C)
#define IO_MUX_GPIO24_REG   (0x3FF49090)
#define IO_MUX_GPIO25_REG   (0x3FF49024)
#define IO_MUX_GPIO26_REG   (0x3FF49028)
#define IO_MUX_GPIO27_REG   (0x3FF4902C)
#define IO_MUX_GPIO32_REG   (0x3FF4901C)
#define IO_MUX_GPIO33_REG   (0x3FF49020)
#define IO_MUX_GPIO34_REG   (0x3FF49014)
#define IO_MUX_GPIO35_REG   (0x3FF49018)
#define IO_MUX_GPIO36_REG   (0x3FF49004)
#define IO_MUX_GPIO37_REG   (0x3FF49008)
#define IO_MUX_GPIO38_REG   (0x3FF4900C)

const uint32_t ioMuxDirections[] = {
IO_MUX_GPIO0_REG, 0x00, IO_MUX_GPIO2_REG, 0x00, 
IO_MUX_GPIO4_REG, IO_MUX_GPIO5_REG, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
IO_MUX_GPIO16_REG, IO_MUX_GPIO17_REG, IO_MUX_GPIO18_REG, IO_MUX_GPIO19_REG, 
IO_MUX_GPIO20_REG, IO_MUX_GPIO21_REG, IO_MUX_GPIO22_REG, IO_MUX_GPIO23_REG,
IO_MUX_GPIO24_REG, IO_MUX_GPIO25_REG, IO_MUX_GPIO26_REG, IO_MUX_GPIO27_REG,
0x00, 0x00, 0x00, 0x00,
IO_MUX_GPIO32_REG, IO_MUX_GPIO33_REG, IO_MUX_GPIO34_REG, IO_MUX_GPIO35_REG,
IO_MUX_GPIO36_REG, IO_MUX_GPIO37_REG, IO_MUX_GPIO38_REG, 0x00};

typedef union 
{
    uint32_t reg;
    struct 
    {
       _IO uint32_t MCU_OE  :1;
       _IO uint32_t SLP_SEL :1;
       _IO uint32_t MCU_WPD :1;
       _IO uint32_t MCU_WPU :1;
       _IO uint32_t MCU_IE  :1;
       _IO uint32_t MCU_DRV :2;
       _IO uint32_t FUN_WPD :1;
       _IO uint32_t FUN_WPU :1;
       _IO uint32_t FUN_IE  :1;
       _IO uint32_t FUN_DRV :2;
       _IO uint32_t MCU_SEL :3;
       uint32_t RESERVED    :17;
    }confirguration;
    
}IO_MUX;


#endif
