#include "legacy.h"
#include <assert.h>

void sfdfsaf45();

int jmp() {
  if (_ioe_init() != 1)
    _halt(1);

  printf("------------------------------\n");
  sfdfsaf45();

  return 0;
}

struct {
  int PNOyOWxJpK, JIGYRzzmas, J_Sl6Dag5p;
  uint32_t Lr13OEObb4;
} dfkasj;

static void yAFGLz8ME3(int PNOyOWxJpK) {
  dfkasj.PNOyOWxJpK = PNOyOWxJpK;
  dfkasj.JIGYRzzmas = screen_width();
  dfkasj.J_Sl6Dag5p = screen_height();
  dfkasj.Lr13OEObb4 = 0;
}

static void TSiSLYknYn() {
  while (uptime() < dfkasj.Lr13OEObb4)
    continue;
  dfkasj.Lr13OEObb4 += 1000 / dfkasj.PNOyOWxJpK;
}

struct {
  int ExGIFMPbha;
  int K7z_BayAM3;
} ks1212lsk;

static void JCyb92PO2X() {
  ks1212lsk.ExGIFMPbha = 0;
  ks1212lsk.K7z_BayAM3 = 0;
}

static void WxSdxkcUJN() {
  if (ks1212lsk.ExGIFMPbha < 30)
    ks1212lsk.ExGIFMPbha++;
}

struct {
  int eZelonvCFU, hck0ckSSZL;
  int XD7kFstGd3[4096];
  int UQRn26Bmz5[4096];
} kslsk;

static void akI2wblQIp() {
  kslsk.eZelonvCFU = kslsk.hck0ckSSZL = 0;
}

static void siuw889(int XD7kFstGd3, int UQRn26Bmz5) {
  kslsk.XD7kFstGd3[kslsk.hck0ckSSZL] = XD7kFstGd3;
  kslsk.UQRn26Bmz5[kslsk.hck0ckSSZL] = UQRn26Bmz5;
  kslsk.hck0ckSSZL++;
  assert(kslsk.hck0ckSSZL <= 4096);
}

static inline int W2yp9bnpy5(int erf1kA3ufC, int IOjC2fkbCg) {
  assert(erf1kA3ufC < IOjC2fkbCg);
  return rand() % (IOjC2fkbCg - erf1kA3ufC) + erf1kA3ufC;
}

static void SU7984_mkw() {
  int XD7kFstGd3 = kslsk.XD7kFstGd3[kslsk.hck0ckSSZL - 1];
  int GDOlvXNmhT = kslsk.UQRn26Bmz5[kslsk.hck0ckSSZL - 1];
  int XQvYgn4qpu = W2yp9bnpy5(2, 10);
  int c0esYbnYow = XD7kFstGd3 + W2yp9bnpy5(GDOlvXNmhT + XQvYgn4qpu + 1, 40);
  siuw889(c0esYbnYow, XQvYgn4qpu);
}

static uint32_t *pu0XGjLhxR;
const uint32_t lklas125 = 0x00000000;
const uint32_t fahjfk = 0x006a005f;
const uint32_t sjidj1 = 0x00ffff00;
const uint32_t d4f5fgsd4 = 0x00ff0000;

static void h72Vdp9m1b(uint32_t vZkqLfCIMW) {
  for (int K7z_BayAM3 = 0; K7z_BayAM3 < dfkasj.J_Sl6Dag5p; K7z_BayAM3++)
    for (int XD7kFstGd3 = 0; XD7kFstGd3 < dfkasj.JIGYRzzmas; XD7kFstGd3++)
        pu0XGjLhxR[K7z_BayAM3 * dfkasj.JIGYRzzmas + XD7kFstGd3] = vZkqLfCIMW;
}

static void ksksld5(uint32_t vZkqLfCIMW, int XD7kFstGd3, int K7z_BayAM3, int OqmibpybCn, int PbckqMrTl2) {
  for (int XaRzohPKKN = K7z_BayAM3; XaRzohPKKN < K7z_BayAM3 + PbckqMrTl2 && XaRzohPKKN < dfkasj.J_Sl6Dag5p; ++XaRzohPKKN)
    if (XaRzohPKKN >= 0)
      for (int cZ5d65ts5U = XD7kFstGd3; cZ5d65ts5U < XD7kFstGd3 + OqmibpybCn && cZ5d65ts5U < dfkasj.JIGYRzzmas; ++cZ5d65ts5U)
        if (cZ5d65ts5U >= 0)
          pu0XGjLhxR[XaRzohPKKN * dfkasj.JIGYRzzmas + cZ5d65ts5U] = vZkqLfCIMW;
}

static void h7WHgbkyVu(uint32_t vZkqLfCIMW) {
  int Apv7PJcujL = 30 - ks1212lsk.ExGIFMPbha + 5;
  int raB0cxTuRP = dfkasj.J_Sl6Dag5p / 2;

  ksksld5(vZkqLfCIMW, 100 - 2, raB0cxTuRP - ks1212lsk.K7z_BayAM3 - Apv7PJcujL,
             2 * 2, Apv7PJcujL);
}

