ADD R0,R1,R2

LDMIA  R13!  , {  R0, R5 - R8, R11}
           
LDR R2,[R1]

LDR R2,[R1,#4]!

STMIA  R13!  , {  R8, R4- R6, R12}