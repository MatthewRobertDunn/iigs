#ifndef MODERN_MODE
#pragma section code = curve
#pragma section data = curvedata
#else
#define far
#endif
#include <STRING.H>
#include "curve25519.h"
#include "printf.h"
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
void curve25519_unpackLE(limb_t *limbs, size_t count, const uint8_t *bytes, size_t len)
{
#if BIGNUMBER_LIMB_8BIT
    if (len < count)
    {
        memcpy(limbs, bytes, len);
        memset(limbs + len, 0, count - len);
    }
    else
    {
        memcpy(limbs, bytes, count);
    }
#elif CRYPTO_LITTLE_ENDIAN
    count *= sizeof(limb_t);
    if (len < count)
    {
        memcpy(limbs, bytes, len);
        memset(((uint8_t *)limbs) + len, 0, count - len);
    }
    else
    {
        memcpy(limbs, bytes, count);
    }
#elif BIGNUMBER_LIMB_16BIT
    while (count > 0 && len >= 2)
    {
        *limbs++ = ((limb_t)(bytes[0])) |
                   (((limb_t)(bytes[1])) << 8);
        bytes += 2;
        --count;
        len -= 2;
    }
    if (count > 0 && len == 1)
    {
        *limbs++ = ((limb_t)(bytes[0]));
        --count;
    }
    while (count > 0)
    {
        *limbs++ = 0;
        --count;
    }
#elif BIGNUMBER_LIMB_32BIT
    while (count > 0 && len >= 4)
    {
        *limbs++ = ((limb_t)(bytes[0])) |
                   (((limb_t)(bytes[1])) << 8) |
                   (((limb_t)(bytes[2])) << 16) |
                   (((limb_t)(bytes[3])) << 24);
        bytes += 4;
        --count;
        len -= 4;
    }
    if (count > 0 && len > 0)
    {
        if (len == 3)
        {
            *limbs++ = ((limb_t)(bytes[0])) |
                       (((limb_t)(bytes[1])) << 8) |
                       (((limb_t)(bytes[2])) << 16);
        }
        else if (len == 2)
        {
            *limbs++ = ((limb_t)(bytes[0])) |
                       (((limb_t)(bytes[1])) << 8);
        }
        else
        {
            *limbs++ = ((limb_t)(bytes[0]));
        }
        --count;
    }
    while (count > 0)
    {
        *limbs++ = 0;
        --count;
    }
#elif BIGNUMBER_LIMB_64BIT
    while (count > 0 && len >= 8)
    {
        *limbs++ = ((limb_t)(bytes[0])) |
                   (((limb_t)(bytes[1])) << 8) |
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
    if (count > 0 && len > 0)
    {
        limb_t word = 0;
        uint8_t shift = 0;
        while (len > 0 && shift < 64)
        {
            word |= (((limb_t)(*bytes++)) << shift);
            shift += 8;
            --len;
        }
        *limbs++ = word;
        --count;
    }
    while (count > 0)
    {
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
void curve25519_packLE(uint8_t *bytes, size_t len,
                       const limb_t *limbs, size_t count)
{
#if BIGNUMBER_LIMB_8BIT
    if (len <= count)
    {
        memcpy(bytes, limbs, len);
    }
    else
    {
        memcpy(bytes, limbs, count);
        memset(bytes + count, 0, len - count);
    }
#elif CRYPTO_LITTLE_ENDIAN
    count *= sizeof(limb_t);
    if (len <= count)
    {
        memcpy(bytes, limbs, len);
    }
    else
    {
        memcpy(bytes, limbs, count);
        memset(bytes + count, 0, len - count);
    }
#elif BIGNUMBER_LIMB_16BIT
    limb_t word;
    while (count > 0 && len >= 2)
    {
        word = *limbs++;
        bytes[0] = (uint8_t)word;
        bytes[1] = (uint8_t)(word >> 8);
        --count;
        len -= 2;
        bytes += 2;
    }
    if (count > 0 && len == 1)
    {
        bytes[0] = (uint8_t)(*limbs);
        --len;
        ++bytes;
    }
    memset(bytes, 0, len);
#elif BIGNUMBER_LIMB_32BIT
    limb_t word;
    while (count > 0 && len >= 4)
    {
        word = *limbs++;
        bytes[0] = (uint8_t)word;
        bytes[1] = (uint8_t)(word >> 8);
        bytes[2] = (uint8_t)(word >> 16);
        bytes[3] = (uint8_t)(word >> 24);
        --count;
        len -= 4;
        bytes += 4;
    }
    if (count > 0)
    {
        if (len == 3)
        {
            word = *limbs;
            bytes[0] = (uint8_t)word;
            bytes[1] = (uint8_t)(word >> 8);
            bytes[2] = (uint8_t)(word >> 16);
            len -= 3;
            bytes += 3;
        }
        else if (len == 2)
        {
            word = *limbs;
            bytes[0] = (uint8_t)word;
            bytes[1] = (uint8_t)(word >> 8);
            len -= 2;
            bytes += 2;
        }
        else if (len == 1)
        {
            bytes[0] = (uint8_t)(*limbs);
            --len;
            ++bytes;
        }
    }
    memset(bytes, 0, len);
#elif BIGNUMBER_LIMB_64BIT
    limb_t word;
    while (count > 0 && len >= 8)
    {
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
    if (count > 0)
    {
        word = *limbs;
        while (len > 0)
        {
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
limb_t curve25519_reduceQuick(limb_t *x)
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
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
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
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
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
uint8_t curve25519_isWeakPoint(const uint8_t k[32])
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
         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}};

    // Check each of the weak points in turn.  We perform the
    // comparisons carefully so as not to reveal the value of "k"
    // in the instruction timing.  If "k" is indeed weak then
    // we still check everything so as not to reveal which
    // weak point it is.
    uint8_t result = 0;
    uint8_t posn;
    for (posn = 0; posn < 5; ++posn)
    {
        const uint8_t *point = points[posn];
        uint8_t check = (point[31] ^ k[31]) & 0x7F;
        uint8_t index;
        for (index = 31; index > 0; --index)
            check |= (point[index - 1] ^ k[index - 1]);
        result |= (uint8_t)((((uint16_t)0x0100) - check) >> 8);
    }

    // The "result" variable will be non-zero if there was a match.
    return result;
}

void curve25519_mulNoReduce(limb_t *result, const limb_t *x, const limb_t *y)
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
    for (i = 0; i < NUM_LIMBS_256BIT; ++i)
    {
        carry += ((dlimb_t)(*yy++)) * word;
        *rr++ = (limb_t)carry;
        carry >>= LIMB_BITS;
    }
    *rr = (limb_t)carry;

    // Multiply and add the remaining words of x by y.
    for (i = 1; i < NUM_LIMBS_256BIT; ++i)
    {
        word = x[i];
        carry = 0;
        yy = y;
        rr = result + i;
        for (j = 0; j < NUM_LIMBS_256BIT; ++j)
        {
            carry += ((dlimb_t)(*yy++)) * word;
            carry += *rr;
            *rr++ = (limb_t)carry;
            carry >>= LIMB_BITS;
        }
        *rr = (limb_t)carry;
    }
}

/**
 * \brief Multiplies two values and then reduces the result modulo 2^255 - 19.
 *
 * \param result The result, which must be NUM_LIMBS_256BIT limbs in size
 * and can be the same array as \a x or \a y.
 * \param x The first value to multiply, which must be NUM_LIMBS_256BIT limbs
 * in size and less than 2^255 - 19.
 * \param y The second value to multiply, which must be NUM_LIMBS_256BIT limbs
 * in size and less than 2^255 - 19.  This can be the same array as \a x.
 */
void curve25519_mul(limb_t *result, const limb_t *x, const limb_t *y)
{
    limb_t temp[NUM_LIMBS_512BIT];
    curve25519_mulNoReduce(temp, x, y);
    curve25519_reduce(result, temp, NUM_LIMBS_256BIT);
}

/**
 * \brief Multiplies a value by the constant 121665 and reduces the result modulo 2^255 - 19.
 *
 * \param result The result array, which must be NUM_LIMBS_256BIT limbs in size
 * and can be the same array as \a x.
 * \param x The value to multiply, which must be NUM_LIMBS_256BIT limbs in size
 * and less than 2^255 - 19.
 *
 * The function multiplies the input \a x by the constant a24 = 121665, represented
 * as a limb array, and then reduces the result modulo 2^255 - 19. The multiplication
 * is performed using a big-number multiplication algorithm, and the intermediate
 * result is reduced to ensure it is in the valid range for curve25519 operations.
 */

void curve25519_mulA24(limb_t *result, const limb_t *x)
{
    // The constant a24 = 121665 (0x1DB41) as a limb array.
#if BIGNUMBER_LIMB_8BIT
    static limb_t const a24[3] = {0x41, 0xDB, 0x01};
#elif BIGNUMBER_LIMB_16BIT
    static limb_t const a24[2] = {0xDB41, 0x0001};
#elif BIGNUMBER_LIMB_32BIT || BIGNUMBER_LIMB_64BIT
    static limb_t const a24[1] = {0x0001DB41};
#else
#error "limb_t must be 8, 16, 32, or 64 bits in size"
#endif
#define NUM_A24_LIMBS (sizeof(a24) / sizeof(limb_t))

    // Multiply the lowest limb of a24 by x and zero-extend into the result.
    limb_t temp[NUM_LIMBS_512BIT];
    uint8_t i, j;
    dlimb_t carry = 0;
    limb_t word = a24[0];
    const limb_t *xx = x;
    limb_t *tt = temp;
    for (i = 0; i < NUM_LIMBS_256BIT; ++i)
    {
        carry += ((dlimb_t)(*xx++)) * word;
        *tt++ = (limb_t)carry;
        carry >>= LIMB_BITS;
    }
    *tt = (limb_t)carry;

    // Multiply and add the remaining limbs of a24.
    for (i = 1; i < NUM_A24_LIMBS; ++i)
    {
        word = a24[i];
        carry = 0;
        xx = x;
        tt = temp + i;
        for (j = 0; j < NUM_LIMBS_256BIT; ++j)
        {
            carry += ((dlimb_t)(*xx++)) * word;
            carry += *tt;
            *tt++ = (limb_t)carry;
            carry >>= LIMB_BITS;
        }
        *tt = (limb_t)carry;
    }

    // Reduce the intermediate result modulo 2^255 - 19.
    curve25519_reduce(result, temp, NUM_A24_LIMBS);
}

/**
 * \brief Adds two values and then reduces the result modulo 2^255 - 19.
 *
 * \param result The result, which must be NUM_LIMBS_256BIT limbs in size
 * and can be the same array as \a x or \a y.
 * \param x The first value to multiply, which must be NUM_LIMBS_256BIT
 * limbs in size and less than 2^255 - 19.
 * \param y The second value to multiply, which must be NUM_LIMBS_256BIT
 * limbs in size and less than 2^255 - 19.
 */
void curve25519_add(limb_t *result, const limb_t *x, const limb_t *y)
{
    dlimb_t carry = 0;
    uint8_t posn;
    limb_t *rr = result;

    // Add the two arrays to obtain the intermediate result.
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        carry += *x++;
        carry += *y++;
        *rr++ = (limb_t)carry;
        carry >>= LIMB_BITS;
    }
    // Reduce the result using the quick trial subtraction method.
    curve25519_reduceQuick(result);
}

/**
 * \brief Subtracts two values and then reduces the result modulo 2^255 - 19.
 *
 * \param result The result, which must be NUM_LIMBS_256BIT limbs in size
 * and can be the same array as \a x or \a y.
 * \param x The first value to multiply, which must be NUM_LIMBS_256BIT
 * limbs in size and less than 2^255 - 19.
 * \param y The second value to multiply, which must be NUM_LIMBS_256BIT
 * limbs in size and less than 2^255 - 19.
 */
void curve25519_sub(limb_t *result, const limb_t *x, const limb_t *y)
{
    dlimb_t borrow;
    uint8_t posn;
    limb_t *rr = result;

    // Subtract y from x to generate the intermediate result.
    borrow = 0;
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        borrow = ((dlimb_t)(*x++)) - (*y++) - ((borrow >> LIMB_BITS) & 0x01);
        *rr++ = (limb_t)borrow;
    }

    // If we had a borrow, then the result has gone negative and we
    // have to add 2^255 - 19 to the result to make it positive again.
    // The top bits of "borrow" will be all 1's if there is a borrow
    // or it will be all 0's if there was no borrow.  Easiest is to
    // conditionally subtract 19 and then mask off the high bit.
    rr = result;
    borrow = (borrow >> LIMB_BITS) & 19U;
    borrow = ((dlimb_t)(*rr)) - borrow;
    *rr++ = (limb_t)borrow;
    for (posn = 1; posn < NUM_LIMBS_256BIT; ++posn)
    {
        borrow = ((dlimb_t)(*rr)) - ((borrow >> LIMB_BITS) & 0x01);
        *rr++ = (limb_t)borrow;
    }
    *(--rr) &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
}

/**
 * \brief Conditionally swaps two values if a selection value is non-zero.
 *
 * \param select Non-zero to swap \a x and \a y, zero to leave them unchanged.
 * \param x The first value to conditionally swap.
 * \param y The second value to conditionally swap.
 *
 * The swap is performed in a way that it should take the same amount of
 * time irrespective of the value of \a select.
 *
 * \sa cmove()
 */
void curve25519_cswap(limb_t select, limb_t *x, limb_t *y)
{
    uint8_t posn;
    limb_t dummy;
    limb_t sel;

    // Turn "select" into an all-zeroes or all-ones mask.  We don't care
    // which bit or bits is set in the original "select" value.
    sel = (limb_t)(((((dlimb_t)1) << LIMB_BITS) - select) >> LIMB_BITS);
    --sel;

    // Swap the two values based on "select".  Algorithm from:
    // http://tools.ietf.org/html/rfc7748
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        dummy = sel & (x[posn] ^ y[posn]);
        x[posn] ^= dummy;
        y[posn] ^= dummy;
    }
}

