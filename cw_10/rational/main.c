#include <stdio.h>
#include <stdbool.h>
#include "rational.h"
int main() {
    Rational test1[]={
        {1, 2},
        {1, 4}
    };
    Rational test2[]={
        {3, 2},
        {3, 4}
    };
    Rational test3[]={
        {1, 1},
        {5, 5}
    };
    Rational test4[]={
        {2, 3},
        {3, 2}
    };
    printf("printRational test:\n");
    printRational(test1[0]);
    printRational(test2[0]);

    printf("sum_rational test:\n");
    sum_rational(test1[0], test1[1]);
    sum_rational(test2[0], test2[1]);
    printf("sum_rational waited results: test1=3/4, test2=9/4 \n");

    printf("multiply_rational test:\n");
    multiply_rational(test3[0], test3[1]);
    multiply_rational(test4[0], test4[1]);
    printf("multiply_rational waited results: test3=1, test2=1 \n");

    printf("compare_rational test:\n");
    if (compare_rational(test3[0], test3[1])) {
        printf("The first rational number is greater than the second.\n");
    }
    else {
        printf("The first rational number is less or equal than the second.\n");
    }
    if (compare_rational(test4[0], test4[1])) {
        printf("The first rational number is greater than the second.\n");
    }
    else {
        printf("The first rational number is less or equal than the second.\n");
    }
    printf("compare_rational waited results: test3=The first rational number is less or equal than the second\n");
    printf("compare_rational waited results: test4=The first rational number is less or equal than the second\n");
    return 0;
}