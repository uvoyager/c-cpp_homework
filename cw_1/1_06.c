#include <stdio.h>

int main() {
    double F, C;
    printf("Input temperature in Celsius: \n");
    scanf("%lf", &C);
    F = C*9/5 + 32;
    printf("Temperature in Fahrenheits: %.2lf\n ", F);

}