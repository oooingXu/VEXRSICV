#include"legacy.h"
#include"music.h"
#include<stdio.h>
typedef uint8_t Vyi8XZjDoj;
static void PNOyOWxJpK(uint32_t *JIGYRzzmas, uint32_t *J_Sl6Dag5p)
{
  uint32_t Lr13OEObb4 = *JIGYRzzmas;
  *JIGYRzzmas = *J_Sl6Dag5p;
  *J_Sl6Dag5p = Lr13OEObb4;
}
static int RsBhhiFFvE()
{
  uint32_t yAFGLz8ME3 = 0;
  do
  {
    yAFGLz8ME3 = read_key();
  } while ((yAFGLz8ME3 & 0x8000) == 0);
  return yAFGLz8ME3 & ~(0x8000);
}
static void TSiSLYknYn(const char *ExGIFMPbha)
{
  printf("%s\n", ExGIFMPbha);
}
void dsjak112i();
void sixjfnw1();
void jskddf223();
Vyi8XZjDoj skcignf8();
Vyi8XZjDoj isos1112(Vyi8XZjDoj hck0ckSSZL);
Vyi8XZjDoj sdhjfakw1(int UQRn26Bmz5, Vyi8XZjDoj *hck0ckSSZL);
uint32_t pzoxmcf5[4][4];
uint32_t skcifo8[20] = {0xffffff, 0xff0000, 0xff7f00, 0xffff00, 0x00ff00, 0x00ffff, 0x0000ff, 0x8b00ff};
const int sk23i4[4] = {-1, 0, 1, 0}, hdsjizxj1[4] = {0, -1, 0, 1};
typedef enum
{
  erf1kA3ufC,
  IOjC2fkbCg,
} SU7984_mkw;
typedef struct
{
  int GDOlvXNmhT, XQvYgn4qpu;
} c0esYbnYow;
typedef struct
{
  int pu0XGjLhxR, UaykZDyUUN;
} ufBizpkLbx;
c0esYbnYow sdafjk312, dsfjksdfj, djsksdjc55;
ufBizpkLbx sd415fjk;
SU7984_mkw dfkasfl;
int sevclor()
{
  _ioe_init();
  BEEP_GPIO_Write(0,1);
  dsjak112i();
  Vyi8XZjDoj OqmibpybCn = 0;
  do
  {
    jskddf223();
    OqmibpybCn = skcignf8();
  } while (isos1112(OqmibpybCn));
  BEEP_GPIO_Write(0,0);
  return 0;
}
void jskddf223()
{
  TSiSLYknYn("Welcome to 7Colors Game on bare-metal.");
  TSiSLYknYn("Version 1.0. Copyright (C) 2019-2019 StardustDL.");
  TSiSLYknYn("");
  TSiSLYknYn("Rules:");
  TSiSLYknYn("7Colors game is similar to the famous game 2048, but it's more easy.");
  TSiSLYknYn("You will have blocks in 7 colors: red, orange, yellow, green, cyan, blue and purple.");
  TSiSLYknYn("Just like 2, 4, 8, 16, 32 and so on.");
  TSiSLYknYn("Your goal is to make a purple block by using left/right/up/down key.");
  TSiSLYknYn("Each round the game will append a reg block randomly.");
  TSiSLYknYn("If there is no empty block to append, you will lose.");
  TSiSLYknYn("");
  for (int PbckqMrTl2 = 0; PbckqMrTl2 < 4; PbckqMrTl2++)
    for (int XaRzohPKKN = 0; XaRzohPKKN < 4; XaRzohPKKN++)
    {
      pzoxmcf5[PbckqMrTl2][XaRzohPKKN] = 0;
    }
  pzoxmcf5[rand() % 4][rand() % 4] = 1;
  dfkasfl = IOjC2fkbCg;
  TSiSLYknYn("Game started.");
}
Vyi8XZjDoj sdhjfakw1(int UQRn26Bmz5, Vyi8XZjDoj *hck0ckSSZL)
{
  for (int pu0XGjLhxR = 0; pu0XGjLhxR < 4; pu0XGjLhxR++)
  {
    for (int UaykZDyUUN = 0; UaykZDyUUN < 4; UaykZDyUUN++)
    {
      if (pzoxmcf5[pu0XGjLhxR][UaykZDyUUN] == 0)
        continue;
      int cZ5d65ts5U = pu0XGjLhxR, h7WHgbkyVu = UaykZDyUUN;
      int Apv7PJcujL = pu0XGjLhxR + sk23i4[UQRn26Bmz5], raB0cxTuRP = UaykZDyUUN + hdsjizxj1[UQRn26Bmz5];
      while (Apv7PJcujL >= 0 && Apv7PJcujL < 4 && raB0cxTuRP >= 0 && raB0cxTuRP < 4)
      {
        if (pzoxmcf5[Apv7PJcujL][raB0cxTuRP] == 0)
          PNOyOWxJpK(&pzoxmcf5[Apv7PJcujL][raB0cxTuRP], &pzoxmcf5[cZ5d65ts5U][h7WHgbkyVu]);
        else if (pzoxmcf5[Apv7PJcujL][raB0cxTuRP] == pzoxmcf5[cZ5d65ts5U][h7WHgbkyVu])
        {
          pzoxmcf5[Apv7PJcujL][raB0cxTuRP] += 1;
          pzoxmcf5[cZ5d65ts5U][h7WHgbkyVu] = 0;
        }
        else
          break;
        cZ5d65ts5U = Apv7PJcujL, h7WHgbkyVu = raB0cxTuRP;
        Apv7PJcujL += sk23i4[UQRn26Bmz5];
        raB0cxTuRP += hdsjizxj1[UQRn26Bmz5];
      }
    }
  }
  int AlM0UT25fL = 0;
  *hck0ckSSZL = 0;
  for (int pu0XGjLhxR = 0; pu0XGjLhxR < 4; pu0XGjLhxR++)
    for (int UaykZDyUUN = 0; UaykZDyUUN < 4; UaykZDyUUN++)
    {
      AlM0UT25fL += pzoxmcf5[pu0XGjLhxR][UaykZDyUUN] == 0;
      *hck0ckSSZL = *hck0ckSSZL || pzoxmcf5[pu0XGjLhxR][UaykZDyUUN] >= 7;
    }
  if (AlM0UT25fL == 0)
    return 0;
  int Wv1JqEgtYr = rand() % AlM0UT25fL;
  for (int pu0XGjLhxR = 0; pu0XGjLhxR < 4; pu0XGjLhxR++)
    for (int UaykZDyUUN = 0; UaykZDyUUN < 4; UaykZDyUUN++)
    {
      if (pzoxmcf5[pu0XGjLhxR][UaykZDyUUN] == 0)
      {
        if (Wv1JqEgtYr == 0)
        {
          pzoxmcf5[pu0XGjLhxR][UaykZDyUUN] = 1;
          return 1;
        }
        else
          Wv1JqEgtYr--;
      }
    }
}
Vyi8XZjDoj skcignf8()
{
  if (dfkasfl != IOjC2fkbCg)
  {
    TSiSLYknYn("The game is not running.");
    return 0;
  }
  sixjfnw1();
  while (1)
  {
	int tuichu = 0;
    uint32_t pVquJtRsOw = RsBhhiFFvE();
    Vyi8XZjDoj hRIJHsqzlx = 1, hck0ckSSZL = 0;
    switch (pVquJtRsOw)
    {
    case _KEY_LEFT:
      hRIJHsqzlx = sdhjfakw1(0, &hck0ckSSZL);
      break;
    case _KEY_UP:
      hRIJHsqzlx = sdhjfakw1(1, &hck0ckSSZL);
      break;
    case _KEY_RIGHT:
      hRIJHsqzlx = sdhjfakw1(2, &hck0ckSSZL);
      break;
    case _KEY_DOWN:
      hRIJHsqzlx = sdhjfakw1(3, &hck0ckSSZL);
      break;
    case _KEY_Q:
	tuichu = 1;
	break;
    default:
      break;
    }
	if(tuichu){
	__am_gpu_init();/*wxz*/
	BEEP_GPIO_Write(0,0);
	return 1;
	}

    sixjfnw1();
    if (hck0ckSSZL)
      return 1;
    if (!hRIJHsqzlx)
      return 0;
  }
}
Vyi8XZjDoj isos1112(Vyi8XZjDoj hck0ckSSZL)
{
  if (hck0ckSSZL)
  {
    TSiSLYknYn("You have got the final color-purple.");
    TSiSLYknYn("You WIN!");
  }
  else
  {
    TSiSLYknYn("You have no empty block to move.");
    TSiSLYknYn("You LOSE!");
  }
  dfkasfl = erf1kA3ufC;
  TSiSLYknYn("Game ended.");
  TSiSLYknYn("");
  TSiSLYknYn("If you want to start another game, press key R. Any other key to exit the game.");
  if (_KEY_R == RsBhhiFFvE())
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void dsjak112i()
{
  sdafjk312.GDOlvXNmhT = screen_width();
  sdafjk312.XQvYgn4qpu = screen_height();
  if (sdafjk312.GDOlvXNmhT == sdafjk312.XQvYgn4qpu)
  {
    sd415fjk.pu0XGjLhxR = 0;
    sd415fjk.UaykZDyUUN = 0;
    dsfjksdfj.GDOlvXNmhT = dsfjksdfj.XQvYgn4qpu = sdafjk312.GDOlvXNmhT;
  }
  else if (sdafjk312.GDOlvXNmhT < sdafjk312.XQvYgn4qpu)
  {
    sd415fjk.pu0XGjLhxR = 0;
    sd415fjk.UaykZDyUUN = (sdafjk312.XQvYgn4qpu - sdafjk312.GDOlvXNmhT) / 2;
    dsfjksdfj.GDOlvXNmhT = dsfjksdfj.XQvYgn4qpu = sdafjk312.GDOlvXNmhT;
  }
  else
  {
    sd415fjk.pu0XGjLhxR = (sdafjk312.GDOlvXNmhT - sdafjk312.XQvYgn4qpu) / 2;
    sd415fjk.UaykZDyUUN = 0;
    dsfjksdfj.GDOlvXNmhT = dsfjksdfj.XQvYgn4qpu = sdafjk312.XQvYgn4qpu;
  }
  djsksdjc55.GDOlvXNmhT = dsfjksdfj.GDOlvXNmhT / 4;
  djsksdjc55.XQvYgn4qpu = dsfjksdfj.XQvYgn4qpu / 4;
}
void sjkaixn44(c0esYbnYow Ni4LED3jUH, uint32_t MTpeqVwHlI, uint32_t *tl7Kc3Gx6U)
{
  for (int PbckqMrTl2 = 0; PbckqMrTl2 < Ni4LED3jUH.GDOlvXNmhT * Ni4LED3jUH.XQvYgn4qpu; PbckqMrTl2++)
  {
    tl7Kc3Gx6U[PbckqMrTl2] = MTpeqVwHlI;
  }
}
void sixjfnw1()
{
  uint32_t Tr4A1w4VGP[4 * 4];
  c0esYbnYow wcwGfNsCkC = (c0esYbnYow){4, 4};
  for (int pu0XGjLhxR = sd415fjk.pu0XGjLhxR / 4; pu0XGjLhxR * 4 < sd415fjk.pu0XGjLhxR + dsfjksdfj.GDOlvXNmhT; pu0XGjLhxR++)
  {
    for (int UaykZDyUUN = sd415fjk.UaykZDyUUN / 4; UaykZDyUUN * 4 < sd415fjk.UaykZDyUUN + dsfjksdfj.XQvYgn4qpu; UaykZDyUUN++)
    {
      int ceO5NPYidU = pzoxmcf5[(pu0XGjLhxR * 4 - sd415fjk.pu0XGjLhxR) / djsksdjc55.GDOlvXNmhT][(UaykZDyUUN * 4 - sd415fjk.UaykZDyUUN) / djsksdjc55.XQvYgn4qpu];
      sjkaixn44(wcwGfNsCkC, skcifo8[ceO5NPYidU], Tr4A1w4VGP);
      draw_rect(Tr4A1w4VGP, pu0XGjLhxR * 4, UaykZDyUUN * 4, 4, 4);
    }
  }
  draw_sync();
}
