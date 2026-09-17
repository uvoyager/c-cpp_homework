#include <stdio.h>
#include <math.h>
#include <stdbool.h>
const double PI = 3.14159265358979323846;

double side(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double area(double a, double b) {
    return PI*a*b;
}

bool iszero(double x) {
    return  fabs(x)<1e-9;
}

int tests() {
    if (!iszero(side(0, 0, 0, 0))) {
        printf("test failed: side(0, 0, 0, 0) != 0\n");
        return 1;
    }
    if (!iszero(side(2, 0, 3, 0)-sqrt(13))) {
        printf("the test failed: side(2, 0, 3, 0) != sqrt(13)\n");
        return 1;
    }
    if (!iszero(side(1,1,3,-2)-5)) {
        printf("the test failed: side(1, 1, 3, -2) != 5\n");
        return 1;
    }
    if (!iszero(area(0, 0))) {
        printf("the test failed: area(0, 0) != 0\n");
        return 1;
    }
    if (!iszero(area(2, 0)-PI*2)) {
        printf("the test failed: area(2, 0) != PI*2\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    double x1, x2, x3, y1, y2, y3;
    printf("input x1, y1, x2, y2, x3, y3: \n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a = side (x1, x2, y1, y2);
    double b = side (x1, x3, y1, y3);
    double c = area (a, b);
    printf("the area is: %lf\n", c);
}