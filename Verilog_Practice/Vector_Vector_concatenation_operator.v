module top_module (
    input [4:0] a, b, c, d, e, f,
    output [7:0] w, x, y, z );//
    
    wire [31:0]combine;
    // assign combine = {a[4:0], b[4:0], c[4:0], d[4:0], e[4:0], f[4:0], 2'b11};
    assign combine = {a, b, c, d, e, f, 2'b11};
    
    assign z = combine[7:0];
    assign y = combine[15:8];
    assign x = combine[23:16];
    assign w = combine[31:24];
    
endmodule