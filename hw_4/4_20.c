#include <stdio.h>
#include <math.h>

int main() {
    double d, h;
    printf("input d: ");
    if (scanf("%lf", &d) != 1) {
        printf("input error\n");
        return 1;
    }
    printf("input step h (h > 0): ");
    if (scanf("%lf", &h) != 1 || h <= 0) {
        printf("error. h must be > 0\n");
        return 1;
    }
    printf("\n=========================\n");
    printf("|    x     |      y     |\n");
    printf("=========================\n");
    for (double x = -3.0; x <= 3.0 + (h / 2.0); x += h) {
        double y = exp(-d * x * x);
        printf("| %8.4f | %10.6f |\n", x, y);
    }
    printf("=========================\n");
    return 0;
}