/**
 * \brief Conditionally moves \a y into \a x if a selection value is non-zero.
 *
 * \param select Non-zero to move \a y into \a x, zero to leave \a x unchanged.
 * \param x The destination to move into.
 * \param y The value to conditionally move.
 *
 * The move is performed in a way that it should take the same amount of
 * time irrespective of the value of \a select.
 *
 * \sa cswap()
 */
void curve25519_cmove(limb_t select, limb_t *x, const limb_t *y)
{
    uint8_t posn;
    limb_t dummy;
    limb_t sel;

    // Turn "select" into an all-zeroes or all-ones mask.  We don't care
    // which bit or bits is set in the original "select" value.
    sel = (limb_t)(((((dlimb_t)1) << LIMB_BITS) - select) >> LIMB_BITS);
    --sel;

    // Move y into x based on "select".  Similar to conditional swap above.
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        dummy = sel & (x[posn] ^ y[posn]);
        x[posn] ^= dummy;
    }
}

/**
 * \brief Reduces a number modulo 2^255 - 19.
 *
 * \param result The array that will contain the result when the
 * function exits.  Must be NUM_LIMBS_256BIT limbs in size.
 * \param x The number to be reduced, which must be NUM_LIMBS_512BIT
 * limbs in size and less than or equal to square(2^255 - 19 - 1).
 * This array will be modified by the reduction process.
 * \param size The size of the high order half of \a x.  This indicates
 * the size of \a x in limbs.  If it is shorter than NUM_LIMBS_256BIT
 * then the reduction can be performed quicker.
 */
