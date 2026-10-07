#include <stdio.h>
#define SIZE 5

void input_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int main() {
    int a[SIZE];
    input_array(a, SIZE);
    int max_el = a[0];
    for (int i = 1; i < SIZE; i++) {
        if (a[i] > max_el) {
            max_el = a[i];
        }
    } printf("maximal element is %d\n", max_el);
}