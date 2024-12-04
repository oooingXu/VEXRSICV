#include"gpio_hxc.h"

void buzzer(){
	while(1){
		BEEP_GPIO_Write(0,1);
	}
}
