#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float hypotenuse(double x, double y) {
    double c_2 = x*x + y*y;
    float c = sqrt(c_2);
    if (c == 0 | x <= 0| y <= 0) {
        return 0.0;
    }
    return c;
}
bool iszero(double x) {
    return fabs(x) < 1e-9;
}
int tests() {
    if (!iszero(hypotenuse(0.0, 0.0))) {
        printf("the test failed 1\n");
        return 1;
    }
    if (!iszero(hypotenuse(0.0, 5.3))) {
        printf("the test failed 2\n");
        return 1;
    }
    if (!iszero(hypotenuse(-3.6, 0.0))) {
        printf("the test failed 3\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    double x, y;
    tests();
    printf("input x and y without punctuation between them: ");
    scanf("%lf %lf", &x, &y);
    float c = hypotenuse(x, y);
    printf("hypotenuse is %f\n", c);
}