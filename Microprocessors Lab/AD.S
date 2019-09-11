.DATA 
A:.WORD 1,2,3,4,5,6

.text
ldr R0,=A
Mov R5,#6
Mov R4,#1  @key = 1
L1: LDR R1,[R0]
add r0,r0,#4;
cmp r1,r4
BEQ L2
B L3

L2:MOV R6,#1
SWI 0X011

L3: MOV R6,#-1
SUBS R5,R5,#1
BNE L1
SWI 0X011 