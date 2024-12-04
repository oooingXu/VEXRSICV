#include "delay.h"
#include "time.h"

void delay_us(uint32_t time) {
    uint32_t load = timer_load_read();
    uint32_t st = timer_polling();         
    uint32_t wait_time = time * ONE_US;    

    uint32_t end = (st >= wait_time) ? (st - wait_time) : (load - (wait_time - st));

    uint32_t tt;
    do {
        tt = timer_polling();             
    } while (!((st >= end && tt <= end) || (st < end && tt > st)));      
}

void delay_ms(uint32_t time) {
    while(time--){    
	delay_us(1000);
    }
}