void curve25519_reduce(limb_t far *result, limb_t far *x, uint8_t size)
{
    /*
    Note: This explaination is best viewed with a UTF-8 text viewer.

    To help explain what this function is doing, the following describes
    how to efficiently compute reductions modulo a base of the form (2ⁿ - b)
    where b is greater than zero and (b + 1)² <= 2ⁿ.

    Here we are interested in reducing the result of multiplying two
    numbers that are less than or equal to (2ⁿ - b - 1).  That is,
    multiplying numbers that have already been reduced.

    Given some x less than or equal to (2ⁿ - b - 1)², we want to find a
    y less than (2ⁿ - b) such that:

        y ≡ x mod (2ⁿ - b)

    We know that for all integer values of k >= 0:

        y ≡ x - k * (2ⁿ - b)
          ≡ x - k * 2ⁿ + k * b

    In our case we choose k = ⌊x / 2ⁿ⌋ and then let:

        w = (x mod 2ⁿ) + ⌊x / 2ⁿ⌋ * b

    The value w will either be the answer y or y can be obtained by
    repeatedly subtracting (2ⁿ - b) from w until it is less than (2ⁿ - b).
    At most b subtractions will be required.

    In our case b is 19 which is more subtractions than we would like to do,
    but we can handle that by performing the above reduction twice and then
    performing a single trial subtraction:

        w = (x mod 2ⁿ) + ⌊x / 2ⁿ⌋ * b
        y = (w mod 2ⁿ) + ⌊w / 2ⁿ⌋ * b
        if y >= (2ⁿ - b)
            y -= (2ⁿ - b)

    The value y is the answer we want for reducing x modulo (2ⁿ - b).
    */
    dlimb_t carry;
    uint8_t posn;
    limb_t mask, nmask;

    // Calculate (x mod 2^255) + ((x / 2^255) * 19) which will
    // either produce the answer we want or it will produce a
    // value of the form "answer + j * (2^255 - 19)".
    carry = ((dlimb_t)(x[NUM_LIMBS_256BIT - 1] >> (LIMB_BITS - 1))) * 19U;
    x[NUM_LIMBS_256BIT - 1] &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
    for (posn = 0; posn < size; ++posn)
    {
        carry += ((dlimb_t)(x[posn + NUM_LIMBS_256BIT])) * 38U;
        carry += x[posn];
        x[posn] = (limb_t)carry;
        carry >>= LIMB_BITS;
    }
    if (size < NUM_LIMBS_256BIT)
    {
        // The high order half of the number is short; e.g. for mulA24().
        // Propagate the carry through the rest of the low order part.
        for (posn = size; posn < NUM_LIMBS_256BIT; ++posn)
        {
            carry += x[posn];
            x[posn] = (limb_t)carry;
            carry >>= LIMB_BITS;
        }
    }

    // The "j" value may still be too large due to the final carry-out.
    // We must repeat the reduction.  If we already have the answer,
    // then this won't do any harm but we must still do the calculation
    // to preserve the overall timing.
    carry *= 38U;
    carry += ((dlimb_t)(x[NUM_LIMBS_256BIT - 1] >> (LIMB_BITS - 1))) * 19U;
    x[NUM_LIMBS_256BIT - 1] &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        carry += x[posn];
        x[posn] = (limb_t)carry;
        carry >>= LIMB_BITS;
    }

    // At this point "x" will either be the answer or it will be the
    // answer plus (2^255 - 19).  Perform a trial subtraction which
    // is equivalent to adding 19 and subtracting 2^255.  We put the
    // trial answer into the top-most limbs of the original "x" array.
    // We add 19 here; the subtraction of 2^255 occurs in the next step.
    carry = 19U;
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        carry += x[posn];
        x[posn + NUM_LIMBS_256BIT] = (limb_t)carry;
        carry >>= LIMB_BITS;
    }

    // If there was a borrow, then the bottom-most limbs of "x" are the
    // correct answer.  If there was no borrow, then the top-most limbs
    // of "x" are the correct answer.  Select the correct answer but do
    // it in a way that instruction timing will not reveal which value
    // was selected.  Borrow will occur if the high bit of the previous
    // result is 0: turn the high bit into a selection mask.
    mask = (limb_t)(((slimb_t)(x[NUM_LIMBS_512BIT - 1])) >> (LIMB_BITS - 1));
    nmask = ~mask;
    x[NUM_LIMBS_512BIT - 1] &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
    for (posn = 0; posn < NUM_LIMBS_256BIT; ++posn)
    {
        result[posn] = (x[posn] & nmask) | (x[posn + NUM_LIMBS_256BIT] & mask);
    }
}

