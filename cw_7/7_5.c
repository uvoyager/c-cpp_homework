#include <stdio.h>
#define SIZE 50

int input_array(int a[], int size) {
    int nl = 0;
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            break;
        }nl++;
    }return nl;
}

int even_elements(int a[], int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0 && a[i] != 0) {
            k++;
        }
    }return k;
}

int odd_elements(int a[], int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            k++;
        }
    }return k;
}

int main() {
    int a[SIZE];
    int nl = input_array(a, SIZE);
    printf("number of even elements is : %d\n", even_elements(a, nl));
    printf("number of odd elements is : %d\n", odd_elements(a, nl));
}