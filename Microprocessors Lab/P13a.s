
.DATA
A: .WORD 1,2,3,4

.TEXT
LDR R1,=A
LDMIA R1!,{R2,R0,R5}

