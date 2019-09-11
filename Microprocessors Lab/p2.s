

ldr r0,=a
ldr r1,=b
ldr r2,[r0]
ldr r3,[r1]
add r0,r0,#4
add r1,r1,#4
adds r4,r2,r3
ldr r2,[r0]
ldr r3,[r1]

adc r5,r2,r3
swi 0x011

.data
a:.word 0x12345678,0x89564213
b:.word 0xf2211111,0x22222222