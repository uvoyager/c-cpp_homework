#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("Input float point number x: ");
    scanf("%lf", &x);

    int i = (int) x;
    printf("using int: %d, using trunc(): %lf\n", i, trunc(x));
    double dec = x-i;
    printf("using float: %lf, using modf(): %lf\n", fabs(dec), fabs(modf(x,&dec)));
    int s, l;
    if (x>=0) {
        s = i;
        l = (x==i)? i : i+1;
    } else {
        s = (x==i)? i: i-1;
        l = i;
    }
    printf("without <math.h> :  %d, using floor(): %lf\n", s, floor(x));
    printf("without <math.h>: %d, using ceil(): %lf", l, ceil(x));

}