;:ts=8
R0	equ	1
R1	equ	5
R2	equ	9
R3	equ	13
;#pragma section code = text
text	section
	ends
;#pragma section data = text
;
;#include "font.h"
	text
	xdef	~~console_font_8x8
~~console_font_8x8:
	db	$0,$0,$0,$0,$0,$0,$0,$0,$7E,$81
	db	$A5,$81,$9D,$B9,$81,$7E,$7E,$FF,$DB,$FF
	db	$E3,$C7,$FF,$7E,$6C,$FE,$FE,$FE,$7C,$38
	db	$10,$0,$10,$38,$7C,$FE,$7C,$38,$10,$0
	db	$38,$7C,$38,$FE,$FE,$10,$10,$7C,$0,$18
	db	$3C,$7E,$FF,$7E,$18,$7E,$0,$0,$18,$3C
	db	$3C,$18,$0,$0,$FF,$FF,$E7,$C3,$C3,$E7
	db	$FF,$FF,$0,$3C,$66,$42,$42,$66,$3C,$0
	db	$FF,$C3,$99,$BD,$BD,$99,$C3,$FF,$F,$7
	db	$F,$7D,$CC,$CC,$CC,$78,$3C,$66,$66,$66
	db	$3C,$18,$7E,$18,$3F,$33,$3F,$30,$30,$70
	db	$F0,$E0,$7F,$63,$7F,$63,$63,$67,$E6,$C0
	db	$99,$5A,$3C,$E7,$E7,$3C,$5A,$99,$80,$E0
	db	$F8,$FE,$F8,$E0,$80,$0,$2,$E,$3E,$FE
	db	$3E,$E,$2,$0,$18,$3C,$7E,$18,$18,$7E
	db	$3C,$18,$66,$66,$66,$66,$66,$0,$66,$0
	db	$7F,$DB,$DB,$7B,$1B,$1B,$1B,$0,$3F,$60
	db	$7C,$66,$66,$3E,$6,$FC,$0,$0,$0,$0
	db	$7E,$7E,$7E,$0,$18,$3C,$7E,$18,$7E,$3C
	db	$18,$FF,$18,$3C,$7E,$18,$18,$18,$18,$0
	db	$18,$18,$18,$18,$7E,$3C,$18,$0,$0,$18
	db	$C,$FE,$C,$18,$0,$0,$0,$30,$60,$FE
	db	$60,$30,$0,$0,$0,$0,$C0,$C0,$C0,$FE
	db	$0,$0,$0,$24,$66,$FF,$66,$24,$0,$0
	db	$0,$18,$3C,$7E,$FF,$FF,$0,$0,$0,$FF
	db	$FF,$7E,$3C,$18,$0,$0,$0,$0,$0,$0
	db	$0,$0,$0,$0,$18,$18,$18,$18,$18,$0
	db	$18,$0,$6C,$6C,$6C,$0,$0,$0,$0,$0
	db	$6C,$6C,$FE,$6C,$FE,$6C,$6C,$0,$18,$7E
	db	$C0,$7C,$6,$FC,$18,$0,$0,$C6,$CC,$18
	db	$30,$66,$C6,$0,$38,$6C,$38,$76,$DC,$CC
	db	$76,$0,$30,$30,$60,$0,$0,$0,$0,$0
	db	$C,$18,$30,$30,$30,$18,$C,$0,$30,$18
	db	$C,$C,$C,$18,$30,$0,$0,$66,$3C,$FF
	db	$3C,$66,$0,$0,$0,$18,$18,$7E,$18,$18
	db	$0,$0,$0,$0,$0,$0,$0,$18,$18,$30
	db	$0,$0,$0,$7E,$0,$0,$0,$0,$0,$0
	db	$0,$0,$0,$18,$18,$0,$6,$C,$18,$30
	db	$60,$C0,$80,$0,$7C,$CE,$DE,$F6,$E6,$C6
	db	$7C,$0,$18,$38,$18,$18,$18,$18,$7E,$0
	db	$7C,$C6,$6,$7C,$C0,$C0,$FE,$0,$FC,$6
	db	$6,$3C,$6,$6,$FC,$0,$C,$CC,$CC,$CC
	db	$FE,$C,$C,$0,$FE,$C0,$FC,$6,$6,$C6
	db	$7C,$0,$7C,$C0,$C0,$FC,$C6,$C6,$7C,$0
	db	$FE,$6,$6,$C,$18,$30,$30,$0,$7C,$C6
	db	$C6,$7C,$C6,$C6,$7C,$0,$7C,$C6,$C6,$7E
	db	$6,$6,$7C,$0,$0,$18,$18,$0,$0,$18
	db	$18,$0,$0,$18,$18,$0,$0,$18,$18,$30
	db	$C,$18,$30,$60,$30,$18,$C,$0,$0,$0
	db	$7E,$0,$7E,$0,$0,$0,$30,$18,$C,$6
	db	$C,$18,$30,$0,$3C,$66,$C,$18,$18,$0
	db	$18,$0,$7C,$C6,$DE,$DE,$DE,$C0,$7E,$0
	db	$38,$6C,$C6,$C6,$FE,$C6,$C6,$0,$FC,$C6
	db	$C6,$FC,$C6,$C6,$FC,$0,$7C,$C6,$C0,$C0
	db	$C0,$C6,$7C,$0,$F8,$CC,$C6,$C6,$C6,$CC
	db	$F8,$0,$FE,$C0,$C0,$F8,$C0,$C0,$FE,$0
	db	$FE,$C0,$C0,$F8,$C0,$C0,$C0,$0,$7C,$C6
	db	$C0,$C0,$CE,$C6,$7C,$0,$C6,$C6,$C6,$FE
	db	$C6,$C6,$C6,$0,$7E,$18,$18,$18,$18,$18
	db	$7E,$0,$6,$6,$6,$6,$6,$C6,$7C,$0
	db	$C6,$CC,$D8,$F0,$D8,$CC,$C6,$0,$C0,$C0
	db	$C0,$C0,$C0,$C0,$FE,$0,$C6,$EE,$FE,$FE
	db	$D6,$C6,$C6,$0,$C6,$E6,$F6,$DE,$CE,$C6
	db	$C6,$0,$7C,$C6,$C6,$C6,$C6,$C6,$7C,$0
	db	$FC,$C6,$C6,$FC,$C0,$C0,$C0,$0,$7C,$C6
	db	$C6,$C6,$D6,$DE,$7C,$6,$FC,$C6,$C6,$FC
	db	$D8,$CC,$C6,$0,$7C,$C6,$C0,$7C,$6,$C6
	db	$7C,$0,$FF,$18,$18,$18,$18,$18,$18,$0
	db	$C6,$C6,$C6,$C6,$C6,$C6,$FE,$0,$C6,$C6
	db	$C6,$C6,$C6,$7C,$38,$0,$C6,$C6,$C6,$C6
	db	$D6,$FE,$6C,$0,$C6,$C6,$6C,$38,$6C,$C6
	db	$C6,$0,$C6,$C6,$C6,$7C,$18,$30,$E0,$0
	db	$FE,$6,$C,$18,$30,$60,$FE,$0,$3C,$30
	db	$30,$30,$30,$30,$3C,$0,$C0,$60,$30,$18
	db	$C,$6,$2,$0,$3C,$C,$C,$C,$C,$C
	db	$3C,$0,$10,$38,$6C,$C6,$0,$0,$0,$0
	db	$0,$0,$0,$0,$0,$0,$0,$FF,$18,$18
	db	$C,$0,$0,$0,$0,$0,$0,$0,$7C,$6
	db	$7E,$C6,$7E,$0,$C0,$C0,$C0,$FC,$C6,$C6
	db	$FC,$0,$0,$0,$7C,$C6,$C0,$C6,$7C,$0
	db	$6,$6,$6,$7E,$C6,$C6,$7E,$0,$0,$0
	db	$7C,$C6,$FE,$C0,$7C,$0,$1C,$36,$30,$78
	db	$30,$30,$78,$0,$0,$0,$7E,$C6,$C6,$7E
	db	$6,$FC,$C0,$C0,$FC,$C6,$C6,$C6,$C6,$0
	db	$18,$0,$38,$18,$18,$18,$3C,$0,$6,$0
	db	$6,$6,$6,$6,$C6,$7C,$C0,$C0,$CC,$D8
	db	$F8,$CC,$C6,$0,$38,$18,$18,$18,$18,$18
	db	$3C,$0,$0,$0,$CC,$FE,$FE,$D6,$D6,$0
	db	$0,$0,$FC,$C6,$C6,$C6,$C6,$0,$0,$0
	db	$7C,$C6,$C6,$C6,$7C,$0,$0,$0,$FC,$C6
	db	$C6,$FC,$C0,$C0,$0,$0,$7E,$C6,$C6,$7E
	db	$6,$6,$0,$0,$FC,$C6,$C0,$C0,$C0,$0
	db	$0,$0,$7E,$C0,$7C,$6,$FC,$0,$18,$18
	db	$7E,$18,$18,$18,$E,$0,$0,$0,$C6,$C6
	db	$C6,$C6,$7E,$0,$0,$0,$C6,$C6,$C6,$7C
	db	$38,$0,$0,$0,$C6,$C6,$D6,$FE,$6C,$0
	db	$0,$0,$C6,$6C,$38,$6C,$C6,$0,$0,$0
	db	$C6,$C6,$C6,$7E,$6,$FC,$0,$0,$FE,$C
	db	$38,$60,$FE,$0,$E,$18,$18,$70,$18,$18
	db	$E,$0,$18,$18,$18,$0,$18,$18,$18,$0
	db	$70,$18,$18,$E,$18,$18,$70,$0,$76,$DC
	db	$0,$0,$0,$0,$0,$0,$0,$10,$38,$6C
	db	$C6,$C6,$FE,$0,$7C,$C6,$C0,$C0,$C0,$D6
	db	$7C,$30,$C6,$0,$C6,$C6,$C6,$C6,$7E,$0
	db	$E,$0,$7C,$C6,$FE,$C0,$7C,$0,$7E,$81
	db	$3C,$6,$7E,$C6,$7E,$0,$66,$0,$7C,$6
	db	$7E,$C6,$7E,$0,$E0,$0,$7C,$6,$7E,$C6
	db	$7E,$0,$18,$18,$7C,$6,$7E,$C6,$7E,$0
	db	$0,$0,$7C,$C6,$C0,$D6,$7C,$30,$7E,$81
	db	$7C,$C6,$FE,$C0,$7C,$0,$66,$0,$7C,$C6
	db	$FE,$C0,$7C,$0,$E0,$0,$7C,$C6,$FE,$C0
	db	$7C,$0,$66,$0,$38,$18,$18,$18,$3C,$0
	db	$7C,$82,$38,$18,$18,$18,$3C,$0,$70,$0
	db	$38,$18,$18,$18,$3C,$0,$C6,$10,$7C,$C6
	db	$FE,$C6,$C6,$0,$38,$38,$0,$7C,$C6,$FE
	db	$C6,$0,$E,$0,$FE,$C0,$F8,$C0,$FE,$0
	db	$0,$0,$7F,$C,$7F,$CC,$7F,$0,$3F,$6C
	db	$CC,$FF,$CC,$CC,$CF,$0,$7C,$82,$7C,$C6
	db	$C6,$C6,$7C,$0,$66,$0,$7C,$C6,$C6,$C6
	db	$7C,$0,$E0,$0,$7C,$C6,$C6,$C6,$7C,$0
	db	$7C,$82,$0,$C6,$C6,$C6,$7E,$0,$E0,$0
	db	$C6,$C6,$C6,$C6,$7E,$0,$66,$0,$66,$66
	db	$66,$3E,$6,$7C,$C6,$7C,$C6,$C6,$C6,$C6
	db	$7C,$0,$C6,$0,$C6,$C6,$C6,$C6,$FE,$0
	db	$18,$18,$7E,$D8,$D8,$D8,$7E,$18,$38,$6C
	db	$60,$F0,$60,$66,$FC,$0,$66,$66,$3C,$18
	db	$7E,$18,$7E,$18,$F8,$CC,$CC,$FA,$C6,$CF
	db	$C6,$C3,$E,$1B,$18,$3C,$18,$18,$D8,$70
	db	$E,$0,$7C,$6,$7E,$C6,$7E,$0,$1C,$0
	db	$38,$18,$18,$18,$3C,$0,$E,$0,$7C,$C6
	db	$C6,$C6,$7C,$0,$E,$0,$C6,$C6,$C6,$C6
	db	$7E,$0,$0,$FE,$0,$FC,$C6,$C6,$C6,$0
	db	$FE,$0,$C6,$E6,$F6,$DE,$CE,$0,$3C,$6C
	db	$6C,$3E,$0,$7E,$0,$0,$3C,$66,$66,$3C
	db	$0,$7E,$0,$0,$18,$0,$18,$18,$30,$66
	db	$3C,$0,$0,$0,$0,$FC,$C0,$C0,$0,$0
	db	$0,$0,$0,$FC,$C,$C,$0,$0,$C6,$CC
	db	$D8,$3F,$63,$CF,$8C,$F,$C3,$C6,$CC,$DB
	db	$37,$6D,$CF,$3,$18,$0,$18,$18,$18,$18
	db	$18,$0,$0,$33,$66,$CC,$66,$33,$0,$0
	db	$0,$CC,$66,$33,$66,$CC,$0,$0,$22,$88
	db	$22,$88,$22,$88,$22,$88,$55,$AA,$55,$AA
	db	$55,$AA,$55,$AA,$DD,$77,$DD,$77,$DD,$77
	db	$DD,$77,$18,$18,$18,$18,$18,$18,$18,$18
	db	$18,$18,$18,$18,$F8,$18,$18,$18,$18,$18
	db	$F8,$18,$F8,$18,$18,$18,$36,$36,$36,$36
	db	$F6,$36,$36,$36,$0,$0,$0,$0,$FE,$36
	db	$36,$36,$0,$0,$F8,$18,$F8,$18,$18,$18
	db	$36,$36,$F6,$6,$F6,$36,$36,$36,$36,$36
	db	$36,$36,$36,$36,$36,$36,$0,$0,$FE,$6
	db	$F6,$36,$36,$36,$36,$36,$F6,$6,$FE,$0
	db	$0,$0,$36,$36,$36,$36,$FE,$0,$0,$0
	db	$18,$18,$F8,$18,$F8,$0,$0,$0,$0,$0
	db	$0,$0,$F8,$18,$18,$18,$18,$18,$18,$18
	db	$1F,$0,$0,$0,$18,$18,$18,$18,$FF,$0
	db	$0,$0,$0,$0,$0,$0,$FF,$18,$18,$18
	db	$18,$18,$18,$18,$1F,$18,$18,$18,$0,$0
	db	$0,$0,$FF,$0,$0,$0,$18,$18,$18,$18
	db	$FF,$18,$18,$18,$18,$18,$1F,$18,$1F,$18
	db	$18,$18,$36,$36,$36,$36,$37,$36,$36,$36
	db	$36,$36,$37,$30,$3F,$0,$0,$0,$0,$0
	db	$3F,$30,$37,$36,$36,$36,$36,$36,$F7,$0
	db	$FF,$0,$0,$0,$0,$0,$FF,$0,$F7,$36
	db	$36,$36,$36,$36,$37,$30,$37,$36,$36,$36
	db	$0,$0,$FF,$0,$FF,$0,$0,$0,$36,$36
	db	$F7,$0,$F7,$36,$36,$36,$18,$18,$FF,$0
	db	$FF,$0,$0,$0,$36,$36,$36,$36,$FF,$0
	db	$0,$0,$0,$0,$FF,$0,$FF,$18,$18,$18
	db	$0,$0,$0,$0,$FF,$36,$36,$36,$36,$36
	db	$36,$36,$3F,$0,$0,$0,$18,$18,$1F,$18
	db	$1F,$0,$0,$0,$0,$0,$1F,$18,$1F,$18
	db	$18,$18,$0,$0,$0,$0,$3F,$36,$36,$36
	db	$36,$36,$36,$36,$FF,$36,$36,$36,$18,$18
	db	$FF,$18,$FF,$18,$18,$18,$18,$18,$18,$18
	db	$F8,$0,$0,$0,$0,$0,$0,$0,$1F,$18
	db	$18,$18,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	db	$0,$0,$0,$0,$FF,$FF,$FF,$FF,$F0,$F0
	db	$F0,$F0,$F0,$F0,$F0,$F0,$F,$F,$F,$F
	db	$F,$F,$F,$F,$FF,$FF,$FF,$FF,$0,$0
	db	$0,$0,$0,$0,$76,$DC,$C8,$DC,$76,$0
	db	$38,$6C,$6C,$78,$6C,$66,$6C,$60,$0,$FE
	db	$C6,$C0,$C0,$C0,$C0,$0,$0,$0,$FE,$6C
	db	$6C,$6C,$6C,$0,$FE,$60,$30,$18,$30,$60
	db	$FE,$0,$0,$0,$7E,$D8,$D8,$D8,$70,$0
	db	$0,$66,$66,$66,$66,$7C,$60,$C0,$0,$76
	db	$DC,$18,$18,$18,$18,$0,$7E,$18,$3C,$66
	db	$66,$3C,$18,$7E,$3C,$66,$C3,$FF,$C3,$66
	db	$3C,$0,$3C,$66,$C3,$C3,$66,$66,$E7,$0
	db	$E,$18,$C,$7E,$C6,$C6,$7C,$0,$0,$0
	db	$7E,$DB,$DB,$7E,$0,$0,$6,$C,$7E,$DB
	db	$DB,$7E,$60,$C0,$38,$60,$C0,$F8,$C0,$60
	db	$38,$0,$78,$CC,$CC,$CC,$CC,$CC,$CC,$0
	db	$0,$7E,$0,$7E,$0,$7E,$0,$0,$18,$18
	db	$7E,$18,$18,$0,$7E,$0,$60,$30,$18,$30
	db	$60,$0,$FC,$0,$18,$30,$60,$30,$18,$0
	db	$FC,$0,$E,$1B,$1B,$18,$18,$18,$18,$18
	db	$18,$18,$18,$18,$18,$D8,$D8,$70,$18,$18
	db	$0,$7E,$0,$18,$18,$0,$0,$76,$DC,$0
	db	$76,$DC,$0,$0,$38,$6C,$6C,$38,$0,$0
	db	$0,$0,$0,$0,$0,$18,$18,$0,$0,$0
	db	$0,$0,$0,$0,$18,$0,$0,$0,$F,$C
	db	$C,$C,$EC,$6C,$3C,$1C,$78,$6C,$6C,$6C
	db	$6C,$0,$0,$0,$7C,$C,$7C,$60,$7C,$0
	db	$0,$0,$0,$0,$3C,$3C,$3C,$3C,$0,$0
	db	$0,$10,$0,$0,$0,$0,$0,$0
	ends
