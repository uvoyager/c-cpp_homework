# include <stdio.h>

double e(double x) {
    double x_2 = 2*x;
    double j = x_2*x_2;
    return j*j + j*x_2 + x_2 + 1;
}

int main() {
    double x;
    printf("input x: ");
    scanf("%lf", &x);
    printf("e(%lf) = %lf\n",x, e(x));
}