;:ts=8
R0	equ	1
R1	equ	5
R2	equ	9
R3	equ	13
;// mame.exe apple2gs -sl7 cffa2 -hard1 "..\gsplus-win-sdl\System 6 and Free Games.hdv" -flop3 ..\gsplus-win-sdl\mydisk.po
;#pragma section code = code
;void main(void);
;#asm
;	JMP >%%main; long jump in case not bank 0
;#endasm
	asmstart
	JMP >~~main; long jump in case not bank 0
	asmend
;
;#include "toolbox.h"
	asmstart
TOOL MACRO INDEX, ERROR
		LDX	INDEX         ; load tool call #
		JSL	$E10000        ; go to dispatcher
		STA	ERROR;
	MACEND

PULL_LONG MACRO RESULT
		PLA				   ;pull first 16bits of result
		STA RESULT 
		PLA				   ;second 16bits of result
		LDX #2 
		STA RESULT, X
	MACEND

PUSH_LONG MACRO RESULT
		LDX #2
		PHA
		LDA RESULT, X
		LDA RESULT
		PHA
	MACEND

	asmend
	code
	xdef	~~CheckToolError
	func
~~CheckToolError:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L2
	tcs
	phd
	tcd
tool_error_0	set	4
	lda	<L2+tool_error_0
	bne	L4
	brl	L10001
L4:
	asmstart
			LDA <L2+tool_error_0
			BRK
	asmend
L10001:
L5:
	lda	<L2+2
	sta	<L2+2+2
	lda	<L2+1
	sta	<L2+1+2
	pld
	tsc
	clc
	adc	#L2+2
	tcs
	rtl
L2	equ	0
L3	equ	1
	ends
	efunc
	code
	xdef	~~_tool
	func
~~_tool:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L6
	tcs
	phd
	tcd
tool_0	set	4
tool_error_1	set	0
	lda	#$1
	sta	<L7+tool_error_1
	asmstart
		LDX	<L6+tool_0         ; load tool call #
		JSL	$E10000        ; go to dispatcher
		STA	<L7+tool_error_1;
	asmend
	pei	<L7+tool_error_1
	jsl	~~CheckToolError
	lda	#$1
L8:
	tay
	lda	<L6+2
	sta	<L6+2+2
	lda	<L6+1
	sta	<L6+1+2
	pld
	tsc
	clc
	adc	#L6+2
	tcs
	tya
	rtl
L6	equ	2
L7	equ	1
	ends
	efunc
	code
	xdef	~~_TLStartUp
	func
~~_TLStartUp:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L9
	tcs
	phd
	tcd
	pea	#<$201
	jsl	~~_tool
L11:
	tay
	pld
	tsc
	clc
	adc	#L9
	tcs
	tya
	rtl
L9	equ	0
L10	equ	1
	ends
	efunc
	data
	xdef	~~userId
~~userId:
	dw	$0
	ends
	code
	xdef	~~_MMStartup
	func
~~_MMStartup:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L12
	tcs
	phd
	tcd
tool_1	set	0
tool_error_1	set	2
result_1	set	4
	lda	#$202
	sta	<L13+tool_1
	lda	#$1
	sta	<L13+tool_error_1
	stz	<L13+result_1
	asmstart
		PEA #0  ;16 bit result
		TOOL	<L13+tool_1, <L13+tool_error_1
		PLA				   ;pull first 16bits of result
		STA <L13+result_1 
	asmend
	pei	<L13+tool_error_1
	jsl	~~CheckToolError
	lda	<L13+result_1
	sta	|~~userId
	lda	<L13+result_1
L14:
	tay
	pld
	tsc
	clc
	adc	#L12
	tcs
	tya
	rtl
L12	equ	6
L13	equ	1
	ends
	efunc
	code
	xdef	~~_HLock
	func
~~_HLock:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L15
	tcs
	phd
	tcd
handle_0	set	4
tool_1	set	0
tool_error_1	set	2
	lda	#$2002
	sta	<L16+tool_1
	lda	#$1
	sta	<L16+tool_error_1
	asmstart
		PUSH_LONG <L15+handle_0
		TOOL	<L16+tool_1, <L16+tool_error_1
	asmend
	pei	<L16+tool_error_1
	jsl	~~CheckToolError
	lda	#$1
