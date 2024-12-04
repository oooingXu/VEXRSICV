#ifndef _GPIO_HXC_H_
#define _GPIO_HXC_H_

#include"stdint.h"

#define GPIO_BASE   0xf0000800
#define GPIO_IDR    *(unsigned int*)(GPIO_BASE)
#define GPIO_ODR    *(unsigned int*)(GPIO_BASE+0x04)
void GPIO_Set(uint32_t pin,uint32_t value);
void GPIO_Write(uint32_t pin,uint32_t value);
uint32_t GPIO_Read(uint32_t pin);
#define JOYPAD2     0x00000800
#define JOY2_GPIO_IDR    *(unsigned int*)(GPIO_BASE+JOYPAD2)
#define JOY2_GPIO_ODR    *(unsigned int*)(GPIO_BASE+JOYPAD2+0x04)
void JOY2_GPIO_Set(uint32_t pin,uint32_t value);
void JOY2_GPIO_Write(uint32_t pin,uint32_t value);
uint32_t JOY2_GPIO_Read(uint32_t pin);

#define BEEP_GPIO_BASE   0xf0001800
#define BEEP_GPIO_ODR    *(unsigned int*)(BEEP_GPIO_BASE)
void BEEP_GPIO_Write(uint32_t pin,uint32_t value);

extern uint32_t offset;
#define IIC_GPIO_BASE   0xf0002000
#define IIC_GPIO_CR     *(unsigned int*)(IIC_GPIO_BASE+offset)
#define IIC_GPIO_ODR    *(unsigned int*)(IIC_GPIO_BASE+offset)
#define IIC_GPIO_IDR    *(unsigned int*)(IIC_GPIO_BASE+offset+0x04)
void IIC_GPIO_Set(uint32_t pin,uint32_t value);
void IIC_GPIO_Write(uint32_t pin,uint32_t value);
uint32_t IIC_GPIO_Read(uint32_t pin);
#endif
