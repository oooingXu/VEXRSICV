#ifndef __IIC_H
#define __IIC_H

#include <stdint.h>
#include"gpio_hxc.h"

/* 引脚定义 */
#define ATK_MS7620_IIC_SCL_GPIO_PIN             0
#define ATK_MS7620_IIC_SDA_GPIO_PIN             2
#define MPU6050_IIC_SCL_GPIO_PIN                0
#define MPU6050_IIC_SDA_GPIO_PIN                2
#define OFFSET_MS7620                0x00000000
#define OFFSET_MS6050                0x00000800

/* IO操作 */
#define IIC_SCL(x)                   do{ x ?                                                                                             \
                                            IIC_GPIO_Write( ATK_MS7620_IIC_SCL_GPIO_PIN, 1) :    \
                                            IIC_GPIO_Write( ATK_MS7620_IIC_SCL_GPIO_PIN, 0);   \
                                        }while(0)

#define IIC_SDA(x)                   do{ x ?                                                                                             \
                                            IIC_GPIO_Write( ATK_MS7620_IIC_SDA_GPIO_PIN, 1) :    \
                                            IIC_GPIO_Write( ATK_MS7620_IIC_SDA_GPIO_PIN, 0);   \
                                        }while(0)

#define IIC_READ_SDA()               IIC_GPIO_Read(0)
#define IIC_SDA_OUT()                IIC_GPIO_Set(1,1)
#define IIC_SDA_IN()                 IIC_GPIO_Set(1,0)
#define IIC_SEL(x)                   offset = (x ? OFFSET_MS6050 : OFFSET_MS7620)

/* 操作函数 */
void iic_start(uint8_t sel);                /* 产生IIC起始信号 */
void iic_stop(uint8_t sel);                 /* 产生IIC停止信号 */
uint8_t iic_wait_ack(uint8_t sel);          /* 等待IIC应答信号 */
void iic_ack(uint8_t sel);                  /* 产生ACK应答信号 */
void iic_nack(uint8_t sel);                 /* 不产生ACK应答信号 */
void iic_send_byte(uint8_t dat,uint8_t sel);     /* IIC发送一个字节 */
uint8_t iic_read_byte(uint8_t ack,uint8_t sel);  /* IIC接收一个字节 */
void atk_ms7620_iic_init(void);                 /* 初始化IIC接口 */
void atk_ms6050_iic_init(void);                 /* 初始化IIC接口 */
//extern uint8_t delay_us(uint32_t time);

#endif
