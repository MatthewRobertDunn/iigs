;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_unpackLE.0","acrx"
	a16
	x16
	global	_curve25519_unpackLE
_curve25519_unpackLE:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	sta	r16
	stx	r16+2
	lda	18,s
	sta	r19
	lda	12,s
	sta	r18
; 37 "curve25519.c"
	asl	r18
; 38 "curve25519.c"
	lda	r19
	cmp	r18
	bcs	l4
; 40 "curve25519.c"
	pei	(r19)
	lda	18,s
	pha
	lda	18,s
	pha
	ldx	r16+2
	lda	r16
	jsl	>_memcpy
; 41 "curve25519.c"
	lda	r18
	sec
	sbc	r19
	pha
	pea	#0
	ldx	r16+2
	lda	r16
	clc
	adc	r19
	jsl	>_memset
; 44 "curve25519.c"
	tsc
	clc
	adc	#10
	tcs
	bra	l5
l4:
; 45 "curve25519.c"
	pei	(r18)
	lda	18,s
	pha
	lda	18,s
	pha
	ldx	r16+2
	lda	r16
	jsl	>_memcpy
; 135 "curve25519.c"
	ply
	ply
	ply
l5:
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_packLE.0","acrx"
	a16
	x16
	global	_curve25519_packLE
_curve25519_packLE:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	sta	r18
	stx	r18+2
	lda	12,s
	sta	r17
	lda	18,s
	sta	r16
; 167 "curve25519.c"
	asl	r16
; 168 "curve25519.c"
	lda	r17
	cmp	r16
;
	beq	l12
	bcs	l9
l12:
; 170 "curve25519.c"
	pei	(r17)
	lda	18,s
	pha
	lda	18,s
	pha
	ldx	r18+2
	lda	r18
	jsl	>_memcpy
; 173 "curve25519.c"
	ply
	ply
	ply
	bra	l10
l9:
; 174 "curve25519.c"
	pei	(r16)
	lda	18,s
	pha
	lda	18,s
	pha
	ldx	r18+2
	lda	r18
	jsl	>_memcpy
; 175 "curve25519.c"
	lda	r17
	sec
	sbc	r16
	pha
	pea	#0
	ldx	r18+2
	lda	r18
	clc
	adc	r16
	jsl	>_memset
; 264 "curve25519.c"
	tsc
	clc
	adc	#10
	tcs
l10:
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_reduceQuick.0","acrx"
	a16
	x16
	global	_curve25519_reduceQuick
_curve25519_reduceQuick:
	sta	r28
	tsc
	clc
	adc	#-32
	tcs
	lda	r28
	sta	r12
	stx	r12+2
; 291 "curve25519.c"
	lda	#19
	sta	r6
	stz	r6+2
; 292 "curve25519.c"
	lda	r12
	sta	r2
	lda	r12+2
	sta	r2+2
; 293 "curve25519.c"
	tsc
	ina
	sta	r10
	stz	r10+2
	lda	r10
	sta	r4
	lda	r10+2
	sta	r4+2
; 294 "curve25519.c"
	stz	r1
l27:
; 296 "curve25519.c"
	lda	[r2]
	ldx	#0
	inc	r2
	inc	r2
	clc
	adc	r6
	sta	r6
	txa
	adc	r6+2
	sta	r6+2
; 297 "curve25519.c"
	lda	r6
	sta	[r4]
	inc	r4
	inc	r4
; 298 "curve25519.c"
	lda	r6+2
	sta	r6
	stz	r6+2
; 295 "curve25519.c"
	sep	#32
	a8
	inc	r1
	lda	r1
	cmp	#16
	a16
	rep	#32
	bcc	l27
; 306 "curve25519.c"
	lda	31,s
	and	#65280
	xba
	bpl	l32
	clc
	adc	#65280
l32:
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	sta	r9
; 307 "curve25519.c"
	lda	r9
	eor	#-1
	sta	r8
; 308 "curve25519.c"
	lda	31,s
	and	#32767
	sta	31,s
; 309 "curve25519.c"
	lda	r12
	sta	r2
	lda	r12+2
	sta	r2+2
; 310 "curve25519.c"
	lda	r10
	sta	r4
	lda	r10+2
	sta	r4+2
; 311 "curve25519.c"
	stz	r1
l28:
; 313 "curve25519.c"
	lda	r8
	and	[r2]
	sta	r0
	lda	[r4]
	inc	r4
	inc	r4
	and	r9
	ora	r0
	sta	[r2]
; 314 "curve25519.c"
	inc	r2
	inc	r2
; 312 "curve25519.c"
	sep	#32
	a8
	inc	r1
	lda	r1
	cmp	#16
	a16
	rep	#32
	bcc	l28
; 318 "curve25519.c"
	lda	r8
	tay
	tsc
	clc
	adc	#32
	tcs
	tya
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_isWeakPoint.0","acrx"
	a16
	x16
	global	_curve25519_isWeakPoint
_curve25519_isWeakPoint:
	sta	r28
	tsc
	clc
	adc	#-160
	tcs
	lda	r28
	sta	r10
	stx	r10+2
; 355 "curve25519.c"
	tsc
	ina
	tay
	ldx	#<l35
	phb
	lda	#159
	mvn	#^l35,#0
	plb
; 362 "curve25519.c"
	stz	r7
; 364 "curve25519.c"
	stz	r5
; 366 "curve25519.c"
	tsc
	ina
	sta	r14
	stz	r14+2
; 367 "curve25519.c"
	ldy	#31
	lda	[r10],y ;am(31)
	sta	r12
l54:
; 366 "curve25519.c"
	lda	r5
	and	#255
	asl
	asl
	asl
	asl
	asl
	sta	r31
	lda	r14+2
	sta	r8+2
	lda	r14
	clc
	adc	r31
	sta	r8
