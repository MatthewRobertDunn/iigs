// mame.exe apple2gs -sl7 cffa2 -hard1 "..\gsplus-win-sdl\System 6 and Free Games.hdv" -flop3 ..\gsplus-win-sdl\mydisk.po
#pragma section code = mainy
#pragma section data = mainyData
void setPalette(int colorNum, int red, int green, int blue);
#include "printf.h"
#include "text.h"
char message[] = "Hello there";
void main(void)
{
	int i = 0;
	char ch = 0;
	char *newVideo = (char *)0x00C029;
	char *shadow = (char *)0x00C035;
	char *scanControl = (char *)0x019D00;
	char *video = (char *)0x012000;
	char **testMemory;
	//__TLStartUp();

	// enable super high res mode, maybe
	*newVideo = *newVideo |= 0x80;

	// Enable shadow for super high res mode
	*shadow &= 0xF7;

	/*
	if (!_TLStartUp())
	{
		while (1)
		{
		}
	}

	if (_MMStartup() == 0)
	{
		while (1)
		{
		}
	}

	if (_multiply(1000, 1000) != 1000000)
	{
		// do nothing
		while (1)
		{
		}
	}


	testMemory = _newHandle(1024l * 1024l * 15l);
	if(testMemory == 0) {
		//do nothing
		while(1){
		}
	} */

	// set all horizontal control lines to 200 pixels wide, default palette, no interrupt.
	for (i = 0; i < 200; i++)
	{
		scanControl[i] = 0;
	}

	for (i = 0; i < 16; i++)
	{
		// set color 0 to be red
		setPalette(i, i, i, i);
	}

	for (i = 0; i < 32000; i++)
	{
		video[i] = 0x0F; // alternate green and red
	}
	printf(message);
	printf("\n");
	printf("Hello there zylanx! %d", (long)1234);
	printf("\n");
	//for(i =0; i< 32000; i++)
	//{
		//printf("%d --Hello there Vuth!!!\n", (long)i);
	//}
	

	// do nothing
	while (1)
	{
	}
}

void setPalette(int colorNum, int red, int green, int blue)
{
	char *palette = (char *)0xe19e00;
	int index = 0;
	index = colorNum * 2;
	palette[index] = ((green & 0xF) << 4) | (blue & 0xF);
	palette[index + 1] = (red & 0xF);
}
