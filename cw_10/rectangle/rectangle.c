#include <stdio.h>
#include <stdbool.h>
#include "rectangle.h"

void printPoint(const TPOINT *p) {
    printf("(%g, %g)", p->x, p->y);
}
bool inputPoint(TPOINT *p) {
    printf("x, y = ");
    int r=scanf("%lf %lf", &p->x, &p->y);
    return r==2;
}

void printRect(const RECT *p) {
    printf("[");
    printPoint(&p->A);
    printf(" ");
    printPoint(&p->B);
    printf("]");
}
bool inputRect(RECT *p) {
    if (!inputPoint(&p->A)) return false;
    if (!inputPoint(&p->B)) return false;
    return true;
}