; 367 "curve25519.c"
	ldy	#31
	lda	[r8],y ;am(31)
	eor	r12
	sep	#32
	a8
	and	#127
	sta	r6
	a16
	rep	#32
; 369 "curve25519.c"
	lda	#31
	sta	r4
l55:
; 370 "curve25519.c"
	lda	r4
	and	#255
	dea
	sta	r31
	lda	r8+2
	sta	r2+2
	lda	r8
	clc
	adc	r31
	sta	r2
	lda	r10+2
	sta	r0+2
	lda	r10
	clc
	adc	r31
	sta	r0
	lda	[r0]
	eor	[r2]
	sep	#32
	a8
	ora	r6
	sta	r6
	dec	r4
	lda	r4
	a16
	rep	#32
	bne	l55
; 371 "curve25519.c"
	lda	r6
	and	#255
	sta	r31
	lda	#256
	sec
	sbc	r31
	xba
	and	#255
	sep	#32
	a8
	ora	r7
	sta	r7
	a16
	rep	#32
; 365 "curve25519.c"
	sep	#32
	a8
	inc	r5
	lda	r5
	cmp	#5
	a16
	rep	#32
	bcc	l54
; 375 "curve25519.c"
	lda	r7
	tay
	tsc
	clc
	adc	#160
	tcs
	tya
	rtl
; stacksize=0+??
	section	"DONTMERGE_data.far..35","adrw"
l35:
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	1
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	0
	db	224
	db	235
	db	122
	db	124
	db	59
	db	65
	db	184
	db	174
	db	22
	db	86
	db	227
	db	250
	db	241
	db	159
	db	196
	db	106
	db	218
	db	9
	db	141
	db	235
	db	156
	db	50
	db	177
	db	253
	db	134
	db	98
	db	5
	db	22
	db	95
	db	73
	db	184
	db	0
	db	95
	db	156
	db	149
	db	188
	db	163
	db	80
	db	140
	db	36
	db	177
	db	208
	db	177
	db	85
	db	156
	db	131
	db	239
	db	91
	db	4
	db	68
	db	92
	db	196
	db	88
	db	28
	db	142
	db	134
	db	216
	db	34
	db	78
	db	221
	db	208
	db	159
	db	17
	db	87
	db	236
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	255
	db	127
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_mulNoReduce.0","acrx"
	a16
	x16
	global	_curve25519_mulNoReduce
_curve25519_mulNoReduce:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	pei	(r22)
	pei	(r23)
	pei	(r24)
	pei	(r25)
	pei	(r26)
	pei	(r27)
	sta	r26
	stx	r26+2
; 390 "curve25519.c"
	stz	r18
	stz	r18+2
; 391 "curve25519.c"
	lda	28,s
	sta	btmp3
	lda	30,s
	sta	btmp3+2
	lda	[btmp3]
; 392 "curve25519.c"
	sta	r31
	lda	32,s
	sta	r20
	lda	34,s
	sta	r20+2
	lda	r31
; 393 "curve25519.c"
	sta	r31
	lda	r26
	sta	r16
	lda	r26+2
	sta	r16+2
	lda	r31
; 394 "curve25519.c"
	stz	r22
; 397 "curve25519.c"
	sta	r25
l78:
; 396 "curve25519.c"
	lda	[r20]
	ldx	#0
	inc	r20
	inc	r20
; 397 "curve25519.c"
	pei	(r25)
	jsl	>_multiply32_16
; 398 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 399 "curve25519.c"
	lda	r18
	sta	[r16]
	inc	r16
	inc	r16
; 400 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 395 "curve25519.c"
	sep	#32
	a8
	inc	r22
	ply
	lda	r22
	cmp	#16
	a16
	rep	#32
	bcc	l78
; 402 "curve25519.c"
	lda	r18
	sta	[r16]
; 405 "curve25519.c"
	lda	#1
	sta	r22
l79:
; 407 "curve25519.c"
	lda	r22
	and	#255
	sta	r31
	asl
	sta	r0
	lda	30,s
	sta	r2+2
	lda	28,s
	clc
	adc	r0
	sta	r2
	lda	[r2]
; 408 "curve25519.c"
	stz	r18
	stz	r18+2
; 409 "curve25519.c"
	sta	r31
	lda	32,s
	sta	r20
	lda	34,s
	sta	r20+2
	lda	r31
; 410 "curve25519.c"
	sta	r31
	lda	r26+2
	sta	r16+2
	lda	r26
	clc
	adc	r0
	sta	r16
	lda	r31
; 411 "curve25519.c"
	stz	r23
; 414 "curve25519.c"
	sta	r24
l80:
; 413 "curve25519.c"
	lda	[r20]
	ldx	#0
	inc	r20
	inc	r20
; 414 "curve25519.c"
	pei	(r24)
	jsl	>_multiply32_16
; 415 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 416 "curve25519.c"
	lda	[r16]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 417 "curve25519.c"
	lda	r18
	sta	[r16]
	inc	r16
	inc	r16
; 418 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 412 "curve25519.c"
	sep	#32
	a8
	inc	r23
	ply
	lda	r23
	cmp	#16
	a16
	rep	#32
	bcc	l80
; 420 "curve25519.c"
	lda	r18
	sta	[r16]
; 406 "curve25519.c"
	sep	#32
	a8
	inc	r22
	lda	r22
	cmp	#16
	a16
	rep	#32
	bcc	l79
	plx
	stx	r27
	plx
	stx	r26
	plx
	stx	r25
	plx
	stx	r24
	plx
	stx	r23
	plx
	stx	r22
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_mul.0","acrx"
	a16
	x16
	global	_curve25519_mul
_curve25519_mul:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	sta	r28
	tsc
	clc
	adc	#-64
	tcs
	lda	r28
	sta	r18
	stx	r18+2
