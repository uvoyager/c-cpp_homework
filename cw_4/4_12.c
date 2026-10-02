#include <stdio.h>

double sub_factorial(int n) {
    if (n == 0) return 1.0;
    if (n == 1) return 0.0;
    double prev = 1.0;
    double current = 0.0;
    double sign = -1.0;
    for (int i = 2; i <= n; i++) {
        sign = -sign;
        current = i * prev + sign;
        prev = current;
    }
    return current;
}

int main() {
    int n;
    printf("input n<25: ");
    scanf("%d", &n);
    printf("sub_factorial(%d) = %.0f\n", n, sub_factorial(n));
}