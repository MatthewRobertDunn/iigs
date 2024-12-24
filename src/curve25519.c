#include "curve25519.h"

/**
 * \brief Unpacks the little-endian byte representation of a big number
 * into a limb array.
 *
 * \param limbs The limb array, starting with the least significant word.
 * \param count The number of elements in the \a limbs array.
 * \param bytes The bytes to unpack.
 * \param len The number of bytes to unpack.
 *
 * If \a len is shorter than the length of \a limbs, then the high bytes
 * will be filled with zeroes.  If \a len is longer than the length of
 * \a limbs, then the high bytes will be truncated and lost.
 *
 * \sa packLE(), unpackBE()
 */
void unpackLE(limb_t *limbs, size_t count, const uint8_t *bytes, size_t len)
{
#if BIGNUMBER_LIMB_8BIT
    if (len < count) {
        memcpy(limbs, bytes, len);
        memset(limbs + len, 0, count - len);
    } else {
        memcpy(limbs, bytes, count);
    }
#elif CRYPTO_LITTLE_ENDIAN
    count *= sizeof(limb_t);
    if (len < count) {
        memcpy(limbs, bytes, len);
        memset(((uint8_t *)limbs) + len, 0, count - len);
    } else {
        memcpy(limbs, bytes, count);
    }
#elif BIGNUMBER_LIMB_16BIT
    while (count > 0 && len >= 2) {
        *limbs++ = ((limb_t)(bytes[0])) |
                  (((limb_t)(bytes[1])) << 8);
        bytes += 2;
        --count;
        len -= 2;
    }
    if (count > 0 && len == 1) {
        *limbs++ = ((limb_t)(bytes[0]));
        --count;
    }
    while (count > 0) {
        *limbs++ = 0;
        --count;
    }
#elif BIGNUMBER_LIMB_32BIT
    while (count > 0 && len >= 4) {
        *limbs++ = ((limb_t)(bytes[0])) |
                  (((limb_t)(bytes[1])) <<  8) |
                  (((limb_t)(bytes[2])) << 16) |
                  (((limb_t)(bytes[3])) << 24);
        bytes += 4;
        --count;
        len -= 4;
    }
    if (count > 0 && len > 0) {
        if (len == 3) {
            *limbs++ = ((limb_t)(bytes[0])) |
                      (((limb_t)(bytes[1])) <<  8) |
                      (((limb_t)(bytes[2])) << 16);
        } else if (len == 2) {
            *limbs++ = ((limb_t)(bytes[0])) |
                      (((limb_t)(bytes[1])) <<  8);
        } else {
            *limbs++ = ((limb_t)(bytes[0]));
        }
        --count;
    }
    while (count > 0) {
        *limbs++ = 0;
        --count;
    }
#elif BIGNUMBER_LIMB_64BIT
    while (count > 0 && len >= 8) {
        *limbs++ = ((limb_t)(bytes[0])) |
                  (((limb_t)(bytes[1])) <<  8) |
                  (((limb_t)(bytes[2])) << 16) |
                  (((limb_t)(bytes[3])) << 24) |
                  (((limb_t)(bytes[4])) << 32) |
                  (((limb_t)(bytes[5])) << 40) |
                  (((limb_t)(bytes[6])) << 48) |
                  (((limb_t)(bytes[7])) << 56);
        bytes += 8;
        --count;
        len -= 8;
    }
    if (count > 0 && len > 0) {
        limb_t word = 0;
        uint8_t shift = 0;
        while (len > 0 && shift < 64) {
            word |= (((limb_t)(*bytes++)) << shift);
            shift += 8;
            --len;
        }
        *limbs++ = word;
        --count;
    }
    while (count > 0) {
        *limbs++ = 0;
        --count;
    }
#endif
}

/**
 * \brief Packs the little-endian byte representation of a big number
 * into a byte array.
 *
 * \param bytes The byte array to pack into.
 * \param len The number of bytes in the destination \a bytes array.
 * \param limbs The limb array representing the big number, starting with
 * the least significant word.
 * \param count The number of elements in the \a limbs array.
 *
 * If \a len is shorter than the length of \a limbs, then the number will
 * be truncated to the least significant \a len bytes.  If \a len is longer
 * than the length of \a limbs, then the high bytes will be filled with zeroes.
 *
 * \sa unpackLE(), packBE()
 */
