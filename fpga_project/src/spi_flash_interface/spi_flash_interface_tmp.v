//Copyright (C)2014-2023 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//Tool Version: V1.9.9
//Part Number: GW5AST-LV138FPG676AC1/I0
//Device: GW5AST-138
//Device Version: B
//Created Time: Fri Oct 25 09:14:23 2024

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

	SPI_Flash_Interface_Top your_instance_name(
		.I_pclk(I_pclk_i), //input I_pclk
		.I_presetn(I_presetn_i), //input I_presetn
		.I_paddr(I_paddr_i), //input [31:0] I_paddr
		.I_penable(I_penable_i), //input I_penable
		.O_prdata(O_prdata_o), //output [31:0] O_prdata
		.O_pready(O_pready_o), //output O_pready
		.I_psel(I_psel_i), //input I_psel
		.I_pwdata(I_pwdata_i), //input [31:0] I_pwdata
		.I_pwrite(I_pwrite_i), //input I_pwrite
		.I_spi_clock(I_spi_clock_i), //input I_spi_clock
		.I_spi_rstn(I_spi_rstn_i), //input I_spi_rstn
		.O_flash_ck(O_flash_ck_o), //output O_flash_ck
		.O_flash_cs_n(O_flash_cs_n_o), //output O_flash_cs_n
		.IO_flash_hold_n(IO_flash_hold_n_io), //inout IO_flash_hold_n
		.IO_flash_wp_n(IO_flash_wp_n_io), //inout IO_flash_wp_n
		.IO_flash_do(IO_flash_do_io), //inout IO_flash_do
		.IO_flash_di(IO_flash_di_io) //inout IO_flash_di
	);

//--------Copy end-------------------
