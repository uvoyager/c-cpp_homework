#include <stdio.h>
#include <math.h>

long double min_ld(long double x, long double y, long double z) {
    long double a = fmin(x, y);
    return fmin(a, z);
}

long double max_ld(long double x, long double y, long double z) {
    long double a = fmax(x, y);
    return fmax(a, z);
}

int main() {
    long double x, y, z;
    printf("input 3 numbers: ");
    scanf("%Lf %Lf %Lf", &x, &y, &z);
    x = fabs(x);
    y = fabs(y);
    z =  fabs(z);
    printf("max(%Lf, %Lf, %Lf) = %Lf\n", x, y, z, max_ld(x, y, z));
    printf("min(%Lf, %Lf, %Lf) = %Lf\n", x, y, z, min_ld(x, y, z));
}