#ifndef CLIONPROJECTS_POLYNOME_H
#define CLIONPROJECTS_POLYNOME_H
#include <stdbool.h>

typedef struct Polynomial {
    int power;
    double *coefficients;
} Polynomial;

extern bool inputPolynomial(Polynomial* p);
extern void printPolynomial(Polynomial p);
#endif //CLIONPROJECTS_POLYNOME_H
