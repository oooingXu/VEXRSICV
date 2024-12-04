#include <stdio.h>
#include <string.h>
#include <generated/csr.h>

#include "am.h"

int white = 0x00ffffff;
int black = 0x00000000;

void __am_gpu_init() {
	//video_framebuffer_dma_base_write(GPUSRAM);
	
	uint32_t h = video_framebuffer_vtg_vres_read();
	uint32_t w = video_framebuffer_vtg_hres_read() - 130;
	int i;

	uint32_t *fb = (uint32_t *)(uintptr_t)video_framebuffer_dma_base_read();
	for(int i = 0; i < h + 1; i++) {
		for(int j = 0; j < w; j++) {
			fb[i * 800 + j] = black;
		}
	}
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {

	uint32_t h = video_framebuffer_vtg_vres_read();
	uint32_t w = video_framebuffer_vtg_hres_read() - 130;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
        int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
        if(!ctl->sync && (w == 0 || h == 0)) return;

        uint32_t *pixels = ctl->pixels;
	uint32_t* fb = (uint32_t *)(uintptr_t)video_framebuffer_dma_base_read();
	//printf("gpu addr = 0x%08x\n", video_framebuffer_dma_base_read());
        uint32_t screen_w = ctl->w;
// ******** 1 *******
/*
        for(int i = y; i < y + h; i++) {
                for(int j = x; j < w + x; j++) {
                        fb[800 * i + j] = pixels[w * (i - y) + (j - x)];
                }
        }
*/

// ******** 2 *******
/*
	for(int i = 0; i < h; i++) {
    // 计算目标地址和源地址
    void* dest = fb + 800 * (y + i) + x; // 目标帧缓冲区的起始地址
    const void* src = pixels + w * i;    // 源像素数组的起始地址

    // 使用memcpy复制一行的像素数据
    //memcpy(dest, src, w * sizeof(pixels[0]));
    memmove(dest, src, w * sizeof(pixels[0]));
}
*/

// ******** 3 *******
int destStride = 800; // 帧缓冲区的行宽
int srcStride = w;    // 源像素数组的行宽
int pixelSize = sizeof(pixels[0]); // 像素的大小

// 计算目标地址和源地址的初始偏移
void* dest = fb + destStride * y + x;
const void* src = pixels;

for(int i = 0; i < h; i++) {
    // 使用memcpy复制一行的像素数据
    memcpy(dest, src, srcStride * pixelSize);

    // 更新指针到下一行
    dest = (char*)dest + destStride * pixelSize;
    src = (const char*)src + srcStride * pixelSize;
}

// ******** 4 *******
/*
int destStride = 800; // 帧缓冲区的行宽
int srcStride = w;    // 源像素数组的行宽
int pixelSize = sizeof(pixels[0]); // 像素的大小
int destStrideBytes = destStride * pixelSize; // 目标行宽的字节数
int srcStrideBytes = srcStride * pixelSize;   // 源行宽的字节数

unsigned char* destPtr = (unsigned char*)fb + destStrideBytes * y + x * pixelSize;
const unsigned char* srcPtr = (const unsigned char*)pixels;

for(int i = 0; i < h; i++) {
    // 根据像素大小选择最合适的复制方式
    switch (pixelSize) {
        case 1:
            // 如果像素大小为1字节，可以使用memmove
            memmove(destPtr, srcPtr, srcStrideBytes);
            break;
        case 2:
            // 如果像素大小为2字节，可以使用uint16_t指针
            memcpy(destPtr, srcPtr, srcStrideBytes);
            break;
        case 4:
            // 如果像素大小为4字节，可以使用uint32_t指针
            memcpy(destPtr, srcPtr, srcStrideBytes);
            break;
        default:
            // 对于其他大小，仍然使用memcpy
            memcpy(destPtr, srcPtr, srcStrideBytes);
            break;
    }

    // 更新指针到下一行
    destPtr += destStrideBytes;
    srcPtr += srcStrideBytes;
}
*/


	if(ctl->sync) {
		video_framebuffer_dma_enable_write(1);
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
	status->ready = 1;
}
