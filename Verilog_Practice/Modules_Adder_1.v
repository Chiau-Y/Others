module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire [15:0]sum_lower; 
    wire cout_lower, cout_higher; 
    wire [15:0]sum_higher;
    
    add16 add_lower(a[15:0], b[15:0], 0, sum_lower, cout_lower);
    add16 add_higher(a[31:16], b[31:16], cout_lower, sum_higher, cout_higher);
    
    assign sum = {sum_higher[15:0], sum_lower[15:0]};

endmodule
