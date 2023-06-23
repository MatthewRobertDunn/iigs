export PATH := ..\bin\:$(PATH)
CC= WDC816CC
LD= wdclink
CFLAGS= -i ../include/ -ML -SF -SI -SS
LIB= ../lib/

all: mydisk.po

clean:
	rm *.obj
	rm *.omf

startup.obj: startup.c
	$(CC) $(CFLAGS) startup.c 

main.obj: main.c toolbox.h text.h text.obj printf.obj startup.obj
	$(CC) $(CFLAGS) main.c 

out.omf: startup.obj main.obj text.obj printf.obj
	$(LD) -L $(LIB)  -l cl -X startup.obj main.obj text.obj printf.obj

text.obj: text.c font.h
	$(CC) $(CFLAGS) text.c

printf.obj: printf.c printf.h
	$(CC) $(CFLAGS) printf.c

#shit.obj: shit.c
#	$(CC) $(CFLAGS) shit.c

mydisk.po: out.omf
	./cadius.exe deletefile ..\..\..\gsplus-win-sdl\mydisk.po /NEW.DISK/OUT.OMF
	./cadius.exe addfile ..\..\..\gsplus-win-sdl\mydisk.po /NEW.DISK/ ./out.omf

emulator: mydisk.po
	emulator.bat
