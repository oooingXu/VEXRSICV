module led_water(clk,rstn,led_o);
input clk;
input rstn;
output [5:0]led_o;

parameter CNT_MAX = 26'd50000000;

reg [25:0] cnt_1s; 
wire flag_1s; 
reg[5:0] led_reg;


always@(posedge clk or negedge rstn) begin
    if(!rstn)
        cnt_1s <= 26'd0;
    else if(cnt_1s >= CNT_MAX - 26'd1) 
        cnt_1s <= 26'd0;
    else
        cnt_1s <= cnt_1s + 26'd1;
end

assign flag_1s = cnt_1s >= CNT_MAX + 26'd1;


always@(posedge clk or negedge rstn) begin
    if(!rstn)
        led_reg <= 6'b000000;
    else if(flag_1s) 
        if(led_reg == 6'b000000)
            led_reg <= 6'b111110;
        else
            led_reg <= {led_reg[4:0],led_reg[5]}; 
    else
        led_reg <= led_reg;
end

assign led_o = led_reg;
endmodule