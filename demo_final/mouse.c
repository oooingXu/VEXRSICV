#include"legacy.h"
static inline void Vyi8XZjDoj(const char *PNOyOWxJpK) {
  for (; *PNOyOWxJpK; PNOyOWxJpK++) _putc(*PNOyOWxJpK);
}
void JIGYRzzmas();
void J_Sl6Dag5p(int Lr13OEObb4, int RsBhhiFFvE, int anki, int shdfippp, uint32_t ExGIFMPbha);
void uiuiooo();
void ishjowow();
void pdjfkcccc();
void ijkswxz();
int okokpp;
static int hck0ckSSZL[]={
    _KEY_1, _KEY_2, _KEY_3, _KEY_4, _KEY_5,
    _KEY_6, _KEY_7, _KEY_8, _KEY_9,
};
int cpopsj=0;
int okokhshsxbx=0;
int koskx0s2[9][2];
int jsixnmak[9];
int isjkkknnnm=0;
void mouse() {
  _ioe_init();
  JIGYRzzmas();
  uiuiooo();
  ishjowow();
  unsigned long W2yp9bnpy5, erf1kA3ufC=0, IOjC2fkbCg=0, SU7984_mkw=0;;
  srand(uptime());
  while(1){
    while(1){
        W2yp9bnpy5 = uptime();
        if(W2yp9bnpy5 >= SU7984_mkw) break;
    }
    SU7984_mkw += 1000/100;
    ijkswxz();
    if(W2yp9bnpy5 >= erf1kA3ufC){
        if(okokhshsxbx+cpopsj<30)
            pdjfkcccc();
        erf1kA3ufC += 1000/3;
    }
    if(W2yp9bnpy5 >= IOjC2fkbCg){
        IOjC2fkbCg += 1000/30;
        ishjowow();
    }
    if(isjkkknnnm==1) break;
  }
  ishjowow();
  //return 0;
}
int anki,shdfippp;
void JIGYRzzmas() {
  anki = screen_width();
  shdfippp = screen_height();
  if(anki/3>80 && shdfippp/3>80)
      okokpp = 80;
  else okokpp = (anki/3<shdfippp/3)?anki/3:shdfippp/3;
}
void uiuiooo(){
    int GDOlvXNmhT = 0;
    for(int RsBhhiFFvE=0; RsBhhiFFvE<=shdfippp-shdfippp/3; RsBhhiFFvE+=shdfippp/3){
        for(int Lr13OEObb4=0; Lr13OEObb4<=anki-anki/3; Lr13OEObb4+=anki/3){
            koskx0s2[GDOlvXNmhT][0]=Lr13OEObb4+(anki/3-okokpp)/2;
            koskx0s2[GDOlvXNmhT][1]=RsBhhiFFvE+(shdfippp/3-okokpp)/2;
            GDOlvXNmhT++;
        }
    }
    for(int XQvYgn4qpu=0; XQvYgn4qpu<9; XQvYgn4qpu++)
        jsixnmak[XQvYgn4qpu] = 0;
}
void ishjowow(){
    for(int XQvYgn4qpu=0; XQvYgn4qpu<9; XQvYgn4qpu++){
        if(jsixnmak[XQvYgn4qpu]==0) J_Sl6Dag5p(koskx0s2[XQvYgn4qpu][0], koskx0s2[XQvYgn4qpu][1], okokpp, okokpp, 0xffffff);
        else J_Sl6Dag5p(koskx0s2[XQvYgn4qpu][0], koskx0s2[XQvYgn4qpu][1], okokpp, okokpp, 0xff0000);
    }
    draw_sync();
}
void pdjfkcccc(){
    int XQvYgn4qpu = rand()%9;
    while(1){
        if(jsixnmak[XQvYgn4qpu]==0){
            jsixnmak[XQvYgn4qpu]=1;
            cpopsj++;
            break;
        }
        XQvYgn4qpu = rand()%9;
    }
    if(cpopsj==9){
        isjkkknnnm=1;
        printf("Lose! You farm is filled with mice\n");
    }
}
void ijkswxz(){
    int c0esYbnYow = 0;
    int pu0XGjLhxR = read_key();
    for(int XQvYgn4qpu=0; XQvYgn4qpu<9; XQvYgn4qpu++){
        if(hck0ckSSZL[XQvYgn4qpu]==pu0XGjLhxR){
            if(jsixnmak[XQvYgn4qpu]==1){
                okokhshsxbx++;
                cpopsj--;
                jsixnmak[XQvYgn4qpu]=0;
            }else{
                c0esYbnYow = 1;
            }
            break;
        }
    }
    if(c0esYbnYow==1){
        isjkkknnnm = 1;
        printf("Lose! You beat the wrong place\n");
    }
    if(okokhshsxbx==30){
        isjkkknnnm = 1;
        printf("Win! You have killed all 20 mice\n");
    }
}
void J_Sl6Dag5p(int Lr13OEObb4, int RsBhhiFFvE, int anki, int shdfippp, uint32_t ExGIFMPbha) {
  uint32_t UaykZDyUUN[anki * shdfippp];
  for (int XQvYgn4qpu = 0; XQvYgn4qpu < anki * shdfippp; XQvYgn4qpu++) {
    UaykZDyUUN[XQvYgn4qpu] = ExGIFMPbha;
  }
  draw_rect(UaykZDyUUN, Lr13OEObb4, RsBhhiFFvE, anki, shdfippp);
}
