#include <stdio.h>

unsigned sum_of_digits(unsigned x) {
    unsigned units = x%10;
    unsigned tens = (x/10)%10;
    unsigned hundreds = x/100;
    return units+tens+hundreds;
}

unsigned inverse(unsigned x) {
    unsigned units = x%10;
    unsigned tens = (x/10)%10;
    unsigned hundreds = x/100;
    return 100*units+10*tens+hundreds;
}

int main() {
    unsigned x;
    printf("input a natural integer: ");
    scanf("%u", &x);

    unsigned char units = (unsigned char)(x%10);
    unsigned char tens = (unsigned char)(x/10)%10;
    unsigned char hundreds = (unsigned char)(x/100);
    printf("units = %hhu, tens = %hhu, hundreds = %hhu\n", units, tens, hundreds);
    printf("sum of digits = %u\n", sum_of_digits(x));
    printf("inverse = %u\n", inverse(x));
}