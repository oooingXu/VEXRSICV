#include "am.h"
#include "memtest.h"

uint32_t hi = 0;
uint32_t num = 0;
uint64_t read_time() {
	timer0_update_value_write(1);
	uint32_t lo = timer0_value_read();

	uint32_t real = (0xffffffff - lo) / (CONFIG_CLOCK_FREQUENCY / 1000000);
	if(lo / CONFIG_CLOCK_FREQUENCY <= 1) {
		num++;
		real = 0;
	timer0_en_write(0);
	timer0_load_write(0xffffffff);
	//timer0_reload_write(0xffffffff);
	timer0_en_write(1);
		hi = num * 84000000;
	}
	
	uint32_t total = real + hi;
//	printf("real = %lu, hi = %lu, total = %lu, num = %d\n", real, hi, total, num);

	return total;
}

void __am_timer_init() {
	timer0_en_write(0);
	timer0_load_write(0xffffffff);
	//timer0_reload_write(0xffffffff);
	timer0_en_write(1);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
	uptime->us = read_time();
}

