

.text
    MOV R1,#20
    MOV R2,#10
    BL L2
    AND R3,R1,R2
    SWI 0X011
L2: CMP R1,R2
    BEQ L3
    SUB R1,R1,R2
    B L5
L3: ADD R1,R1,R2
    MOV R4,R1
L5: MOV PC,LR


 
