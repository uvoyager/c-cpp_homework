#include <stdio.h>

void print_matrix(int N, double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", matrix[i][j]);
        }printf("\n");
    }
}

int main() {
    int i, j;
    double a;
    double matrix[3][3] = {{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("input indexes i and j: ");
    scanf("%d %d" , &i, &j);
    if (i > 2 || j > 2) {
        printf("indexes are invalid, try again.\n");
        return 0;
    }
    printf("input float a: ");
    scanf("%lf", &a);
    matrix[i][j] = a;
    print_matrix(3, matrix);
}