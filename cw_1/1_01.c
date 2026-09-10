#include <stdio.h>

int main(void) {
    int c = 2+31;
    printf("2+31 = %d\n", c);

    int a = 45*54 - 11;
    printf("45*54 - 11 = %d\n", a);

    int b = 15/4;
    printf("15/4 = %d\n", b);

    double d = 15.0/4;
    printf("15.0/4 = %.2f\n", d);

    double m = 67%5;
    printf("67 = %.2lf (mod 5)\n", m);

    double r = (2*45.1+3.2)/2;
    printf("(2*45.1+3.2)/2 = %.1lf\n", r);
}