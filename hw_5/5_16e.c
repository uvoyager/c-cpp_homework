#include <stdio.h>
#include <math.h>

double ln_taylor(double x, double eps) {
    double sum = x;
    double term = x;
    int i = 1;
    while (1) {
        term *= -x/(1+i);
        if (fabs(term)<eps) {
            break;
        }
        sum += term;
        i++;
    } return sum;
}

int main() {
    double x, eps, y;
    printf("x = ");
    scanf("%lf", &x);
    printf("eps = ");
    scanf("%lf", &eps);
    while (eps <= 0) {
        printf("enter the value > 0");
        scanf("%lf", &eps);
    } y = ln_taylor(x, eps);
    printf("ln_taylor(x) = %lf, %lf", y, 1.0-exp(-x));
}