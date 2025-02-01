#include <stdint.h>
#include <stdio.h>
#include "fucks.h"

int main(void)
{
    uint32_t a = 254;
    uint16_t b = 1234;
    uint32_t result;
    init_mul8_table();
    result = multiply32_16(a, b);
    printf("Result: %d\n", result);
    result = a * b;
    printf("Result: %d\n", result);
}