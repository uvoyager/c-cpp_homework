#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double e = 2.7182818284;
double eReLu(double a, double x) {
    if (x<1e-9) {
        return a*(pow(e, x) - 1);
    }
    return 0;
}

double eReLu_derivative(double a, double x) {
    if (x<1e-9) {
        return a*pow(e, x);
    }
    return 0;
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}

int tests_eReLu() {
    printf("tests... \n");
    if (!iszero(eReLu(2.0, 1.0))) {
        printf("the test failed: eReLu(2.0, 1.0) != 0.0\n");
        return 1;
    }
    if (!iszero(eReLu(3.0, 0.0))) {
        printf("the test failed: eReLu(3.0, 0.0) != 0.0\n");
        return 1;
    }
    if (!iszero(eReLu_derivative(2.0, 1.0))) {
        printf("the test failed: eReLu_derivative(2.0, 1.0) != 0.0\n");
        return 1;
    }
    if (!iszero(eReLu_derivative(5.0, 0.0) - 5.0)) {
        printf("the test failed: eReLu_derivative(5.0, 0.0) != 5.0\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}