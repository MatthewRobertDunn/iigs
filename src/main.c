// mame.exe apple2gs -sl7 cffa2 -hard1 "..\gsplus-win-sdl\System 6 and Free Games.hdv" -flop3 ..\gsplus-win-sdl\mydisk.po
#pragma section code = mainy
#pragma section data = mainyData
void setPalette(int colorNum, int red, int green, int blue);
#include "printf.h"
#include "text.h"
#include "chacha20.h"
#include <string.h>
#include "uECC.h"
char message[] = "Hello there";

uint8_t key[] = "58994083179912377936593775884845";
uint8_t nonce[] = "468133307134";

struct chacha20_context rng_ctx;

static int RNG(uint8_t *dest, unsigned size) {
	chacha20_next_random(&rng_ctx, dest, size);
	return 1;
}

uint8_t private1[32];
uint8_t private2[32];
uint8_t public1[64];
uint8_t public2[64];
uint8_t secret1[32];
uint8_t secret2[32];

void doCurve(void){
  const struct uECC_Curve_t * curve;
  int r;
  printf("Making key 1!\n");
  curve = uECC_secp256k1();
  uECC_make_key(public1, private1, curve);
  printf("Making key 2!\n");
  uECC_make_key(public2, private2, curve);
  printf("getting shared secret\n");
  r = uECC_shared_secret(public2, private1, secret1, curve);
  if(!r){
	printf("secret bad\n");
  }
  printf("All good!\n");
}

void main(void)
{
	int i = 0;
	char ch = 0;
	char *newVideo = (char *)0x00C029;
	char *shadow = (char *)0x00C035;
	char *scanControl = (char *)0x019D00;
	char *video = (char *)0x012000;
	char **testMemory;
	uint8_t randomByte;
	int * foo = 0;
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

	printf("Starting\n");

	//foo = (int*)alloca(8);
	//foo[2] = 123;
	//printf("Hi %d", (long)foo[2]);


	chacha20_ietf_init(&rng_ctx, key, nonce);
	uECC_set_rng(&RNG);
	doCurve();

	
	/*
	chacha20_ietf_init(&ctx, key, nonce);
	for (i = 0; i < 32000; i+=64)
	{
		//video[i] = 0x0F; // alternate green and red
		chacha20_block_next(&ctx, video + i);
	}
	*/

	// do nothing
	printf("Finished");
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
