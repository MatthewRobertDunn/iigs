export PATH := ..\bin\:$(PATH)
CC=WDC816CC
LD=wdclink
CAD=cadius
CFLAGS= -i ../include/ -ML
SAFECFLAGS= -i ../include/ -ML
LIB= ../lib/

all: mydisk.po

clean:
	rm *.obj
	rm *.omf

startup.obj: startup.c
	$(CC) $(CFLAGS) startup.c 

main.obj: test-curve-25519.c 
	$(CC) $(CFLAGS) test-curve-25519.c -o main.obj

out.omf: startup.obj main.obj text.obj printf.obj chacha20.obj fastscroll.obj uECC.obj curve25519.obj
	$(LD) -L $(LIB)  -l cl -X startup.obj main.obj text.obj printf.obj chacha20.obj fastscroll.obj uECC.obj curve25519.obj

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

uECC.obj: uECC.c uECC.h uECC_vli.h types.h platform-specific.inc curve-specific.inc
	$(CC) $(CFLAGS) uECC.c	
	
curve25519.obj: curve25519.c curve25519.h
	$(CC) $(SAFECFLAGS) curve25519.c	


#shit.obj: shit.c
#	$(CC) $(CFLAGS) shit.c

mydisk.po: out.omf
	$(CAD) deletefile mydisk.po /NEW.DISK/OUT.OMF
	$(CAD) addfile mydisk.po /NEW.DISK/ .\out.omf

emulator: mydisk.po
	./emulator.bat
