module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//
    
    wire cout_a, cout_b;
    wire [15:0]sum_a;
    wire [15:0]sum_b; 
    add16 add16_a(a[15:0], b[15:0], 0, sum_a[15:0], cout_a);
    add16 add16_b(a[31:16], b[31:16], cout_a, sum_b[15:0], cout_b);
    
    assign sum = {{sum_b[15:0]},{sum_a[15:0]}};
    
endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );

	// Full adder module here
    assign sum = a ^ b ^ cin;
    assign cout = (a&cin) | (a&b) | (b&cin);

endmodule