#include"gpio_hxc.h"
#include"delay.h"
#include"time.h"

void delay_us(uint32_t time);

uint32_t Switch(uint32_t t){
    uint32_t time;
    switch(t){
	case 10 : time = 15289;break; //C1
	case 101: time = 14431;break;
	case 20 : time = 13621;break;
	case 201: time = 12856;break;
	case 30 : time = 12135;break;
	case 40 : time = 11454;break;
	case 401: time = 10811;break;
	case 50 : time = 10204;break;
	case 501: time =  9631;break;
	case 60 : time =  9091;break;
	case 601: time =  8581;break;
	case 70 : time =  8099;break;
	case 11 : time =  7645;break; //C2
	case 111: time =  7215;break;
	case 21 : time =  6810;break;
	case 211: time =  6428;break;
	case 31 : time =  6067;break;
	case 41 : time =  5727;break;
	case 411: time =  5405;break;
	case 51 : time =  5102;break;
	case 511: time =  5816;break;
	case 61 : time =  4545;break;
	case 611: time =  4290;break;
	case 71 : time =  4050;break;
	case 12 : time =  3822;break; //C3
	case 121: time =  3608;break;
	case 22 : time =  3405;break;
	case 221: time =  3214;break;
	case 32 : time =  3034;break;
	case 42 : time =  2863;break;
	case 421: time =  2703;break;
	case 52 : time =  2551;break;
	case 521: time =  2408;break;
	case 62 : time =  2273;break;
	case 621: time =  2145;break;
	case 72 : time =  2025;break;
	case 13 : time =  1911;break; //C4
	case 131: time =  1804;break;
	case 23 : time =  1703;break;
	case 231: time =  1607;break;
	case 33 : time =  1517;break;
	case 43 : time =  1432;break;
	case 431: time =  1351;break;
	case 53 : time =  1276;break;
	case 531: time =  1204;break;
	case 63 : time =  1136;break;
	case 631: time =  1073;break;
	case 73 : time =  1012;break;
	case 14 : time =   956;break; //C5
	case 141: time =   902;break;
	case 24 : time =   851;break;
	case 241: time =   804;break;
	case 34 : time =   758;break;
	case 44 : time =   716;break;
	case 441: time =   676;break;
	case 54 : time =   638;break;
	case 541: time =   602;break;
	case 64 : time =   568;break;
	case 641: time =   536;break;
	case 74 : time =   506;break;
	default : time =   478;break;
    }
    return time;
}

void tone(uint32_t t, uint32_t duration){
    uint32_t time = Switch(t);
    uint32_t st = timer_polling(); 
    if(t){
        do{
           BEEP_GPIO_Write(0,1);
           delay_us(time/2);
           BEEP_GPIO_Write(0,0);
           delay_us(time/2);
        }while(st - timer_polling() < duration * ONE_MS);
    } 
    else{
	delay_ms(duration);
    }
}

