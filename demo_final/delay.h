#ifndef _DELAY_H_
#define _DELAY_H_
#include "generated/csr.h"

//Timer Frequency : 50MHZ
#define ONE_US 50     //Timer counts 50 times per us
#define ONE_MS 50000  //Timer counts 50000 times per ms

void delay_us(uint32_t time);
void delay_ms(uint32_t time);

#endif
