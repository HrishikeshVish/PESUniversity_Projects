
.DATA
A:.word -8
b: .word 0
.TEXT
 LDR R0,=A
 LDR R5,=b
 LDR R1,[R0]
 strb r1,[r5]
 SWI 0X011