#include <stdio.h>
#include <math.h>
const int SIZE = 100;

int main() {
    double arithmetic = 0.0, geometric = 0.0;
    int i = 0, n;
    double  a[SIZE];
    do {
        printf("a[%d] = ", i);
        scanf("%d", &n);
        a[i] = n;
        i ++;
        if (i >= SIZE) {
            printf("Array is full!\n");
            break;
        }
    }while (n != 0);

    for (i = 0; a[i] != 0; i++) {
        arithmetic += a[i];
    }arithmetic = arithmetic/i;

    for (i = 1; i <= SIZE; i++) {
        geometric *= a[i];
    }geometric = pow(geometric, 1/i);

    printf("arithmetic = %g\n", arithmetic);
    printf("geometric = %g\n", geometric);
}