L17:
	tay
	lda	<L15+2
	sta	<L15+2+4
	lda	<L15+1
	sta	<L15+1+4
	pld
	tsc
	clc
	adc	#L15+4
	tcs
	tya
	rtl
L15	equ	4
L16	equ	1
	ends
	efunc
	code
	xdef	~~_GetHandleSize
	func
~~_GetHandleSize:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L18
	tcs
	phd
	tcd
handle_0	set	4
tool_1	set	0
tool_error_1	set	2
result_1	set	4
	lda	#$1802
	sta	<L19+tool_1
	lda	#$1
	sta	<L19+tool_error_1
	stz	<L19+result_1
	stz	<L19+result_1+2
	asmstart
		PUSH_LONG <L19+result_1	; Leave space for result
		PUSH_LONG <L18+handle_0
		TOOL <L19+tool_1, <L19+tool_error_1
		PULL_LONG <L19+result_1;
	asmend
	pei	<L19+tool_error_1
	jsl	~~CheckToolError
	ldx	<L19+result_1+2
	lda	<L19+result_1
L20:
	tay
	lda	<L18+2
	sta	<L18+2+4
	lda	<L18+1
	sta	<L18+1+4
	pld
	tsc
	clc
	adc	#L18+4
	tcs
	tya
	rtl
L18	equ	8
L19	equ	1
	ends
	efunc
	code
	xdef	~~_newHandle
	func
~~_newHandle:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L21
	tcs
	phd
	tcd
numberBytes_0	set	4
tool_1	set	0
tool_error_1	set	2
result_1	set	4
attributes_1	set	8
uid_1	set	10
actualBytes_1	set	12
	lda	#$902
	sta	<L22+tool_1
	lda	#$1
	sta	<L22+tool_error_1
	stz	<L22+result_1
	stz	<L22+result_1+2
	lda	#$8000
	sta	<L22+attributes_1
	lda	|~~userId
	sta	<L22+uid_1
	stz	<L22+actualBytes_1
	stz	<L22+actualBytes_1+2
	asmstart
		PUSH_LONG <L22+result_1	; Leave space for result
		PUSH_LONG <L21+numberBytes_0
		PEI <L22+uid_1
		PEI <L22+attributes_1
		PUSH_LONG <L22+result_1 ; Unused
		TOOL <L22+tool_1, <L22+tool_error_1
		PULL_LONG <L22+result_1;
	asmend
	pei	<L22+tool_error_1
	jsl	~~CheckToolError
	pei	<L22+result_1+2
	pei	<L22+result_1
	jsl	~~_GetHandleSize
	sta	<L22+actualBytes_1
	stx	<L22+actualBytes_1+2
	lda	<L21+numberBytes_0
	cmp	<L22+actualBytes_1
	bne	L23
	lda	<L21+numberBytes_0+2
	cmp	<L22+actualBytes_1+2
L23:
	bne	L24
	brl	L10002
L24:
	pea	#<$99
	jsl	~~CheckToolError
L10002:
	lda	[<L22+result_1]
	ldy	#$2
	ora	[<L22+result_1],Y
	beq	L25
	brl	L10003
L25:
	pea	#<$999
	jsl	~~CheckToolError
L10003:
	ldx	<L22+result_1+2
	lda	<L22+result_1
L26:
	tay
	lda	<L21+2
	sta	<L21+2+4
	lda	<L21+1
	sta	<L21+1+4
	pld
	tsc
	clc
	adc	#L21+4
	tcs
	tya
	rtl
L21	equ	16
L22	equ	1
	ends
	efunc
	code
	xdef	~~_multiply
	func
~~_multiply:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L27
	tcs
	phd
	tcd
x_0	set	4
y_0	set	6
tool_1	set	0
tool_error_1	set	2
result_1	set	4
	lda	#$90b
	sta	<L28+tool_1
	lda	#$1
	sta	<L28+tool_error_1
	stz	<L28+result_1
	stz	<L28+result_1+2
	asmstart
		PEA #0  ;Push immediate two 16bit words to leave space for result
		PEA #0
		PEI <L27+x_0 ;Our two parameters
		PEI <L27+y_0
		;LDX	<L28+tool_1         ; load tool call #
		;JSL	$E10000        ; go to dispatcher
		TOOL	<L28+tool_1, <L28+tool_error_1
		PULL_LONG	<L28+result_1
	asmend
	pei	<L28+tool_error_1
	jsl	~~CheckToolError
	ldx	<L28+result_1+2
	lda	<L28+result_1
