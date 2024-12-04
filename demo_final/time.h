#ifndef _TIME_H_
#define _TIME_H_

#include "generated/csr.h"

uint32_t timer_load_read(void);
void timer_init_periodic(uint32_t period);
void timer_init_one_step(uint32_t time);
uint32_t timer_polling(void);

#endif