; 437 "curve25519.c"
	lda	82,s
	pha
	lda	82,s
	pha
	lda	82,s
	pha
	lda	82,s
	pha
	tsc
	clc
	adc	#9
	sta	r16
	stz	r16+2
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mulNoReduce
; 438 "curve25519.c"
	pea	#16
	pei	(r16+2)
	pei	(r16)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_reduce
	tsc
	clc
	adc	#78
	tcs
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_mulA24.0","acrx"
	a16
	x16
	global	_curve25519_mulA24
_curve25519_mulA24:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	pei	(r22)
	pei	(r23)
	pei	(r24)
	pei	(r26)
	pei	(r27)
	sta	r28
	tsc
	clc
	adc	#-68
	tcs
	lda	r28
	sta	r31
	sta	1,s
	txa
	sta	3,s
; 472 "curve25519.c"
	stz	r18
	stz	r18+2
; 474 "curve25519.c"
	lda	94,s
	sta	r20
	lda	96,s
	sta	r20+2
; 475 "curve25519.c"
	tsc
	clc
	adc	#5
	sta	r26
	stz	r26+2
	lda	r26
	sta	r16
	lda	r26+2
	sta	r16+2
; 476 "curve25519.c"
	stz	r22
l110:
; 478 "curve25519.c"
	lda	[r20]
	ldx	#0
	inc	r20
	inc	r20
; 479 "curve25519.c"
	pea	#56129
	jsl	>_multiply32_16
; 480 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 481 "curve25519.c"
	lda	r18
	sta	[r16]
	inc	r16
	inc	r16
; 482 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 477 "curve25519.c"
	sep	#32
	a8
	inc	r22
	ply
	lda	r22
	cmp	#16
	a16
	rep	#32
	bcc	l110
; 484 "curve25519.c"
	lda	r18
	sta	[r16]
; 487 "curve25519.c"
	lda	#1
	sta	r22
l111:
; 489 "curve25519.c"
	lda	r22
	and	#255
	sta	r31
	asl
	sta	r0
	tax
	lda	>0+l88,x ;am(r0)
; 490 "curve25519.c"
	stz	r18
	stz	r18+2
; 491 "curve25519.c"
	sta	r31
	lda	94,s
	sta	r20
	lda	96,s
	sta	r20+2
	lda	r31
; 492 "curve25519.c"
	sta	r31
	lda	r26+2
	sta	r16+2
	lda	r26
	clc
	adc	r0
	sta	r16
	lda	r31
; 493 "curve25519.c"
	stz	r23
; 496 "curve25519.c"
	sta	r24
l112:
; 495 "curve25519.c"
	lda	[r20]
	ldx	#0
	inc	r20
	inc	r20
; 496 "curve25519.c"
	pei	(r24)
	jsl	>_multiply32_16
; 497 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 498 "curve25519.c"
	lda	[r16]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 499 "curve25519.c"
	lda	r18
	sta	[r16]
	inc	r16
	inc	r16
; 500 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 494 "curve25519.c"
	sep	#32
	a8
	inc	r23
	ply
	lda	r23
	cmp	#16
	a16
	rep	#32
	bcc	l112
; 502 "curve25519.c"
	lda	r18
	sta	[r16]
; 488 "curve25519.c"
	sep	#32
	a8
	inc	r22
	lda	r22
	cmp	#2
	a16
	rep	#32
	bcc	l111
; 506 "curve25519.c"
	pea	#2
	pei	(r26+2)
	pei	(r26)
	lda	9,s
	tax
	lda	7,s
	jsl	>_curve25519_reduce
	tsc
	clc
	adc	#74
	tcs
	plx
	stx	r27
	plx
	stx	r26
	plx
	stx	r24
	plx
	stx	r23
	plx
	stx	r22
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
	section	"DONTMERGE_data.near.a24.88","adrw"
l88:
	dw	56129
	dw	1
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_add.0","acrx"
	a16
	x16
	global	_curve25519_add
_curve25519_add:
	sta	r10
	stx	r10+2
	lda	8,s
	sta	r6
	lda	10,s
	sta	r6+2
	lda	4,s
	sta	r4
	lda	6,s
	sta	r4+2
; 521 "curve25519.c"
	stz	r0
	stz	r0+2
; 523 "curve25519.c"
	lda	r10
	sta	r2
	lda	r10+2
	sta	r2+2
; 526 "curve25519.c"
	stz	r8
l124:
; 528 "curve25519.c"
	lda	[r4]
	ldx	#0
	inc	r4
	inc	r4
	clc
	adc	r0
	sta	r0
	txa
	adc	r0+2
	sta	r0+2
; 529 "curve25519.c"
	lda	[r6]
	inc	r6
	inc	r6
	clc
	adc	r0
	sta	r0
	txa
	adc	r0+2
	sta	r0+2
; 530 "curve25519.c"
	lda	r0
	sta	[r2]
	inc	r2
	inc	r2
; 531 "curve25519.c"
	lda	r0+2
	sta	r0
	stz	r0+2
; 527 "curve25519.c"
	sep	#32
	a8
	inc	r8
	lda	r8
	cmp	#16
	a16
	rep	#32
	bcc	l124
	ldx	r10+2
	lda	r10
; 534 "curve25519.c"
	jml	>_curve25519_reduceQuick
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_sub.0","acrx"
	a16
	x16
	global	_curve25519_sub
_curve25519_sub:
	sta	r12
	stx	r12+2
	lda	4,s
	sta	r10
	lda	6,s
	sta	r10+2
	lda	8,s
	sta	r8
	lda	10,s
	sta	r8+2
; 551 "curve25519.c"
	lda	r12
	sta	r2
	lda	r12+2
	sta	r2+2
