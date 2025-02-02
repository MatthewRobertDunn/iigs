export PATH := ..\bin\:$(PATH)
CC=vc
LD=vclink
CAD=cadius
CFLAGS=+iigs -O2 -DSCREEN_X=80
LFLAGS=+iigs -O2 -DSCREEN_X=80 -c
LFULL=+iigs -O3 -speed -DSCREEN_X=80 -c
LIB= ../lib/

all: mydisk.po

clean:
	rm -f *.o
	rm -f *.omf

out.omf: hello.c chacha20.o blake2s.o curve25519.o maths.o
	$(CC) $(CFLAGS) native-tests.c chacha20.o blake2s.o curve25519.o maths.o -o out.omf

chacha20.o: chacha20.c chacha20.h
	$(CC) $(LFLAGS) chacha20.c

blake2s.o: blake2s.c blake2s.h
	$(CC) $(LFLAGS) blake2s.c	

curve25519.o: curve25519.c curve25519.h
	$(CC) $(LFLAGS) curve25519.c		

maths.o: maths.c maths.h
	$(CC) $(LFULL) -mhuge maths.c			

native-tests.exe: native-tests.c curve25519.c maths.c
	gcc native-tests.c curve25519.c maths.c -o native-tests.exe

#shit.obj: shit.c
#	$(CC) $(CFLAGS) shit.c

mydisk.po: out.omf
	$(CAD) deletefile mydisk.po /NEW.DISK/OUT.OMF
	$(CAD) addfile mydisk.po /NEW.DISK/ .\out.omf

emulator: mydisk.po
	./emulator.bat
