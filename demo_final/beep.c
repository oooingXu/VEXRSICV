#include"tone.h"

void beep(){
   timer_init_periodic(0x7fffffff);
   static uint32_t dur_0 = 250;
   static uint32_t dur_1 = 500;
   static uint32_t dur_2 = 1000;
   tone(12 ,dur_1);
   tone(22 ,dur_1);
   tone(32 ,dur_1);
   tone(12 ,dur_1);

   tone(12 ,dur_1);
   tone(22 ,dur_1);
   tone(32 ,dur_1);
   tone(12 ,dur_1);

   tone(32 ,dur_1);
   tone(42 ,dur_1);
   tone(52 ,dur_2);

   tone(32 ,dur_1);
   tone(42 ,dur_1);
   tone(52 ,dur_2);
   delay_us(10000);

   tone(52 ,dur_0);
   tone(62 ,dur_0);
   tone(52 ,dur_0);
   tone(42 ,dur_0);
   tone(32 ,dur_1);
   tone(12 ,dur_1);

   tone(52 ,dur_0);
   tone(62 ,dur_0);
   tone(52 ,dur_0);
   tone(42 ,dur_0);
   tone(32 ,dur_1);
   tone(12 ,dur_1);
   delay_us(10000);

   tone(12 ,dur_1);
   tone(51,dur_1);
   tone(12 ,dur_2);
   delay_us(10000);

   tone(12 ,dur_1);
   tone(51,dur_1);
   tone(12 ,dur_2);
}