/**
 * \brief Raise x to the power of (2^250 - 1).
 *
 * \param result The result array, which must be NUM_LIMBS_256BIT limbs in size.
 * \param x The value to raise.
 */
void curve25519_pow250(limb_t *result, const limb_t *x)
{
    limb_t t1[NUM_LIMBS_256BIT];
    uint8_t i, j;

// The big-endian hexadecimal expansion of (2^250 - 1) is:
// 03FFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
//
// The naive implementation needs to do 2 multiplications per 1 bit and
// 1 multiplication per 0 bit.  We can improve upon this by creating a
// pattern 0000000001 ... 0000000001.  If we square and multiply the
// pattern by itself we can turn the pattern into the partial results
// 0000000011 ... 0000000011, 0000000111 ... 0000000111, etc.
// This averages out to about 1.1 multiplications per 1 bit instead of 2.

// Build a pattern of 250 bits in length of repeated copies of 0000000001.
#define RECIP_GROUP_SIZE 10
#define RECIP_GROUP_BITS 250 // Must be a multiple of RECIP_GROUP_SIZE.
    curve25519_square(t1, x);
    for (j = 0; j < (RECIP_GROUP_SIZE - 1); ++j)
        curve25519_square(t1, t1);
    curve25519_mul(result, t1, x);
    for (i = 0; i < ((RECIP_GROUP_BITS / RECIP_GROUP_SIZE) - 2); ++i)
    {
        for (j = 0; j < RECIP_GROUP_SIZE; ++j)
            curve25519_square(t1, t1);
        curve25519_mul(result, result, t1);
    }

    // Multiply bit-shifted versions of the 0000000001 pattern into
    // the result to "fill in" the gaps in the pattern.
    curve25519_square(t1, result);
    curve25519_mul(result, result, t1);
    for (j = 0; j < (RECIP_GROUP_SIZE - 2); ++j)
    {
        curve25519_square(t1, t1);
        curve25519_mul(result, result, t1);
    }
}

