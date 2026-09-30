//task4_3

/*#include <stdio.h>
#include <math.h>
void polynomial( int x, int n) {
    int res = 0;
    for (unsigned i = 0; i < n; i++) {
        int el = pow(x, n-i);
        res += el;
    }
    printf("the value is: %d\n", res);
}

int main() {
    int x, n;
    printf("enter the value of x and n: ");
    scanf("%d %d", &x, &n);
    polynomial(x, n);
}*/


//task2_17j

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


double invsqrt(double x, double alpha){
    if (alpha*x*x < -1) {
        return NAN;
    }
    return x/sqrt(1+alpha*x*x);
}

double invsqrt_derivative(double x, double alpha) {
    if (alpha*x*x < -1) {
        return NAN;
    }
    double y = pow(1+alpha*x*x, 3);
    return 1/sqrt(y);
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}
///Tests
int tests_eReLu() {
    printf("tests ...\n");
    if (!iszero(invsqrt(0.0, 0.0))) {
        printf("invsqrt(0.0, 0.0) != 0\n");
        return 1;
    }
    if (!iszero(invsqrt(1.0, 3.0)-0.5)) {
        printf("invsqrt(1.0, 3.0) != 0.5\n");
        return 1;
    }
    if (!isnan(invsqrt(-1.0, -5.0))) {
        printf("invsqrt(-1.0, -5.0) != nan\n");
        return 1;
    }
    if (!iszero(invsqrt_derivative(0.0, 0.0)-1.0)) {
        printf("invsqrt_derivative(0.0, 0.0) != 1\n");
    }
    if (!isnan(invsqrt_derivative(1.0, -3.0))) {}
    printf("tests are successful\n");
    return 0;
}

int main() {
    double x, alpha;
    tests_eReLu();
    printf("input x and alpha: ");
    scanf("%lf %lf", &x, &alpha);
    double i = invsqrt(x, alpha);
    double j = invsqrt_derivative(x, alpha);
    printf("invsqrt(%lf, %lf) = %lf\n", x, alpha, i);
    printf("invsqrt_derivative(%lf, %lf) = %lf\n", x, alpha, j);
}
