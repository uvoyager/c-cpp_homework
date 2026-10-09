#include <stdio.h>
#define SIZE 25

void input_matrix_row_by_row(int row, int col, double matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        printf("input matrix row %d with %d elements:\n", i, col);
        while (scanf("%lf", &matrix[i][col]) != EOF) {
            matrix[i][col] = 1;
        }
    }
}

void print_matrix(int row, int col, double matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }printf("\n");
}

int main() {
    double matrix[SIZE][SIZE];
    int n, m;
    printf("input the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    if (m <= 0 || n <= 0 || m > SIZE || n > SIZE) {
        printf("the number of rows or columns is invalid, try again.\n");
        return 0;
    }
    input_matrix_row_by_row(n, m, matrix);
    printf("the matrix is:\n");
    print_matrix(n, m, matrix);
}