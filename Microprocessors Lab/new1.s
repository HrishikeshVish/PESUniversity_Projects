.data
A:.asciz "HELLO WORLD"

.text

LDR r0, =A
L2:LDRB R1,[R0],#1
CMP R1,#0
BEQ L1
SWI 0X00
B L2
L1:SWI 0X011