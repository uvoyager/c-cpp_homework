#include <stdio.h>

int main() {
    int x, y, z;
    printf("input three integers: ");
    scanf("%d, %d, %d", &x, &y, &z);
    int m = x*y*z;
    printf("%d*%d*%d = %d\n", x, y, z, m);
}