// mame.exe apple2gs -sl7 cffa2 -hard1 "..\gsplus-win-sdl\System 6 and Free Games.hdv" -flop3 ..\gsplus-win-sdl\mydisk.po
#pragma section code = code
extern volatile void main(void);
#asm
    JMP >%%main; long jump in case not bank 0
#endasm

void foo(void){
    main();
}
