// mame.exe apple2gs -sl7 cffa2 -hard1 "..\gsplus-win-sdl\System 6 and Free Games.hdv" -flop3 ..\gsplus-win-sdl\mydisk.po
#pragma section code = mainy
#pragma section data = mainyData
void setPalette(int colorNum, int red, int green, int blue);
#include "printf.h"
#include "text.h"
#include "chacha20.h"
#include <string.h>
#include "maths.h"
uint8_t key[] = "58994083179912377936593775884845";
uint8_t nonce[] = "468133307134";

struct chacha20_context rng_ctx;

static int RNG(uint8_t *dest, unsigned size) {
	chacha20_next_random(&rng_ctx, dest, size);
	return 1;
}
    static uint8_t far alice_private[32] = {
        0x77, 0x07, 0x6d, 0x0a, 0x73, 0x18, 0xa5, 0x7d,
        0x3c, 0x16, 0xc1, 0x72, 0x51, 0xb2, 0x66, 0x45,
        0xdf, 0x4c, 0x2f, 0x87, 0xeb, 0xc0, 0x99, 0x2a,
        0xb1, 0x77, 0xfb, 0xa5, 0x1d, 0xb9, 0x2c, 0x2a
    };
    static uint8_t const alice_public[32] = {
        0x85, 0x20, 0xf0, 0x09, 0x89, 0x30, 0xa7, 0x54,
        0x74, 0x8b, 0x7d, 0xdc, 0xb4, 0x3e, 0xf7, 0x5a,
        0x0d, 0xbf, 0x3a, 0x0d, 0x26, 0x38, 0x1a, 0xf4,
        0xeb, 0xa4, 0xa9, 0x8e, 0xaa, 0x9b, 0x4e, 0x6a
    };
    static uint8_t bob_private[32] = {
        0x5d, 0xab, 0x08, 0x7e, 0x62, 0x4a, 0x8a, 0x4b,
        0x79, 0xe1, 0x7f, 0x8b, 0x83, 0x80, 0x0e, 0xe6,
        0x6f, 0x3b, 0xb1, 0x29, 0x26, 0x18, 0xb6, 0xfd,
        0x1c, 0x2f, 0x8b, 0x27, 0xff, 0x88, 0xe0, 0xeb
    };
    static uint8_t const bob_public[32] = {
        0xde, 0x9e, 0xdb, 0x7d, 0x7b, 0x7d, 0xc1, 0xb4,
        0xd3, 0x5b, 0x61, 0xc2, 0xec, 0xe4, 0x35, 0x37,
        0x3f, 0x83, 0x43, 0xc8, 0x5b, 0x78, 0x67, 0x4d,
        0xad, 0xfc, 0x7e, 0x14, 0x6f, 0x88, 0x2b, 0x4f
    };
    static uint8_t const shared_secret[32] = {
        0x4a, 0x5d, 0x9d, 0x5b, 0xa4, 0xce, 0x2d, 0xe1,
        0x72, 0x8e, 0x3b, 0xf4, 0x80, 0x35, 0x0f, 0x25,
        0xe0, 0x7e, 0x21, 0xc9, 0x47, 0xd1, 0x9e, 0x33,
        0x76, 0xf0, 0x9b, 0x3c, 0x1e, 0x16, 0x17, 0x42
    };

void testEval(void){

    uint8_t result[32];

        // Fix up the private keys by applying the standard masks.
    alice_private[0] &= 0xF8;
    alice_private[31] = (alice_private[31] & 0x7F) | 0x40;
    bob_private[0] &= 0xF8;
    bob_private[31] = (bob_private[31] & 0x7F) | 0x40;

    // Evaluate the curve function and check the public keys.
    printf("Fixed test vectors:\n");
    printf("Computing Alice's public key ... \n");
    curve25519_eval(result, alice_private, NULL);
    if (memcmp(result, alice_public, 32) == 0) {
        printf("ok\n");
    } else {
        printf("failed\n");
    }
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
    uint32_t a = 0xFFFFFFFF;
    uint16_t b = 1234;
    uint32_t result;

	//__TLStartUp();

	// enable super high res mode, maybe
	*newVideo = *newVideo |= 0x80;

	// Enable shadow for super high res mode
	*shadow &= 0xF7;
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
    printf("Create LUT\n");
    init_mul8_table();
    printf("OK");

    result = multiply32_16(a, b);
    printf("Result: %X\n", result);
    result = a * b;
    printf("Result: %X\n", result);
    


	chacha20_ietf_init(&rng_ctx, key, nonce);
	testEval();

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
