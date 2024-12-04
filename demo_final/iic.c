#include "iic.h"
#include "delay.h"
uint32_t offset;
//uint8_t delay_us(uint32_t time){
//        while(time--){
//               int volatile freq = 50;
//                while(freq--);
//        }
//}
void delay_us(uint32_t time);
void delay_ms(uint32_t time);

void iic_delay(void)
{
    delay_us(2);
}

void iic_start(uint8_t sel)
{
	  IIC_SEL(sel);
    IIC_SDA_OUT();

    IIC_SDA(1);
    IIC_SCL(1);
    iic_delay();
    IIC_SDA(0);
    iic_delay();
    IIC_SCL(0);
    iic_delay();
}

void iic_stop(uint8_t sel)
{
	  IIC_SEL(sel);
    IIC_SDA_OUT();

    IIC_SDA(0);
    IIC_SCL(1);
    iic_delay();
    IIC_SDA(1);
    IIC_SCL(1);
    iic_delay();
}

uint8_t iic_wait_ack(uint8_t sel)
{
	  IIC_SEL(sel);
    uint32_t waittime = 0;
    uint8_t rack = 0;
    IIC_SDA_IN();
    
    IIC_SDA(1);
    iic_delay();
    IIC_SCL(1);
    iic_delay();
    
    while (IIC_READ_SDA())
    {
        waittime++;
        
        if (waittime > 250)
        {
            iic_stop(sel);
            //rack = 1;
            break;
        }
    }
    
    IIC_SCL(0);
    iic_delay();
    
    return rack;
}

///
 //
void iic_ack(uint8_t sel)
{
	  IIC_SEL(sel);
    IIC_SDA_OUT();

    IIC_SDA(0);
    iic_delay();
    IIC_SCL(1);
    iic_delay();
    IIC_SCL(0);
    iic_delay();
    IIC_SDA(1);
    iic_delay();
}

///
 //
void iic_nack(uint8_t sel)
{
	  IIC_SEL(sel);
    IIC_SDA_OUT();

    IIC_SDA(1);
    iic_delay();
    IIC_SCL(1);
    iic_delay();
    IIC_SCL(0);
    iic_delay();
}

///
 //
void iic_send_byte(uint8_t dat,uint8_t sel)
{
	  IIC_SEL(sel);
    uint8_t t;
    IIC_SDA_OUT();

    for (t=0; t<8; t++)
    {
        IIC_SDA((dat & 0x80) >> 7);
        iic_delay();
        IIC_SCL(1);
        iic_delay();
        IIC_SCL(0);
        dat <<= 1;
    }
    IIC_SDA(1);
}

///
 //
uint8_t iic_read_byte(uint8_t ack,uint8_t sel)
{
	  IIC_SEL(sel);
    uint8_t i;
    uint8_t dat = 0;
    IIC_SDA_IN();
    
    for (i = 0; i < 8; i++ )
    {
        dat <<= 1;
        IIC_SCL(1);
        iic_delay();
        
        if (IIC_READ_SDA())
        {
            dat++;
        }
        
        IIC_SCL(0);
        iic_delay();
    }
    
    if (ack == 0)
    {
        iic_nack(sel);
    }
    else
    {
        iic_ack(sel);
    }

    return dat;
}

void atk_ms7620_iic_init(void)
{
	  IIC_SEL(0);
    IIC_SDA_OUT();
    IIC_SCL(0);
    iic_delay(); 
    IIC_SDA(0);
    iic_delay();
}

void atk_ms6050_iic_init(void)
{
	  IIC_SEL(1);
    IIC_SDA_OUT();
    IIC_SCL(0);
    iic_delay(); 
    IIC_SDA(0);
    iic_delay();
}

