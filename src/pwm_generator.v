`timescale 1ns / 1ps
module pwm_generator #(
    parameter CLK_FREQ = 50_000_000// FPGA 时钟频率
)(
    input wire clk,                   // 系统时钟
    input wire reset,                 // 复位信号
    input wire [31:0] freq,           // 输入频率 (Hz)
    input wire [31:0] duration,       // 播放持续时间 (ms)
    input wire enable,                // 启用信号
    output reg done,                  // 播放完成信号
    output wire pwm_out               // PWM 信号输出
);

    // 频率到周期转换
    reg [31:0] period;
    reg [31:0] period_0p5;
    always @(*) begin
			if (freq != 0) begin
          period = CLK_FREQ / freq; // 计算周期
          period_0p5 = CLK_FREQ / (freq * 2); // 计算周期
				end else begin
          period = 0;
          period_0p5 = 0;
				end
    end

    // PWM 信号生成
    reg [31:0] counter;
    reg pwm_reg;
    assign pwm_out = pwm_reg;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            pwm_reg <= 0;
        end else if (enable) begin
            if (counter < period_0p5) begin
                pwm_reg <= 1;
            end else begin
                pwm_reg <= 0;
						end
            if (counter >= period)begin
                counter <= 0;
						end else begin
								counter <= counter + 1;
					  end
        end else begin
            pwm_reg <= 0;
        end
    end

    // 持续时间控制
    reg [31:0] duration_counter;
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            duration_counter <= 0;
            done <= 0;
        end else if (enable) begin
            if (duration_counter >= (CLK_FREQ / 1000) * duration) begin
                done <= 1;  // 播放完成
            end else begin
                duration_counter <= duration_counter + 1;
                done <= 0;
            end
        end else begin
            duration_counter <= 0;
            done <= 0;
        end
    end

endmodule
