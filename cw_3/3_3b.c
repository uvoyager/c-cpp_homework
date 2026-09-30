#include <stdio.h>

int main() {
    long long x, y, z;
    printf("input three integers: ");
    scanf("%lld, %lld, %lld", &x, &y, &z);
    long long m = x*y*z;
    printf("%lld*%lld*%lld = %lld\n", x, y, z, m);
}