; 554 "curve25519.c"
	stz	r4
	stz	r4+2
; 555 "curve25519.c"
	stz	r6
l140:
; 557 "curve25519.c"
	lda	[r10]
	ldx	#0
	inc	r10
	inc	r10
	sta	r31
	lda	[r8]
	sta	r0
	stz	r0+2
	lda	r31
	inc	r8
	inc	r8
	sec
	sbc	r0
	pha
	txa
	sbc	r0+2
	tax
	pla
	sta	r31
	lda	r4+2
	sta	r0
	stz	r0+2
	lda	r0
	and	#1
	sta	r0
	lda	#0
	sta	r0+2
	lda	r31
	sec
	sbc	r0
	sta	r4
	txa
	sbc	r0+2
	sta	r4+2
; 558 "curve25519.c"
	lda	r4
	sta	[r2]
	inc	r2
	inc	r2
; 556 "curve25519.c"
	sep	#32
	a8
	inc	r6
	lda	r6
	cmp	#16
	a16
	rep	#32
	bcc	l140
; 567 "curve25519.c"
	lda	r4+2
	ldx	#0
	and	#19
	sta	r4
	txa
	sta	r4+2
; 568 "curve25519.c"
	lda	[r12]
	sec
	sbc	r4
	sta	r4
	txa
	sbc	r4+2
	sta	r4+2
; 569 "curve25519.c"
	lda	r4
	sta	r31
	lda	r12+2
	sta	r2+2
	lda	r12
	ina
	ina
	sta	r2
	lda	r31
	sta	[r12]
; 570 "curve25519.c"
	lda	#1
	sta	r6
l141:
; 572 "curve25519.c"
	lda	[r2]
	ldx	#0
	sta	r31
	lda	r4+2
	sta	r0
	stz	r0+2
	lda	r0
	and	#1
	sta	r0
	txa
	sta	r0+2
	lda	r31
	sec
	sbc	r0
	sta	r4
	txa
	sbc	r0+2
	sta	r4+2
; 573 "curve25519.c"
	lda	r4
	sta	[r2]
	inc	r2
	inc	r2
; 571 "curve25519.c"
	sep	#32
	a8
	inc	r6
	lda	r6
	cmp	#16
	a16
	rep	#32
	bcc	l141
; 575 "curve25519.c"
	dec	r2
	dec	r2
	lda	[r2]
	and	#32767
	sta	[r2]
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_cswap.0","acrx"
	a16
	x16
	global	_curve25519_cswap
_curve25519_cswap:
	sta	r0
	lda	8,s
	sta	r10
	lda	10,s
	sta	r10+2
	lda	4,s
	sta	r8
	lda	6,s
	sta	r8+2
; 598 "curve25519.c"
	lda	r0
	ldx	#0
	sta	btmp3
	stx	btmp3+2
	sec
	txa
	sbc	btmp3
	pha
	lda	#1
	sbc	btmp3+2
	tax
	pla
	txa
	ldx	#0
	sta	r31
	sta	r6
; 599 "curve25519.c"
	dec	r6
; 603 "curve25519.c"
	stz	r3
l153:
; 605 "curve25519.c"
	lda	r3
	and	#255
	asl
	sta	r31
	lda	r8+2
	sta	r4+2
	lda	r8
	clc
	adc	r31
	sta	r4
	lda	r10+2
	sta	r0+2
	lda	r10
	clc
	adc	r31
	sta	r0
	lda	[r4]
	sta	r2
	lda	[r0]
	eor	r2
	and	r6
; 606 "curve25519.c"
	sta	r31
	eor	r2
	sta	[r4]
	lda	r31
; 607 "curve25519.c"
	eor	[r0]
	sta	[r0]
; 604 "curve25519.c"
	sep	#32
	a8
	inc	r3
	lda	r3
	cmp	#16
	a16
	rep	#32
	bcc	l153
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_cmove.0","acrx"
	a16
	x16
	global	_curve25519_cmove
_curve25519_cmove:
	sta	r0
	lda	8,s
	sta	r10
	lda	10,s
	sta	r10+2
	lda	4,s
	sta	r8
	lda	6,s
	sta	r8+2
; 631 "curve25519.c"
	lda	r0
	ldx	#0
	sta	btmp3
	stx	btmp3+2
	sec
	txa
	sbc	btmp3
	pha
	lda	#1
	sbc	btmp3+2
	tax
	pla
	txa
	ldx	#0
	sta	r31
	sta	r6
; 632 "curve25519.c"
	dec	r6
; 635 "curve25519.c"
	stz	r1
l164:
; 637 "curve25519.c"
	lda	r1
	and	#255
	asl
	sta	r31
	lda	r8+2
	sta	r2+2
	lda	r8
	clc
	adc	r31
	sta	r2
	lda	r10+2
	sta	r4+2
	lda	r10
	clc
	adc	r31
	sta	r4
	lda	[r2]
	sta	r0
	lda	[r4]
	eor	r0
	and	r6
; 638 "curve25519.c"
	eor	r0
	sta	[r2]
; 636 "curve25519.c"
	sep	#32
	a8
	inc	r1
	lda	r1
	cmp	#16
	a16
	rep	#32
	bcc	l164
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_reduce.0","acrx"
	a16
	x16
	global	_curve25519_reduce
_curve25519_reduce:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	pei	(r22)
	pei	(r23)
	pei	(r24)
	pei	(r25)
	sta	r24
	stx	r24+2
	lda	24,s
	sta	r20
	lda	26,s
	sta	r20+2
	lda	28,s
	sta	r17
; 703 "curve25519.c"
	lda	r20+2
	sta	r22+2
	lda	r20
	clc
	adc	#30
	sta	r22
	lda	[r22]
	xba
	and	#255
	lsr
	lsr
	lsr
	lsr
	lsr
	lsr
	lsr
	sta	r0
	ldx	#0
	sta	r31
	lda	#19
	sta	r4
	stz	r4+2
	lda	r31
	sta	r2
	stx	r2+2
