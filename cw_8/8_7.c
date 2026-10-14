#include <stdio.h>
#include <stdlib.h>

void input_matrix(double** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("el[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double determinant(double** A, int n) {
    if (n == 1) {
        return A[0][0];
    }
    if (n == 2) {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }

    double sum = 0;
    double** al_major = malloc((n - 1) * sizeof(double*));
    for (int i = 0; i < n - 1; i++) {
        al_major[i] = malloc((n - 1) * sizeof(double));
    }
    for (int j = 0; j < n; j++) {
        int major_i = 0;
        for (int r = 1; r < n; r++) {
            int major_j = 0;
            for (int c = 0; c < n; c++) {
                if (c == j) {
                    continue;
                }
                al_major[major_i][major_j] = A[r][c];
                major_j++;
            }
            major_i++;
        }
        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        sum += sign * A[0][j] * determinant(al_major, n - 1);
    }
    for (int i = 0; i < n - 1; i++) {
        free(al_major[i]);
    }
    free(al_major);

    return sum;
}

int main() {
    int n;
    printf("input the size of matrix n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid dimension matrix format.\n");
        return 1;
    }
    double** matrix = malloc(n * sizeof(double*));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns at row %d.\n", i);
            return 1;
        }
    }
    input_matrix(matrix, n);
    double det = determinant(matrix, n);
    printf("the determinant of A is: %lf\n", det);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
