module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    reg [7:0]q_a;
    reg [7:0]q_b;
    reg [7:0]q_c;
    
    my_dff8 dff8_a(clk, d, q_a);
    my_dff8 dff8_b(clk, q_a, q_b);
    my_dff8 dff8_c(clk, q_b, q_c);
    
    always@(*)begin
        if(sel == 0) q = d;
        else if (sel == 1) q = q_a;
        else if (sel == 2) q = q_b;
        else if (sel == 3) q = q_c;
    end

endmodule
