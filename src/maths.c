#include "maths.h"
static uint16_t mul8[65536];

void init_mul8_table() {
    uint16_t a, b;
    for (a = 0; a < 256; a++) {
        for (b = 0; b < 256; b++) {
            mul8[(a << 8) | b] = a * b;
        }
    }
}

uint32_t multiply32_16(uint32_t a, uint16_t b) {
    uint16_t a0 = a & 0xFF;      // Extract lower 8 bits of 'a'
    uint16_t a1 = (a & 0xFF00);  // Extract next 8 bits of 'a', these happen to be in the right spot for the mul8 table
    uint16_t a2 = (a >> 8) & 0xFF00; // Extract next 8 bits of 'a'
    uint16_t a3 = (a >> 16) & 0xFF00; // Extract highest 8 bits of 'a'
    uint16_t b0 = b & 0xFF;        // Extract lower 8 bits of 'b'
    uint16_t b1 = (b >> 8) & 0xFF; // Extract higher 8 bits of 'b'

    // Perform the multiplications of 8-bit components, using lookup table
    uint16_t p00 = mul8[(a0 << 8) | b0]; // a0 * b0
    uint16_t p01 = mul8[(a0 << 8) | b1]; // a0 * b1
    uint16_t p10 = mul8[a1 | b0]; // a1 * b0 special case where the lower 8 bits of a1 are 0
    uint16_t p11 = mul8[a1 | b1]; // a1 * b1
    uint16_t p20 = mul8[a2 | b0]; // a2 * b0
    uint16_t p21 = mul8[a2 | b1]; // a2 * b1
    uint16_t p30 = mul8[a3 | b0]; // a3 * b0
    uint16_t p31 = mul8[a3 | b1]; // a3 * b1


    uint32_t lo    = (uint32_t)p00;
    uint32_t sum8  = ((uint32_t)p01 + (uint32_t)p10) <<  8;
    uint32_t sum16 = ((uint32_t)p11 + (uint32_t)p20) << 16;
    uint32_t sum24 = ((uint32_t)p21 + (uint32_t)p30) << 24;
    return lo + sum8 + sum16 + sum24;
}

uint16_t multiply16_8(uint16_t a, uint8_t b) {
    uint16_t a0 = a & 0xFF;      // Extract lower 8 bits of 'a'
    uint16_t a1 = (a >> 8) & 0xFF; // Extract higher 8 bits of 'a'

    // Perform the multiplications of 8-bit components, using the lookup table
    uint16_t p0 = mul8[(a0 << 8) | b]; // a0 * b
    uint16_t p1 = mul8[(a1 << 8) | b]; // a1 * b

    // Accumulate the result in a 16-bit variable
    uint16_t result = p0; // Start with p0 (no shift needed)

    // Add p1 (shifted by 8 bits) to the result
    result += (uint16_t)p1 << 8;

    return result;
}