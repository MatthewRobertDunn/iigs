;:ts=8
R0	equ	1
R1	equ	5
R2	equ	9
R3	equ	13
;//Here we get called with X containing how much to shift and A containing the input, return in A
;#asm
;shit section
;	xdef	~~~asr
;	func
;    ~~~asr:
;        cpx #0
;        beq __finish
;        lsr A
;        dex
;        bra ~~~asr
;    __finish:
;        rtl
;#endasm
	asmstart
shit section
	xdef	~~~asr
	func
    ~~~asr:
        cpx #0
        beq __finish
        lsr A
        dex
        bra ~~~asr
    __finish:
        rtl
	asmend
;
;
;//Here we get called with X containing how much to shift and A containing the input, return in A
;#asm
;.shit
;	xdef	~~~asl
;	func
;    ~~~asl:
;        cpx #0
;        beq __finish3
;        asl A
;        dex
;        bra ~~~asl
;    __finish3:
;        rtl
;#endasm
	asmstart
.shit
	xdef	~~~asl
	func
    ~~~asl:
        cpx #0
        beq __finish3
        asl A
        dex
        bra ~~~asl
    __finish3:
        rtl
	asmend
;
;
;//Here we get called with A containing how much to shift and the stack containing the input
;#asm
;r0  equ  1
;r1  equ  3
;shit
;    xdef ~~~lasl
;    func
;    ~~~lasl:
;        ;save how much we need to shift into x
;        tax
;        ;Read our 32bits off the stack
;        lda 6, S
;        sta <r0
;        lda 4, S
;        sta <r1
;
;        ;Loop until there's no more shifts left to do
;        loop:
;        cpx #0
;        beq __finish2
;        asl <r0
;        rol <r1
;        dex
;        bra loop
;    __finish2:
;        ;Put the result back on the stack
;        lda <r0
;        sta 6, S
;        lda <r1
;        sta 4, S
;        rtl
;#endasm
	asmstart
r0  equ  1
r1  equ  3
shit
    xdef ~~~lasl
    func
    ~~~lasl:
        ;save how much we need to shift into x
        tax
        ;Read our 32bits off the stack
        lda 6, S
        sta <r0
        lda 4, S
        sta <r1

        ;Loop until there's no more shifts left to do
        loop:
        cpx #0
        beq __finish2
        asl <r0
        rol <r1
        dex
        bra loop
    __finish2:
        ;Put the result back on the stack
        lda <r0
        sta 6, S
        lda <r1
        sta 4, S
        rtl
	asmend
;
	end
