


.DATA
A:.WORD 0X12345678
B:.WORD 0XA2345678

.TEXT
LDR R0,=A
LDR R1,[R0]
LDR R2,=B
LDR R3,[R2]
UMULLs R5,R4,R1,R3
SWI 0X011
