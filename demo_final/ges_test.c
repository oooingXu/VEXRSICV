#include"atk_ms7620.h"

/**
 * @brief       例程演示入口函数
 * @param       无
 * @retval      无
 */
void ges_test(void)
{
    uint8_t ret;
    atk_ms7620_gesture_t gesture;
    
    /* 初始化ATK-MS7620模块 */
    ret = atk_ms7620_init();
    printf("init_1\n");
    if (ret != 0){
        printf("ATK-MS7620 init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }
    
    /* 配置ATK-MS7620模块为手势检测模式 */
    printf("config_0\n");
    ret = atk_ms7620_mode_config(ATK_MS7620_MODE_GESTURE);
    printf("config_1\n");
    if (ret != 0){
        printf("ATK_MS7620 config failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }
    
    printf("ATK-MS7620 config succedded!\r\n");
    
    while (1)
    {
        /* 获取手势 */
        ret = atk_ms7620_get_gesture(&gesture);
        if (ret == ATK_MS7620_EOK)
        {
            switch (gesture)
            {
                case ATK_MS7620_GESTURE_UP:
                {
                    printf("Gesture: Up\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_DOWN:
                {
                    printf("Gesture: Down\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_LEFT:
                {
                    printf("Gesture: Left\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_RIGHT:
                {
                    printf("Gesture: Right\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_FORWARD:
                {
                    printf("Gesture: Forward\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_BACKWARD:
                {
                    printf("Gesture: Backward\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_CLOCKWISE:
                {
                    printf("Gesture: Clockwise\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_ANTICLOCKWISE:
                {
                    printf("Gesture: Anticlockwise\r\n");
                    break;
                }
                case ATK_MS7620_GESTURE_WAVE:
                {
                    printf("Gesture: Wave\r\n");
                    break;
                }
                default:
                {
		    printf("defaul\n");
                    break;
                }
            }
        }
    }
}
