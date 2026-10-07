#include <stdio.h>

int main() {
    int a[4] = {5, 112, 4, 3};
    for (int i = 3; i > -1; i--) {
        printf("%d ", a[i]);
    }
}