;void draw_line(char charLine, unsigned int offset, unsigned char color);
;
;void draw_line(char charLine, unsigned int offset, unsigned char color)
;{
	text
	xdef	~~draw_line
	func
~~draw_line:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L2
	tcs
	phd
	tcd
charLine_0	set	4
offset_0	set	6
color_0	set	8
;	char *video = (char *)0x012000;
;	char *drawStart;
;	int x;
;
;	drawStart = video + offset;
video_1	set	0
drawStart_1	set	4
x_1	set	8
	lda	#$2000
	sta	<L3+video_1
	lda	#$1
	sta	<L3+video_1+2
	lda	<L2+offset_0
	sta	<R0
	stz	<R0+2
	clc
	lda	<L3+video_1
	adc	<R0
	sta	<L3+drawStart_1
	lda	<L3+video_1+2
	adc	<R0+2
	sta	<L3+drawStart_1+2
;	for (x = 0; x < 4; x++)
	stz	<L3+x_1
	brl	L10002
L10001:
	inc	<L3+x_1
L10002:
	lda	<L3+x_1
	bmi	L4
	dea
	dea
	dea
	dea
	bmi	L4
	brl	L10003
L4:
;	{
;		// drawStart[x] = charLine;
;		if (charLine & 0x80)
;		{
	sep	#$20
	longa	off
	lda	<L2+charLine_0
	and	#<$80
	rep	#$20
	longa	on
	bne	L5
	brl	L10004
L5:
;			drawStart[x] = color << 4;
	ldy	#$0
	lda	<L3+x_1
	bpl	L6
	dey
L6:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L3+drawStart_1
	adc	<R0
	sta	<R1
	lda	<L3+drawStart_1+2
	adc	<R0+2
	sta	<R1+2
	sep	#$20
	longa	off
	lda	<L2+color_0
	asl	A
	asl	A
	asl	A
	asl	A
	rep	#$20
	longa	on
	sep	#$20
	longa	off
	sta	[<R1]
	rep	#$20
	longa	on
;		}
;		else
	brl	L10005
L10004:
;		{
;			drawStart[x] = 0;
	ldy	#$0
	lda	<L3+x_1
	bpl	L7
	dey
L7:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L3+drawStart_1
	adc	<R0
	sta	<R1
	lda	<L3+drawStart_1+2
	adc	<R0+2
	sta	<R1+2
	sep	#$20
	longa	off
	lda	#$0
	sta	[<R1]
	rep	#$20
	longa	on
;		}
L10005:
;
;		charLine = charLine << 1;
	sep	#$20
	longa	off
	asl	<L2+charLine_0
	rep	#$20
	longa	on
;
;		if (charLine & 0x80)
;		{
	sep	#$20
	longa	off
	lda	<L2+charLine_0
	and	#<$80
	rep	#$20
	longa	on
	bne	L8
	brl	L10006
L8:
;			drawStart[x] = drawStart[x] | color;
	ldy	#$0
	lda	<L3+x_1
	bpl	L9
	dey
L9:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L3+drawStart_1
	adc	<R0
	sta	<R1
	lda	<L3+drawStart_1+2
	adc	<R0+2
	sta	<R1+2
	ldy	#$0
	lda	<L3+x_1
	bpl	L10
	dey
L10:
	sta	<R0
	sty	<R0+2
	clc
	lda	<L3+drawStart_1
	adc	<R0
	sta	<R2
	lda	<L3+drawStart_1+2
	adc	<R0+2
	sta	<R2+2
	sep	#$20
	longa	off
	lda	<L2+color_0
	ora	[<R2]
	rep	#$20
	longa	on
	sep	#$20
	longa	off
	sta	[<R1]
	rep	#$20
	longa	on
;		}
;
;		charLine = charLine << 1;
L10006:
	sep	#$20
	longa	off
	asl	<L2+charLine_0
	rep	#$20
	longa	on
;	}
	brl	L10001
L10003:
;}
L11:
	lda	<L2+2
	sta	<L2+2+6
	lda	<L2+1
	sta	<L2+1+6
	pld
	tsc
	clc
	adc	#L2+6
	tcs
	rtl
