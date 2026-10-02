#include <stdio.h>
#include <math.h>

void print_factorial(unsigned n) {
    printf("%u!=", n);
    for (unsigned i = 1; i<n; i++) {
        printf("%u*", i);
    }
    printf("%u\n", n);
}

void print_factorial_inverse(unsigned n) {
    printf("%u!=", n);
    for (unsigned i = n; i>1; i--) {
        printf("%u*", i);
    }
    printf("1\n");
}

int main() {
    unsigned n;
    printf("input int n: ");
    scanf("%u", &n);
    printf("factorial of n: \n");
    print_factorial(n);
    printf("inverse factorial of n:\n");
    print_factorial_inverse(n);
}