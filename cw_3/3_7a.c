#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    double eps = 1e-9;
    if (fabs(a)<eps) {
        if (fabs(b)<eps) {
            if (fabs(c)<eps) {
                printf("infinite solutions\n");
            } else {
                printf("no solutions, 0 != %g\n", c);
            }
        } else {
            double x = -c/b;
            printf("one root : x = %g\n", x);
        }
        return;
    }
    double D = b*b-4*a*c;
    if (fabs(D)<eps) {
        printf("one root: x = %g\n", -b/(2*a));
    } else if (D<eps) {
        printf("no real roots\n");
    } else {
        double s_D = sqrt(D);
        double x1 = (-b+s_D)/(2*a);
        double x2 = (-b-s_D)/(2*a);
        printf("x1 = %g, x2 = %g\n", x1, x2);
    }
}

int main() {
    double a, b, c;
    //tests//
    solve_quadratic(1, -3, 2);
    solve_quadratic(0, 0, 0);
    solve_quadratic(0, 0, -3);
    solve_quadratic(-1, 0, 0);
    solve_quadratic(0, 3, -2);
    printf("input coefficients: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    solve_quadratic(a, b, c);
}