#include <stdio.h>
#include <stdlib.h>

double input_array(double* array, unsigned n) {
    for (int i = 0; i < n; i++) {
        printf("input el[%d]: ", i);
        scanf("%lf", &array[i]);
    }
}

int main() {
    unsigned n;
    double summ = 0.0;
    printf("input integer n: ");
    scanf("%u", &n);
    double* array = malloc(n * sizeof(double));
    input_array(array, n);
    for (int i = 0; i < n; i++) {
        summ += array[i]*array[i];
    }
    printf("the sum is: %lf\n", summ);
    free(array);
}