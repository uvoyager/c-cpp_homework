#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 0, n;
    double y, z_max, *a, *b;

    printf("input int n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }
    a = (double *)malloc(n * sizeof(double));
    b = (double *)malloc(n * sizeof(double));
    if (a == NULL || b == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%lf", &y) == 1) {
            a[i] = y;
        }
    }
    for (i = 0; i < n; i++) {
        if (fabs(a[i]) <= 2.0) {
            b[i] = a[i];
        }
        else {
            b[i] = 0.5;
        }
    }
    z_max = fabs(b[0]);
    for (i = 1; i < n; i++) {
        if (fabs(b[i]) > z_max) {
            z_max = fabs(b[i]);
        }
    }
    printf("max(z1, ..., zn) = %g\n", z_max);
    free(a);
    free(b);
}
