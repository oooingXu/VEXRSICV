## 目录
- [SOC](soc/soc.md)
- [CPU](cpu/cpu.md)
- [AM](abstract-machine/AM.md)
- [VexRsicv](VexRsicv/VexRsicv.md)
- [ddr3](ddr3/ddr3.md)
- [fpga_project](fpga_project/fpga_project.md)

  主要参考[VexRiscv](https://github.com/SpinalHDL/VexRiscv),[NJU-ProjectN](https://github.com/NJU-ProjectN/abstract-machine)和[GowinDDR3_AXI4_SpinalHDL](https://github.com/PaserTech-Hardware/GowinDDR3_AXI4_SpinalHDL.git)
  
  基于Gowin_Arora V的[VexRiscv](https://github.com/SpinalHDL/VexRiscv)软核移植实现.

  存储器方面使用高云DDR3 Memory Interface软核,参考[GowinDDR3_AXI4_SpinalHDL](https://github.com/PaserTech-Hardware/GowinDDR3_AXI4_SpinalHDL.git)进行核心总线与DDR3控制器之间耦合.

  FPGA项目主要文件: [verilog file](fpga_project/src)(\*.v)
  ,[netlist file](fpga_project/impl/gwsynthesis)(\*.vg)
  ,[physical constraints file](fpga_project/src)(\*.cst)
  ,[Gowin_PLL软核](https://github.com/shaw-wu/VEXRSICV/tree/main/fpga_projiect/src/gowin_pll)
