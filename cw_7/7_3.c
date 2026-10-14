#include <stdio.h>
#include <math.h>
#define SIZE 10

void input_array(double a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

int main() {
    double a[SIZE], k = 0.0;
    input_array(a, SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (a[i] > exp(1)) {
            k += a[i];
        }
    }printf("sum of elements larger than e: %lf\n", k);
}