L29:
	tay
	lda	<L27+2
	sta	<L27+2+4
	lda	<L27+1
	sta	<L27+1+4
	pld
	tsc
	clc
	adc	#L27+4
	tcs
	tya
	rtl
L27	equ	8
L28	equ	1
	ends
	efunc
;#include "text.h"
;#include "printf.h"
;
;	void
;	setPalette(int colorNum, int red, int green, int blue);
;
;void main(void)
;{
	code
	xdef	~~main
	func
~~main:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L30
	tcs
	phd
	tcd
;	int i = 0;
;	char ch = 0;
;	char *newVideo = (char *)0x00C029;
;	char *shadow = (char *)0x00C035;
;	char *scanControl = (char *)0x019D00;
;	char *video = (char *)0x012000;
;
;	char **testMemory;
;	//__TLStartUp();
;
;	// enable super high res mode, maybe
;	*newVideo = *newVideo |= 0x80;
i_1	set	0
ch_1	set	2
newVideo_1	set	3
shadow_1	set	7
scanControl_1	set	11
video_1	set	15
testMemory_1	set	19
	stz	<L31+i_1
	sep	#$20
	longa	off
	stz	<L31+ch_1
	rep	#$20
	longa	on
	lda	#$c029
	sta	<L31+newVideo_1
	lda	#$0
	sta	<L31+newVideo_1+2
	lda	#$c035
	sta	<L31+shadow_1
	lda	#$0
	sta	<L31+shadow_1+2
	lda	#$9d00
	sta	<L31+scanControl_1
	lda	#$1
	sta	<L31+scanControl_1+2
	lda	#$2000
	sta	<L31+video_1
	lda	#$1
	sta	<L31+video_1+2
	sep	#$20
	longa	off
	lda	[<L31+newVideo_1]
	ora	#<$80
	sta	[<L31+newVideo_1]
	rep	#$20
	longa	on
	sep	#$20
	longa	off
	lda	[<L31+newVideo_1]
	sta	[<L31+newVideo_1]
	rep	#$20
	longa	on
;
;	// Enable shadow for super high res mode
;	*shadow &= 0xF7;
	sep	#$20
	longa	off
	lda	[<L31+shadow_1]
	and	#<$f7
	sta	[<L31+shadow_1]
	rep	#$20
	longa	on
;
;	/*
;	if (!_TLStartUp())
;	{
;		while (1)
;		{
;		}
;	}
;
;	if (_MMStartup() == 0)
;	{
;		while (1)
;		{
;		}
;	}
;
;	if (_multiply(1000, 1000) != 1000000)
;	{
;		// do nothing
;		while (1)
;		{
;		}
;	}
;
;
;	testMemory = _newHandle(1024l * 1024l * 15l);
;	if(testMemory == 0) {
;		//do nothing
;		while(1){
;		}
;	} */
;
;	// set all horizontal control lines to 200 pixels wide, default palette, no interrupt.
;	for (i = 0; i < 200; i++)
	stz	<L31+i_1
	brl	L10005
L10004:
	inc	<L31+i_1
L10005:
	sec
	lda	<L31+i_1
	sbc	#<$c8
	bvs	L32
	eor	#$8000
L32:
	bpl	L33
	brl	L10006
L33:
;	{
;		scanControl[i] = 0;
	ldy	#$0
	lda	<L31+i_1
	bpl	L34
	dey
L34:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L31+scanControl_1
	adc	<R0
	sta	<R1
	lda	<L31+scanControl_1+2
	adc	<R0+2
	sta	<R1+2
	sep	#$20
	longa	off
	lda	#$0
	sta	[<R1]
	rep	#$20
	longa	on
;	}
	brl	L10004
L10006:
;
;	for (i = 0; i < 16; i++)
	stz	<L31+i_1
	brl	L10008
L10007:
	inc	<L31+i_1
L10008:
	sec
	lda	<L31+i_1
	sbc	#<$10
	bvs	L35
	eor	#$8000
L35:
	bpl	L36
	brl	L10009
L36:
;	{
;		// set color 0 to be red
;		setPalette(i, i, i, i);
	pei	<L31+i_1
	pei	<L31+i_1
	pei	<L31+i_1
	pei	<L31+i_1
	jsl	~~setPalette
;	}
	brl	L10007
L10009:
;
;	for (i = 0; i < 32000; i++)
	stz	<L31+i_1
	brl	L10011
L10010:
	inc	<L31+i_1
L10011:
	sec
	lda	<L31+i_1
	sbc	#<$7d00
	bvs	L37
	eor	#$8000
L37:
	bpl	L38
	brl	L10012
L38:
;	{
;		video[i] = 0x01; // alternate green and red
	ldy	#$0
	lda	<L31+i_1
	bpl	L39
	dey
L39:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L31+video_1
	adc	<R0
	sta	<R1
	lda	<L31+video_1+2
	adc	<R0+2
	sta	<R1+2
	sep	#$20
	longa	off
	lda	#$1
	sta	[<R1]
	rep	#$20
	longa	on
;	}
	brl	L10010
L10012:
;
;	printf("What is this crap? %d",i);
	pei	<L31+i_1
	pea	#^L1
	pea	#<L1
	pea	#8
	jsl	~~printf
;
;	/*
;		putchar('A');
;		putchar('B');
;		putchar('C');
;	for (ch = 0; ch < 255; ch++)
;	{
;		putchar(ch);
;	}
;			*/
;
;	// do nothing
;	while (1)
L10013:
;	{
;	}
	brl	L10013
;}
L30	equ	31
L31	equ	9
	ends
	efunc
	data
