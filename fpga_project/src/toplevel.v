`timescale 1ns / 1ps

module toplevel(
    input  wire clk50,
    input  wire cpu_reset,//active low

    output wire [12:0]   io_ddr3_O_ddr_addr,
    output wire [2:0]    io_ddr3_O_ddr_ba,
    output wire          io_ddr3_O_ddr_cs_n,
    output wire          io_ddr3_O_ddr_ras_n,
    output wire          io_ddr3_O_ddr_cas_n,
    output wire          io_ddr3_O_ddr_we_n,
    output wire          io_ddr3_O_ddr_clk,
    output wire          io_ddr3_O_ddr_clk_n,
    output wire          io_ddr3_O_ddr_cke,
    output wire          io_ddr3_O_ddr_odt,
    output wire          io_ddr3_O_ddr_reset_n,
    output wire [1:0]    io_ddr3_O_ddr_dqm,
    inout  wire [15:0]   io_ddr3_IO_ddr_dq,
    inout  wire [1:0]    io_ddr3_IO_ddr_dqs,
    inout  wire [1:0]    io_ddr3_IO_ddr_dqs_n,
  
    output wire          io_flash_O_flash_ck,
    output wire          io_flash_O_flash_cs_n,
    inout  wire          io_flash_IO_flash_hold_n,
    inout  wire          io_flash_IO_flash_wp_n,
    inout  wire          io_flash_IO_flash_do,
    inout  wire          io_flash_IO_flash_di,
    input  wire          spi_clock_resetn,
    input  wire          spi_clock_clk,

    input  wire          io_vgaClk,
    output wire          io_vga_vSync,
    output wire          io_vga_hSync,
    output wire          io_vga_colorEn,
    output wire [4:0]    io_vga_color_r,
    output wire [5:0]    io_vga_color_g,
    output wire [4:0]    io_vga_color_b,

    output wire led0
  );
	
   wire io_asyncReset = ~cpu_reset;

   wire ddr3_mem_clk;
   wire ddr3_pll_stop;
   wire ddr3_pll_lock;	

//----------------------VGA------------------------------------//
  
   

//-----------------------DDR3--------------------------------//
	Gowin_PLL_DDR3 pll(
		.clkin    (clk50),
		.lock     (ddr3_pll_lock),
		.clkout2  (ddr3_mem_clk),
		.enclk2   (ddr3_pll_stop)
	);
//----------------------Briey---------------------------------//
  Briey core (
    .io_asyncReset(io_asyncReset),
    .io_axiClk (clk50),

	.io_ddr3_pll_stop    (ddr3_pll_stop),
	.io_ddr3_pll_lock    (ddr3_pll_lock),
	.io_ddr3_O_ddr_addr  (io_ddr3_O_ddr_adrr),
    .io_ddr3_O_ddr_ba    (io_ddr3_O_ddr_ba),
    .io_ddr3_O_ddr_cs_n  (io_ddr3_O_ddr_cs_n),
    .io_ddr3_O_ddr_ras_n (io_ddr3_O_ddr_ras_n),
    .io_ddr3_O_ddr_cas_n (io_ddr3_O_ddr_cas_n),
    .io_ddr3_O_ddr_we_n  (io_ddr3_O_ddr_we_n),
    .io_ddr3_O_ddr_clk   (io_ddr3_O_ddr_clk),
    .io_ddr3_O_ddr_clk_n (io_ddr3_O_ddr_clk_n),
    .io_ddr3_O_ddr_cke   (io_ddr3_O_ddr_cke),
    .io_ddr3_O_ddr_odt   (io_ddr3_O_ddr_odt),
    .io_ddr3_O_ddr_reset_n(io_ddr3_O_ddr_reset_n),
    .io_ddr3_O_ddr_dqm   (io_ddr3_O_ddr_dqm),
    .io_ddr3_IO_ddr_dq   (io_ddr3_IO_ddr_dq),
    .io_ddr3_IO_ddr_dqs  (io_ddr3_IO_ddr_dqs), 
    .io_ddr3_IO_ddr_dqs_n(io_ddr3_IO_ddr_dqs_n),
	.mem_clk_clk         (ddr3_mem_clk),

    .io_flash_O_flash_ck (io_flash_O_flash_ck),    		
    .io_flash_O_flash_cs_n(io_flash_O_flash_cs_n),
    .io_flash_IO_flash_hold_n(io_flash_IO_flash_hold),
    .io_flash_IO_flash_wp_n(io_flash_IO_flash_wp_n),
    .io_flash_IO_flash_do(io_flash_IO_flash_do),
    .io_flash_IO_flash_di(io_flash_IO_flash_di),
	.spi_clock_resetn    (spi_resetn),
	.spi_clock_clk       (spi_clk),

    .io_vgaClk            (io_vgaClk),
    .io_vga_vSync         (io_vga_vSync),
    .io_vga_hSync         (io_vga_hSync),
    .io_vga_colorEn       (io_vga_colorEn),
    .io_vga_color_r       (io_vga_color_r),
    .io_vga_color_g       (io_vga_color_g),
    .io_vga_color_b       (io_vga_color_b)

	);

endmodule
