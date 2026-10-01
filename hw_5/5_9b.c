#include <stdio.h>

double function_of_three(int i) {
    if (i<3) {
        return 1.0;
    }
    double v0 = 1.0;
    double v1 = 1.0;
    double v2 = 1.0;
    double vk = 1.0;
    for (int k = 3; k<=i; k++) {
        vk = (k+4)*(v2-1)+(k+5)*v0;
        v0 = v1; v1 = v2; v2 = vk;
    }return vk;
}

int main() {
    int i;
    printf("input int i: ");
    scanf("%d", &i);
    printf("function_of_three(%d) = %.0lf", i, function_of_three(i));
}