.TEXT
LDR R0,=A
LDR R1,=B
LDR R5,=C
LDR R2,[R0]
LDR R3,[R1]
ADDS R4,R2,R3
STR R4,[R5]
ADD R0,R0,#4
ADD R1,R1,#4
ADD R5,R5,#4
LDR R2,[R0]
LDR R3,[R1]
ADC R4,R2,R3
STR R4,[R5]
.DATA
A:.WORD 0X123213A9,0X12121212
B:.WORD 0X11111111,0X21212121
C:.WORD 0X00