#include <stdio.h>
#define SIZE 20

void input_array(double a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("el[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

void output_array(double a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", a[i]);
    }printf("\n");
}

double sum_of_vectors(const double a[], const double b[], double c[],  int size){
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

double scalar_multiply(double a[], double b[], int size) {
    double c = 0.0;
    for (int i = 0; i < size; i++) {
        c += a[i] * b[i];
    } return c;
}

int main() {
    int n;
    double a[SIZE], b[SIZE], c[SIZE];
    printf("input size of array: ");
    scanf("%d", &n);
    if (n == 0 || n>SIZE) {
        printf("array with this size cannot be processed.");
        return 0;
    }
    printf("input elements of a[]: ");
    input_array(a, n);
    printf("input elements of b[]: ");
    input_array(b, n);
    printf("array a: ");
    output_array(a, n);
    printf("array b: ");
    output_array(b, n);

    sum_of_vectors(a, b, c, n);
    printf("sum of vectors a and b: ");
    output_array(c, n);

    printf("scalar product is: %lf\n", scalar_multiply(a, b, n));
}