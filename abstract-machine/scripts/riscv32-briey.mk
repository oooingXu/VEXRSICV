include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/briey.mk
# add one
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/briey/libgcc/div.S \
           riscv/briey/libgcc/muldi3.S \
           riscv/briey/libgcc/multi3.c \
           riscv/briey/libgcc/ashldi3.c \
           riscv/briey/libgcc/unused.c
