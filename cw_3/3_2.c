#include <stdio.h>
#include <stdbool.h>

bool equal_num(unsigned x) {
    unsigned units = x%10;
    unsigned tens = (x/10)%10;
    unsigned hundreds = x/100;
    if (tens == units == hundreds) {
        return true;
    }
}

int main() {
    unsigned x;
    printf("enter a natural number: ");
    scanf("%u", &x);

    unsigned char units = (unsigned char)(x%10);
    unsigned char tens = (unsigned char)(x/10)%10;
    unsigned char hundreds = (unsigned char)(x/100);
    if (equal_num(x) != true) {
        printf("%u\n", x);
        printf("%hhu%hhu%hhu\n", hundreds, units, tens);
        printf("%hhu%hhu%hhu\n", units, tens, hundreds);
        printf("%hhu%hhu%hhu\n", units, hundreds, tens);
        printf("%hhu%hhu%hhu\n", tens, hundreds, units);
        printf("%hhu%hhu%hhu\n", tens, units, hundreds);
    }
    else {printf("number %u consists of identical elements\n", x);}
}