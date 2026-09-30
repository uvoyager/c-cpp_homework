#include <stdio.h>

double exp_taylor(double x, unsigned n) {
    double sum = 0;
    double term = 1.0;
    for (unsigned i = 1; i <= n; i++) {
        term *= x/i*(i+1);
        sum += term;
    }
    return sum;
}

int main() {
    double x, y;
    unsigned n;
    printf("input the value of x and n: ");
    scanf("%lf %u", &x, &n);
    y = exp_taylor(x, n);
    printf("exp_taylor(%lf, %u) = %lf\n", x, n, y);
}