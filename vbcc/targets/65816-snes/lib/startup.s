 zpage r0
 zpage r1
 zpage r2
 zpage r3
 global ___exit
 section start_text.startup
_start:
 clc
 xce
 rep #48
 a16
 lda #$1ffe
 tcs
 lda #r0
 and #$ff00
 tcd
 pea #^__NDS
 plb
 sep #32
 a8
 pla
 rep #32
 a16

 lda #<__FBS
 sta r0
 lda #^__FBS
 sta r1
 jmp l2
l1:
 sep #32
 a8
 lda #0
 sta [r0]
 rep #32
 a16
 inc r0
 bne l2
 inc r1
l2:
 lda r0
 cmp #<__FBE
 bne l1
 lda r1
 cmp #^__FBE
 bne l1

 lda #<__FDS
 sta r0
 lda #^__FDS
 sta r1
 lda #<__FDC
 sta r2
 lda #^__FDC
 sta r3
 jmp l5
l3:
 sep #32
 a8
 lda [r2]
 sta [r0]
 rep #32
 a16
 inc r0
 bne l4
 inc r1
l4:
 inc r2
 bne l5
 inc r3
l5:
 lda r0
 cmp #<__FDE
 bne l3
 lda r1
 cmp #^__FDE
 bne l3



 jsl ___main
___exit:
 jmp ___exit

 section zpage
r0: reserve 2
r1: reserve 2
r2: reserve 2
r3: reserve 2
r4: reserve 2
r5: reserve 2
r6: reserve 2
r7: reserve 2
r8: reserve 2
r9: reserve 2
r10: reserve 2
r11: reserve 2
r12: reserve 2
r13: reserve 2
r14: reserve 2
r15: reserve 2
r16: reserve 2
r17: reserve 2
r18: reserve 2
r19: reserve 2
r20: reserve 2
r21: reserve 2
r22: reserve 2
r23: reserve 2
r24: reserve 2
r25: reserve 2
r26: reserve 2
r27: reserve 2
r28: reserve 2
r29: reserve 2
r30: reserve 2
r31: reserve 2

 global r0
 global r1
 global r2
 global r3
 global r4
 global r5
 global r6
 global r7
 global r8
 global r9
 global r10
 global r11
 global r12
 global r13
 global r14
 global r15
 global r16
 global r17
 global r18
 global r19
 global r20
 global r21
 global r22
 global r23
 global r24
 global r25
 global r26
 global r27
 global r28
 global r29
 global r30
 global r31






