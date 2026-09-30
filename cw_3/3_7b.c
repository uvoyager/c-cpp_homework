#include <math.h>
#include <stdio.h>

void solve_biquadratic(double a, double b, double c) {
    double eps = 1e-9;
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            if (fabs(c) < eps) {
                printf("infinite solutions\n");
            } else {
                printf("no real roots\n");
            }
        } else {
            double v = -c / b;
            if (v < -eps) {
                printf("no real roots\n");
            } else if (fabs(v) < eps) {
                printf("one root: x = 0\n");
            } else {
                double s = sqrt(v);
                printf("x1 = %g, x2 = %g\n", -s, s);
            }
        }
        return;
    }
    double D = b * b - 4 * a * c;
    if (D < -eps) {
        printf("no real roots\n");
    } else if (fabs(D) < eps) {
        double y = -b / (2 * a);
        if (y < -eps) {
            printf("no real roots\n");
        } else if (fabs(y) < eps) {
            printf("one root: x = 0\n");
        } else {
            double s = sqrt(y);
            printf("x1 = %g, x2 = %g\n", -s, s);
        }
    } else {
        double s_D = sqrt(D);
        double y1 = (-b + s_D) / (2 * a);
        double y2 = (-b - s_D) / (2 * a);

        double roots[4];
        int count = 0;
        if (fabs(y1) < eps) {
            roots[count++] = 0.0;
        } else if (y1 > eps) {
            double s1 = sqrt(y1);
            roots[count++] = -s1;
            roots[count++] = s1;
        }
        if (fabs(y2) < eps) {
            roots[count++] = 0.0;
        } else if (y2 > eps) {
            double s2 = sqrt(y2);
            roots[count++] = -s2;
            roots[count++] = s2;
        }
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (roots[i] > roots[j]) {
                    double temp = roots[i];
                    roots[i] = roots[j];
                    roots[j] = temp;
                }
            }
        }
        if (count == 0) {
            printf("no real roots\n");
        } else if (count == 1) {
            printf("one root: x = %g\n", roots[0]);
        } else if (count == 2) {
            printf("x1 = %g, x2 = %g\n", roots[0], roots[1]);
        } else if (count == 3) {
            printf("x1 = %g, x2 = %g, x3 = %g\n", roots[0], roots[1], roots[2]);
        } else if (count == 4) {
            printf("x1 = %g, x2 = %g, x3 = %g, x4 = %g\n", roots[0], roots[1], roots[2], roots[3]);
        }
    }
}

int main() {
    double a, b, c;
    //tests//
    solve_biquadratic(1, -5, 4);
    solve_biquadratic(1, 0, -4);
    solve_biquadratic(0, 1, -4);
    solve_biquadratic(1, 2, 1);
    printf("input coefficients (a b c): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        solve_biquadratic(a, b, c);
    }
    return 0;
}