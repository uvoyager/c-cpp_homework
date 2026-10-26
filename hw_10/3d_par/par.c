#include <stdio.h>
#include <stdbool.h>
#include "par.h"

void print_point(const TPOINT *p) {
    printf("(%g, %g, %g)", p->x, p->y, p->z);
}
bool input_point(TPOINT *p) {
    printf("x, y, z = ");
    int r = scanf("%lf %lf %lf", &p->x, &p->y, &p->z);
    return r == 3;
}

void print_rectpar(const RECTPAR *p) {
    printf("[");
    print_point(&p->a);
    printf(" ");
    print_point(&p->b);
    printf(" ");
    print_point(&p->c);
    printf("]");
}
bool input_rectpar(RECTPAR *p) {
    if (!input_point(&p->a)) return false;
    if (!input_point(&p->b)) return false;
    if (!input_point(&p->c)) return false;
    return true;
}