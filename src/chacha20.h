#ifndef _CHACHA20_H_
#define _CHACHA20_H_
#include <STDINT.H>
#define CHACHA_ROUNDS 10
struct chacha20_context
{
	uint32_t state[16];  //Full state of chacha20
	uint8_t stream[64]; //The current 64 blocks of our psuedo random stream.
	unsigned int bytes_remaining; //How many bytes we have remaining out of the above 64
};

void chacha20_block_next(struct chacha20_context *ctx, uint32_t stream[]);

void chacha20_next(struct chacha20_context* ctx);

void chacha20_next_random(struct chacha20_context* ctx, uint8_t output[], uint32_t count);

//Initialize the IETF version of chacha20 for a given 32 byte key and a 12 byte nonce
//Note, the nonce can be public and included with ciphertext
void chacha20_ietf_init(struct chacha20_context *ctx, uint8_t* key, uint8_t* nonce);


//Converts a stream of uint32s to a stream of bytes, outstream should be 64 long
void chacha20_serialize(uint32_t inStream[], uint8_t outStream[]);





#endif