#ifndef _CURVE26619_H
#define _CURVE26619_H

#ifdef MODERN_MODE
#define far
#endif

#include <STDINT.H>
#include <STDDEF.H>
#include <STDBOOL.H>
// big number stuff

#define CRYPTO_LITTLE_ENDIAN 1
#define BIGNUMBER_LIMB_16BIT 1

// Define the limb types to use on this platform.
#if BIGNUMBER_LIMB_8BIT
typedef uint8_t limb_t;
typedef int8_t slimb_t;
typedef uint16_t dlimb_t;
#elif BIGNUMBER_LIMB_16BIT
typedef uint16_t limb_t;
typedef int16_t slimb_t;
typedef uint32_t dlimb_t;
#elif BIGNUMBER_LIMB_32BIT
typedef uint32_t limb_t;
typedef int32_t slimb_t;
typedef uint64_t dlimb_t;
#elif BIGNUMBER_LIMB_64BIT
typedef uint64_t limb_t;
typedef int64_t slimb_t;
typedef unsigned __int128 dlimb_t;
#else
#error "limb_t must be 8, 16, 32, or 64 bits in size"
#endif

// Number of limbs in a big number value of various sizes.
#define NUM_LIMBS_BITS(n) \
    (((n) + sizeof(limb_t) * 8 - 1) / (8 * sizeof(limb_t)))
#define NUM_LIMBS_128BIT NUM_LIMBS_BITS(128)
#define NUM_LIMBS_256BIT NUM_LIMBS_BITS(256)
#define NUM_LIMBS_512BIT NUM_LIMBS_BITS(512)

// The number of bits in a limb.
#define LIMB_BITS (8 * sizeof(limb_t))

#if BIGNUMBER_LIMB_8BIT
#define LIMB(value) ((uint8_t)(value)),         \
                    ((uint8_t)((value) >> 8)),  \
                    ((uint8_t)((value) >> 16)), \
                    ((uint8_t)((value) >> 24))
#define LIMB_PAIR(x, y) LIMB((x)), LIMB((y))
#elif BIGNUMBER_LIMB_16BIT
#define LIMB(value) ((uint16_t)(value)), \
                    ((uint16_t)(((uint32_t)(value)) >> 16))
#define LIMB_PAIR(x, y) LIMB((x)), LIMB((y))
#elif BIGNUMBER_LIMB_32BIT
#define LIMB(value) (value)
#define LIMB_PAIR(x, y) LIMB((x)), LIMB((y))
#elif BIGNUMBER_LIMB_64BIT
#define LIMB(value) (value)
#define LIMB_PAIR(x, y) ((((uint64_t)(y)) << 32) | ((uint64_t)(x)))
#endif

void curve25519_unpackLE(limb_t *limbs, size_t count, const uint8_t *bytes, size_t len);
void curve25519_packLE(uint8_t *bytes, size_t len, const limb_t *limbs, size_t count);
bool curve25519_eval(uint8_t result[32], const uint8_t s[32], const uint8_t x[32]);

// end of bignumber stuff

void curve25519_reduce(limb_t *result, limb_t *x, uint8_t size);
limb_t curve25519_reduceQuick(limb_t *x);
uint8_t curve25519_isWeakPoint(const uint8_t k[32]);
void curve25519_mulNoReduce(limb_t *result, const limb_t *x, const limb_t *y);
void curve25519_mul(limb_t *result, const limb_t *x, const limb_t *y);
void curve25519_mulA24(limb_t *result, const limb_t *x);
void curve25519_add(limb_t *result, const limb_t *x, const limb_t *y);
void curve25519_sub(limb_t *result, const limb_t *x, const limb_t *y);
void curve25519_cswap(limb_t select, limb_t *x, limb_t *y);
void curve25519_cmove(limb_t select, limb_t *x, const limb_t *y);
void curve25519_pow250(limb_t *result, const limb_t *x);
void curve25519_recip(limb_t *result, const limb_t *x);
bool curve25519_sqrt(limb_t *result, const limb_t *x);
void curve25519_square(limb_t *result, const limb_t *x);
#endif
