#include <stdio.h>
#include "joypad.h" 
#include "am.h"
#include "amdev.h"
#include "klib-macros.h"

void joytest(){ 
  	while(1){
//	printf("AM_INPUT_KEYBRD_T\n");
    	AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
//	printf("io_read input\n");
	   printf("data2 = %d, char = %c\n", ev.keydown, ev.keycode);
//	printf("data1 = %d\n",data1);
	}
}

