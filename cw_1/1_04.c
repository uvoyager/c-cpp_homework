#include <stdio.h>
#include <math.h>

int main() {
    double m1 = 3;
    double m2 = 1.5;
    double r = 0.36;
    double gamma = 6.673*pow(10, -11);
    double F = (gamma*m1*m2)/r*r;
    printf("F = %e\n", F);
}