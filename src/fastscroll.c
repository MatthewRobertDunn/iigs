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

        LDA #($2000+$FF)       ;start 0XFF bytes from the start of video memory, stack pointer decrements every time.
START:
        TCS                    ;Start stack at top of screen

        CLC
        ADC #(($08*$A0)-$FF)    ;Start copying from 0x08 rows * 0xA0 bytes per line down.
        TCD

        ;Here we push 128*2 bytes onto the stack, and the stack happens to be 1 row behind us...
        PEI $fe
        PEI $fc
        PEI $fa
        PEI $f8
        PEI $f6
        PEI $f4
        PEI $f2
        PEI $f0
        PEI $ee
        PEI $ec
        PEI $ea
        PEI $e8
        PEI $e6
        PEI $e4
        PEI $e2
        PEI $e0
        PEI $de
        PEI $dc
        PEI $da
        PEI $d8
        PEI $d6
        PEI $d4
        PEI $d2
        PEI $d0
        PEI $ce
        PEI $cc
        PEI $ca
        PEI $c8
        PEI $c6
        PEI $c4
        PEI $c2
        PEI $c0
        PEI $be
        PEI $bc
        PEI $ba
        PEI $b8
        PEI $b6
        PEI $b4
        PEI $b2
        PEI $b0
        PEI $ae
        PEI $ac
        PEI $aa
        PEI $a8
        PEI $a6
        PEI $a4
        PEI $a2
        PEI $a0
        PEI $9e
        PEI $9c
        PEI $9a
        PEI $98
        PEI $96
        PEI $94
        PEI $92
        PEI $90
        PEI $8e
        PEI $8c
        PEI $8a
        PEI $88
        PEI $86
        PEI $84
        PEI $82
        PEI $80
        PEI $7e
        PEI $7c
        PEI $7a
        PEI $78
        PEI $76
        PEI $74
        PEI $72
        PEI $70
        PEI $6e
        PEI $6c
        PEI $6a
        PEI $68
        PEI $66
        PEI $64
        PEI $62
        PEI $60
        PEI $5e
        PEI $5c
        PEI $5a
        PEI $58
        PEI $56
        PEI $54
        PEI $52
        PEI $50
        PEI $4e
        PEI $4c
        PEI $4a
        PEI $48
        PEI $46
        PEI $44
        PEI $42
        PEI $40
        PEI $3e
        PEI $3c
        PEI $3a
        PEI $38
        PEI $36
        PEI $34
        PEI $32
        PEI $30
        PEI $2e
        PEI $2c
        PEI $2a
        PEI $28
        PEI $26
        PEI $24
        PEI $22
        PEI $20
        PEI $1e
        PEI $1c
        PEI $1a
        PEI $18
        PEI $16
        PEI $14
        PEI $12
        PEI $10
        PEI $e
        PEI $c
        PEI $a
        PEI $8
        PEI $6
        PEI $4
        PEI $2
        PEI $0
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