; 774 "curve25519.c"
	jsl	>___mulint32
	sta	r18
	stx	r18+2
; 704 "curve25519.c"
	lda	[r22]
	and	#32767
	sta	[r22]
; 705 "curve25519.c"
	stz	r16
; 706 "curve25519.c"
	sep	#32
	a8
	lda	r17
	a16
	rep	#32
	beq	l215
l210:
; 707 "curve25519.c"
	lda	r16
	and	#255
	clc
	adc	#16
	asl
	sta	r31
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	r31
	sta	r0
	lda	[r0]
	ldx	#0
; 708 "curve25519.c"
	pea	#38
	jsl	>_multiply32_16
; 709 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 710 "curve25519.c"
	lda	r16
	and	#255
	asl
	sta	r31
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	r31
	sta	r0
	lda	[r0]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 711 "curve25519.c"
	lda	r18
	sta	[r0]
; 712 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 706 "curve25519.c"
	sep	#32
	a8
	inc	r16
	ply
	lda	r16
	cmp	r17
	a16
	rep	#32
	bcc	l210
l215:
; 714 "curve25519.c"
	sep	#32
	a8
	lda	r17
	cmp	#16
	a16
	rep	#32
	bcs	l216
; 718 "curve25519.c"
	lda	r17
	sta	r16
; 719 "curve25519.c"
	sep	#32
	a8
	lda	r17
	cmp	#16
	a16
	rep	#32
	bcs	l216
l211:
; 720 "curve25519.c"
	lda	r16
	and	#255
	asl
	sta	r31
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	r31
	sta	r0
	lda	[r0]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 721 "curve25519.c"
	lda	r18
	sta	[r0]
; 722 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 719 "curve25519.c"
	sep	#32
	a8
	inc	r16
	lda	r16
	cmp	#16
	a16
	rep	#32
	bcc	l211
l216:
	lda	#38
	sta	r4
	stz	r4+2
	lda	r18
	sta	r2
	lda	r18+2
	sta	r2+2
; 774 "curve25519.c"
	jsl	>___mulint32
	sta	r18
	stx	r18+2
; 731 "curve25519.c"
	lda	[r22]
	xba
	and	#255
	lsr
	lsr
	lsr
	lsr
	lsr
	lsr
	lsr
	sta	r0
	ldx	#0
	sta	r31
	lda	#19
	sta	r4
	stz	r4+2
	lda	r31
	sta	r2
	stx	r2+2
; 774 "curve25519.c"
	jsl	>___mulint32
; 731 "curve25519.c"
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 732 "curve25519.c"
	lda	[r22]
	and	#32767
	sta	[r22]
; 733 "curve25519.c"
	stz	r16
l212:
; 735 "curve25519.c"
	lda	r16
	and	#255
	asl
	sta	r31
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	r31
	sta	r0
	lda	[r0]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 736 "curve25519.c"
	lda	r18
	sta	[r0]
; 737 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 734 "curve25519.c"
	sep	#32
	a8
	inc	r16
	lda	r16
	cmp	#16
	a16
	rep	#32
	bcc	l212
; 745 "curve25519.c"
	lda	#19
	sta	r18
	stz	r18+2
; 746 "curve25519.c"
	stz	r16
l213:
; 748 "curve25519.c"
	lda	r16
	and	#255
	asl
	sta	r31
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	r31
	sta	r0
	lda	[r0]
	ldx	#0
	clc
	adc	r18
	sta	r18
	txa
	adc	r18+2
	sta	r18+2
; 749 "curve25519.c"
	lda	r18
	sta	r31
	lda	r16
	and	#255
	sta	r2
	clc
	adc	#16
	sta	r2
	lda	r31
	asl	r2
	ldy	r2
	sta	[r20],y ;am(r2)
; 750 "curve25519.c"
	lda	r18+2
	sta	r18
	stz	r18+2
; 747 "curve25519.c"
	sep	#32
	a8
	inc	r16
	lda	r16
	cmp	#16
	a16
	rep	#32
	bcc	l213
; 759 "curve25519.c"
	lda	r20+2
	sta	r0+2
	lda	r20
	clc
	adc	#62
	sta	r0
	lda	[r0]
	and	#65280
	xba
	bpl	l221
	clc
	adc	#65280
l221:
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	cmp	#32768
	ror
	sta	r3
; 760 "curve25519.c"
	lda	r3
	eor	#-1
	sta	r4
; 761 "curve25519.c"
	lda	[r0]
	and	#32767
	sta	[r0]
; 762 "curve25519.c"
	stz	r16
l214:
; 764 "curve25519.c"
	lda	r16
	and	#255
	sta	r31
	asl
	sta	r2
	lda	r20+2
	sta	r6+2
	lda	r20
	clc
	adc	r2
	sta	r6
	lda	r4
	and	[r6]
	sta	r0
	lda	r16
	and	#255
	clc
	adc	#16
	asl
	sta	r31
	lda	r20+2
	sta	r6+2
	lda	r20
	clc
	adc	r31
	sta	r6
	lda	r3
	and	[r6]
	ora	r0
	sta	r31
	lda	r24+2
	sta	r0+2
	lda	r24
	clc
	adc	r2
	sta	r0
	lda	r31
	sta	[r0]
; 763 "curve25519.c"
	sep	#32
	a8
	inc	r16
	lda	r16
	cmp	#16
	a16
	rep	#32
	bcc	l214
	plx
	stx	r25
	plx
	stx	r24
	plx
	stx	r23
	plx
	stx	r22
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_pow250.0","acrx"
	a16
	x16
	global	_curve25519_pow250
