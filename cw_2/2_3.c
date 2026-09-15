#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double heron(double x, double y, double z) {
    if (x>= y+z | y>= x+z | z >= x+y | x <= 0 | y <= 0 | z <= 0) {
        return 0.0;
    }
    double p = (x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}

int tests() {
    if (!iszero(heron(0.0, 0.0, 0.0))) {
        printf("the test failed 1\n");
        return 1;
    }
    if (!iszero(heron(0.0, 5.3, 0.0))) {
        printf("the test failed 2\n");
        return 1;
    }
    if (!iszero(heron(-3.6, 0.0, 4.7))) {
        printf("the test failed 3\n");
        return 1;
    }
    if (!iszero(heron(-3.5, -2.0, -5.23))) {
        printf("the test failed 4\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    double x, y, z;
    tests();
    printf("input x, y and z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("area of a triangle with sides %lf, %lf, %lf is : %lf\n", x, y, z, heron(x, y, z));
}