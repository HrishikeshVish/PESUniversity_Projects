// Write code for modules you need here
module reg16(input wire load,clk,reset ,input wire [15:0] d_in ,output wire [15:0] o);
dfrl d0(clk,reset,load, d_in[0],o[0]);
dfrl d1(clk,reset,load, d_in[1],o[1]);
dfrl d2(clk,reset,load, d_in[2],o[2]);
dfrl d3(clk,reset,load, d_in[3],o[3]);
dfrl d4(clk,reset,load, d_in[4],o[4]);
dfrl d5(clk,reset,load, d_in[5],o[5]);
dfrl d6(clk,reset,load, d_in[6],o[6]);
dfrl d7(clk,reset,load, d_in[7],o[7]);
dfrl d8(clk,reset,load, d_in[8],o[8]);
dfrl d9(clk,reset,load, d_in[9],o[9]);
dfrl d10(clk,reset,load, d_in[10],o[10]);
dfrl d11(clk,reset,load, d_in[11],o[11]);
dfrl d12(clk,reset,load, d_in[12],o[12]);
dfrl d13(clk,reset,load, d_in[13],o[13]);
dfrl d14(clk,reset,load, d_in[14],o[14]);
dfrl d15(clk,reset,load, d_in[15],o[15]);
endmodule

/*
module shift_reg(input wire sel,input wire [3:0] s_amt,input wire [15:0] o , output wire bit_out);
wire shift_left_out,shift_right_out,load;
wire [15:0] o1,o2;
assign o1=o;
assign o2=o;

assign bit_out = sel ? shift_left_out:shift_right_out;
endmodule
*/

module reg8_16(input wire [7:0] load ,input wire clk,reset ,input wire [15:0] d_in,output wire[15:0] q0,q1,q2,q3,q4,q5,q6,q7);
reg16 r0(load[0],clk,reset,d_in,q0);
reg16 r1(load[1],clk,reset,d_in,q1);
reg16 r2(load[2],clk,reset,d_in,q2);
reg16 r3(load[3],clk,reset,d_in,q3);
reg16 r4(load[4],clk,reset,d_in,q4);
reg16 r5(load[5],clk,reset,d_in,q5);
reg16 r6(load[6],clk,reset,d_in,q6);
reg16 r7(load[7],clk,reset,d_in,q7);
endmodule
module mux8_16(input wire s0,s1,s2, input wire[15:0] q0,q1,q2,q3,q4,q5,q6,q7, output wire [15:0] o);
mux8 m0({q0[0],q1[0],q2[0],q3[0],q4[0],q5[0],q6[0],q7[0]},s0, s1, s2, o[0]);
mux8 m1({q0[1],q1[1],q2[1],q3[1],q4[1],q5[1],q6[1],q7[1]},s0, s1, s2, o[1]);
mux8 m2({q0[2],q1[2],q2[2],q3[2],q4[2],q5[2],q6[2],q7[2]},s0, s1, s2, o[2]);
mux8 m3({q0[3],q1[3],q2[3],q3[3],q4[3],q5[3],q6[3],q7[3]},s0, s1, s2, o[3]);
mux8 m4({q0[4],q1[4],q2[4],q3[4],q4[4],q5[4],q6[4],q7[4]},s0, s1, s2, o[4]);
mux8 m5({q0[5],q1[5],q2[5],q3[5],q4[5],q5[5],q6[5],q7[5]},s0, s1, s2, o[5]);
mux8 m6({q0[6],q1[6],q2[6],q3[6],q4[6],q5[6],q6[6],q7[6]},s0, s1, s2, o[6]);
mux8 m7({q0[7],q1[7],q2[7],q3[7],q4[7],q5[7],q6[7],q7[7]},s0, s1, s2, o[7]);
mux8 m8({q0[8],q1[8],q2[8],q3[8],q4[8],q5[8],q6[8],q7[8]},s0, s1, s2, o[8]);
mux8 m9({q0[9],q1[9],q2[9],q3[9],q4[9],q5[9],q6[9],q7[9]},s0, s1, s2, o[9]);
mux8 m10({q0[10],q1[10],q2[10],q3[10],q4[10],q5[10],q6[10],q7[10]},s0, s1, s2, o[10]);
mux8 m11({q0[11],q1[11],q2[11],q3[11],q4[11],q5[11],q6[11],q7[11]},s0, s1, s2, o[11]);
mux8 m12({q0[12],q1[12],q2[12],q3[12],q4[12],q5[12],q6[12],q7[12]},s0, s1, s2, o[12]);
mux8 m13({q0[13],q1[13],q2[13],q3[13],q4[13],q5[13],q6[13],q7[13]},s0, s1, s2, o[13]);
mux8 m14({q0[14],q1[14],q2[14],q3[14],q4[14],q5[14],q6[14],q7[14]},s0, s1, s2, o[14]);
mux8 m15({q0[15],q1[15],q2[15],q3[15],q4[15],q5[15],q6[15],q7[15]},s0, s1, s2, o[15]);
endmodule

