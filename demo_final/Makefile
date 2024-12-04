BUILD_DIR?=../build
SOC_DIRECTORY=$(shell pwd)/../build/sipeed_tang_mega_138k_pro
include $(SOC_DIRECTORY)/software/include/generated/variables.mak
include $(SOC_DIRECTORY)/software/common.mak
#DEMO_SRCS = $(wildcard $(shell pwd)/*.c)
#OBJECTS = $(DEMO_SRCS:.c=.o) 
OBJECTS  = donut.o helloc.o crt0.o main.o gpu.o input.o timer.o cmatrix.o dry.o eggs.o ioe.o image.o ant.o hanoi.o snake.o slider.o common.o fce.o mmc.o cpu-addressing.o mario.o ppu.o cpu.o mario-rom.o memory.o psg.o JoyPad.o gpio_hxc.o type.o font.o video.o tetris.o tetris-rom.o battlecity.o battlecity-rom.o circus.o circus-rom.o hunderd.o hunderd-rom.o kungfu.o kungfu-rom.o balloon.o balloon-rom.o bomberman.o bomberman-rom.o castlevania.o castlevania-rom.o exerion.o exerion-rom.o fone.o fone-rom.o karateka.o karateka-rom.o loderunner.o loderunner-rom.o lunarpool.o lunarpool-rom.o mariothree.o mariothree-rom.o pacman.o pacman-rom.o pinball.o pinball-rom.o skydestroyer.o skydestroyer-rom.o spartanx.o spartanx-rom.o stargate.o stargate-rom.o starforce.o starforce-rom.o atk_ms7620.o iic.o ges_test.o pushbox.o battle.o joytest.o block.o atk_ms6050.o inv_mpu.o inv_mpu_dmp_motion_driver.o mputest.o moto.o mouse.o AE_II.o blendoku.o skipsquare.o eattobig.o shake.o beep.o time.o delay.o time_test.o tone.o mmario.o music.o sevclor.o buzzer.o
ifdef WITH_CXX
	OBJECTS += hellocpp.o
	CFLAGS += -DWITH_CXX
endif


all: demo.bin


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

vpath %.a $(PACKAGES:%=../%)

demo.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -T linker.ld -N -o $@ \
		$(OBJECTS) \
		$(PACKAGES:%=-L$(BUILD_DIR)/software/%) \
		-Wl,--whole-archive \
		-Wl,--gc-sections \
		-Wl,-Map,$@.map \
		$(LIBS:lib%=-l%)

ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

donut.o: CFLAGS   += -w

VPATH = $(BIOS_DIRECTORY):$(BIOS_DIRECTORY)/cmds:$(CPU_DIRECTORY)


%.o: %.cpp
	$(compilexx)

%.o: %.c
	$(compile)

%.o: %.S
	$(assemble)

clean:
	$(RM) $(OBJECTS) demo.elf demo.bin .*~ *~

.PHONY: all clean
