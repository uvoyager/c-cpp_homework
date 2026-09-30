#include <stdio.h>

int main() {
    int x = 2;
    int x_2 = x*x;
    int x_4 = x_2*x_2;
    printf("x^2 = %d\n", x_4);

    int x_6 = x_4*x_2;
    printf("x^6 = %d\n", x_6);

    int x_8 = x_4*x_4;
    int x_9 = x_8*x;
    printf("x^9 = %d\n", x_9);

    int x_16 = x_8*x_8;
    int x_15 = x_16/x;
    printf("x^15 = %d\n", x_15);

    int x_24 = x_16*x_8;
    int x_26 = x_24*x_2;
    printf("x^26 = %d\n", x_26);

    long double  x_64 = (long double)x_16*x_16*x_16*x_16;
    printf("x^64 = %.0Lf\n", x_64);
}