module mux16(input wire [15:0] ip, input wire [3:0] sel, output wire out);
wire t0,t1;
mux8 m1(ip[7:0],sel[0],sel[1],sel[2],t0);
mux8 m2(ip[15:8],sel[0],sel[1],sel[2],t1);
mux2 m3(t0,t1,sel[3],out);
endmodule

module shift_left_log(input wire[3:0] amt,input wire [15:0] ip, output wire [15:0] out);
wire [15:0] o;
mux16 m0(ip,amt,o[0]);
mux16 m1({ip[14:0],1'b0},amt,o[1]);
mux16 m2({ip[13:0],1'b0,1'b0},amt,o[2]);
mux16 m3({ip[12:0],1'b0,1'b0,1'b0},amt,o[3]);
mux16 m4({ip[11:0],1'b0,1'b0,1'b0,1'b0},amt,o[4]);
mux16 m5({ip[10:0],1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[5]);
mux16 m6({ip[9:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[6]);
mux16 m7({ip[8:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[7]);  
mux16 m8({ip[7:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[8]);
mux16 m9({ip[6:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[9]);
mux16 m10({ip[5:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[10]);
mux16 m11({ip[4:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[11]);
mux16 m12({ip[3:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[12]);
mux16 m13({ip[2:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[13]);
mux16 m14({ip[1:0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[14]);
mux16 m15({ip[0],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[15]);

assign out = o;
endmodule

module shift_right_log(input wire[3:0] amt,input wire [15:0] ip, output wire [15:0] out);
wire [15:0] o;
mux16 mo({ip[15],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[15]);
mux16 m1({ip[15:14],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[14]);
mux16 m2({ip[15:13],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[13]);
mux16 m3({ip[15:12],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[12]);
mux16 m4({ip[15:11],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[11]);
mux16 m5({ip[15:10],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[10]);
mux16 m6({ip[15:9],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[9]);
mux16 m7({ip[15:8],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[8]);
mux16 m8({ip[15:7],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[7]);
mux16 m9({ip[15:6],1'b0,1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[6]);
mux16 m10({ip[15:5],1'b0,1'b0,1'b0,1'b0,1'b0},amt,o[5]);
mux16 m11({ip[15:4],1'b0,1'b0,1'b0,1'b0},amt,o[4]);
mux16 m12({ip[15:3],1'b0,1'b0,1'b0},amt,o[3]);
mux16 m13({ip[15:2],1'b0,1'b0},amt,o[2]);
mux16 m14({ip[15:1],1'b0},amt,o[1]);
mux16 m15(ip[15:0],amt,o[0]);
assign out=o;
endmodule

module shift_right_ar(input wire[3:0] amt,input wire [15:0] ip, output wire [15:0] out);
wire [15:0] o;
wire msb;
assign msb=ip[15];
mux16 mo({ip[15],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[15]);
mux16 m1({ip[15:14],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[14]);
mux16 m2({ip[15:13],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[13]);
mux16 m3({ip[15:12],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[12]);
mux16 m4({ip[15:11],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[11]);
mux16 m5({ip[15:10],msb,msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[10]);
mux16 m6({ip[15:9],msb,msb,msb,msb,msb,msb,msb,msb,msb},amt,o[9]);
mux16 m7({ip[15:8],msb,msb,msb,msb,msb,msb,msb,msb},amt,o[8]);
mux16 m8({ip[15:7],msb,msb,msb,msb,msb,msb,msb},amt,o[7]);
mux16 m9({ip[15:6],msb,msb,msb,msb,msb,msb},amt,o[6]);
mux16 m10({ip[15:5],msb,msb,msb,msb,msb},amt,o[5]);
mux16 m11({ip[15:4],msb,msb,msb,msb},amt,o[4]);
mux16 m12({ip[15:3],msb,msb,msb},amt,o[3]);
mux16 m13({ip[15:2],msb,msb},amt,o[2]);
mux16 m14({ip[15:1],msb},amt,o[1]);
mux16 m15(ip[15:0],amt,o[0]);
assign out=o;
endmodule

module shift(input wire[3:0] amt,input wire [1:0] sel,input wire [15:0] ip, output wire [15:0] out);
wire [15:0] sro,slo,srao,sralo;
wire bit;
shift_right_log srl1(amt,ip,sro);
shift_left_log sll1(amt,ip,slo);
shift_right_ar sra1(amt,ip,srao);
assign sralo = (sel[1]==1'b0)?sro:srao;
assign out = (sel[0]==1'b0)?slo:sralo;
endmodule

module reg_file (input wire clk, reset, wr, input wire [2:0] rd_addr_a, rd_addr_b, wr_addr, input wire [15:0] d_in, output wire [15:0] d_out_a, d_out_b);

// Declare wires here
wire[15:0] q0,q1,q2,q3,q4,q5,q6,q7;
wire [7:0] load;

// Instantiate modules here
demux8 d1(wr,wr_addr[2],wr_addr[1],wr_addr[0],load);
reg8_16 r1(load,clk,reset,d_in,q0,q1,q2,q3,q4,q5,q6,q7);
mux8_16 ma(rd_addr_a[0],rd_addr_a[1],rd_addr_a[2],q0,q1,q2,q3,q4,q5,q6,q7,d_out_a);
mux8_16 mb(rd_addr_b[0],rd_addr_b[1],rd_addr_b[2],q0,q1,q2,q3,q4,q5,q6,q7,d_out_b);
endmodule

module mux2_16(input wire sel, input wire[15:0] i0,i1, output wire [15:0] o);
mux2 m0(i0[0],i1[0],sel,o[0]);
mux2 m1(i0[1],i1[1],sel,o[1]);
mux2 m2(i0[2],i1[2],sel,o[2]);
mux2 m3(i0[3],i1[3],sel,o[3]);
mux2 m4(i0[4],i1[4],sel,o[4]);
mux2 m5(i0[5],i1[5],sel,o[5]);
mux2 m6(i0[6],i1[6],sel,o[6]);
mux2 m7(i0[7],i1[7],sel,o[7]);
mux2 m8(i0[8],i1[8],sel,o[8]);
mux2 m9(i0[9],i1[9],sel,o[9]);
mux2 m10(i0[10],i1[10],sel,o[10]);
mux2 m11(i0[11],i1[11],sel,o[11]);
mux2 m12(i0[12],i1[12],sel,o[12]);
mux2 m13(i0[13],i1[13],sel,o[13]);
mux2 m14(i0[14],i1[14],sel,o[14]);
mux2 m15(i0[15],i1[15],sel,o[15]);
endmodule

module reg_alu (input wire clk, reset, sel, wr, input wire [2:0] op, input wire [2:0] rd_addr_a,
		rd_addr_b, wr_addr, input wire [15:0] d_in, output wire [15:0] d_out_a, d_out_b);

// Declare wires here
wire[15:0] o,in;

mux2_16 m1(sel,d_in,o,in);
reg_file rg1(clk,reset,wr,rd_addr_a,rd_addr_b,wr_addr,in,d_out_a,d_out_b);

// Instantiate modules here

endmodule


module final_reg(input wire clk, reset, sel, wr,input wire[2:0]op, input wire[2:0] rd_adder_a, rd_adder_b, wr_addr, input wire [15:0] din,  output wire[15:0]o, output wire cout);

wire [15:0] d_out_a, d_out_b;
wire c,t_cout;

reg_alu r(clk, reset, sel, wr,op,rd_addr_a, rd_addr_b, wr_addr, d_in, d_out_a, d_out_b, c );
alu a(clk,reset,op,d_out_a, d_out_b, o,t_cout);
dfr d0(clk,reset,t_cout, cout);

endmodule

