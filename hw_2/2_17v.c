#include <stdio.h>
#include <math.h>
#include <stdbool.h>
// softSign = x/(1+fabs(x));
double softSign(double x){
    return x/(1+fabs(x));
}

double softSign_derivative(double x) {
    return 1/pow(1+fabs(x), 2);
}

bool iszero(double x) {
    return fabs(x) < 1e-9;
}

int tests() {
    printf("tests\n");
    if (!iszero(softSign(0.0))) {
        printf("softSign(0.0) != 0\n");
        return 1;
    }
    if (!iszero(softSign(1.0)-0.5)) {
        printf("softSign(1.0) != 0.5\n");
        return 1;
    }
    if (!iszero(softSign(-1.0)+0.5)) {
        printf("softSign(-1.0) != 0.5\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;

}

int main() {
    double x, alpha;
    tests();
    printf("input x: ");
    scanf("%lf", &x);
    double i = softSign(x);
    double j = softSign_derivative(x);
    printf("softSign(%lf) = %lf\n", x, i);
    printf("softSign_derivative(%lf) = %lf\n", x, j);
}