/**
 * \brief Computes the reciprocal of a number modulo 2^255 - 19.
 *
 * \param result The result as a array of NUM_LIMBS_256BIT limbs in size.
 * This cannot be the same array as \a x.
 * \param x The number to compute the reciprocal for.
 */
void curve25519_recip(limb_t *result, const limb_t *x)
{
    // The reciprocal is the same as x ^ (p - 2) where p = 2^255 - 19.
    // The big-endian hexadecimal expansion of (p - 2) is:
    // 7FFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFEB
    // Start with the 250 upper bits of the expansion of (p - 2).
    curve25519_pow250(result, x);

    // Deal with the 5 lowest bits of (p - 2), 01011, from highest to lowest.
    curve25519_square(result, result);
    curve25519_square(result, result);
    curve25519_mul(result, result, x);
    curve25519_square(result, result);
    curve25519_square(result, result);
    curve25519_mul(result, result, x);
    curve25519_square(result, result);
    curve25519_mul(result, result, x);
}

void curve25519_square(limb_t *result, const limb_t *x)
{
    curve25519_mul(result, x, x);
}

/**
 * \brief Computes the square root of a number modulo 2^255 - 19.
 *
 * \param result The result as a array of NUM_LIMBS_256BIT limbs in size.
 * This must not overlap with \a x.
 * \param x The number to compute the square root for.
 *
 * For any number \a x, there are two square roots: positive and negative.
 * For example, both 2 and -2 are square roots of 4 because 2 * 2 = -2 * -2.
 * This function will return one or the other.  Callers must determine which
 * square root they are interested in and invert the result as necessary.
 *
 * \note This function is not constant time so it should only be used
 * on publicly-known values.
 */
