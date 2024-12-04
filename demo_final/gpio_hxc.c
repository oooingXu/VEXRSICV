#include"gpio_hxc.h"
void GPIO_Write(uint32_t pin,uint32_t value)
{
    if(value)
	GPIO_ODR |= (1<<pin);
	else
	GPIO_ODR &=  ~(1<<pin);
}
void GPIO_Set(uint32_t pin,uint32_t value)
{
	GPIO_Write(pin,value);
}
uint32_t GPIO_Read(uint32_t pin)
{
	return GPIO_IDR&(1<<pin);
}                                          
void BEEP_GPIO_Write(uint32_t pin,uint32_t value)
{
    if(value)
	BEEP_GPIO_ODR |= (1<<pin);
	else
	BEEP_GPIO_ODR &=  ~(1<<pin);
}

void JOY2_GPIO_Write(uint32_t pin,uint32_t value)
{
    if(value)
	JOY2_GPIO_ODR |= (1<<pin);
	else
	JOY2_GPIO_ODR &=  ~(1<<pin);
}
void JOY2_GPIO_Set(uint32_t pin,uint32_t value)
{
	JOY2_GPIO_Write(pin,value);
}
uint32_t JOY2_GPIO_Read(uint32_t pin)
{
	return JOY2_GPIO_IDR&(1<<pin);
}                                          

void IIC_GPIO_Set(uint32_t pin,uint32_t value)
{
    if(value)
	IIC_GPIO_CR |= (1<<pin);
	else
	IIC_GPIO_CR &=  ~(1<<pin);
}
void IIC_GPIO_Write(uint32_t pin,uint32_t value)
{
    if(value)
	IIC_GPIO_ODR |= (1<<pin);
	else
	IIC_GPIO_ODR &=  ~(1<<pin);
}
uint32_t IIC_GPIO_Read(uint32_t pin)
{
	return IIC_GPIO_IDR&(1<<pin);
}                                          
