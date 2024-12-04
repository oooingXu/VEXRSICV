#ifndef __ATK_MS7620_H
#define __ATK_MS7620_H

#include"stdint.h"
#include "iic.h"

typedef enum
{
    ATK_MS7620_MODE_PS = 0x00,  /* 接近检测模式 */
    ATK_MS7620_MODE_GESTURE,    /* 手势检测模式 */
} atk_ms7620_mode_t;

/* ATK-MS7620模块手势枚举 */
typedef enum
{
    ATK_MS7620_GESTURE_UP = 0x00,
    ATK_MS7620_GESTURE_DOWN,
    ATK_MS7620_GESTURE_LEFT,
    ATK_MS7620_GESTURE_RIGHT,
    ATK_MS7620_GESTURE_FORWARD,
    ATK_MS7620_GESTURE_BACKWARD,
    ATK_MS7620_GESTURE_CLOCKWISE,
    ATK_MS7620_GESTURE_ANTICLOCKWISE,
    ATK_MS7620_GESTURE_WAVE,
} atk_ms7620_gesture_t;

/* 函数错误代码 */
#define ATK_MS7620_EOK      0   /* 没有错误 */
#define ATK_MS7620_ERROR    1   /* 通用错误 */
#define ATK_MS7620_EINVAL   2   /* 参数错误 */
#define ATK_MS7620_EACK     3   /* IIC通讯ACK错误 */

/* 操作函数 */
uint8_t atk_ms7620_init(void);                                  /* ATK-MS7620模块初始化 */
uint8_t atk_ms7620_mode_config(atk_ms7620_mode_t mode);         /* 配置ATK-MS7620模块的模式 */
																																/* ATK_MS7620_MODE_PS : 接近检测模式
																																/* ATK_MS7620_MODE_GESTURE : 手势检测模式 */
uint8_t atk_ms7620_get_obj_brightness(uint8_t *brightness);     /* ATK-MS7620模块获取物体亮度 */
uint8_t atk_ms7620_get_obj_size(uint16_t *size);                /* ATK-MS7620模块获取物体大小 */
uint8_t atk_ms7620_get_gesture(atk_ms7620_gesture_t *gesture);  /* ATK-MS7620模块获取手势 */

#endif
