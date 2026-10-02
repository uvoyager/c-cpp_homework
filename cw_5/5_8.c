#include <stdio.h>
#include <math.h>
double exp_taylor(double x, double eps) {
    double term = 1.0, y = 1.0;
    int k =1;
    while (1) {
        term *= x/k;
        if (fabs(term) >= eps) {
            y += term;
            k++;
        }
    } return y;
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
    } y = exp_taylor(x, eps);
    printf("exp(x) = %lf, %lf", y, exp(x));
}