_curve25519_pow250:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	sta	r28
	tsc
	clc
	adc	#-32
	tcs
	lda	r28
	sta	r20
	stx	r20+2
; 792 "curve25519.c"
	lda	50,s
	pha
	lda	50,s
	pha
	tsc
	clc
	adc	#5
	sta	r18
	stz	r18+2
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
; 793 "curve25519.c"
	stz	r16
	ply
	ply
l256:
; 794 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
	sep	#32
	a8
	inc	r16
	a16
	ply
	ply
	a8
	lda	r16
	cmp	#9
	a16
	rep	#32
	bcc	l256
; 795 "curve25519.c"
	lda	50,s
	pha
	lda	50,s
	pha
	pei	(r18+2)
	pei	(r18)
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_mul
; 796 "curve25519.c"
	stz	r17
	ply
	ply
	ply
	ply
l257:
; 798 "curve25519.c"
	stz	r16
l258:
; 799 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
	sep	#32
	a8
	inc	r16
	a16
	ply
	ply
	a8
	lda	r16
	cmp	#10
	a16
	rep	#32
	bcc	l258
; 800 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r20+2)
	pei	(r20)
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_mul
; 797 "curve25519.c"
	sep	#32
	a8
	inc	r17
	a16
	ply
	ply
	ply
	ply
	a8
	lda	r17
	cmp	#23
	a16
	rep	#32
	bcc	l257
; 805 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
; 806 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r20+2)
	pei	(r20)
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_mul
; 807 "curve25519.c"
	stz	r16
	tsc
	clc
	adc	#12
	tcs
l259:
; 809 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
; 810 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r20+2)
	pei	(r20)
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_mul
; 808 "curve25519.c"
	sep	#32
	a8
	inc	r16
	a16
	tsc
	clc
	rep	#32
	adc	#12
	tcs
	sep	#32
	a8
	lda	r16
	cmp	#8
	a16
	rep	#32
	bcc	l259
	tsc
	clc
	adc	#32
	tcs
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_recip.0","acrx"
	a16
	x16
	global	_curve25519_recip
_curve25519_recip:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	sta	r16
	stx	r16+2
	lda	12,s
	sta	r18
	lda	14,s
	sta	r18+2
; 827 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_pow250
; 830 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 831 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 832 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
; 833 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 834 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 835 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
; 836 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 837 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
	tsc
	clc
	adc	#48
	tcs
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_square.0","acrx"
	a16
	x16
	global	_curve25519_square
_curve25519_square:
	sta	r0
	stx	r0+2
; 842 "curve25519.c"
	lda	6,s
	pha
	lda	6,s
	pha
	lda	10,s
	pha
	lda	10,s
	pha
	ldx	r0+2
	lda	r0
	jsl	>_curve25519_mul
	ply
	ply
	ply
	ply
	rtl
; stacksize=0+??
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_sqrt.0","acrx"
	a16
	x16
	global	_curve25519_sqrt
_curve25519_sqrt:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	sta	r28
	tsc
	clc
	adc	#-32
	tcs
	lda	r28
	sta	r16
	stx	r16+2
	lda	48,s
	sta	r20
	lda	50,s
	sta	r20+2
; 873 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_pow250
; 874 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 875 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
; 876 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 879 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	tsc
	clc
	adc	#25
	sta	r18
	stz	r18+2
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
; 880 "curve25519.c"
	pea	#32
	pei	(r18+2)
	pei	(r18)
	ldx	r20+2
	lda	r20
	jsl	>_memcmp
	sta	r31
	tsc
	clc
	adc	#30
	tcs
	lda	r31
	bne	l272
; 882 "curve25519.c"
	lda	#1
; 883 "curve25519.c"
	bra	l268
; 886 "curve25519.c"
l272:
	pea	#^(l270)
	pea	#<l270
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
; 887 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_square
; 888 "curve25519.c"
	pea	#32
	pei	(r18+2)
	pei	(r18)
	ldx	r20+2
	lda	r20
	jsl	>_memcmp
	sta	r31
	tsc
	clc
	adc	#18
	tcs
	lda	r31
	bne	l274
; 890 "curve25519.c"
	lda	#1
; 891 "curve25519.c"
	bra	l268
; 894 "curve25519.c"
l274:
	lda	#0
; 916 "curve25519.c"
l268:
	tay
	tsc
	clc
	adc	#32
	tcs
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	tya
	rtl
; stacksize=0+??
	section	"DONTMERGE_data.far.numSqrtM1.270","adrw"
l270:
	dw	41136
	dw	18958
	dw	6951
	dw	50414
	dw	58488
	dw	44335
	dw	6150
	dw	12099
	dw	55207
	dw	15867
	dw	153
	dw	11085
	dw	57099
	dw	20417
	dw	9344
	dw	11139
;vcprmin=10000
	section	"DONTMERGE_text.far.curve25519_eval.0","acrx"
	a16
	x16
	global	_curve25519_eval
_curve25519_eval:
	pei	(r16)
	pei	(r17)
	pei	(r18)
	pei	(r19)
	pei	(r20)
	pei	(r21)
	pei	(r22)
	pei	(r23)
	pei	(r24)
	pei	(r25)
	pei	(r26)
	pei	(r27)
	sta	r28
	tsc
	clc
	adc	#-500
	tcs
	lda	r28
	sta	r31
	sta	48,s
	txa
	sta	50,s
; 942 "curve25519.c"
	tsc
	clc
	adc	#532
	sta	btmp3
	stz	btmp3+2
	lda	[btmp3]
	ldy	#2
	ora	[btmp3],y
	beq	l278
