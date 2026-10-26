#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>
#define SIZE 100

int input_to_zero(int* array) {
    int i = 0;
    do {
        printf("input element %d or 0 to end input: ", i+1);
        int scanf_result = scanf("%d", &array[i]);
        if (scanf_result != true) {
            printf("invalid input\n");
            return i;
        }
        if (array[i] == 0) {
            return i;
        }
        if (i>=SIZE) {
            return i;
        }
        i++;
    }while(true);
}

void print_array(const int* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

bool is_sqrt(int x) {
    if (x<0) return false;
    int root = (int) sqrt(x+0.5);
    return x==root*root;
}

bool is_cube(int x) {
    int root = (int)cbrt(x+0.5);
    return root*root*root==x;
}

void print_sqrt_and_cube(const int* array, int n) {
    int sqrt_count=0;
    int cubic_count=0;
    for (int i = 0; i < n; i++) {
        if (is_sqrt(array[i])) {
            printf("%d is perfect square\n", array[i]);
            sqrt_count++;
        }
        if (is_cube(array[i])) {
            printf("%d is perfect cube\n", array[i]);
            cubic_count++;
        }
    }
    printf("number of perfect squares: %d\n", sqrt_count);
    printf("number of perfect cubes: %d\n", cubic_count);
}

int main() {
    int* array=malloc(SIZE*sizeof(int));
    if (array == NULL) {
        printf("memory allocation failed\n");
        return EXIT_FAILURE;
    }
    int n = input_to_zero(array);
    printf("the elements are: ");
    print_array(array, n);
    print_sqrt_and_cube(array, n);
    free(array);
    return EXIT_SUCCESS;
}