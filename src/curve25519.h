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

void unpackLE(limb_t *limbs, size_t count, const uint8_t *bytes, size_t len);
void packLE(uint8_t *bytes, size_t len, const limb_t *limbs, size_t count);






					   
					   