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
    uint16_t a1 = (a >> 8) & 0xFF;  // Extract next 8 bits of 'a'
    uint16_t a2 = (a >> 16) & 0xFF; // Extract next 8 bits of 'a'
    uint16_t a3 = (a >> 24) & 0xFF; // Extract highest 8 bits of 'a'
    uint16_t b0 = b & 0xFF;        // Extract lower 8 bits of 'b'
    uint16_t b1 = (b >> 8) & 0xFF; // Extract higher 8 bits of 'b'

    // Perform the multiplications of 8-bit components, using lookup table
    uint16_t p00 = mul8[(a0 << 8) | b0]; // a0 * b0
    uint16_t p01 = mul8[(a0 << 8) | b1]; // a0 * b1
    uint16_t p10 = mul8[(a1 << 8) | b0]; // a1 * b0
    uint16_t p11 = mul8[(a1 << 8) | b1]; // a1 * b1
    uint16_t p20 = mul8[(a2 << 8) | b0]; // a2 * b0
    uint16_t p21 = mul8[(a2 << 8) | b1]; // a2 * b1
    uint16_t p30 = mul8[(a3 << 8) | b0]; // a3 * b0
    uint16_t p31 = mul8[(a3 << 8) | b1]; // a3 * b1

    // Accumulate the result in a 32-bit variable
    uint32_t result = 0;

    // Add partial products together, correctly shifting and handling carry
    result += p00; // No shift needed for p00 (bits 0–15)

    // Add p01 (shifted by 8 bits)
    result += (uint32_t)p01 << 8;

    // Add p10 (shifted by 8 bits)
    result += (uint32_t)p10 << 8;

    // Add p11 (shifted by 16 bits)
    result += (uint32_t)p11 << 16;

    // Add p20 (shifted by 16 bits)
    result += (uint32_t)p20 << 16;

    // Add p21 (shifted by 24 bits)
    result += (uint32_t)p21 << 24;

    // Add p30 (shifted by 24 bits)
    result += (uint32_t)p30 << 24;

    // Ignore p31 (shifted by 32 bits) because it exceeds 32 bits
    // p31 contributes to bits 32–39, which are beyond the 32-bit result
    return result;
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