module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire cout_low, cout_high_cout0, cout_high_cout1;
    wire [15:0]sum_low;
    wire [15:0]sum_cout0;
    wire [15:0]sum_cout1;
    add16 add16_low (a[15:0], b[15:0], 0, sum_low[15:0], cout_low);
    add16 add16_high_cout0 (a[31:16], b[31:16], 0, sum_cout0[15:0], cout_high_cout0);
    add16 add16_high_cout1 (a[31:16], b[31:16], 1, sum_cout1[15:0], cout_high_cout1);
    
    always @(*) begin
        if (cout_low == 1)
            sum = {{sum_cout1[15:0]}, {sum_low[15:0]}};
        else
            sum = {{sum_cout0[15:0]}, {sum_low[15:0]}};
    end

endmodule
