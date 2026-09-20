#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int16_t mult(int8_t a, int8_t b) {
    return (int16_t)(a*b);
}

int main() {
    uint64_t x, y, z;
    printf("input 3 integers: ");
    scanf("%" SCNu64 ", %"SCNu64 ", %"SCNu64, &x, &y, &z);

    uint64_t m = x*y*z;
    printf("product is: %" PRIu64 "\n", m);
}