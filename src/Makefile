export PATH := ..\bin\:$(PATH)
CC=WDC816CC
LD=wdclink
CAD=cadius
CFLAGS= -i ../include/ -ML -SF -SI -SP
LIB= ../lib/

all: mydisk.po

clean:
	rm *.obj
	rm *.omf

startup.obj: startup.c
	$(CC) $(CFLAGS) startup.c 

main.obj: main.c 
	$(CC) $(CFLAGS) main.c 

out.omf: startup.obj main.obj text.obj printf.obj chacha20.obj fastscroll.obj
	$(LD) -L $(LIB)  -l cl -X startup.obj main.obj text.obj printf.obj chacha20.obj fastscroll.obj

text.obj: text.c font.h
	$(CC) $(CFLAGS) text.c

printf.obj: printf.c printf.h
	$(CC) $(CFLAGS) printf.c

chacha20.obj: chacha20.c chacha20.h
	$(CC) $(CFLAGS) chacha20.c

blake2s.obj: blake2s.c blake2s.h
	$(CC) $(CFLAGS) blake2s.c	

fastscroll.obj: fastscroll.c fastscroll.h
	$(CC) $(CFLAGS) fastscroll.c		


#shit.obj: shit.c
#	$(CC) $(CFLAGS) shit.c

mydisk.po: out.omf
	$(CAD) deletefile mydisk.po /NEW.DISK/OUT.OMF
	$(CAD) addfile mydisk.po /NEW.DISK/ .\out.omf

emulator: mydisk.po
	emulator.bat
