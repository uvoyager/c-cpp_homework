#include <stdio.h>
#include "par.h"

int main() {
    TPOINT p1;
    TPOINT p2;
    TPOINT p3;
    input_point(&p1);
    input_point(&p2);
    input_point(&p3);
    printf("your points: \n");
    print_point(&p1);
    printf("\n");
    print_point(&p2);
    printf("\n");
    print_point(&p3);
    printf("\n");

    RECTPAR r;
    input_rectpar(&r);
    printf("your rectangle: \n");
    print_rectpar(&r);
}