bool curve25519_sqrt(limb_t *result, const limb_t *x)
{
    // sqrt(-1) mod (2^255 - 19).
    static limb_t const numSqrtM1[NUM_LIMBS_256BIT] = {
        LIMB_PAIR(0x4A0EA0B0, 0xC4EE1B27), LIMB_PAIR(0xAD2FE478, 0x2F431806),
        LIMB_PAIR(0x3DFBD7A7, 0x2B4D0099), LIMB_PAIR(0x4FC1DF0B, 0x2B832480)};
    limb_t y[NUM_LIMBS_256BIT];

    // Algorithm from: http://tools.ietf.org/html/rfc7748

    // Compute a candidate root: result = x^((p + 3) / 8) mod p.
    // (p + 3) / 8 = (2^252 - 2) which is 251 one bits followed by a zero:
    // 0FFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFE
    curve25519_pow250(result, x);
    curve25519_square(result, result);
    curve25519_mul(result, result, x);
    curve25519_square(result, result);

    // Did we get the square root immediately?
    curve25519_square(y, result);
    if (memcmp(x, y, sizeof(y)) == 0)
    {
        return true;
    }

    // Multiply the result by sqrt(-1) and check again.
    curve25519_mul(result, result, numSqrtM1);
    curve25519_square(y, result);
    if (memcmp(x, y, sizeof(y)) == 0)
    {
        return true;
    }

    // The number does not have a square root.
    return false;
}

