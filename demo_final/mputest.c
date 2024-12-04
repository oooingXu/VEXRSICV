/**
 ****************************************************************************************************
 * @file        demo.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MS6050模块测试实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "atk_ms6050.h"
#include "inv_mpu.h"

void mputest(void)
{
    uint8_t ret;
    uint8_t key;
    uint8_t niming_report = 0;
    int pit, rol, yaw;
    int16_t acc_x, acc_y, acc_z;
    int16_t gyr_x, gyr_y, gyr_z;
    int16_t temp;
    
    __am_timer_init();
    ret = atk_ms6050_init();
    if (ret != 0)
    {
        printf("ATK-MS6050 init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }
    
    /* 初始化ATK-MS6050 DMP */
    ret = atk_ms6050_dmp_init();
    if (ret != 0)
    {
        printf("ATK-MS6050 DMP init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }
    
    
    while (1)
    {
	delay_ms(1000);
        /* 获取ATK-MS6050 DMP处理后的数据 */
        ret  = atk_ms6050_dmp_get_data(&pit, &rol, &yaw);
        /* 获取ATK-MS6050加速度值 */
        ret += atk_ms6050_get_accelerometer(&acc_x, &acc_y, &acc_z);
        /* 获取ATK-MS6050陀螺仪值 */
        ret += atk_ms6050_get_gyroscope(&gyr_x, &gyr_y, &gyr_z);
        /* 获取ATK-MS6050温度值 */
        ret += atk_ms6050_get_temperature(&temp);
        if (ret == 0)
        {
                printf("pit: %d, rol: %d, yaw: %d, ", pit, rol, yaw);
                printf("acc_x: %d, acc_y: %d, acc_z: %d, ", acc_x, acc_y, acc_z);
                printf("gyr_x: %d, gyr_y: %d, gyr_z: %d, ", gyr_x, gyr_y, gyr_z);
                printf("temp: %d\r\n", temp);
        }
    }
}
