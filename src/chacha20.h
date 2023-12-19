typedef unsigned long int uint32_t;
typedef int bool;
typedef unsigned char uint8_t;
#define false 0
#define true  1
#define CHACHA_ROUNDS 20

struct chacha20_context
{
	uint32_t state[16];
};

void chacha20_block_next(struct chacha20_context *ctx, uint32_t stream[]);

bool chacha20_ietf_increment_counter(struct chacha20_context *ctx);


//Initialize the IETF version of chacha20 for a given 32 byte key and a 12 byte nonce
//Note, the nonce can be public and included with ciphertext
void chacha20_ietf_init(struct chacha20_context *ctx, uint8_t* key, uint8_t* nonce);