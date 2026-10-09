#include <stdio.h>
#define SIZE 100

void input_matrix(int row, int col, double matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("el[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

int main() {
    double A[SIZE][SIZE], sum = 0.0;
    int N, M, k, count = 0;
    printf("input k: ");
    scanf("%d", &k);
    printf("input the number of rows and columns: ");
    scanf("%d %d", &N, &M);
    if (M <= 0 || N <= 0 || M > SIZE || N > SIZE) {
        printf("the number of rows or columns is invalid, try again.\n");
        return 0;
    }
    input_matrix(N, M, A);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i-j == k) {
                sum += A[i][j];
                count++;
            }
        }
    }
    if (count == 0) {
        printf("0");
    }
    else {
        printf("the sum of elements is: %lf\n", sum);
    }
}