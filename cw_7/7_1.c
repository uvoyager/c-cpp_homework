#include <stdio.h>
#define SIZE 5

void input_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int main() {
    double n;
    int a[SIZE], k = 0;
    printf("enter n: ");
    scanf("%lf", &n);
    input_array(a, SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (a[i] < n) {
            k +=1;
        }
    } printf("number of elements smaller than %lf: %d", n, k);
}