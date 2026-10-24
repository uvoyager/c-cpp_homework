#include <stdio.h>
#include <stdlib.h>

double* create_array(int n) {
    double* array = malloc(n * sizeof(double));
    if (array == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("el[%d] = ", i);
        scanf("%lf", &array[i]);
    }
    printf("\n");
    return array;
}

void delete_array(double* array) {
    if (array != NULL) {
        free(array);
        printf("memory successfully freed\n");
    } else {
        printf("something went wrong: pointer is NULL\n");
    }
}

void print_array(const double* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf, ", array[i]);
    }
    printf("\n");
}

int main() {
    int n,m;
    printf("input n and m (sizes of the arrays): ");
    if (scanf("%d %d", &n, &m) != 2) {
        printf("invalid input\n");
        return EXIT_FAILURE;
    }
    double* array_n = create_array(n);
    double* array_m = create_array(m);
    if (n==m) {
        double* result=malloc(n * sizeof(double));
        if (result == NULL) {
            printf("memory allocation failed for result\n");
            delete_array(array_n);
            delete_array(array_m);
            return EXIT_FAILURE;
        }
        for (int i = 0; i < n; i++) {
            result[i] = array_n[i]-array_m[i];
        }
        printf("the result array is:\n");
        print_array(result,n);
        delete_array(result);
    }
    else{printf("n != m => cannot do the substraction\n");}
    delete_array(array_n);
    delete_array(array_m);
}