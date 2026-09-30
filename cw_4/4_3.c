#include <stdio.h>

int a(int x, int n) {
    int summ = 0;
    for (unsigned i = 1; i<=n; i++) {
        summ += x;
        x *= x;
    }
    return summ+1;
}

int b(int x, int y, int n) {
    int summ = 0;
    int x_2 = x*x;
    for (unsigned i = 1; i<=n; i++) {
        summ += x_2*y;
        x_2 *= x_2;
        y *= y;
    }
    return summ+1;
}

int main() {
    unsigned n;
    int x, y;
    printf("input x and n: ");
    scanf("%d %u", &x, &n);
    printf("the result for a is: %d\n", a(x, n));
    printf("input x, y and n: ");
    scanf("%d %d %u", &x, &y, &n);
    printf("the result for b is: %d\n", b(x, y, n));
}