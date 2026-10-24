#include <stdio.h>
#include <stdlib.h>

double** input_matrix(int n) {
    double** matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    if (matrix == NULL) {
        printf("memory allocation failed for matrix.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("el[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

double* create_array(int n) {
    double* array = malloc(n*n * sizeof(double));
    if (array == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }
    for (int i = 0; i < n*n; i++) {
        printf("el[%d] = ", i);
        scanf("%lf", &array[i]);
    }
    printf("\n");
    return array;
}

void delete_matrix(double** matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        printf("memory successfully freed.\n");
    }
    else {
        printf("something went wrong: pointer id NULL.\n");
    }
}

void delete_array(double* array) {
    if (array != NULL) {
        free(array);
        printf("memory successfully freed\n");
    } else {
        printf("something went wrong: pointer is NULL\n");
    }
}


double** matrix_mult(double** matrix1, double** matrix2, int n, int m) {         //n, m are numbers of rows&columns of matrix1 and matrix2 respectively
    if (n==m) {
        double** result = malloc(n * sizeof(double*));
        for (int i = 0; i < n; i++) {
            result[i] = (double*)malloc(n * sizeof(double));
        }
        if (result == NULL) {
            printf("memory allocation failed for matrix.\n");
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = 0.0;
                for (int k = 0; k < n; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("the result of matrix multiplication is:\n");
        return result;
    }
    else {
        printf("n != m => cannot multiply matrices.\n");
        return 0;
    }
}

double* array_mult(double* array1, double* array2, int n, int m) {
    if (n==m) {                                                             //n, m are numbers of rows&columns of matrix1 and matrix2 respectively
        double* result = malloc(n*n * sizeof(double));
        if (result == NULL) {
            printf("memory allocation failed for matrix.\n");
            return NULL;
        }
        for (int i = 0; i < n; i++) {
            for  (int j = 0; j < n; j++) {
                double summ = 0.0;
                for (int k = 0; k < n; k++) {
                    summ += array1[i*n+k]*array2[k*n+j];
                }
                result[i*n+j] = summ;
            }
        }
        printf("the result of matrix multiplication is:\n");
        return result;
    }
    else {
        printf("n != m => cannot multiply matrices.\n");
        return 0;
    }
}

void print_array(const double* array, int n) {
    for (int i = 0; i < n*n; i++) {
        printf("%lf, ", array[i]);
    }
    printf("\n");
}

void print_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

int main() {
    int n, m;
    printf("input size of matrix 1: ");
    scanf("%d", &n);
    printf("input size of matrix 2: ");
    scanf("%d", &m);

    //part for matrices nxn//
    double** matrix1 = input_matrix(n);
    double** matrix2 = input_matrix(m);
    double** result = matrix_mult(matrix1, matrix2, n, m);
    print_matrix(result, n);
    delete_matrix(matrix1, n);
    delete_matrix(matrix2, m);
    delete_matrix(result, n);

    //part  for matrices represented like an array with n^2 elements
    double* array1 = create_array(n);
    double* array2 = create_array(m);
    double* result_array = array_mult(array1, array2, n, m);
    print_array(result_array, n);
    delete_array(array1);
    delete_array(array2);
    delete_array(result_array);
}