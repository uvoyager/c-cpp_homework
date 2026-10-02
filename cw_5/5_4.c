#include <stdio.h>
#include <math.h>

double a(int n) {
    double term = 1.0;
    double res = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= term/i;
        res  *= 1.0+term;
    }return res;
}

double b(int n) {
    double term = 1.0, res = 1.0;
    for (int i = 1; i <=  n; i++) {
        term = pow(-1, i+1)*pow(i, 2)/pow(2, i);
        res *= 1.0+term;
    }return res;
}

int main() {
    int n;
    printf("input n: ");
    scanf("%d", &n);
    printf("a(%d) = %lf\n", n, a(n));
    printf("b(%d) = %lf\n", n, b(n));
}