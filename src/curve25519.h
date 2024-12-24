#ifndef _CURVE26619_H
#define _CURVE26619_H

#include <stdint.h>
#include <stddef.h>
//big number stuff

#define CRYPTO_LITTLE_ENDIAN 1
#define BIGNUMBER_LIMB_16BIT 1
#define NUM_LIMBS_256BIT 16

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

// The number of bits in a limb.
#define LIMB_BITS   (8 * sizeof(limb_t))

void unpackLE(limb_t *limbs, size_t count, const uint8_t *bytes, size_t len);
void packLE(uint8_t *bytes, size_t len, const limb_t *limbs, size_t count);


//end of bignumber stuff

limb_t reduceQuick(limb_t *x);
uint8_t isWeakPoint(const uint8_t k[32]);
void mulNoReduce(limb_t *result, const limb_t *x, const limb_t *y);

#endif
					   
					   