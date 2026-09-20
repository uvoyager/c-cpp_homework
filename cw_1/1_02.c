#include <stdio.h>
#include <math.h>

int main(void){
    double k = pow(10, -4);
    printf("10^(-4) = %.2lf\n", k);

    double u = 24.33E5;
    printf("24.33E5 = %.2lf\n", u);

    const double pi = 3.14159265358979323846;
    double p = pi;
    printf("pi = %.2lf\n", p);

    const double e = 2.7182;
    double ex = e;
    printf("e = %.2lf\n", ex);

    double s = sqrt(5);
    printf("sqrt(5) = %.2lf\n", s);

    double l = log(100);
    printf("log(100) = %.2lf\n", l);
}
