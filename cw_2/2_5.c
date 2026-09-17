#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double Rosenbrock2d(double x, double y) {
    return 100*pow(x*x -y, 2)+pow(x-1, 2);
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}

int tests() {
    if (!iszero(Rosenbrock2d(1.0, 1.0))) {
        printf("the test failed: Rosenbrock2d(1.0, 1.0) != 0.0\n");
        return 1;
    }
    if (!iszero(Rosenbrock2d(0.0, 5.3) -(100*pow(0.0*0.0 - 5.3, 2)+pow(0.0-1, 2)))) {
        printf("the test failed: Rosenbrock2d(0.0, 5.3) != %lf\n", Rosenbrock2d(0.0, 5.3));
        return 1;
    }
    if (!iszero(Rosenbrock2d(-3.6, 0.0) - (100*pow(-3.6*-3.6 - 0.0, 2)+pow(-3.6-1, 2)))) {
        printf("the test failed: Rosenbrock2d(-3.6, 0.0) != %lf\n", Rosenbrock2d(-3.6, 0.0));
        return 1;
    }
    if (!iszero(Rosenbrock2d(-3.5, -2.0) - (100*pow(-3.5*-3.5 - (-2.0), 2)+pow(-3.5-1, 2)))) {
        printf("the test failed: Rosenbrock(-3.5, -2.0) != %lf\n", Rosenbrock2d(-3.5, -2.0));
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    tests();
    double x, y;
    printf("input x and y: ");
    scanf("%lf %lf", &x, &y);
    printf("Rosenbrock2d(%lf,%lf) = %lf\n", x, y, Rosenbrock2d(x, y));
}