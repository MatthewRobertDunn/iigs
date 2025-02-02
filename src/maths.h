#ifndef _MATHS_H
#define _MATHS_H
#include <stdint.h>
void init_mul8_table();
uint32_t multiply32_16(uint32_t a, uint16_t b);
uint16_t multiply16_8(uint16_t a, uint8_t b);
#endif