static limb_t far x_1[NUM_LIMBS_256BIT];
static limb_t far x_2[NUM_LIMBS_256BIT];
static limb_t far x_3[NUM_LIMBS_256BIT];
static limb_t far z_2[NUM_LIMBS_256BIT];
static limb_t far z_3[NUM_LIMBS_256BIT];
static limb_t far A[NUM_LIMBS_256BIT];
static limb_t far B[NUM_LIMBS_256BIT];
static limb_t far C[NUM_LIMBS_256BIT];
static limb_t far D[NUM_LIMBS_256BIT];
static limb_t far E[NUM_LIMBS_256BIT];
static limb_t far AA[NUM_LIMBS_256BIT];
static limb_t far BB[NUM_LIMBS_256BIT];
static limb_t far DA[NUM_LIMBS_256BIT];
static limb_t far CB[NUM_LIMBS_256BIT];

/**
 * \brief Evaluates the raw Curve25519 function.
 *
 * \param result The result of evaluating the curve function.
 * \param s The S parameter to the curve function.
 * \param x The X(Q) parameter to the curve function.  If this pointer is
 * NULL then the value 9 is used for \a x.
 *
 * This function is provided to assist with implementating other
 * algorithms with the curve.  Normally applications should use dh1()
 * and dh2() directly instead.
 *
 * \return Returns true if the function was evaluated; false if \a x is
 * not a proper member of the field modulo (2^255 - 19).
 *
 * Reference: <a href="http://tools.ietf.org/html/rfc7748">RFC 7748</a>
 *
 * \sa dh1(), dh2()
 */
