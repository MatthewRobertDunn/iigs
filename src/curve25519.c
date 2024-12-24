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
void BigNumberUtil::packLE(uint8_t *bytes, size_t len,
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