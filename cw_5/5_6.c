#include <stdio.h>

double a(int n, int b) {
    double term = b;
    for (int i = 1; i <= n; i++) {
        term = b +1.0/term;
    }return term;
}

double b(int n) {
    double term = 4*n + 2;
    for (int i = n-1; i<=n; i++) {
        term = 4*(n-i)+2+1.0/term;
    } return term;
}

double c(int n) {
    double term = 2.0;
    for (int i = 0; i<=n; i++) {
        if (i%2 == 0) {
            term = 2 + 1.0/term;
        }
        else if (i%2 == 1) {
            term = 1+1.0/term;
        }
    }
    return term;
}

int main() {
    int n, k;
    printf("input n, k: ");
    scanf("%d %d", &n, &k);
    printf("a(%d) = %lf\n", n, a(n, k));
    printf("b(%d) = %lf\n", n, b(n));
    printf("c(%d) = %lf\n", n, c(n));
}