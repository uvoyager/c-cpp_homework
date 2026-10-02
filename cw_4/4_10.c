#include <stdio.h>
#include <float.h>

int main() {
    float a = 1.0F;
    do {
        a/2.0F;
    }while (a+1.0F != 1.0F);
    printf("the smallest float value of a such as 1.0+a == 1.0 is %g %g\n ", a, FLT_EPSILON);

    double a1 = 1.0;
    do {
        a1/2.0;
    }while (a1+1.0 != 1.0);
    printf("the smallest double value of a such as 1.0+a1 == 1.0 is %g %g\n ", a1, DBL_EPSILON);

    long double a2 = 1.0L;
    do {
        a2/2.0L;
    }while (a2+1.0L != 1.0L);
    printf("the smallest value of a such as 1.0+a2 == 1.0 is %lg %lg\n ", a2, LDBL_EPSILON);
}