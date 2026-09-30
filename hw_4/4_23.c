#include <stdio.h>
#include <math.h>

int main() {
    int i = 0, n;
    printf("input int n: ");
    scanf("%d", &n);
    double a[n], b[n],y, z_max;
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &y);
        a[i] = y;
    }
    for (i = 0; i < n; i++) {
        if (fabs(a[i]) <= 2.0) {
            b[i] = a[i];
        }
        else {b[i] = 0.5;}
    }
    z_max = fabs(b[0]);
    for (i = 1; i < n; i++) {
        if (fabs(b[i]) > z_max) {
            z_max = fabs(b[i]);
        }
    }
    printf("max(z1, ..., zn) = %g\n", z_max);
}