## soc
### Briey
Briey是个官方的soc，使用AXI接口。和Rocket Chip一样，支持Verilator+OpenOCD+GDB仿真。

### Murax
Murax 是一个非常轻的 SoC（它适合 ICE40 FPGA），可以在没有任何外部组件的情况下工作：
- VexRiscv RV32I[中]
- JTAG 调试器 （Eclipse/GDB/openocd 就绪）
- 8 kB 片上 RAM
- 中断支持
- 外设的 APB 总线
- 32 个 GPIO 引脚
- 1 个 16 位预分频器，2 个 16 位定时器
- 一个带 tx/rx fifo 的 UART