bool curve25519_eval(uint8_t result[32], const uint8_t s[32], const uint8_t x[32])
{
    uint8_t t;
    uint8_t mask;
    uint8_t sposn;
    uint8_t select;
    uint8_t swap;
    long k;
    bool retval;

    // Unpack the "x" argument into the limb representation
    // which also masks off the high bit.  NULL means 9.
    if (x)
    {
        // x1 = x
        curve25519_unpackLE(x_1, NUM_LIMBS_256BIT, x, 32);
        x_1[NUM_LIMBS_256BIT - 1] &= ((((limb_t)1) << (LIMB_BITS - 1)) - 1);
    }
    else
    {
        memset(x_1, 0, sizeof(x_1)); // x_1 = 9
        x_1[0] = 9;
    }

    // Check that "x" is within the range of the modulo field.
    // We can do this with a reduction - if there was no borrow
    // then the value of "x" was out of range.  Timing is sensitive
    // here so that we don't reveal anything about the value of "x".
    // If there was a reduction, then continue executing the rest
    // of this function with the (now) in-range "x" value and
    // report the failure at the end.
    retval = (bool)(curve25519_reduceQuick(x_1) & 0x01);

    // Initialize the other temporary variables.
    memset(x_2, 0, sizeof(x_2)); // x_2 = 1

    x_2[0] = 1;
    memset(z_2, 0, sizeof(z_2));   // z_2 = 0
    memcpy(x_3, x_1, sizeof(x_1)); // x_3 = x
    memcpy(z_3, x_2, sizeof(x_2)); // z_3 = 1

    // Iterate over all 255 bits of "s" from the highest to the lowest.
    // We ignore the high bit of the 256-bit representation of "s".
    mask = 0x40;
    sposn = 31;
    swap = 0;
    for (t = 255; t > 0; --t)
    {
        printf(".");
        // Conditional swaps on entry to this bit but only if we
        // didn't swap on the previous bit.
        select = s[sposn] & mask;
        swap ^= select;
        curve25519_cswap(swap, x_2, x_3);
        curve25519_cswap(swap, z_2, z_3);
        // Evaluate the curve.
        curve25519_add(A, x_2, z_2); // A = x_2 + z_2
        curve25519_square(AA, A);    // AA = A^2
        curve25519_sub(B, x_2, z_2); // B = x_2 - z_2
        curve25519_square(BB, B);    // BB = B^2
        curve25519_sub(E, AA, BB);   // E = AA - BB
        curve25519_add(C, x_3, z_3); // C = x_3 + z_3
        curve25519_sub(D, x_3, z_3); // D = x_3 - z_3
        curve25519_mul(DA, D, A);    // DA = D * A
        curve25519_mul(CB, C, B);    // CB = C * B
        curve25519_add(x_3, DA, CB); // x_3 = (DA + CB)^2
        curve25519_square(x_3, x_3);
        curve25519_sub(z_3, DA, CB); // z_3 = x_1 * (DA - CB)^2
        curve25519_square(z_3, z_3);
        curve25519_mul(z_3, z_3, x_1);
        curve25519_mul(x_2, AA, BB); // x_2 = AA * BB
        curve25519_mulA24(z_2, E);   // z_2 = E * (AA + a24 * E)
        curve25519_add(z_2, z_2, AA);
        curve25519_mul(z_2, z_2, E);

        // Move onto the next lower bit of "s".
        mask >>= 1;
        if (!mask)
        {
            --sposn;
            mask = 0x80;
            swap = select << 7;
        }
        else
        {
            swap = select >> 1;
        }
    }

    // Final conditional swaps.
    curve25519_cswap(swap, x_2, x_3);
    curve25519_cswap(swap, z_2, z_3);

    // Compute x_2 * (z_2 ^ (p - 2)) where p = 2^255 - 19.
    curve25519_recip(z_3, z_2);
    curve25519_mul(x_2, x_2, z_3);

    // Pack the result into the return array.
    curve25519_packLE(result, 32, x_2, NUM_LIMBS_256BIT);

    return retval;
}