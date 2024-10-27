set_device -name GW5AST-138B GW5AST-LV138FPG676AES
add_file sipeed_tang_mega_138k_pro.cst
add_file sipeed_tang_mega_138k_pro.sdc
add_file /home/furiosa/litex/FPGA/pythondata-cpu-vexriscv/pythondata_cpu_vexriscv/verilog/VexRiscv.v
add_file /home/furiosa/FPGA/mega138kpro/build/sipeed_tang_mega_138k_pro/gateware/sipeed_tang_mega_138k_pro.v
set_option -use_ready_as_gpio 1
set_option -use_done_as_gpio 1
set_option -use_mspi_as_gpio 1
set_option -use_sspi_as_gpio 1
set_option -use_cpu_as_gpio 1
set_option -rw_check_on_ram 1
set_option -bit_security 0
set_option -bit_encrypt 0
set_option -bit_compress 0
run all