L2	equ	22
L3	equ	13
	ends
	efunc
;
;static unsigned int cursor = 0;
	text
~~cursor:
	dw	$0
	ends
;void _putchar(char character, unsigned char color)
;{
	text
	xdef	~~_putchar
	func
~~_putchar:
	longa	on
	longi	on
	tsc
	sec
	sbc	#L12
	tcs
	phd
	tcd
character_0	set	4
color_0	set	6
;	unsigned char *template;
;	template = console_font_8x8[character];
template_1	set	0
	lda	<L12+character_0
	and	#$ff
	sta	<R1
	stz	<R1+2
	pei	<R1+2
	pei	<R1
	lda	#$3
	xref	~~~lasl
	jsl	~~~lasl
	sta	<R0
	stx	<R0+2
	clc
	lda	#<~~console_font_8x8
	adc	<R0
	sta	<L13+template_1
	lda	#^~~console_font_8x8
	adc	<R0+2
	sta	<L13+template_1+2
;	draw_line(template[0], cursor, color);
	pei	<L12+color_0
	lda	|~~cursor
	pha
	lda	[<L13+template_1]
	pha
	jsl	~~draw_line
;	draw_line(template[1], cursor + 160, color);
	pei	<L12+color_0
	clc
	lda	#$a0
	adc	|~~cursor
	pha
	ldy	#$1
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[2], cursor + 160 * 2, color);
	pei	<L12+color_0
	clc
	lda	#$140
	adc	|~~cursor
	pha
	ldy	#$2
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[3], cursor + 160 * 3, color);
	pei	<L12+color_0
	clc
	lda	#$1e0
	adc	|~~cursor
	pha
	ldy	#$3
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[4], cursor + 160 * 4, color);
	pei	<L12+color_0
	clc
	lda	#$280
	adc	|~~cursor
	pha
	ldy	#$4
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[5], cursor + 160 * 5, color);
	pei	<L12+color_0
	clc
	lda	#$320
	adc	|~~cursor
	pha
	ldy	#$5
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[6], cursor + 160 * 6, color);
	pei	<L12+color_0
	clc
	lda	#$3c0
	adc	|~~cursor
	pha
	ldy	#$6
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	draw_line(template[7], cursor + 160 * 7, color);
	pei	<L12+color_0
	clc
	lda	#$460
	adc	|~~cursor
	pha
	ldy	#$7
	lda	[<L13+template_1],Y
	pha
	jsl	~~draw_line
;	cursor += 4;
	clc
	lda	#$4
	adc	|~~cursor
	sta	|~~cursor
;	if (cursor % 160 == 0)
;	{
	lda	|~~cursor
	ldx	#<$a0
	xref	~~~umd
	jsl	~~~umd
	tax
	beq	L14
	brl	L10007
L14:
;		cursor += 1280;
	clc
	lda	#$500
	adc	|~~cursor
	sta	|~~cursor
;	}
;
;	if (cursor > 32000)
L10007:
;	{
	lda	#$7d00
	cmp	|~~cursor
	bcc	L15
	brl	L10008
L15:
;		cursor = 0;
	stz	|~~cursor
;	}
;}
L10008:
L16:
	lda	<L12+2
	sta	<L12+2+4
	lda	<L12+1
	sta	<L12+1+4
	pld
	tsc
	clc
	adc	#L12+4
	tcs
	rtl
L12	equ	12
L13	equ	9
	ends
	efunc
;
	end
