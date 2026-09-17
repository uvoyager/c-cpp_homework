#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double PI = 3.14159265358979323846;

double volume(double r, double h) {
    if (r <= 1e-9) {
        printf("r is zero or negative.\n");
        return 0.0;
    }
    else if (h <= 1e-9) {
        printf("h is zero or negative.\n");
        return 0.0;
    }
    return PI * r * r * h;
}

bool ispositive(double x) {
    return x > 1e-9;
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}

int tests() {
    if (!iszero(volume(0.0, 0.0))) {
        printf("test failed: volume(0.0, 0.0) != 0\n");
        return 1;
    }
    if (!iszero(volume(2.0, -3.0))) {
        printf("test failed: volume(2.0, -3.0) != 0\n");
        return 1;
    }
    double expected = PI * 2.0 * 2.0 * 3.0;
    double actual = volume(2.0, 3.0);
    if (fabs(actual - expected) > 1e-6) {
        printf("test failed: volume(2.0, 3.0) expected %f but got %f\n", expected, actual);
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    tests();
    double r, h;
    printf("input the radius and height: ");
    scanf("%lf %lf", &r, &h);
    double v = volume(r, h);
    if (ispositive(v)) {
        printf("volume of a cone is : %lf\n", v);
        return 0;
    }
    else {printf("cannot compute the volume of a cone \n");}
}