#include "am.h"
#include "atk_ms7620.h"
#include <stdio.h>

/*
void __am_input_config(AM_INPUT_CONFIG_T *kbd) {
	printf("input config\n");
	char key;
	uint8_t mark = JOYPAD_Read();
	printf("joy = %d\n", mark);
	
	kbd->keydown = (mark != 0);
	
	switch(mark) {
		case 64: key = 'A';
		case 16: key = 'W';
		case 128: key = 'D';
		case 12: key = 'S';
		case 4: key = 'U';
		case 8: key = 'I';
		case 2: key = 'J';
		case 1: key = 'K';
		default: key = AM_KEY_NONE;
	}

	kbd->keycode = key;
}
*/

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
/*
	if(kbd->keydown) {
		kbd->keycode = 'I';
		//kbd->keycode = uart_read();
	} else {
		kbd->keycode = AM_KEY_NONE;
	}
*/

	atk_ms7620_gesture_t gesture;
	uint8_t ret;
	uint8_t mark;
	char key;
    int pit, rol, yaw;
    int16_t acc_x, acc_y, acc_z;
    int16_t gyr_x, gyr_y, gyr_z;
    int16_t temp;

    /* 初始化ATK-MS7620模块 */
/*
    ret = atk_ms7620_init();
    if (ret != 0){
        printf("ATK-MS7620 init failed!\r\n");
        while (1)
        {   
            delay_ms(200);
        }
    }
*/

    /* 配置ATK-MS7620模块为手势检测模式 */
    ret = atk_ms7620_mode_config(1);
    if (ret != 0){
        printf("ATK_MS7620 config failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }

//    printf("ATK-MS7620 config succedded!\r\n");

        /* 获取手势 */
        ret = atk_ms7620_get_gesture(&gesture);
        if (ret == 0) {
	kbd->keydown = 1;
	switch (gesture)
            {
                case 0:
                {
	  	    key = AM_KEY_UP;
                    printf("Gesture: Up\r\n");
                    break;
                }
                case 1:
                {
	  	    key = AM_KEY_DOWN;
                    printf("Gesture: Down\r\n");
                    break;
                }
                case 2:
                {
	  	    key = AM_KEY_LEFT;
                    printf("Gesture: Left\r\n");
                    break;
                }
                case 3:
                {
	  	    key = AM_KEY_RIGHT;
                    printf("Gesture: Right\r\n");
                    break;
                }
                case 4:
                {
	  	    key = AM_KEY_RSHIFT;
                    printf("Gesture: Forward RSHIFT\r\n");
                    break;
                }
                case 5:
                {
	  	    key = AM_KEY_RETURN;
                    printf("Gesture: Backward RETURN\r\n");
                    break;
                }
                case 6:
                {
	  	    key = AM_KEY_Q;
                    printf("Gesture: Clockwise Q\r\n");
                    break;
                }
                case 7:
                {
	  	    key = AM_KEY_P;
                    printf("Gesture: Anticlockwise P\r\n");
                    break;
                }
                case 8:
                {
	  	    key = AM_KEY_SPACE;
                    printf("Gesture: Wave SPACE\r\n");
                    break;
                }
                default:
		{
	  	    key = AM_KEY_NONE;
			printf("None\n");
		}
	    }
	}
	
//	if(key == AM_KEY_NONE){
//	        delay_ms(1000);
//        ret  = atk_ms6050_dmp_get_data(&pit, &rol, &yaw);
//        ret += atk_ms6050_get_accelerometer(&acc_x, &acc_y, &acc_z);
//        ret += atk_ms6050_get_gyroscope(&gyr_x, &gyr_y, &gyr_z);
//        ret += atk_ms6050_get_temperature(&temp);
//                printf("pit: %d, rol: %d, yaw: %d, ", pit, rol, yaw);
//                printf("acc_x: %d, acc_y: %d, acc_z: %d, ", acc_x, acc_y, acc_z);
//                printf("gyr_x: %d, gyr_y: %d, gyr_z: %d, ", gyr_x, gyr_y, gyr_z);
//                printf("temp: %d\r\n", temp);
//
//	}

	if(key == AM_KEY_NONE){
	mark = JOYPAD_Read();
//	printf("JOYPAD = %d\n", mark);
	
	kbd->keydown = (mark != 0);
	
	switch(mark) {
		case  64: key = AM_KEY_A; break;
		case  16: key = AM_KEY_W;break;
		case 128: key = AM_KEY_D;break;
		case  32: key = AM_KEY_S;break;
		case   4: key = AM_KEY_U;break;
		case   8: key = AM_KEY_I;break;
		case   2: key = AM_KEY_J;break;
		case   1: key = AM_KEY_K;break;
		case  18: key = AM_KEY_SPACE;break;
		default: key = AM_KEY_NONE;
	}

	}
	if(key == AM_KEY_NONE){
	mark = JOYPAD_Read_0();
//	printf("JOYPAD0 = %d\n", mark);
	
	kbd->keydown = (mark != 0);
	
	switch(mark) {
		case 64: key = AM_KEY_LEFT; break;
		case 16: key = AM_KEY_UP;break;
		case 128: key = AM_KEY_RIGHT;break;
		case 32: key = AM_KEY_DOWN;break;
		case 4: key = AM_KEY_Q;break;
		case 8: key = AM_KEY_R;break;
		case 2: key = AM_KEY_RSHIFT;break;
		case 1: key = AM_KEY_RETURN;break;
		case  18: key = AM_KEY_SPACE;break;
		default: key = AM_KEY_NONE;
	}
	}
//	printf("A = %d, W = %d, S = %d, D = %d\n J = %d, K = %d, U = %d, I = %d\n", AM_KEY_A,  AM_KEY_W, AM_KEY_S, AM_KEY_D, AM_KEY_J, AM_KEY_K, AM_KEY_U, AM_KEY_I);
//	printf("up = %d, down = %d, right = %d, left = %d\n", (AM_KEY_UP), (AM_KEY_DOWN), (AM_KEY_RIGHT), (AM_KEY_LEFT));

	kbd->keycode = key;
}
