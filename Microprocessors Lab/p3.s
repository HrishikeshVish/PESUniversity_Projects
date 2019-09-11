
MOV R4,#10
MVN R5,R4
MOV R1,#5
MOV R2,#2
 ADD  r0, r1, r2	              ;r0:=r1+r2 
ADC  r0, r1, r2		;r0:=r1+r2+C
SUB  r0, r1, r2		;r0:=r1–r2
SBC   r0, r1, r2		;r0:=r1–r2+C–1
RSB   r0, r1, r2		;r0:=r2–r1,Reverse Subtra
RSC   r0, r1, r2		;r0:=r2–r1+C–1
