#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

void input_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("el[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double print_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

double turn_matrix(double** matrix, int N) {
    double** matrix2 = malloc(N * sizeof(double*));
    for (int i = 0; i<N; i++) {
        matrix2[i] = malloc(N * sizeof(double));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix2[j][N-i-1] = matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = matrix2[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
}

bool iszero(double x) {
    return fabs(x) < 1e-6;
}

int tests() {
    printf("tests...\n");
    {double matrix[1][1] = { {42.0} };
        double* m[1] = {matrix[0] };
        turn_matrix(m, 1);

        if (!iszero(m[0][0] - 42.0)) {
            printf("the test failed: 1x1 matrix changed value\n");
            return 1;
        }
    }
    {double matrix[2][2] = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        double* m[2] = {matrix[0], matrix[1] };
        turn_matrix(m, 2);
        if (!iszero(m[0][0] - 3.0)) {
            printf("the test failed: 2x2 matrix m[0][0] != 3.0\n");
            return 1;
        }
        if (!iszero(m[0][1] - 1.0)) {
            printf("the test failed: 2x2 matrix m[0][1] != 1.0\n");
            return 1;
        }
        if (!iszero(m[1][0] - 4.0)) {
            printf("the test failed: 2x2 matrix m[1][0] != 4.0\n");
            return 1;
        }
        if (!iszero(m[1][1] - 2.0)) {
            printf("the test failed: 2x2 matrix m[1][1] != 2.0\n");
            return 1;
        }
    }
    {double matrix[3][3] = {
            {1.0, 2.0, 3.0},
            {4.0, 5.0, 6.0},
            {7.0, 8.0, 9.0}
        };
        double* m[3] = {matrix[0], matrix[1], matrix[2] };
        turn_matrix(m, 3);
        if (!iszero(m[0][0] - 7.0)) {
            printf("the test failed: 3x3 matrix m[0][0] != 7.0\n");
            return 1;
        }
        if (!iszero(m[0][2] - 1.0)) {
            printf("the test failed: 3x3 matrix m[0][2] != 1.0\n");
            return 1;
        }
        if (!iszero(m[1][1] - 5.0)) {
            printf("the test failed: 3x3 matrix m[1][1] != 5.0\n");
            return 1;
        }
        if (!iszero(m[2][0] - 9.0)) {
            printf("the test failed: 3x3 matrix m[2][0] != 9.0\n");
            return 1;
        }
        if (!iszero(m[2][2] - 3.0)) {
            printf("the test failed: 3x3 matrix m[2][2] != 3.0\n");
            return 1;
        }
    }

    printf("All tests passed successfully!\n");
    return 0;
}

int main() {
    tests();
    int n;
    printf("input the size of matrix n (n<=50): ");
    scanf("%d", &n);
    if ( n <= 0 || n > 50) {
        printf("Invalid dimension matrix format.\n");
        return 1;
    }
    int size = 2*n;
    double** matrix = malloc(size * sizeof(double*));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns at row %d.\n", i);
            return 1;
        }
    }
    input_matrix(matrix, size);
    printf(" your matrix is: \n");
    print_matrix(matrix, size);
    turn_matrix(matrix, size);
    printf("turned matrix is: \n");
    print_matrix(matrix, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}