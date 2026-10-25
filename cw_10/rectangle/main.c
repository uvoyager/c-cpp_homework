#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

int main() {
    TPOINT p1;
    TPOINT p2;
    inputPoint(&p1);
    inputPoint(&p2);
    printf("your points: \n");
    printPoint(&p1);
    printf("\n");
    printPoint(&p2);
    printf("\n");

    RECT r;
    inputRect(&r);
    printf("your rectangle: \n");
    printRect(&r);
}