#include <stdio.h>
#include <stdlib.h>

#include "polynome.h"

bool inputPolynomial(Polynomial* p) {
    printf("input power of polynomial: ");
    if (scanf("%d", &p->power) != 1) {
        return false;
    }
    p->coefficients = malloc((p->power + 1) * sizeof(double));
    if (p->coefficients == NULL) {
        return false;
    }
    printf("input coefficients: ");
    for (int i = 0; i <= p->power; i++) {
        if (scanf("%lf", &p->coefficients[i]) != 1) {
            return false;
        }
    }
    return true;
}
void printPolynomial(Polynomial p) {
    printf("power of the polynomial: %d\n", p.power);
    printf("coefficients of this polynomial:\n");
    for (int i = 0; i <=p.power; i++) {
        printf("%lf\n", p.coefficients[i]);
    }
}