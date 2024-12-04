module top (
    inout  wire          atkms7620_scl,
    inout  wire          atkms7620_sda,
    output wire          buzzer_out_pwm,
    input  wire          clk50,
    input  wire          joypad2_in_data,
    output wire          joypad2_out_clk,
    output wire          joypad2_out_load,
    input  wire          joypad_in_data,
    output wire          joypad_out_clk,
    output wire          joypad_out_load,
    output wire    [5:0] lcd_b,
    output wire          lcd_clk,
    output wire          lcd_de,
    output wire    [5:0] lcd_g,
    output wire          lcd_hsync_n,
    output wire    [5:0] lcd_r,
    output wire          lcd_vsync_n,
    output wire          led_n0,
    output wire          led_n1,
    output wire          led_n2,
    output wire          led_n3,
    output wire          led_n4,
    output wire          led_n5,
    input  wire          rst,
    output wire   [12:0] sdram_a,
    output wire    [1:0] sdram_ba,
    output wire          sdram_cas_n,
    output wire          sdram_clock,
    output wire          sdram_cs_n,
    output wire    [1:0] sdram_dm,
    inout  wire   [15:0] sdram_dq,
    output wire          sdram_ras_n,
    output wire          sdram_we_n,
    input  wire          serial_rx,
    output reg           serial_tx,
    output reg           spisdcard_clk,
    output reg           spisdcard_cs_n,
    input  wire          spisdcard_miso,
    output reg           spisdcard_mosi
);
    wire gpio_stop;
    wire uart_tx;
    wire spi_clk;
    wire spi_cs_n;
    wire spi_mosi;

always @(*) begin
    serial_tx <= uart_tx;
    spisdcard_clk <= spi_clk;
    spisdcard_cs_n <= spi_cs_n;
    spisdcard_mosi <= spi_mosi;
end

music_player play(
    .clk(clk50),                    // 系统时钟
    .reset(rst),                  // 复位信号
    .key(1),
    .stop(~gpio_stop),
    .pwm(buzzer_out_pwm)                // PWM 信号输出
);

sipeed_tang_mega_138k_pro SoC(
    .atkms7620_scl(atkms7620_scl),
    .atkms7620_sda(atkms7620_sda),
    .buzzer_out_pwm(gpio_stop),
    .clk50(clk50),
    .joypad2_in_data(joypad2_in_data),
    .joypad2_out_clk(joypad2_out_clk),
    .joypad2_out_load(joypad2_out_load),
    .joypad_in_data(joypad_in_data),
    .joypad_out_clk(joypad_out_clk),
    .joypad_out_load(joypad_out_load),
    .lcd_b(lcd_b),
    .lcd_clk(lcd_clk),
    .lcd_de(lcd_de),
    .lcd_g(lcd_g),
    .lcd_hsync_n(lcd_hsync_n),
    .lcd_r(lcd_r),
    .lcd_vsync_n(lcd_vsync_n),
    .led_n0(led_n0),
    .led_n1(led_n1),
    .led_n2(led_n2),
    .led_n3(led_n3),
    .led_n4(led_n4),
    .led_n5(led_n5),
    .rst(rst),
    .sdram_a(sdram_a),
    .sdram_ba(sdram_ba),
    .sdram_cas_n(sdram_cas_n),
    .sdram_clock(sdram_clock),
    .sdram_cs_n(sdram_cs_n),
    .sdram_dm(sdram_dm),
    .sdram_dq(sdram_dq),
    .sdram_ras_n(sdram_ras_n),
    .sdram_we_n(sdram_we_n),
    .serial_rx(serial_rx),
    .serial_tx(uart_tx),
    .spisdcard_clk(spi_clk),
    .spisdcard_cs_n(spi_cs_n),
    .spisdcard_miso(spisdcard_miso),
    .spisdcard_mosi(spi_mosi)
);

endmodule