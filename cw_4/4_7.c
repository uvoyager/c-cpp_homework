#include <stdio.h>
#include <math.h>

double exp_taylor(double x, unsigned u) {
    double sum = 1.0;
    double term = 1.0;
    for (unsigned i = 1; i < u; i++) {
        term *= x/i;
        sum += term;
    }
    return sum;
}

int main() {
    double x, y;
    unsigned n;
    printf("input values for x, n: ");
    scanf("%lf %u", &x, &n);
    y = exp_taylor(x, n);
    printf("exp_taylor(%lf, %u) = %lf\n%lf\n", x, n, y, exp(x));
}