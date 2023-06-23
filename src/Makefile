export PATH := ..\bin\:$(PATH)
CC= WDC816CC
LD= wdclink
CAD= cadius
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
	MSYS2_ARG_CONV_EXCL=\* $(CAD) deletefile mydisk.po /NEW.DISK/OUT.OMF
	MSYS2_ARG_CONV_EXCL=\* $(CAD) addfile mydisk.po /NEW.DISK/ \.\\out.omf

emulator: mydisk.po
	emulator.bat
