


         MOV  R1, #25                              
         MOV  R2, #20                              
         STMFA R13!, { R1, R2}                 
	   BL  LINK
        LDR    R4, =A
	   STR R0, [R4]                              
         SWI 0x11
LINK:  LDMFA R13!, { R4, R5} 
           ADD R0, R4, R5                         
           MOV PC, LR                               

   A:    .WORD  0

.END
