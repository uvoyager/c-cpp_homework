#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

void input_array(double a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

double mean(double a[], int n) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    } return res/n;
}

double variance(double a[], int n) {
    double mean_value, sq_difference = 0.0;
    mean_value = mean(a, n);
    for (int i = 0; i < n; i++) {
        sq_difference += (a[i] - mean_value)*(a[i] - mean_value);
    }return sq_difference/n;
}

bool iszero(double a) {
    return fabs(a)<1e-9;
}
int tests() {
    double test1[] = {3.0, 5.0, 7.0, 9.0};
    double test2[] = {5.5, 5.5, 5.5, 5.5, 5.5};
    double test3[] = {-2.0, 0.0, 2.0};
    printf("tests...\n");
    if (!iszero(variance(test1, 4) - 5.0)) {
        printf("the test failed: variance([3,5,7,9]) != 5.0\n");
        return 1;
    }
    if (!iszero(variance(test2, 5))) {
        printf("the test failed: variance([5.5,...]) != 0.0\n");
        return 1;
    }
    if (!iszero(variance(test3, 3) - 8.0 / 3.0)) {
        printf("the test failed: variance([-2,0,2]) != 2.666667\n");
        return 1;
    }
    printf("tests are successful!\n");
}

int main() {
    tests();
    int N;
    printf("input N, size of and array: ");
    scanf("%d", &N);
    double* A = malloc(N*sizeof(double));
    input_array(A, N);
    printf("variation of A: %lf\n", variance(A, N));
}