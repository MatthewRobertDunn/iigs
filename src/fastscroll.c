static unsigned int far stackPointer = 0;
static unsigned int far directRegister = 0;

void fastScroll() 
{
    #asm
RDMAINRAM equ $E0C002        ; Read from main memory
RDCARDRAM equ $E0C003         ; Read from auxiliary memory
WRMAINRAM equ $E0C004         ; Write to main memory
WRCARDRAM equ $E0C005         ; Write to auxiliary memory
        TSC     ;transfer stack pointer to accumulator
        STA ~~stackPointer     ;store accumulator

        TDC     ;transfer direct register to accumulator
        STA ~~directRegister     ;store accumulator

        SEI     ;Set interrupt disable flag, disabling interrupts


        SEP #$20
        STA >WRCARDRAM          ; Writes to bank $00 go to bank $01
        STA >RDCARDRAM          ; Reads from bank $00 to go bank $01
        REP #$20

        lda #($2000+$FF)       ;start 0XFF bytes from the start of video memory, stack pointer decrements every time.
START:
        tcs                    ;Start stack at top of screen

        clc
        adc #(($08*$A0)-$FF)    ;Start copying from 0x08 rows * 0xA0 bytes per line down.
        tcd

        ;Here we push 128*2 bytes onto the stack, and the stack happens to be 1 row behind us...
        pei $fe
        pei $fc
        pei $fa
        pei $f8
        pei $f6
        pei $f4
        pei $f2
        pei $f0
        pei $ee
        pei $ec
        pei $ea
        pei $e8
        pei $e6
        pei $e4
        pei $e2
        pei $e0
        pei $de
        pei $dc
        pei $da
        pei $d8
        pei $d6
        pei $d4
        pei $d2
        pei $d0
        pei $ce
        pei $cc
        pei $ca
        pei $c8
        pei $c6
        pei $c4
        pei $c2
        pei $c0
        pei $be
        pei $bc
        pei $ba
        pei $b8
        pei $b6
        pei $b4
        pei $b2
        pei $b0
        pei $ae
        pei $ac
        pei $aa
        pei $a8
        pei $a6
        pei $a4
        pei $a2
        pei $a0
        pei $9e
        pei $9c
        pei $9a
        pei $98
        pei $96
        pei $94
        pei $92
        pei $90
        pei $8e
        pei $8c
        pei $8a
        pei $88
        pei $86
        pei $84
        pei $82
        pei $80
        pei $7e
        pei $7c
        pei $7a
        pei $78
        pei $76
        pei $74
        pei $72
        pei $70
        pei $6e
        pei $6c
        pei $6a
        pei $68
        pei $66
        pei $64
        pei $62
        pei $60
        pei $5e
        pei $5c
        pei $5a
        pei $58
        pei $56
        pei $54
        pei $52
        pei $50
        pei $4e
        pei $4c
        pei $4a
        pei $48
        pei $46
        pei $44
        pei $42
        pei $40
        pei $3e
        pei $3c
        pei $3a
        pei $38
        pei $36
        pei $34
        pei $32
        pei $30
        pei $2e
        pei $2c
        pei $2a
        pei $28
        pei $26
        pei $24
        pei $22
        pei $20
        pei $1e
        pei $1c
        pei $1a
        pei $18
        pei $16
        pei $14
        pei $12
        pei $10
        pei $e
        pei $c
        pei $a
        pei $8
        pei $6
        pei $4
        pei $2
        pei $0
        SEC
        SBC #(($08*$A0)-$FF-$FF)   ;Undo our previous addition but move 0xFF bytes ahead

        CMP #($20FF+($FF*120))   ;Repeat until 120 lots of 0xff bytes, which is one whole screen, then exit.
        BEQ END
        BRL START

END        

        ;Clean up all the mess we made so we dont crash

        ;Restore bank 0
        SEP #$20
        STA >RDMAINRAM          ; Read from bank $00
        STA >WRMAINRAM          ; Write to bank $00
        REP #$20


        ;Restore direct register
        LDA ~~directRegister
        TCD
        
        ;Restore stack pointer
        LDA ~~stackPointer
        TCS

        CLI    ;re-enable interrupts
    #endasm
}