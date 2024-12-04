#include"time.h"

void time_test(){
    timer_init_periodic(0x7fffffff);
    uint32_t st = timer_polling();
    uint32_t one_sec = 50000000;
    uint32_t end = st - one_sec * 30;
    uint32_t tt;
    do{
        tt = timer_polling();
        printf("tt = %d\n",tt);
    }while(tt>end);
}
