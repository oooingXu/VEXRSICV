//Copyright (C)2014-2023 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//Tool Version: V1.9.9
//Part Number: GW5AST-LV138FPG676AC1/I0
//Device: GW5AST-138B
//Device Version: B
//Created Time: Fri Oct 25 20:59:23 2024

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    Gowin_PLL your_instance_name(
        .lock(lock_o), //output lock
        .clkout0(clkout0_o), //output clkout0
        .clkout2(clkout2_o), //output clkout2
        .clkin(clkin_i), //input clkin
        .enclk0(enclk0_i), //input enclk0
        .enclk2(enclk2_i) //input enclk2
    );

//--------Copy end-------------------
