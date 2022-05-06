module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
    
    wire cout_a, cout_b;
    reg[31:0]b_xor;
    
    add16 add16_a(a[15:0], b_xor[15:0], sub, sum[15:0], cout_a);
    add16 add16_b(a[31:16], b_xor[31:16], cout_a, sum[31:16], cout_b);
    
    always @(*) begin
        for (int i=0; i<32; i++) begin
            b_xor[i] = b[i] ^ sub;
        end
    end
    
endmodule