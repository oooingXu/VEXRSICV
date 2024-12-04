#ifndef _MUSIC_H_
#define _MUSIC_H_

#include<stdint.h>
#include"tone.h"

#define MARIO_LENGTH 232 
#define MARIO_DUR0    150
#define MARIO_DUR1    300
#define MARIO_DUR2    600

extern uint16_t mario_nmn[MARIO_LENGTH][2];

typedef struct {
    uint16_t (*NMN)[2];
    uint16_t length;
    uint16_t rate;
}Music;

void music_display(Music *nmn,uint16_t st);

#endif
