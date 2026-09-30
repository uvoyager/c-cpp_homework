#include <stdio.h>
#include <math.h>

unsigned long long dbl_function(unsigned char n) {
    if (n == 0 || n == 1) {return 1;}
    unsigned long long result = 1UL;
    for (unsigned char i = n; i>1; i-=2) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned char n;
    printf("input the value if n: ");
    scanf("%hhu", &n);
    printf("the result for %hhu is: %llu", n, dbl_function(n));
}