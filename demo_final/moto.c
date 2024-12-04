#include"legacy.h"
static inline void Vyi8XZjDoj(const char *PNOyOWxJpK) {
  for (; *PNOyOWxJpK; PNOyOWxJpK++) _putc(*PNOyOWxJpK);
}
enum {JIGYRzzmas = 0, J_Sl6Dag5p, Lr13OEObb4, RsBhhiFFvE, yAFGLz8ME3, TSiSLYknYn};
char wondrfwejei = 0;
struct K7z_BayAM3{
 int qBLBhlntx_;
 int JCyb92PO2X;
 int WxSdxkcUJN;
} wpsikkd, wosdjai11ei;
char wios[(800/4)][(600/4)]={};
void aminos();
void owisp();
int ambolliujfsid();
uint8_t fhjd();
void sf45as4f(int erf1kA3ufC);
void woei(char SU7984_mkw);
void GDOlvXNmhT();
int moto() {
  uint8_t quit = 0;
  _ioe_init();
  BEEP_GPIO_Write(0,1);
  aminos();
 owisp();
 GDOlvXNmhT();
  uint32_t XQvYgn4qpu=ambolliujfsid();
 while (1) {
  uint32_t c0esYbnYow=ambolliujfsid();
  if(c0esYbnYow/40 != XQvYgn4qpu/40){
   XQvYgn4qpu=c0esYbnYow;
   quit = fhjd();
   GDOlvXNmhT();
   if(wondrfwejei == 1){
    Vyi8XZjDoj("Player A (Jade) lost!\n");
    break;
   }
   else if (wondrfwejei == 2){
    Vyi8XZjDoj("Player B (Violet) lost!\n");
    break;
   }
   else if(quit == 1){break;}
  }
  }
  BEEP_GPIO_Write(0,0);
  __am_gpu_init();
}
int pu0XGjLhxR(int erf1kA3ufC){
 switch(erf1kA3ufC){
  case _KEY_W: return _KEY_S;
  case _KEY_S: return _KEY_W;
  case _KEY_A: return _KEY_D;
  case _KEY_D: return _KEY_A;
  case _KEY_UP: return _KEY_DOWN;
  case _KEY_DOWN: return _KEY_UP;
  case _KEY_LEFT: return _KEY_RIGHT;
  case _KEY_RIGHT: return _KEY_LEFT;
 }
 return 0;
}
uint8_t fhjd(){
  uint8_t quit = 0;
  int UaykZDyUUN = 0, ufBizpkLbx = 0, QkSY7m7Gvu = 0;
  UaykZDyUUN = read_key();
 while(((UaykZDyUUN) & ~0x8000)!=_KEY_NONE && (((UaykZDyUUN) & 0x8000) != 0)){
  switch(((UaykZDyUUN) & ~0x8000)){
   case _KEY_W: case _KEY_S: case _KEY_A: case _KEY_D:
     ufBizpkLbx = UaykZDyUUN; break;
   case _KEY_UP: case _KEY_DOWN: case _KEY_LEFT: case _KEY_RIGHT:
     QkSY7m7Gvu = UaykZDyUUN; break;
   case _KEY_Q:
     quit = 1; BEEP_GPIO_Write(0,0); break;
   default: Vyi8XZjDoj("ILLEGAL KEY\n");
  }
    UaykZDyUUN = read_key();
 }
  if(((ufBizpkLbx) & ~0x8000) != _KEY_NONE && (((ufBizpkLbx) & 0x8000) != 0)
    && ((ufBizpkLbx) & ~0x8000) != pu0XGjLhxR(wpsikkd.WxSdxkcUJN))
   sf45as4f(((ufBizpkLbx) & ~0x8000));
 else
  sf45as4f(wpsikkd.WxSdxkcUJN);
 woei(1);
 if(((QkSY7m7Gvu) & ~0x8000) != _KEY_NONE && (((QkSY7m7Gvu) & 0x8000) != 0)
    && ((QkSY7m7Gvu) & ~0x8000) != pu0XGjLhxR(wosdjai11ei.WxSdxkcUJN))
  sf45as4f(((QkSY7m7Gvu) & ~0x8000));
 else
  sf45as4f(wosdjai11ei.WxSdxkcUJN);
 woei(2);
 return quit;
}
int ukvKuleR4X, ameshing;
void aminos() {
  ukvKuleR4X = screen_width();
  ameshing = screen_height();
}
void anba(int gZ5nzpxC8r, int OqmibpybCn, int ukvKuleR4X, int ameshing, uint32_t PbckqMrTl2) {
  uint32_t XaRzohPKKN[ukvKuleR4X * ameshing];
  for (int cZ5d65ts5U = 0; cZ5d65ts5U < ukvKuleR4X * ameshing; cZ5d65ts5U++) {
    XaRzohPKKN[cZ5d65ts5U] = PbckqMrTl2;
  }
  draw_rect(XaRzohPKKN, gZ5nzpxC8r, OqmibpybCn, ukvKuleR4X, ameshing);
}
void GDOlvXNmhT(){
 int h7WHgbkyVu[] = {0x283232, 0x51CC99, 0xFF66FF, 0xFFFFFF, 0xFF00000,0xFFFF00};
 for(int gZ5nzpxC8r=0;gZ5nzpxC8r*4<ukvKuleR4X;gZ5nzpxC8r++){
  for(int OqmibpybCn=0;OqmibpybCn*4<ameshing;OqmibpybCn++){
   anba(gZ5nzpxC8r*4,OqmibpybCn*4,4,4,h7WHgbkyVu[(int)wios[gZ5nzpxC8r][OqmibpybCn]]);
  }
 }
  draw_sync();
}
int ambolliujfsid(){
  return uptime();
}
void owisp(){
 int Apv7PJcujL = ukvKuleR4X / 4;
 int raB0cxTuRP = ameshing / 4;
 wpsikkd.qBLBhlntx_= Apv7PJcujL / 4;
 wpsikkd.JCyb92PO2X= raB0cxTuRP / 2;
 wpsikkd.WxSdxkcUJN=_KEY_D;
 wosdjai11ei.qBLBhlntx_= Apv7PJcujL * 3 / 4;
 wosdjai11ei.JCyb92PO2X= raB0cxTuRP / 2;
 wosdjai11ei.WxSdxkcUJN=_KEY_LEFT;
 for(int gZ5nzpxC8r=0;gZ5nzpxC8r<Apv7PJcujL;gZ5nzpxC8r++){
  wios[gZ5nzpxC8r][0]=RsBhhiFFvE;
  wios[gZ5nzpxC8r][raB0cxTuRP-1]=RsBhhiFFvE;
 }
 for(int OqmibpybCn=0;OqmibpybCn<raB0cxTuRP;OqmibpybCn++){
  wios[0][OqmibpybCn]=RsBhhiFFvE;
  wios[Apv7PJcujL-1][OqmibpybCn]=RsBhhiFFvE;
 }
}
void sf45as4f(int erf1kA3ufC){
 switch(erf1kA3ufC){
  case _KEY_W:
   wpsikkd.WxSdxkcUJN = _KEY_W;
   wpsikkd.JCyb92PO2X--;
   break;
  case _KEY_S:
   wpsikkd.WxSdxkcUJN = _KEY_S;
   wpsikkd.JCyb92PO2X++;
   break;
  case _KEY_A:
   wpsikkd.WxSdxkcUJN = _KEY_A;
   wpsikkd.qBLBhlntx_--;
   break;
  case _KEY_D:
   wpsikkd.WxSdxkcUJN = _KEY_D;
   wpsikkd.qBLBhlntx_++;
   break;
  case _KEY_UP:
   wosdjai11ei.WxSdxkcUJN = _KEY_UP;
   wosdjai11ei.JCyb92PO2X--;
   break;
  case _KEY_DOWN:
   wosdjai11ei.WxSdxkcUJN = _KEY_DOWN;
   wosdjai11ei.JCyb92PO2X++;
   break;
  case _KEY_LEFT:
   wosdjai11ei.WxSdxkcUJN = _KEY_LEFT;
   wosdjai11ei.qBLBhlntx_--;
   break;
  case _KEY_RIGHT:
   wosdjai11ei.WxSdxkcUJN = _KEY_RIGHT;
   wosdjai11ei.qBLBhlntx_++;
   break;
  default: printf("No such direction");
 }
}
void woei(char SU7984_mkw){
 switch(SU7984_mkw){
  case 1:
   if(wios[wpsikkd.qBLBhlntx_][wpsikkd.JCyb92PO2X]==JIGYRzzmas){
    wios[wpsikkd.qBLBhlntx_][wpsikkd.JCyb92PO2X]=J_Sl6Dag5p;
   }
   else{
    wios[wpsikkd.qBLBhlntx_][wpsikkd.JCyb92PO2X]=yAFGLz8ME3;
    wios[wpsikkd.qBLBhlntx_-1][wpsikkd.JCyb92PO2X-1]=TSiSLYknYn;
    wios[wpsikkd.qBLBhlntx_-1][wpsikkd.JCyb92PO2X+1]=TSiSLYknYn;
    wios[wpsikkd.qBLBhlntx_+1][wpsikkd.JCyb92PO2X-1]=TSiSLYknYn;
    wios[wpsikkd.qBLBhlntx_+1][wpsikkd.JCyb92PO2X+1]=TSiSLYknYn;
    wondrfwejei = 1;
   }
   break;
  case 2:
   if(wios[wosdjai11ei.qBLBhlntx_][wosdjai11ei.JCyb92PO2X]==JIGYRzzmas){
    wios[wosdjai11ei.qBLBhlntx_][wosdjai11ei.JCyb92PO2X]=Lr13OEObb4;
   }
   else{
    wios[wosdjai11ei.qBLBhlntx_][wosdjai11ei.JCyb92PO2X]=yAFGLz8ME3;
    wios[wosdjai11ei.qBLBhlntx_-1][wosdjai11ei.JCyb92PO2X-1]=TSiSLYknYn;
    wios[wosdjai11ei.qBLBhlntx_-1][wosdjai11ei.JCyb92PO2X+1]=TSiSLYknYn;
    wios[wosdjai11ei.qBLBhlntx_+1][wosdjai11ei.JCyb92PO2X-1]=TSiSLYknYn;
    wios[wosdjai11ei.qBLBhlntx_+1][wosdjai11ei.JCyb92PO2X+1]=TSiSLYknYn;
    wondrfwejei = 2;
   }
   break;
 }
}
