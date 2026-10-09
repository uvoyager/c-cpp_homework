#include <stdio.h>
#define SIZE 20

void input_matrix(int row, int col, double matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("el[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(int row, int col, double matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

int main() {
    int row, col;
    double matrix[SIZE][SIZE];
    printf("enter number of rows and columns respectively: ");
    scanf("%d %d", &row, &col);
    if (row>20 || col>20 || row<=0 || col<=0) {
        printf("you entered invalid number of rows or columns.\n");
        return 0;
    }
    input_matrix(row, col, matrix);
    print_matrix(row, col, matrix);
}