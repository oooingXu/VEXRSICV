#ifndef DRIVER_MPU6050_INTERFACE_H
#define DRIVER_MPU6050_INTERFACE_H

#include "driver_mpu6050.h"
#include "iic.h"

#ifdef __cplusplus
extern "C"{
#endif

uint8_t mpu6050_interface_iic_init(void);

uint8_t mpu6050_interface_iic_deinit(void);

uint8_t mpu6050_interface_iic_read(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);

uint8_t mpu6050_interface_iic_write(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);

void mpu6050_interface_delay_ms(uint32_t ms);

void mpu6050_interface_debug_print(const char *const fmt, ...);

void mpu6050_interface_receive_callback(uint8_t type);

void mpu6050_interface_dmp_tap_callback(uint8_t count, uint8_t direction);

void mpu6050_interface_dmp_orient_callback(uint8_t orientation);

#ifdef __cplusplus
}
#endif

#endif
