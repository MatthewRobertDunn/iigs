 code = chacha
#pragma section data = chachadata
#include "chacha20.h"
uint32_t rotl(uint32_t x, int n)
{
    return (x << n) | (x >> (32 - n));
}

quarter_round(uint32_t x[], int a, int b, int c, int d)
{
    x[a] += x[b];
    x[d] = rotl(x[d] ^ x[a], 16);
    x[c] += x[d];
    x[b] = rotl(x[b] ^ x[c], 12);
    x[a] += x[b];
    x[d] = rotl(x[d] ^ x[a], 8);
    x[c] += x[d];
    x[b] = rotl(x[b] ^ x[c], 7);
}

uint32_t pack4(const uint8_t *a)
{
    uint32_t res = 0;
    res |= (uint32_t)a[0] << 0 * 8;
    res |= (uint32_t)a[1] << 1 * 8;
    res |= (uint32_t)a[2] << 2 * 8;
    res |= (uint32_t)a[3] << 3 * 8;
    return res;
}

void unpack4(uint32_t src, uint8_t *dst)
{
    dst[0] = (src >> 0 * 8) & 0xff;
    dst[1] = (src >> 1 * 8) & 0xff;
    dst[2] = (src >> 2 * 8) & 0xff;
    dst[3] = (src >> 3 * 8) & 0xff;
}

// This function takes a chacha20 context, produces 64 bytes of random stream output
// Then increments the counter by 1 for you.
void chacha20_block_next(struct chacha20_context *ctx, uint32_t stream[])
{
    int i;
    // First we copy the current state to the output stream
    for (i = 0; i < 16; i++)
    {
        stream[i] = ctx->state[i];
    }

    for (i = 0; i < CHACHA_ROUNDS; i += 2)
    {
        // Column-wise rounds
        quarter_round(stream, 0, 4, 8, 12);
        quarter_round(stream, 1, 5, 9, 13);
        quarter_round(stream, 2, 6, 10, 14);
        quarter_round(stream, 3, 7, 11, 15);

        // Diagonal-wise rounds
        quarter_round(stream, 0, 5, 10, 15);
        quarter_round(stream, 1, 6, 11, 12);
        quarter_round(stream, 2, 7, 8, 13);
        quarter_round(stream, 3, 4, 9, 14);
    }

    // Finish by summing state onto output stream
    for (i = 0; i < 16; i++)
    {
        stream[i] += ctx->state[i];
    }
}

bool chacha20_ietf_increment_counter(struct chacha20_context *ctx)
{
    if (ctx->state[12] == 0xFFFFFFFF)
    {
        return false; // max message length
    }

    ctx->state[12] += 1;
    return true;
}

void chacha20_ietf_init(struct chacha20_context *ctx, uint8_t *key, uint8_t *nonce)
{
    // magic string
    const uint8_t *magic_constant = (uint8_t *)"expand 32-byte k";
    ctx->state[0] = pack4(&magic_constant[0 * 4]);
    ctx->state[1] = pack4(&magic_constant[1 * 4]);
    ctx->state[2] = pack4(&magic_constant[2 * 4]);
    ctx->state[3] = pack4(&magic_constant[3 * 4]);

    // key
    ctx->state[4] = pack4(&key[0 * 4]);
    ctx->state[5] = pack4(&key[1 * 4]);
    ctx->state[6] = pack4(&key[2 * 4]);
    ctx->state[7] = pack4(&key[3 * 4]);
    ctx->state[8] = pack4(&key[4 * 4]);
    ctx->state[9] = pack4(&key[5 * 4]);
    ctx->state[10] = pack4(&key[6 * 4]);
    ctx->state[11] = pack4(&key[7 * 4]);

    // counter
    ctx->state[12] = 0;

    // nonce
    ctx->state[13] = pack4(&nonce[0 * 4]);
    ctx->state[14] = pack4(&nonce[1 * 4]);
    ctx->state[15] = pack4(&nonce[2 * 4]);

    // All done
}