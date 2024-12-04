#include <stdio.h>
#include <generated/csr.h>

#define FPS 30
#define N   32

static inline uint32_t pixel(uint8_t r, uint8_t g, uint8_t b) {
  return (r << 16) | (g << 8) | b;
}
static inline uint8_t R(uint32_t p) { return p >> 16; }
static inline uint8_t G(uint32_t p) { return p >> 8; }
static inline uint8_t B(uint32_t p) { return p; }

static uint32_t canvas[N][N];
static int used[N][N];

static uint32_t color_buf[32 * 32];

void redraw() {
  int w = video_framebuffer_vtg_vres_read() / N;
  int h = video_framebuffer_vtg_vres_read() / N;
  int block_size = w * h;

  int x, y, k;
  for (y = 0; y < N; y ++) {
    for (x = 0; x < N; x ++) {
      for (k = 0; k < block_size; k ++) {
        color_buf[k] = canvas[y][x];
      }
      video_write(x * w, y * h, color_buf, w, h, 0);
    }
  }
  video_write(0, 0, NULL, 0, 0, 1);
}

static uint32_t p(int tsc) {
  int b = tsc & 0xff;
  return pixel(b * 6, b * 7, b);
}

void update() {
  static int tsc = 0;
  static int dx[4] = {0, 1, 0, -1};
  static int dy[4] = {1, 0, -1, 0};

  tsc ++;

  for (int i = 0; i < N; i ++)
    for (int j = 0; j < N; j ++) {
      used[i][j] = 0;
    }

  int init = tsc * 1;
  canvas[0][0] = p(init); used[0][0] = 1;
  int x = 0, y = 0, d = 0;
  for (int step = 1; step < N * N; step ++) {
    for (int t = 0; t < 4; t ++) {
      int x1 = x + dx[d], y1 = y + dy[d];
      if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < N && !used[x1][y1]) {
        x = x1; y = y1;
        used[x][y] = 1;
        canvas[x][y] = p(init + step / 2);
        break;
      }
      d = (d + 1) % 4;
    }
  }
}

void video_test(void);
void video_test(void) {

  unsigned long last = 0;
  unsigned long fps_last = 0;
  int fps = 0;

	timer0_en_write(0);
	timer0_reload_write(0);
	timer0_load_write(0xffffffff);
	timer0_en_write(1);

  while (1) {
    unsigned long upt = update_ms();
    if (last - upt > 1/ FPS) {
      update();
      redraw();
      last = upt;
      fps ++;
    }
    if (fps_last - upt > 1) {
      // display fps every 1s
      printf("%ld: FPS = %d\n", upt, fps);
      fps_last = upt;
      fps = 0;
    }
	printf("last = %d, upt = %d, fps_last = %d, fps = %d\n",last, upt, fps_last, fps);
  }
}
