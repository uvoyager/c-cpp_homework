#include <stdio.h>
#include <math.h>

double chain_sqrt(double x, unsigned n) {
    double result = x;
    for (unsigned i = 1; i<=n; i++) {
        result = sqrt(result)+result;
    }
    return result;
}

int main() {
    double x, y;
    unsigned n;
    printf(" enter values for x, n: ");
    scanf("%lf %u", &x, &n);
    y = chain_sqrt(x, n);
    printf("chain_sqrt(%lf, %u) = %lf\n", x, n, y);
}