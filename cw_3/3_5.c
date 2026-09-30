#include <stdio.h>

int main() {
    long double x, y;
    printf("input 2 float numbers: ");
    scanf("%Lf %Lf", &x, &y);
    if (x>y) {
        printf("%Lf > %Lf\n", x, y);
    }
    else if (x<y) {
        printf("%Lf < %Lf\n", x, y);
    }
    else {printf("%Lf = %Lf\n", x, y);}
}