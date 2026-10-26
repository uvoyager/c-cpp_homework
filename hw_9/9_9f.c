#include <stdio.h>
#include <stdlib.h>

void print_matrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

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

double** add_rows(double** matrix, int n, int m, int k) {
    if (matrix == NULL) {
        printf("given matrix is NULL\n");
        return 0;
    }
    double** result = malloc((n+k) * sizeof(double*));
    for (int i = 0; i < n+k; i++) {
        result[i] = (double*)malloc(m*sizeof(double));
    }
    if (matrix == NULL) {
        printf("memory allocation failed for matrix.\n");
        return 0;
    }
    for (int i = 0; i < n+k; i++) {
        for (int j = 0; j < m; j++) {
            if (i < m) {
                result[i][j] = matrix[i][j];
            }
            else if (i < m+k) {
                result[i][j] = 7.7;
            }
            else {
                result[i][j] = matrix[i-k][j];
            }
        }
    }
    return result;
}

int main() {
    int n, m, k;
    printf("input n, m dimension of matrix: ");
    scanf("%d %d", &n, &m);
    if (n < m) {
        printf("number of columns is greater than number of rows. cannot follow through with required function.\n");
        return 0;
    }

    double** matrix = input_matrix(n, m);
    printf("input number of rows you want to add: ");
    scanf("%d", &k);
    double** res = add_rows(matrix, n, m, k);

    printf("\nnew matrix is: \n");
    print_matrix(res, n+k, m);
}