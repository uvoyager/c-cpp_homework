#include <stdio.h>

int main() {
    double a, b;
    printf("input a and b: ");
    scanf("%lf %lf", &a, &b);
    double ar = (a+b)/2;
    double har = 2/(1/a + 1/b);
    printf("arithmetic mean scientific: %e, decimal: %lf\n", ar, ar);
    printf("harmonic mean scientific: %e, decimal: %lf\n", har, har);

}