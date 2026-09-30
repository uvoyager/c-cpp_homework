#include <stdio.h>
#include <math.h>
double exp_taylor(double x, double eps) {
    double term, y;
    int k =1;
    while (fabs(term) >= eps) {
        y = term;
        term *= x/k;
        y += term;
        k++;
    } return y;
}

int main() {
    double x, eps, y;
    printf("x = ");
    scanf("%lf", &x);
    while (eps <= 0) {
        printf("enter the value > 0");
        scanf("%lf", &eps);
    } y = exp_taylor(x, eps);
    printf("exp(x) = %lf, %lf", y, exp(x));
}

//check!! there is a mistake, find it!