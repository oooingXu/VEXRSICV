`timescale 1ns / 1ps
module music_player (
    input wire clk,                    // 系统时钟
    input wire reset,                  // 复位信号
    input wire key,
    input wire stop,
    output wire pwm                // PWM 信号输出
);

    // 乐谱存储 (音符频率和持续时间)
    reg [31:0] notes_freq  [0:8'd232];    // 频率 (Hz)
    reg [31:0] notes_dur   [0:8'd232];     // 持续时间 (ms)

    // 当前音符索引
    reg [7:0] note_index;
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
    // 第1-50个音符
    notes_freq[0] <= 330; notes_dur[0] <= 150;
    notes_freq[1] <= 0;   notes_dur[1] <= 5;
    notes_freq[2] <= 330; notes_dur[2] <= 150;
    notes_freq[3] <= 0;   notes_dur[3] <= 150;
    notes_freq[4] <= 330; notes_dur[4] <= 150;
    notes_freq[5] <= 0;   notes_dur[5] <= 150;
    notes_freq[6] <= 262; notes_dur[6] <= 150;
    notes_freq[7] <= 330; notes_dur[7] <= 300;
    notes_freq[8] <= 392; notes_dur[8] <= 300;
    notes_freq[9] <= 0;   notes_dur[9] <= 300;
    notes_freq[10] <= 523; notes_dur[10] <= 300;
    notes_freq[11] <= 0;   notes_dur[11] <= 300;
    notes_freq[12] <= 262; notes_dur[12] <= 300;
    notes_freq[13] <= 0;   notes_dur[13] <= 150;
    notes_freq[14] <= 523; notes_dur[14] <= 300;
    notes_freq[15] <= 0;   notes_dur[15] <= 150;
    notes_freq[16] <= 330; notes_dur[16] <= 300;
    notes_freq[17] <= 0;   notes_dur[17] <= 150;
    notes_freq[18] <= 587; notes_dur[18] <= 300;
    notes_freq[19] <= 784; notes_dur[19] <= 300;
    notes_freq[20] <= 740; notes_dur[20] <= 150;
    notes_freq[21] <= 0;   notes_dur[21] <= 5;
    notes_freq[22] <= 740; notes_dur[22] <= 300;
    notes_freq[23] <= 523; notes_dur[23] <= 200;
    notes_freq[24] <= 330; notes_dur[24] <= 200;
    notes_freq[25] <= 392; notes_dur[25] <= 200;
    notes_freq[26] <= 659; notes_dur[26] <= 300;
    notes_freq[27] <= 349; notes_dur[27] <= 150;
    notes_freq[28] <= 392; notes_dur[28] <= 150;
    notes_freq[29] <= 0;   notes_dur[29] <= 150;
    notes_freq[30] <= 330; notes_dur[30] <= 300;
    notes_freq[31] <= 262; notes_dur[31] <= 150;
    notes_freq[32] <= 294; notes_dur[32] <= 150;
    notes_freq[33] <= 784; notes_dur[33] <= 300;
    notes_freq[34] <= 0;   notes_dur[34] <= 150;
    notes_freq[35] <= 262; notes_dur[35] <= 300;
    notes_freq[36] <= 0;   notes_dur[36] <= 150;
    notes_freq[37] <= 523; notes_dur[37] <= 300;
    notes_freq[38] <= 0;   notes_dur[38] <= 150;
    notes_freq[39] <= 330; notes_dur[39] <= 300;
    notes_freq[40] <= 0;   notes_dur[40] <= 150;
    notes_freq[41] <= 587; notes_dur[41] <= 300;
    notes_freq[42] <= 784; notes_dur[42] <= 300;
    notes_freq[43] <= 740; notes_dur[43] <= 150;
    notes_freq[44] <= 0;   notes_dur[44] <= 5;
    notes_freq[45] <= 740; notes_dur[45] <= 300;
    notes_freq[46] <= 523; notes_dur[46] <= 200;
    notes_freq[47] <= 330; notes_dur[47] <= 200;
    notes_freq[48] <= 392; notes_dur[48] <= 200;
    notes_freq[49] <= 659; notes_dur[49] <= 300;

    // 第51-100个音符
    notes_freq[50] <= 349; notes_dur[50] <= 150;
    notes_freq[51] <= 392; notes_dur[51] <= 150;
    notes_freq[52] <= 0;   notes_dur[52] <= 150;
    notes_freq[53] <= 330; notes_dur[53] <= 300;
    notes_freq[54] <= 262; notes_dur[54] <= 150;
    notes_freq[55] <= 294; notes_dur[55] <= 150;
    notes_freq[56] <= 784; notes_dur[56] <= 300;
    notes_freq[57] <= 0;   notes_dur[57] <= 150;
    notes_freq[58] <= 0;   notes_dur[58] <= 300;
    notes_freq[59] <= 392; notes_dur[59] <= 150;
    notes_freq[60] <= 370; notes_dur[60] <= 150;
    notes_freq[61] <= 0;   notes_dur[61] <= 5;
    notes_freq[62] <= 370; notes_dur[62] <= 150;
    notes_freq[63] <= 311; notes_dur[63] <= 300;
    notes_freq[64] <= 330; notes_dur[64] <= 150;
    notes_freq[65] <= 0;   notes_dur[65] <= 150;
    notes_freq[66] <= 466; notes_dur[66] <= 150;
    notes_freq[67] <= 587; notes_dur[67] <= 150;
    notes_freq[68] <= 262; notes_dur[68] <= 150;
    notes_freq[69] <= 0;   notes_dur[69] <= 150;
    notes_freq[70] <= 587; notes_dur[70] <= 150;
    notes_freq[71] <= 262; notes_dur[71] <= 150;
    notes_freq[72] <= 294; notes_dur[72] <= 150;
    notes_freq[73] <= 0;   notes_dur[73] <= 300;
    notes_freq[74] <= 392; notes_dur[74] <= 150;
    notes_freq[75] <= 370; notes_dur[75] <= 150;
    notes_freq[76] <= 0;   notes_dur[76] <= 5;
    notes_freq[77] <= 370; notes_dur[77] <= 150;
    notes_freq[78] <= 311; notes_dur[78] <= 300;
    notes_freq[79] <= 330; notes_dur[79] <= 150;
    notes_freq[80] <= 0;   notes_dur[80] <= 150;
    notes_freq[81] <= 523; notes_dur[81] <= 300;
    notes_freq[82] <= 0;   notes_dur[82] <= 5;
    notes_freq[83] <= 523; notes_dur[83] <= 150;
    notes_freq[84] <= 0;   notes_dur[84] <= 5;
    notes_freq[85] <= 523; notes_dur[85] <= 300;
    notes_freq[86] <= 0;   notes_dur[86] <= 300;
    notes_freq[87] <= 0;   notes_dur[87] <= 300;
    notes_freq[88] <= 392; notes_dur[88] <= 150;
    notes_freq[89] <= 370; notes_dur[89] <= 150;
    notes_freq[90] <= 0;   notes_dur[90] <= 5;
    notes_freq[91] <= 370; notes_dur[91] <= 150;
    notes_freq[92] <= 311; notes_dur[92] <= 300;
    notes_freq[93] <= 330; notes_dur[93] <= 150;
    notes_freq[94] <= 0;   notes_dur[94] <= 150;
    notes_freq[95] <= 466; notes_dur[95] <= 150;
    notes_freq[96] <= 587; notes_dur[96] <= 150;
    notes_freq[97] <= 262; notes_dur[97] <= 150;
    notes_freq[98] <= 0;   notes_dur[98] <= 150;
    notes_freq[99] <= 587; notes_dur[99] <= 150;

    // 第101-150个音符
    notes_freq[100] <= 262; notes_dur[100] <= 150;
    notes_freq[101] <= 294; notes_dur[101] <= 150;
    notes_freq[102] <= 0;   notes_dur[102] <= 300;
    notes_freq[103] <= 311; notes_dur[103] <= 300;
    notes_freq[104] <= 0;   notes_dur[104] <= 150;
    notes_freq[105] <= 311; notes_dur[105] <= 300;
    notes_freq[106] <= 0;   notes_dur[106] <= 150;
    notes_freq[107] <= 262; notes_dur[107] <= 300;
    notes_freq[108] <= 0;   notes_dur[108] <= 300;
    notes_freq[109] <= 0;   notes_dur[109] <= 300;
    notes_freq[110] <= 0;   notes_dur[110] <= 300;
    notes_freq[111] <= 0;   notes_dur[111] <= 300;
    notes_freq[112] <= 392; notes_dur[112] <= 150;
    notes_freq[113] <= 370; notes_dur[113] <= 150;
    notes_freq[114] <= 0;   notes_dur[114] <= 5;
    notes_freq[115] <= 370; notes_dur[115] <= 150;
    notes_freq[116] <= 311; notes_dur[116] <= 300;
    notes_freq[117] <= 330; notes_dur[117] <= 150;
    notes_freq[118] <= 0;   notes_dur[118] <= 150;
    notes_freq[119] <= 466; notes_dur[119] <= 150;
    notes_freq[120] <= 587; notes_dur[120] <= 150;
    notes_freq[121] <= 262; notes_dur[121] <= 150;
    notes_freq[122] <= 0;   notes_dur[122] <= 150;
    notes_freq[123] <= 587; notes_dur[123] <= 150;
    notes_freq[124] <= 262; notes_dur[124] <= 150;
    notes_freq[125] <= 294; notes_dur[125] <= 150;
    notes_freq[126] <= 0;   notes_dur[126] <= 300;
    notes_freq[127] <= 392; notes_dur[127] <= 150;
    notes_freq[128] <= 370; notes_dur[128] <= 150;
    notes_freq[129] <= 0;   notes_dur[129] <= 5;
    notes_freq[130] <= 370; notes_dur[130] <= 150;
    notes_freq[131] <= 311; notes_dur[131] <= 300;
    notes_freq[132] <= 330; notes_dur[132] <= 150;
    notes_freq[133] <= 0;   notes_dur[133] <= 150;
    notes_freq[134] <= 523; notes_dur[134] <= 300;
    notes_freq[135] <= 0;   notes_dur[135] <= 5;
    notes_freq[136] <= 523; notes_dur[136] <= 150;
    notes_freq[137] <= 0;   notes_dur[137] <= 5;
    notes_freq[138] <= 523; notes_dur[138] <= 300;
    notes_freq[139] <= 0;   notes_dur[139] <= 300;
    notes_freq[140] <= 0;   notes_dur[140] <= 300;
    notes_freq[141] <= 392; notes_dur[141] <= 150;
    notes_freq[142] <= 370; notes_dur[142] <= 150;
    notes_freq[143] <= 0;   notes_dur[143] <= 5;
    notes_freq[144] <= 370; notes_dur[144] <= 150;
    notes_freq[145] <= 311; notes_dur[145] <= 300;
    notes_freq[146] <= 330; notes_dur[146] <= 150;
    notes_freq[147] <= 0;   notes_dur[147] <= 150;
    notes_freq[148] <= 466; notes_dur[148] <= 150;
    notes_freq[149] <= 587; notes_dur[149] <= 150;

    // 第151-200个音符
    notes_freq[150] <= 262; notes_dur[150] <= 150;
    notes_freq[151] <= 0;   notes_dur[151] <= 150;
    notes_freq[152] <= 587; notes_dur[152] <= 150;
    notes_freq[153] <= 262; notes_dur[153] <= 150;
    notes_freq[154] <= 294; notes_dur[154] <= 150;
    notes_freq[155] <= 0;   notes_dur[155] <= 300;
    notes_freq[156] <= 311; notes_dur[156] <= 300;
    notes_freq[157] <= 0;   notes_dur[157] <= 150;
    notes_freq[158] <= 311; notes_dur[158] <= 300;
    notes_freq[159] <= 0;   notes_dur[159] <= 150;
    notes_freq[160] <= 262; notes_dur[160] <= 300;
    notes_freq[161] <= 0;   notes_dur[161] <= 300;
    notes_freq[162] <= 0;   notes_dur[162] <= 300;
    notes_freq[163] <= 0;   notes_dur[163] <= 300;
    notes_freq[164] <= 262; notes_dur[164] <= 150;
    notes_freq[165] <= 0;   notes_dur[165] <= 5;
    notes_freq[166] <= 262; notes_dur[166] <= 150;
    notes_freq[167] <= 0;   notes_dur[167] <= 5;
    notes_freq[168] <= 262; notes_dur[168] <= 150;
    notes_freq[169] <= 0;   notes_dur[169] <= 5;
    notes_freq[170] <= 262; notes_dur[170] <= 150;
    notes_freq[171] <= 294; notes_dur[171] <= 300;
    notes_freq[172] <= 330; notes_dur[172] <= 150;
    notes_freq[173] <= 262; notes_dur[173] <= 150;
    notes_freq[174] <= 0;   notes_dur[174] <= 150;
    notes_freq[175] <= 587; notes_dur[175] <= 150;
    notes_freq[176] <= 523; notes_dur[176] <= 600;
    notes_freq[177] <= 262; notes_dur[177] <= 150;
    notes_freq[178] <= 0;   notes_dur[178] <= 5;
    notes_freq[179] <= 262; notes_dur[179] <= 150;
    notes_freq[180] <= 0;   notes_dur[180] <= 150;
    notes_freq[181] <= 262; notes_dur[181] <= 150;
    notes_freq[182] <= 0;   notes_dur[182] <= 150;
    notes_freq[183] <= 262; notes_dur[183] <= 150;
    notes_freq[184] <= 294; notes_dur[184] <= 150;
    notes_freq[185] <= 330; notes_dur[185] <= 150;
    notes_freq[186] <= 0;   notes_dur[186] <= 600;
    notes_freq[187] <= 0;   notes_dur[187] <= 600;
    notes_freq[188] <= 262; notes_dur[188] <= 150;
    notes_freq[189] <= 0;   notes_dur[189] <= 5;
    notes_freq[190] <= 262; notes_dur[190] <= 150;
    notes_freq[191] <= 0;   notes_dur[191] <= 5;
    notes_freq[192] <= 262; notes_dur[192] <= 150;
    notes_freq[193] <= 0;   notes_dur[193] <= 5;
    notes_freq[194] <= 262; notes_dur[194] <= 150;
    notes_freq[195] <= 294; notes_dur[195] <= 300;
    notes_freq[196] <= 330; notes_dur[196] <= 150;
    notes_freq[197] <= 262; notes_dur[197] <= 150;
    notes_freq[198] <= 0;   notes_dur[198] <= 150;
    notes_freq[199] <= 587; notes_dur[199] <= 150;

    // 最后一部分 200-232
    notes_freq[200] <= 523; notes_dur[200] <= 600;
    // 最后一部分 201-232
    notes_freq[201] <= 262; notes_dur[201] <= 150;
    notes_freq[202] <= 0;   notes_dur[202] <= 5;
    notes_freq[203] <= 262; notes_dur[203] <= 150;
    notes_freq[204] <= 0;   notes_dur[204] <= 150;
    notes_freq[205] <= 262; notes_dur[205] <= 150;
    notes_freq[206] <= 0;   notes_dur[206] <= 150;
    notes_freq[207] <= 262; notes_dur[207] <= 150;
    notes_freq[208] <= 294; notes_dur[208] <= 150;
    notes_freq[209] <= 330; notes_dur[209] <= 150;
    notes_freq[210] <= 0;   notes_dur[210] <= 600;
    notes_freq[211] <= 0;   notes_dur[211] <= 600;
    notes_freq[212] <= 262; notes_dur[212] <= 150;
    notes_freq[213] <= 0;   notes_dur[213] <= 5;
    notes_freq[214] <= 262; notes_dur[214] <= 150;
    notes_freq[215] <= 0;   notes_dur[215] <= 5;
    notes_freq[216] <= 262; notes_dur[216] <= 150;
    notes_freq[217] <= 0;   notes_dur[217] <= 5;
    notes_freq[218] <= 262; notes_dur[218] <= 150;
    notes_freq[219] <= 294; notes_dur[219] <= 300;
    notes_freq[220] <= 330; notes_dur[220] <= 150;
    notes_freq[221] <= 262; notes_dur[221] <= 150;
    notes_freq[222] <= 0;   notes_dur[222] <= 150;
    notes_freq[223] <= 587; notes_dur[223] <= 150;
    notes_freq[224] <= 523; notes_dur[224] <= 600;
    notes_freq[225] <= 262; notes_dur[225] <= 150;
    notes_freq[226] <= 0;   notes_dur[226] <= 5;
    notes_freq[227] <= 262; notes_dur[227] <= 150;
    notes_freq[228] <= 0;   notes_dur[228] <= 5;
    notes_freq[229] <= 262; notes_dur[229] <= 150;
    notes_freq[230] <= 0;   notes_dur[230] <= 5;
    notes_freq[231] <= 262; notes_dur[231] <= 150;
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
        		    if (note_index < 8'd232) begin
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