void packLE(uint8_t *bytes, size_t len,
                           const limb_t *limbs, size_t count)
{
#if BIGNUMBER_LIMB_8BIT
    if (len <= count) {
        memcpy(bytes, limbs, len);
    } else {
        memcpy(bytes, limbs, count);
        memset(bytes + count, 0, len - count);
    }
#elif CRYPTO_LITTLE_ENDIAN
    count *= sizeof(limb_t);
    if (len <= count) {
        memcpy(bytes, limbs, len);
    } else {
        memcpy(bytes, limbs, count);
        memset(bytes + count, 0, len - count);
    }
#elif BIGNUMBER_LIMB_16BIT
    limb_t word;
    while (count > 0 && len >= 2) {
        word = *limbs++;
        bytes[0] = (uint8_t)word;
        bytes[1] = (uint8_t)(word >> 8);
        --count;
        len -= 2;
        bytes += 2;
    }
    if (count > 0 && len == 1) {
        bytes[0] = (uint8_t)(*limbs);
        --len;
        ++bytes;
    }
    memset(bytes, 0, len);
#elif BIGNUMBER_LIMB_32BIT
    limb_t word;
    while (count > 0 && len >= 4) {
        word = *limbs++;
        bytes[0] = (uint8_t)word;
        bytes[1] = (uint8_t)(word >> 8);
        bytes[2] = (uint8_t)(word >> 16);
        bytes[3] = (uint8_t)(word >> 24);
        --count;
        len -= 4;
        bytes += 4;
    }
    if (count > 0) {
        if (len == 3) {
            word = *limbs;
            bytes[0] = (uint8_t)word;
            bytes[1] = (uint8_t)(word >> 8);
            bytes[2] = (uint8_t)(word >> 16);
            len -= 3;
            bytes += 3;
        } else if (len == 2) {
            word = *limbs;
            bytes[0] = (uint8_t)word;
            bytes[1] = (uint8_t)(word >> 8);
            len -= 2;
            bytes += 2;
        } else if (len == 1) {
            bytes[0] = (uint8_t)(*limbs);
            --len;
            ++bytes;
        }
    }
    memset(bytes, 0, len);
#elif BIGNUMBER_LIMB_64BIT
    limb_t word;
    while (count > 0 && len >= 8) {
        word = *limbs++;
        bytes[0] = (uint8_t)word;
        bytes[1] = (uint8_t)(word >> 8);
        bytes[2] = (uint8_t)(word >> 16);
        bytes[3] = (uint8_t)(word >> 24);
        bytes[4] = (uint8_t)(word >> 32);
        bytes[5] = (uint8_t)(word >> 40);
        bytes[6] = (uint8_t)(word >> 48);
        bytes[7] = (uint8_t)(word >> 56);
        --count;
        len -= 8;
        bytes += 8;
    }
    if (count > 0) {
        word = *limbs;
        while (len > 0) {
            *bytes++ = (uint8_t)word;
            word >>= 8;
            --len;
        }
    }
    memset(bytes, 0, len);
#endif
}

/**
 * \brief Quickly reduces a number modulo 2^255 - 19.
 *
 * \param x The number to be reduced, which must be NUM_LIMBS_256BIT
 * limbs in size and less than or equal to 2 * (2^255 - 19 - 1).
 * \return Zero if \a x was greater than or equal to (2^255 - 19).
 *
 * The answer is also put into \a x and will consist of NUM_LIMBS_256BIT limbs.
 *
 * This function is intended for reducing the result of additions where
 * the caller knows that \a x is within the described range.  A single
 * trial subtraction is all that is needed to reduce the number.
 */
