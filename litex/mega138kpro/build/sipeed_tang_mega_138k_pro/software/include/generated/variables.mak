PACKAGES=libc libcompiler_rt libbase libfatfs liblitespi liblitedram libliteeth liblitesdcard liblitesata bios
PACKAGE_DIRS=/home/furiosa/litex/FPGA/litex/litex/soc/software/libc /home/furiosa/litex/FPGA/litex/litex/soc/software/libcompiler_rt /home/furiosa/litex/FPGA/litex/litex/soc/software/libbase /home/furiosa/litex/FPGA/litex/litex/soc/software/libfatfs /home/furiosa/litex/FPGA/litex/litex/soc/software/liblitespi /home/furiosa/litex/FPGA/litex/litex/soc/software/liblitedram /home/furiosa/litex/FPGA/litex/litex/soc/software/libliteeth /home/furiosa/litex/FPGA/litex/litex/soc/software/liblitesdcard /home/furiosa/litex/FPGA/litex/litex/soc/software/liblitesata /home/furiosa/litex/FPGA/litex/litex/soc/software/bios
LIBS=libc libcompiler_rt libbase libfatfs liblitespi liblitedram libliteeth liblitesdcard liblitesata
TRIPLE=riscv64-unknown-elf
CPU=vexriscv
CPUFAMILY=riscv
CPUFLAGS=-march=rv32i2p0_m     -mabi=ilp32 -D__vexriscv__
CPUENDIANNESS=little
CLANG=0
CPU_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/cores/cpu/vexriscv
SOC_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc
PICOLIBC_DIRECTORY=/home/furiosa/litex/FPGA/pythondata-software-picolibc/pythondata_software_picolibc/data
PICOLIBC_FORMAT=integer
COMPILER_RT_DIRECTORY=/home/furiosa/litex/FPGA/pythondata-software-compiler_rt/pythondata_software_compiler_rt/data
export BUILDINC_DIRECTORY
BUILDINC_DIRECTORY=/home/furiosa/FPGA/mega138kpro/build/sipeed_tang_mega_138k_pro/software/include
LIBC_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/libc
LIBCOMPILER_RT_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/libcompiler_rt
LIBBASE_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/libbase
LIBFATFS_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/libfatfs
LIBLITESPI_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/liblitespi
LIBLITEDRAM_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/liblitedram
LIBLITEETH_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/libliteeth
LIBLITESDCARD_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/liblitesdcard
LIBLITESATA_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/liblitesata
BIOS_DIRECTORY=/home/furiosa/litex/FPGA/litex/litex/soc/software/bios
LTO=0
BIOS_CONSOLE_FULL=1