; 945 "curve25519.c"
	pea	#32
	tsc
	clc
	adc	#534
	sta	btmp3
	stz	btmp3+2
	ldy	#2
	lda	[btmp3],y
	pha
	lda	[btmp3]
	pha
	pea	#16
	tsc
	clc
	adc	#60
	sta	9,s
	lda	#0
	sta	11,s
	tax
	lda	9,s
	jsl	>_curve25519_unpackLE
; 946 "curve25519.c"
	lda	90,s
	and	#32767
	sta	90,s
; 949 "curve25519.c"
	ply
	ply
	ply
	ply
	bra	l279
l278:
; 950 "curve25519.c"
	pea	#32
	pea	#0
	tsc
	clc
	adc	#56
	sta	5,s
	lda	#0
	sta	7,s
	tax
	lda	5,s
	jsl	>_memset
; 951 "curve25519.c"
	lda	#9
	sta	56,s
; 961 "curve25519.c"
	ply
	ply
l279:
	lda	3,s
	tax
	lda	1,s
	jsl	>_curve25519_reduceQuick
	sep	#32
	a8
	and	#1
	sta	5,s
	a16
	rep	#32
; 964 "curve25519.c"
	pea	#32
	pea	#0
	tsc
	clc
	adc	#88
	sta	r24
	stz	r24+2
	ldx	r24+2
	lda	r24
	jsl	>_memset
; 966 "curve25519.c"
	lda	#1
	sta	88,s
; 967 "curve25519.c"
	pea	#32
	pea	#0
	tsc
	clc
	adc	#124
	sta	r18
	stz	r18+2
	ldx	r18+2
	lda	r18
	jsl	>_memset
; 968 "curve25519.c"
	tsc
	clc
	adc	#156
	sta	r20
	stz	r20+2
	tsc
	clc
	adc	#156
	tay
	tsc
	clc
	adc	#60
	tax
	phb
	lda	#31
	mvn	#0,#0
	plb
; 969 "curve25519.c"
	tsc
	clc
	adc	#188
	sta	r16
	stz	r16+2
	tsc
	clc
	adc	#188
	tay
	tsc
	clc
	adc	#92
	tax
	phb
	lda	#31
	mvn	#0,#0
	plb
; 973 "curve25519.c"
	lda	#64
	sta	r23
; 974 "curve25519.c"
	sep	#32
	a8
	lda	#31
	sta	18,s
	a16
	rep	#32
; 975 "curve25519.c"
	stz	r22
; 976 "curve25519.c"
	sep	#32
	a8
	lda	#255
	sta	19,s
	a16
	rep	#32
; 986 "curve25519.c"
	tsc
	clc
	adc	#220
	sta	20,s
	lda	#0
	sta	22,s
; 987 "curve25519.c"
	tsc
	clc
	adc	#252
	sta	r26
	stz	r26+2
; 988 "curve25519.c"
	tsc
	clc
	adc	#284
	sta	28,s
	lda	#0
	sta	30,s
; 989 "curve25519.c"
	tsc
	clc
	adc	#316
	sta	32,s
	lda	#0
	sta	34,s
; 990 "curve25519.c"
	tsc
	clc
	adc	#348
	sta	36,s
	lda	#0
	sta	38,s
; 991 "curve25519.c"
	tsc
	clc
	adc	#380
	sta	40,s
	lda	#0
	sta	42,s
; 992 "curve25519.c"
	tsc
	clc
	adc	#412
	sta	44,s
	lda	#0
	sta	46,s
; 993 "curve25519.c"
	tsc
	clc
	adc	#444
	sta	48,s
	lda	#0
	sta	50,s
; 994 "curve25519.c"
	tsc
	clc
	adc	#476
	sta	52,s
	lda	#0
	sta	54,s
	lda	r24
	sta	14,s
	lda	r24+2
	sta	16,s
	lda	r26
	sta	24,s
	lda	r26+2
	sta	26,s
	lda	14,s
	sta	r26
	lda	16,s
	sta	r26+2
	lda	18,s
	sta	r25
	ply
	ply
	ply
	ply
l290:
	ldx	#^(l284)
	lda	#<l284
; 978 "curve25519.c"
	jsl	>_printf.1
; 981 "curve25519.c"
	lda	r25
	and	#255
	tax
	tsc
	clc
	adc	#528
	sta	btmp3
	stz	btmp3+2
	txa
	sta	r31
	lda	[btmp3]
	sta	r0
	ldy	#2
	lda	[btmp3],y
	sta	r0+2
	lda	r31
	sep	#32
	a8
	lda	r23
	ldy	r31
	and	[r0],y ;am(r31)
	sta	r24
	a16
	rep	#32
; 982 "curve25519.c"
	sep	#32
	a8
	lda	r22
	eor	r24
	sta	r22
	a16
	rep	#32
; 983 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	pei	(r26+2)
	pei	(r26)
	lda	r22
	and	#255
	sta	r7
	jsl	>_curve25519_cswap
; 984 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	pei	(r18+2)
	pei	(r18)
	lda	r7
	jsl	>_curve25519_cswap
; 986 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r26+2)
	pei	(r26)
	lda	38,s
	tax
	lda	36,s
	jsl	>_curve25519_add
; 987 "curve25519.c"
	lda	38,s
	pha
	lda	38,s
	pha
	lda	46,s
	tax
	lda	44,s
	jsl	>_curve25519_square
; 988 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	pei	(r26+2)
	pei	(r26)
	lda	58,s
	tax
	lda	56,s
	jsl	>_curve25519_sub
; 989 "curve25519.c"
	lda	58,s
	pha
	lda	58,s
	pha
	lda	66,s
	tax
	lda	64,s
	jsl	>_curve25519_square
; 990 "curve25519.c"
	lda	66,s
	pha
	lda	66,s
	pha
	lda	62,s
	pha
	lda	62,s
	pha
	lda	78,s
	tax
	lda	76,s
	jsl	>_curve25519_sub
