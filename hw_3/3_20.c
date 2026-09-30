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

bool check(double xa, double ya, double xb, double yb, double xc, double yc, double x, double y) {
    double ac = side(xa, xc, ya, yc);
    double ab = side(xa, xb, ya, yb);
    double bc = side(xb, xc, yb, yc);
    double area_abc = area(ab, ac, bc);

    double ap = side(xa, x, ya, y);
    double bp = side(xb, x, yb, y);
    double cp = side(xc, x, yc, y);
    double area_abp = area(ab, ap, bp);
    double area_acp = area(ac, cp, ap);
    double area_cbp = area(bc, bp, cp);

    double eps = 1e-9;
    if (area_abc >= area_abp + area_acp + area_cbp - eps) {
        return true;
    }
    return false;
}

bool iszero(double x) {
    return fabs(x)<1e-9;
}

int tests_eReLu() {
    printf("tests...\n");
    if (!iszero(side(0, 0, 0, 1) - 1.0)) {
        printf("the test failed: side(0, 0, 0, 1) != 1.0\n");
        return 1;
    }
    if (!iszero(side(0, 3, 0, 4) - 5.0)) {
        printf("the test failed: side(0, 0, 3, 4) != 5.0\n");
        return 1;
    }
    if (!iszero(area(3.0, 4.0, 5.0) - 6.0)) {
        printf("the test failed: area(3.0, 4.0, 5.0) != 6.0\n");
        return 1;
    }
    if (!iszero(area(0.0, 0.0, 0.0))) {
        printf("the test failed: area(0.0, 0.0, 0.0) != 0.0\n");
        return 1;
    }
    if (!check(0, 0, 4, 0, 0, 4, 1, 1)) {
        printf("the test failed: check() expected point (1,1) to be inside\n");
        return 1;
    }
    if (check(0, 0, 4, 0, 0, 4, 5, 5)) {
        printf("the test failed: check() expected point (5,5) to be outside\n");
        return 1;
    }
    printf("tests are successful\n");
    return 0;
}

int main() {
    tests_eReLu();
    double xa, ya, xb, yb, xc, yc, x, y;
    printf("input coordinates of the 1st vertex: \n");
    scanf("%lf %lf", &xa, &ya);
    printf("input coordinates of the 2nd vertex: \n");
    scanf("%lf %lf", &xb, &yb);
    printf("input coordinates of the 3rd vertex: \n");
    scanf("%lf %lf", &xc, &yc);
    printf("input coordinates of the point: \n");
    scanf("%lf %lf", &x, &y);if (check(xa, ya, xb, yb, xc, yc, x, y)) {
        printf("point p is inside the triangle\n");
    } else {
        printf("point p is outside the triangle\n");
    }
}