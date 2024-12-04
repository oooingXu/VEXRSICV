/* from http://rosettacode.org/wiki/Langton%27s_ant#C */

//#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "klib.h"

static int w = 40, h = 25;

static unsigned char *pix = NULL ;

static void refresh(int x, int y) {
  int i, j, k;
  screen_clear();
  uart_screen_clear();
  for (i = k = 0; i < h; i++)
    for (j = 0; j < w; j++, k++)
      print_char(pix[k] ? '#' : ' ', i, j);
      uart_print_char(pix[k] ? '#' : ' ', i, j);
}

void ant() {
  w = screen_tile_width();
  h = screen_tile_height();

  int dx = 0, dy = 1, i, k;
  int x = w / 2, y = h / 2;

  printf("read video config\n");
  char kant[800*480];
  pix = kant;
  printf("malloc ant\n");
  
  memset(pix, 0, w * h);
  screen_clear();
  uart_screen_clear();

  while (1) {
    i = (y * w + x);
    if (pix[i]) k = dx, dx = -dy, dy = k;
    else	      k = dy, dy = -dx, dx = k;

    pix[i] = !pix[i];
    print_char(pix[i] ? 'o' : ' ', y + 1, x + 1);
    uart_print_char(pix[i] ? 'o' : ' ', y + 1, x + 1);

    x += dx, y += dy;

    k = 0;
    if (x < 0) {
      memmove(pix + 1, pix, w * h - 1);
      for (i = 0; i < w * h; i += w) pix[i] = 0;
      x++, k = 1;
    }
    else if (x >= w) {
      memmove(pix, pix + 1, w * h - 1);
      for (i = w-1; i < w * h; i += w) pix[i] = 0;
      x--, k = 1;
    }

    if (y >= h) {
      memmove(pix, pix + w, w * (h - 1));
      memset(pix + w * (h - 1), 0, w);
      y--, k = 1;
    }
    else if (y < 0) {
      memmove(pix + w, pix, w * (h - 1));
      memset(pix, 0, w);
      y++, k = 1;
    }
    if (k) refresh(x, y);
    set_color(ANSI_COLOR_RED);
    uart_set_color(ANSI_COLOR_RED);

    print_char('+', y + 1, x + 1);
    uart_print_char('+', y + 1, x + 1);

    set_color(ANSI_COLOR_RESET);
    uart_set_color(ANSI_COLOR_RESET);

    screen_refresh();
    uart_screen_refresh();

    if(readchar_nonblock()) {
                getchar();
                printf("\033[H\033[J");
                break;
        }
        fputs("\x1b[23A", stdout);
  }
}
