#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void input_array(double a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

double min_element(double a[], int size) {
    double min_el = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] < min_el) {
            min_el = a[i];
        }
    } return min_el;
}

double min_elementsq(double a[], int size) {
    double min_el = a[0]*a[0];
    for (int i = 0; i < size; i++) {
        if (a[i]*a[i] < min_el) {
            min_el = a[i]*a[i];
        }
    } return min_el;
}

bool iszero(double a) {
    return fabs(a)<1e-9;
}

int tests() {
    double arr1[] = {3.0, 1.0, 4.0, 1.5};
    double arr2[] = {-5.0, 2.0, 0.0, -3.0};
    printf("tests...");
    if (!iszero(min_element(arr1, 4) - 1.0)) {
        printf("the test failed: min_element({3.0, 1.0, 4.0, 1.5}) != 1.0\n");
        return 1;
    }
    if (!iszero(min_element(arr2, 4) - (-5.0))) {
        printf("the test failed: min_element({-5.0, 2.0, 0.0, -3.0}) != -5.0\n");
        return 1;
    }
    if (!iszero(min_elementsq(arr1, 4) - 1.0)) {
        printf("the test failed: min_elementsq({3.0, 1.0, 4.0, 1.5}) != 1.0\n");
        return 1;
    }
    if (!iszero(min_elementsq(arr2, 4) - 0.0)) {
        printf("the test failed: min_elementsq({-5.0, 2.0, 0.0, -3.0}) != 0.0\n");
        return 1;
    }
    printf("tests are successful!\n");
}

int main() {
    tests();
    int n;
    printf("input n, size of an array: ");
    scanf("%d", &n);
    double result;
    double* a = malloc(n * sizeof(double));
    input_array(a, n);
    result = min_element(a, n)*min_element(a, n) - min_elementsq(a, n);
    printf("the result is: %lf\n", result);
    free(a);
}