#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double side(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double area(double x, double y, double z) {
    if (x>= y+z | y>= x+z | z >= x+y | x <= 0 | y <= 0 | z <= 0) {
        return 0.0;
    }
    double p = (x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}

bool iszero(double x) {
    return  fabs(x)<1e-9;
}

int tests() {
    if (!iszero(side(0,0,1,1)-1)) {
        printf("the test failed: side(0, 0, 1, 1) != 1\n");
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
    if (!iszero(area(0.0, 0.0, 0.0))) {
        printf("the test failed: area(0.0, 0.0, 0.0) != 0.0\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    double x1, x2, x3, y1, y2, y3;
    printf("input x1, y1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("input x2, y2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("input x3, y3: ");
    scanf("%lf %lf", &x3, &y3);
    double a = side(x1, x2, y1, y2);
    double b = side(x2, x3, y2, y3);
    double c = side(x1, x3, y1, y3);
    double ar = area(a, b, c);
    printf("are of the triangle with given vertexes: %lf\n", ar);

}