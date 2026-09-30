#include <stdio.h>

int first_pos(void) {
    int x0 = -99,  x1 = -99, x2 = -99, x = 0, k = 3;
    while (x <= 0) {
        x = x0+x2+100;
        x0 = x1;
        x1 = x2;
        x2 = x;
        k++;
    }return k;
}

//needs main function to call first_pos();