limb_t reduceQuick(limb_t *x)
{
    limb_t temp[NUM_LIMBS_256BIT];
    dlimb_t carry;
    uint8_t posn;
    limb_t *xx;
    limb_t *tt;
	limb_t mask, nmask;
    
    // Perform a trial subtraction of (2^255 - 19) from "x" which is
    // equivalent to adding 19 and subtracting 2^255.  We add 19 here;
    // the subtraction of 2^255 occurs in the next step.
    carry = 19U;
    xx = x;
    tt = temp;
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn) {
        carry += *xx++;
        *tt++ = (limb_t)carry;
        carry >>= LIMB_BITS;
    }

    // If there was a borrow, then the original "x" is the correct answer.
    // If there was no borrow, then "temp" is the correct answer.  Select the
    // correct answer but do it in a way that instruction timing will not
    // reveal which value was selected.  Borrow will occur if the high bit
    // of "temp" is 0: turn the high bit into a selection mask.
    mask = (limb_t)(((slimb_t)(temp[NUM_LIMBS_256BIT - 1])) >> (LIMB_BITS - 1));
    nmask = ~mask;
    temp[NUM_LIMBS_256BIT - 1] &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
    xx = x;
    tt = temp;
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn) {
        *xx = ((*xx) & nmask) | ((*tt++) & mask);
        ++xx;
    }

    // Return a zero value if we actually subtracted (2^255 - 19) from "x".
    return nmask;
}

/**
 * \brief Determines if a Curve25519 point is weak for contributory behaviour.
 *
 * \param k The point to check.
 * \return Returns 1 if \a k is weak for contributory behavior or
 * returns zero if \a k is not weak.
 */
uint8_t isWeakPoint(const uint8_t k[32])
{
	
    // List of weak points from http://cr.yp.to/ecdh.html
    // That page lists some others but they are variants on these
    // of the form "point + i * (2^255 - 19)" for i = 0, 1, 2.
    // Here we mask off the high bit and eval() catches the rest.
    const uint8_t points[5][32] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0xE0, 0xEB, 0x7A, 0x7C, 0x3B, 0x41, 0xB8, 0xAE,
         0x16, 0x56, 0xE3, 0xFA, 0xF1, 0x9F, 0xC4, 0x6A,
         0xDA, 0x09, 0x8D, 0xEB, 0x9C, 0x32, 0xB1, 0xFD,
         0x86, 0x62, 0x05, 0x16, 0x5F, 0x49, 0xB8, 0x00},
        {0x5F, 0x9C, 0x95, 0xBC, 0xA3, 0x50, 0x8C, 0x24,
         0xB1, 0xD0, 0xB1, 0x55, 0x9C, 0x83, 0xEF, 0x5B,
         0x04, 0x44, 0x5C, 0xC4, 0x58, 0x1C, 0x8E, 0x86,
         0xD8, 0x22, 0x4E, 0xDD, 0xD0, 0x9F, 0x11, 0x57},
        {0xEC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}
    };

    // Check each of the weak points in turn.  We perform the
    // comparisons carefully so as not to reveal the value of "k"
    // in the instruction timing.  If "k" is indeed weak then
    // we still check everything so as not to reveal which
    // weak point it is.
    uint8_t result = 0;
	uint8_t posn;
    for (posn = 0; posn < 5; ++posn) {
        const uint8_t *point = points[posn];
        uint8_t check = (pgm_read_byte(&(point[31])) ^ k[31]) & 0x7F;
        uint8_t index;
		for (index = 31; index > 0; --index)
            check |= (pgm_read_byte(&(point[index - 1])) ^ k[index - 1]);
        result |= (uint8_t)((((uint16_t)0x0100) - check) >> 8);
    }

    // The "result" variable will be non-zero if there was a match.
    return result;
}

void mulNoReduce(limb_t *result, const limb_t *x, const limb_t *y)
{
    uint8_t i, j;
    dlimb_t carry;
    limb_t word;
    const limb_t *yy;
    limb_t *rr;

    // Multiply the lowest word of x by y.
    carry = 0;
    word = x[0];
    yy = y;
    rr = result;
    for (i = 0; i < NUM_LIMBS_256BIT; ++i) {
        carry += ((dlimb_t)(*yy++)) * word;
        *rr++ = (limb_t)carry;
        carry >>= LIMB_BITS;
    }
    *rr = (limb_t)carry;

    // Multiply and add the remaining words of x by y.
    for (i = 1; i < NUM_LIMBS_256BIT; ++i) {
        word = x[i];
        carry = 0;
        yy = y;
        rr = result + i;
        for (j = 0; j < NUM_LIMBS_256BIT; ++j) {
            carry += ((dlimb_t)(*yy++)) * word;
            carry += *rr;
            *rr++ = (limb_t)carry;
            carry >>= LIMB_BITS;
        }
        *rr = (limb_t)carry;
    }
}