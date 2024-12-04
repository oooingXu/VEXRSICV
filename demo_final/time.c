#include "time.h"

uint32_t timer_load_read(void){
    return timer0_load_read();
}

void timer_init_periodic(uint32_t period){
    timer0_en_write(0);
    timer0_reload_write(period);
    timer0_load_write(period);
    timer0_en_write(1);
}

uint32_t timer_polling(void){
    timer0_update_value_write(1);
    uint32_t value = timer0_value_read();
    //timer0_update_value_write(0);
    return value;
}
