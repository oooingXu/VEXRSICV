`timescale 1ns / 1ps
module music_player (
    input wire clk,                    // 系统时钟
    input wire reset,                  // 复位信号
    input wire key,
    input wire stop,
    output wire pwm                // PWM 信号输出
);

    // 乐谱存储 (音符频率和持续时间)
    reg [31:0] notes_freq  [0:4'd15];    // 频率 (Hz)
    reg [31:0] notes_dur   [0:4'd15];     // 持续时间 (ms)

    // 当前音符索引
    reg [3:0] note_index;
    reg [31:0] current_freq;
    reg [31:0] current_dur;

    // 状态机定义
    reg [1:0] state; // 将 logic 替换为 reg

    localparam IDLE = 2'b00;
    localparam PLAY_NOTE = 2'b01;
    localparam NEXT_NOTE = 2'b10;



    // PWM 生成模块实例
    wire pwm_enable;
    wire pwm_done;
    pwm_generator pwm_inst (
        .clk(clk),
        .reset(reset),
        .freq(current_freq),
        .duration(current_dur),
        .enable(pwm_enable),
        .done(pwm_done),
        .pwm_out(pwm)
    );

    // 状态机控制逻辑
always @(posedge clk or posedge reset) begin
    if (reset) begin
        notes_freq[0] <= 262; notes_dur[0] <= 1500;  // C4, 500ms
        notes_freq[1] <= 294; notes_dur[1] <= 1500;  // D4, 500ms
        notes_freq[2] <= 329; notes_dur[2] <= 1500;  // E4, 500ms
        notes_freq[3] <= 349; notes_dur[3] <= 1500;  // F4, 500ms
        notes_freq[4] <= 392; notes_dur[4] <= 1500;  // G4, 500ms
        notes_freq[5] <= 440; notes_dur[5] <= 1500;  // A4, 500ms
        notes_freq[6] <= 493; notes_dur[6] <= 1500;  // B4, 500ms
        notes_freq[7] <= 523; notes_dur[7] <= 1500;  // C5, 500ms
        state <= IDLE;
        note_index <= 0;
    end else begin
        case (state) 
						IDLE: begin
        		    if (key) begin
        		        note_index <= 0;
        		        current_freq <= notes_freq[0];
        		        current_dur <= notes_dur[0];
        		        state <= PLAY_NOTE;
        		    end else begin
        		        state <= IDLE;
        		    end
        		end

        		PLAY_NOTE: begin
        		    if (pwm_done & ~stop) begin
        		          note_index <= note_index + 1;
        		          state <= NEXT_NOTE;
        		    end else begin
        		        state <= PLAY_NOTE;
        		    end
        		end

        		NEXT_NOTE: begin
        		    if (note_index < 4'd15) begin
        		        current_freq <= notes_freq[note_index];
        		        current_dur <= notes_dur[note_index];
        		        state <= PLAY_NOTE;
        		    end else begin
        		        state <= IDLE;
        		    end
        		end

						default: begin
								state <= IDLE;
						end	
				endcase
    end
end


    // 启用 PWM 播放控制
    assign pwm_enable = (state == PLAY_NOTE) & ~stop;

endmodule