L1:
	db	$57,$68,$61,$74,$20,$69,$73,$20,$74,$68,$69,$73,$20,$63,$72
	db	$61,$70,$3F,$20,$25,$64,$00
	ends
;
;void setPalette(int colorNum, int red, int green, int blue)
;{
	code
	xdef	~~setPalette
	func
~~setPalette:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L41
	tcs
	phd
	tcd
colorNum_0	set	4
red_0	set	6
green_0	set	8
blue_0	set	10
;	char *palette = (char *)0xe19e00;
;	int index = 0;
;	index = colorNum * 2;
palette_1	set	0
index_1	set	4
	lda	#$9e00
	sta	<L42+palette_1
	lda	#$e1
	sta	<L42+palette_1+2
	stz	<L42+index_1
	lda	<L41+colorNum_0
	asl	A
	sta	<L42+index_1
;	palette[index] = ((green & 0xF) << 4) | (blue & 0xF);
	ldy	#$0
	lda	<L42+index_1
	bpl	L43
	dey
L43:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L42+palette_1
	adc	<R0
	sta	<R1
	lda	<L42+palette_1+2
	adc	<R0+2
	sta	<R1+2
	lda	<L41+green_0
	and	#<$f
	sta	<R2
	lda	<R2
	asl	A
	asl	A
	asl	A
	asl	A
	sta	<R0
	lda	<L41+blue_0
	and	#<$f
	sta	<R2
	lda	<R2
	ora	<R0
	sep	#$20
	longa	off
	sta	[<R1]
	rep	#$20
	longa	on
;	palette[index + 1] = (red & 0xF);
	lda	<L42+index_1
	ina
	sta	<R0
	ldy	#$0
	lda	<R0
	bpl	L44
	dey
L44:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L42+palette_1
	adc	<R0
	sta	<R1
	lda	<L42+palette_1+2
	adc	<R0+2
	sta	<R1+2
	lda	<L41+red_0
	and	#<$f
	sep	#$20
	longa	off
	sta	[<R1]
	rep	#$20
	longa	on
;}
L45:
	lda	<L41+2
	sta	<L41+2+8
	lda	<L41+1
	sta	<L41+1+8
	pld
	tsc
	clc
	adc	#L41+8
	tcs
	rtl
L41	equ	18
L42	equ	13
	ends
	efunc
;
	xref	~~printf
	end
