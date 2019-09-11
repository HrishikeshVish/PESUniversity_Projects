;Arithmetic Operations


MOV R4,#10
MVN R5,R4

Mov r1,#5
MOV r2,#3
                  
ADD r0,r1,r2	;r0:=r1+r2
ADC r0,r1,r2	;r0:=r1+r2+C
SUBs r0,r1,r2	;r0:=r1–r2
SBC r0,r1,r2	;r0:=r1–r2+C–1
RSBs r0,r1,r2	;r0:=r2–r1, reverse subtraction
RSC r0,r1,r2	;r0:=r2–r1+C–1
;By default data processing operations do no affect the condition flags

;Bit-wise Logical Operations
AND r0,r1,r2	;r0:=r1ANDr2
ORR r0,r1,r2	;r0:=r1ORr2
EOR r0,r1,r2	;r0:=r1XORr2
BIC r0,r1,r2	;r0:=r1AND(NOT r2), bit clear
