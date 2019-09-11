MOV R0,#10
B LABEL

LABEL: MOV R1,#2
       BL LABEL1
       SWI 0X11

LABEL2: MOV R3,#4
        LDMED R13!,{R0,R1,R14}
        MOV PC,LR
       


LABEL1: STMED R13!,{R0,R1,R14} 
        MOV R2,#3
       
        BL LABEL2


