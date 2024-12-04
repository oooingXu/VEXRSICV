#include"tone.h"
#include"delay.h" 
#include"music.h" 

Music MMario;
//uint16_t mario_nmn[MARIO_LENGTH][2];

void mmario(){
    timer_init_periodic(0x7fffffff);
    MMario.length = MARIO_LENGTH;
    MMario.rate = MARIO_DUR1;
    MMario.NMN = mario_nmn;
    music_display(&MMario,0);
//    static uint32_t dur_0 = 150;
//    static uint32_t dur_1 = 300;
//    static uint32_t dur_2 = 600;
//
//while(1){
//    tone(33 ,dur_0);
//    tone(0  ,5);
//    tone(33 ,dur_0);
//    tone(0  ,dur_0);
//    tone(33 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(33 ,dur_1);
//    
//    tone(53 ,dur_1);
//    tone(0  ,dur_1);
//    tone(52 ,dur_0);
//    tone(0  ,dur_1);
///*-------------------*/
//    tone(13 ,dur_1);
//    tone(0  ,dur_0);
//    tone(52 ,dur_1);
//    tone(0  ,dur_0);
//    tone(32 ,dur_1);
//
//    tone(0  ,dur_0);
//    tone(62 ,dur_1);
//    tone(72 ,dur_1);
//    tone(621,dur_0);
//    tone(0  ,50);
//    tone(621,dur_1);
//
//    tone(52 ,200);
//    tone(33 ,200);
//    tone(53 ,200);
//    tone(63 ,dur_1);
//    tone(43 ,dur_0);
//    tone(53 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(33 ,dur_1);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//    tone(72 ,dur_1);
//    tone(0  ,dur_0);
///*-------------------*/
//    tone(13 ,dur_1);
//    tone(0  ,dur_0);
//    tone(52 ,dur_1);
//    tone(0  ,dur_0);
//    tone(32 ,dur_1);
//
//    tone(0  ,dur_0);
//    tone(62 ,dur_1);
//    tone(72 ,dur_1);
//    tone(621,dur_0);
//    tone(0  ,10);
//    tone(621,dur_1);
//
//    tone(52 ,200);
//    tone(33 ,200);
//    tone(53 ,200);
//    tone(63 ,dur_1);
//    tone(43 ,dur_0);
//    tone(53 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(33 ,dur_1);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//    tone(72 ,dur_1);
//    tone(0  ,dur_0);
///*-------------------*/
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(521,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(14 ,dur_1);
//    tone(0  ,5);
//    tone(14 ,dur_0);
//    tone(0  ,5);
//    tone(14 ,dur_1);
//    tone(0  ,dur_1);
//
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(521,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//    
//    tone(0  ,dur_1);
//    tone(231,dur_1);
//    tone(0  ,dur_0);
//    tone(231,dur_1);
//    tone(0  ,dur_0);
//
//    tone(13 ,dur_1);
//    tone(0  ,dur_1);
//    tone(0  ,dur_1);
//    tone(0  ,dur_1);
///*-------------------*/
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(521,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(14 ,dur_1);
//    tone(0  ,5);
//    tone(14 ,dur_0);
//    tone(0  ,5);
//    tone(14 ,dur_1);
//    tone(0  ,dur_1);
//
//    tone(0  ,dur_1);
//    tone(53 ,dur_0);
//    tone(431,dur_0);
//    tone(0  ,5);
//    tone(431,dur_0);
//    tone(231,dur_1);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_0);
//    tone(521,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//    
//    tone(0  ,dur_1);
//    tone(231,dur_1);
//    tone(0  ,dur_0);
//    tone(231,dur_1);
//    tone(0  ,dur_0);
//
//    tone(13 ,dur_1);
//    tone(0  ,dur_1);
//    tone(0  ,dur_1);
//    tone(0  ,dur_1);
///*-------------------*/
//    tone(13 ,dur_0);
//    tone(0  ,5);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_1);
//
//    tone(33 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(52 ,dur_2);
//
//    tone(13 ,dur_0);
//    tone(0  ,5);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_0);
//    tone(33 ,dur_0);
//
//    tone(0  ,dur_2);
//    tone(0  ,dur_2);
//
//    tone(13 ,dur_0);
//    tone(0  ,5);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(13 ,dur_0);
//    tone(23 ,dur_1);
//
//    tone(33 ,dur_0);
//    tone(13 ,dur_0);
//    tone(0  ,dur_0);
//    tone(62 ,dur_0);
//    tone(52 ,dur_2);
//
////    tone(33 ,dur_0);
////    tone(0  ,5);
////    tone(33 ,dur_0);
////    tone(0  ,dur_0);
////    tone(33 ,dur_0);
////    tone(0  ,dur_0);
////    tone(13 ,dur_0);
////    tone(33 ,dur_1);
////    
////    tone(53 ,dur_1);
////    tone(0  ,dur_1);
////    tone(52 ,dur_0);
////    tone(0  ,dur_1);
//}
}
