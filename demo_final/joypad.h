#ifndef _JOYPAD_H_
#define _JOYPAD_H_

#include "stdint.h"
#include "gpio_hxc.h"

#define JOYPAD_LAT_HIGH     GPIO_Write(1,1)
#define JOYPAD_LAT_LOW      GPIO_Write(1,0)
#define JOYPAD_DAT_READ     GPIO_Read(0)
#define JOYPAD_CLK_HIGH     GPIO_Write(0,1)
#define JOYPAD_CLK_LOW      GPIO_Write(0,0)

#define JOYPAD_LAT_HIGH_0     JOY2_GPIO_Write(1,1)
#define JOYPAD_LAT_LOW_0      JOY2_GPIO_Write(1,0)
#define JOYPAD_DAT_READ_0     JOY2_GPIO_Read(0)
#define JOYPAD_CLK_HIGH_0     JOY2_GPIO_Write(0,1)
#define JOYPAD_CLK_LOW_0      JOY2_GPIO_Write(0,0)
void JOYPAD_Delay(uint32_t t);
void JOYPAD_Init(void);
uint8_t JOYPAD_Read(void);
uint8_t JOYPAD_Read_0(void);
#endif
