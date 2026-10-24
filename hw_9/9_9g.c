#include <stdio.h>
#include <stdlib.h>

double** input_matrix(int n, int m) {
    double** matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
    }
    if (matrix == NULL) {
        printf("memory allocation failed for matrix.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("el[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

double** add_column(double** matrix, int n, int m) {
    double** result = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc((m+1)*sizeof(double));
    }
    if (matrix == NULL) {
        printf("memory allocation failed for matrix.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m+1; j++) {
            if (j<m) {
                result[i][j] = matrix[i][j];
            }
            else{result[i][j] = 7.7;}
        }
    }
    return result;
}

void print_matrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

int main() {
    int n, m;
    printf("input n, m dimension of matrix: ");
    scanf("%d %d", &n, &m);
    double** matrix = input_matrix(n, m);
    printf("you have entered the matrix:\n");
    print_matrix(matrix, n, m);
    printf("matrix with an added last column:\n");
    double** new_matrix = add_column(matrix, n, m);
    print_matrix(new_matrix, n, m+1);
}