; 991 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	pei	(r20+2)
	pei	(r20)
	lda	90,s
	tax
	lda	88,s
	jsl	>_curve25519_add
; 992 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	pei	(r20+2)
	pei	(r20)
	lda	102,s
	tax
	lda	100,s
	jsl	>_curve25519_sub
; 993 "curve25519.c"
	lda	78,s
	pha
	lda	78,s
	pha
	lda	106,s
	pha
	lda	106,s
	pha
	lda	114,s
	tax
	lda	112,s
	jsl	>_curve25519_mul
; 994 "curve25519.c"
	lda	94,s
	pha
	lda	94,s
	pha
	lda	110,s
	pha
	lda	110,s
	pha
	lda	126,s
	tax
	lda	124,s
	jsl	>_curve25519_mul
; 995 "curve25519.c"
	lda	126,s
	pha
	lda	126,s
	pha
	lda	126,s
	pha
	lda	126,s
	pha
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_add
; 996 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	ldx	r20+2
	lda	r20
	jsl	>_curve25519_square
; 997 "curve25519.c"
	lda	138,s
	pha
	lda	138,s
	pha
	lda	138,s
	pha
	lda	138,s
	pha
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_sub
; 998 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_square
; 999 "curve25519.c"
	lda	107,s
	pha
	lda	107,s
	pha
	pei	(r16+2)
	pei	(r16)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_mul
; 1000 "curve25519.c"
	lda	138,s
	pha
	lda	138,s
	pha
	lda	134,s
	pha
	lda	134,s
	pha
	ldx	r26+2
	lda	r26
	jsl	>_curve25519_mul
; 1001 "curve25519.c"
	lda	150,s
	pha
	lda	150,s
	pha
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_mulA24
; 1002 "curve25519.c"
	lda	142,s
	pha
	lda	142,s
	pha
	pei	(r18+2)
	pei	(r18)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_add
; 1003 "curve25519.c"
	lda	162,s
	pha
	lda	162,s
	pha
	pei	(r18+2)
	pei	(r18)
	ldx	r18+2
	lda	r18
	jsl	>_curve25519_mul
; 1006 "curve25519.c"
	sep	#32
	a8
	lsr	r23
	a16
	rep	#32
; 1007 "curve25519.c"
	tsc
	clc
	adc	#140
	tcs
	sep	#32
	a8
	lda	r23
	a16
	rep	#32
	bne	l286
; 1009 "curve25519.c"
	sep	#32
	a8
	dec	r25
	a16
	rep	#32
; 1010 "curve25519.c"
	lda	#128
	sta	r23
; 1011 "curve25519.c"
	sep	#32
	a8
	lda	r24
	asl
	asl
	asl
	asl
	asl
	asl
	asl
	sta	r22
	a16
	rep	#32
; 1014 "curve25519.c"
	bra	l287
l286:
; 1015 "curve25519.c"
	sep	#32
	a8
	lda	r24
	lsr
	sta	r22
	a16
	rep	#32
; 1017 "curve25519.c"
l287:
; 977 "curve25519.c"
	sep	#32
	a8
	lda	11,s
	dea
	sta	11,s
	cmp	#0
	a16
	rep	#32
	bne	l290
	lda	r26
	sta	6,s
	lda	r26+2
	sta	8,s
	lda	6,s
	sta	r24
	lda	8,s
	sta	r24+2
; 1020 "curve25519.c"
	pei	(r20+2)
	pei	(r20)
	pei	(r24+2)
	pei	(r24)
	lda	r22
	and	#255
	sta	r7
	jsl	>_curve25519_cswap
; 1021 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	pei	(r18+2)
	pei	(r18)
	lda	r7
	jsl	>_curve25519_cswap
; 1024 "curve25519.c"
	pei	(r18+2)
	pei	(r18)
	ldx	r16+2
	lda	r16
	jsl	>_curve25519_recip
; 1025 "curve25519.c"
	pei	(r16+2)
	pei	(r16)
	pei	(r24+2)
	pei	(r24)
	ldx	r24+2
	lda	r24
	jsl	>_curve25519_mul
; 1028 "curve25519.c"
	pea	#16
	pei	(r24+2)
	pei	(r24)
	pea	#32
	lda	86,s
	tax
	lda	84,s
	jsl	>_curve25519_packLE
; 1030 "curve25519.c"
	lda	41,s
	tay
	tsc
	clc
	adc	#536
	tcs
	plx
	stx	r27
	plx
	stx	r26
	plx
	stx	r25
	plx
	stx	r24
	plx
	stx	r23
	plx
	stx	r22
	plx
	stx	r21
	plx
	stx	r20
	plx
	stx	r19
	plx
	stx	r18
	plx
	stx	r17
	plx
	stx	r16
	tya
	rtl
; stacksize=0+??
	section	"DONTMERGE_data.near..284","adrw"
l284:
	db	46
	db	0
	global	___mulint32
	global	_memcpy
	global	_memcmp
	global	_memset
	global	_multiply32_16
	global	_printf.1
	needs	_vfprintf.1
	zpage	r0
	zpage	r1
	zpage	r2
	zpage	r3
	zpage	r4
	zpage	r5
	zpage	r6
	zpage	r7
	zpage	r8
	zpage	r9
	zpage	r10
	zpage	r11
	zpage	r12
	zpage	r13
	zpage	r14
	zpage	r15
	zpage	r16
	zpage	r17
	zpage	r18
	zpage	r19
	zpage	r20
	zpage	r21
	zpage	r22
	zpage	r23
	zpage	r24
	zpage	r25
	zpage	r26
	zpage	r27
	zpage	r28
	zpage	r29
	zpage	r30
	zpage	r31
	zpage	btmp0
	zpage	btmp1
	zpage	btmp2
	zpage	btmp3
