#include <stdio.h>
#include <string.h>
#include <generated/csr.h>
#include <generated/soc.h>
#include <stdint.h>

#include "am.h"
#include "klib-macros.h"
#include "klib.h"
#include "atk_ms7620.h"
#include "atk_ms6050.h"
#include "inv_mpu.h"

void __am_timer_init(void);
void __am_gpu_init(void);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
//void __am_input_config(AM_INPUT_CONFIG_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = 1; cfg->has_rtc = 1; }
static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = 0; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = 1; }

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
	[AM_TIMER_CONFIG] = __am_timer_config,
	[AM_TIMER_UPTIME] = __am_timer_uptime,
	[AM_INPUT_CONFIG] = __am_input_config,
	[AM_INPUT_KEYBRD] = __am_input_keybrd,
	[AM_GPU_CONFIG  ] = __am_gpu_config,
	[AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
	[AM_GPU_STATUS  ] = __am_gpu_status,
	[AM_UART_CONFIG ] = __am_uart_config,
};

int ioe_init(void);
int ioe_init(void) {
	uint8_t ret;

	__am_gpu_init();
	__am_timer_init();
	atk_ms6050_init();
    if (ret != 0)
    {
        printf("ATK-MS6050 init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }


	atk_ms6050_dmp_init();
    if (ret != 0)
    {
        printf("ATK-MS6050 DMP init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }


	atk_ms7620_init();
    if (ret != 0){
        printf("ATK-MS7620 init failed!\r\n");
        while (1)
        {
            delay_ms(200);
        }
    }


	return 1;
}

void ioe_read( int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }

static unsigned long int next = 1;
int krand(void);
int krand(void) {
	next = next * 1103515245 + 12345;

	return (unsigned int)(next/65536) % 32768;
}
	
