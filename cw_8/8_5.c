#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool iszero(double val) {
    return fabs(val) < 1e-9;
}

void input_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <N; j++) {
            printf("el[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

void transponate_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int tests() {
    printf("tests...\n");
    {
        double raw_matrix[1][1] = { {5.5} };
        double* m[1] = { raw_matrix[0] }; // Pointer mapping to mock double**
        transponate_matrix(m, 1);
        if (!iszero(m[0][0] - 5.5)) {
            printf("the test failed: 1x1 matrix changed value\n");
            return 1;
        }
    }
    {
        double raw_matrix[2][2] = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        double* m[2] = { raw_matrix[0], raw_matrix[1] };
        transponate_matrix(m, 2);
        if (!iszero(m[0][1] - 3.0)) {
            printf("the test failed: 2x2 matrix m[0][1] != 3.0\n");
            return 1;
        }
        if (!iszero(m[1][0] - 2.0)) {
            printf("the test failed: 2x2 matrix m[1][0] != 2.0\n");
            return 1;
        }
    }
        double raw_matrix[3][3] = {
            {1.0, 0.0, 2.0},
            {0.0, 4.0, 5.0},
            {2.0, 5.0, 6.0}
        };
        double* m[3] = { raw_matrix[0], raw_matrix[1], raw_matrix[2] };
        transponate_matrix(m, 3);
        if (!iszero(m[0][2] - 2.0) || !iszero(m[2][0] - 2.0)) {
            printf("the test failed: Symmetric 3x3 matrix changed values\n");
            return 1;
        }
        if (!iszero(m[1][2] - 5.0) || !iszero(m[2][1] - 5.0)) {
            printf("the test failed: Symmetric 3x3 matrix changed values\n");
            return 1;
        }
    printf("All tests passed successfully!\n");
    return 0;
}

int main() {
    tests();
    int N;
    printf("enter N (number of rows and columns): ");
    scanf("%d", &N);
    double** matrix = malloc(N * sizeof(double*));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns at row %d.\n", i);
            return 1;
        }
    }
    input_matrix(matrix, N);
    printf("your matrix is: \n");
    print_matrix(matrix, N);
    transponate_matrix(matrix, N);
    printf("transponated matrix is: \n");
    print_matrix(matrix, N);
}