static void AlM0UT25fL(uint32_t vZkqLfCIMW) {
  for (int cZ5d65ts5U = kslsk.eZelonvCFU; cZ5d65ts5U < kslsk.hck0ckSSZL; ++cZ5d65ts5U)
    ksksld5(vZkqLfCIMW, kslsk.XD7kFstGd3[cZ5d65ts5U] - kslsk.UQRn26Bmz5[cZ5d65ts5U],
               dfkasj.J_Sl6Dag5p / 2, kslsk.UQRn26Bmz5[cZ5d65ts5U] * 2, 3);
}

static void Wv1JqEgtYr() {
  static int OqmibpybCn = 20;
  ksksld5(d4f5fgsd4, 0, 0, dfkasj.JIGYRzzmas, OqmibpybCn);
  ksksld5(d4f5fgsd4, 0, dfkasj.J_Sl6Dag5p - OqmibpybCn, dfkasj.JIGYRzzmas, OqmibpybCn);
  ksksld5(d4f5fgsd4, 0, 0, OqmibpybCn, dfkasj.J_Sl6Dag5p);
  ksksld5(d4f5fgsd4, dfkasj.JIGYRzzmas - OqmibpybCn, 0, OqmibpybCn, dfkasj.J_Sl6Dag5p);
}

static void pVquJtRsOw() {
  h72Vdp9m1b(lklas125);
  h7WHgbkyVu(fahjfk);
  AlM0UT25fL(sjidj1);
}

static void hRIJHsqzlx() {
  for (int K7z_BayAM3 = 0; K7z_BayAM3 < dfkasj.J_Sl6Dag5p; K7z_BayAM3++)
    draw_rect(&pu0XGjLhxR[K7z_BayAM3 * dfkasj.JIGYRzzmas], 0, K7z_BayAM3, dfkasj.JIGYRzzmas, 1);
  draw_sync();
}

static int mzR186wepk, PNOyOWxJpK, Ni4LED3jUH, MTpeqVwHlI;

static void sdakhjfs45() {
  mzR186wepk = 0;
  PNOyOWxJpK = 60;
  MTpeqVwHlI = 1;
  Ni4LED3jUH = 0;
  pu0XGjLhxR = _heap.start;

  printf("------------------------------\n");
  printf("      score = 0\n");
  yAFGLz8ME3(PNOyOWxJpK);
  JCyb92PO2X();
  akI2wblQIp();
  siuw889(100, 10);
  SU7984_mkw();
  pVquJtRsOw();
  hRIJHsqzlx();
}

static void wcwGfNsCkC() {
  while (1) {
    TSiSLYknYn();
    if (ks1212lsk.ExGIFMPbha <= 0 && ks1212lsk.K7z_BayAM3 <= 0)
      break;
    if (ks1212lsk.ExGIFMPbha > 0) {
      ks1212lsk.ExGIFMPbha--;
      ks1212lsk.K7z_BayAM3 += 2;
    } else {
      ks1212lsk.K7z_BayAM3 -= 2;
    }
    for (int cZ5d65ts5U = kslsk.eZelonvCFU; cZ5d65ts5U < kslsk.hck0ckSSZL; ++cZ5d65ts5U)
      kslsk.XD7kFstGd3[cZ5d65ts5U]--;
    pVquJtRsOw();
    hRIJHsqzlx();
  }
}

static void lklk909() {
  printf("Welcome to my jump game!\n");
  printf("Press SPACE to jmp\n");
  printf("Enter R to restart and q to quit\n");
  printf("Enjoy it!\n");
}

void sfdfsaf45() {
  lklk909();
  sdakhjfs45();

  while (1) {
    TSiSLYknYn();

    int vK_Tb2f4LK = read_key();
    int T2L2xQFOiP = 0;
    if (vK_Tb2f4LK & 0x8000) {
      vK_Tb2f4LK ^= 0x8000;
      T2L2xQFOiP = 1;
    }

    if (vK_Tb2f4LK == _KEY_Q)
      break;

    if (vK_Tb2f4LK == _KEY_R && T2L2xQFOiP) {
      sdakhjfs45();
      continue;
    }

    if (vK_Tb2f4LK != _KEY_SPACE)
      continue;

    if (mzR186wepk == 0) {
      if (T2L2xQFOiP) {
        WxSdxkcUJN();
        pVquJtRsOw();
        hRIJHsqzlx();
        mzR186wepk = 1;
      }
    }
    else if (mzR186wepk == 1) {
      if (T2L2xQFOiP) {
        WxSdxkcUJN();
        pVquJtRsOw();
        hRIJHsqzlx();
      } else {
        wcwGfNsCkC();
        int XD7kFstGd3 = kslsk.XD7kFstGd3[kslsk.hck0ckSSZL - 1];
        int GDOlvXNmhT = kslsk.UQRn26Bmz5[kslsk.hck0ckSSZL - 1];
        if (XD7kFstGd3 - GDOlvXNmhT >= 100 + 2 || XD7kFstGd3 + GDOlvXNmhT <= 100 - 2) {
          mzR186wepk = 3;
          Wv1JqEgtYr();
          hRIJHsqzlx();
        } else {
          if(XD7kFstGd3 >= 100 - 1 && XD7kFstGd3 <= 100 + 1)
            MTpeqVwHlI *= 2;
          else
            MTpeqVwHlI = 1;
          Ni4LED3jUH += MTpeqVwHlI;
          printf("+%d    score = %d\n", MTpeqVwHlI, Ni4LED3jUH);
          SU7984_mkw();
          pVquJtRsOw();
          hRIJHsqzlx();
          mzR186wepk = 0;
        }
      }
    }
  }
}
