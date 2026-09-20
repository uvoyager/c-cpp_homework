#include <stdio.h>

int tests_eReLu(void);

int main () {
    if (tests_eReLu() == 0) {
        printf("everything works correctly\n");
    } else {
        printf("test failed. something went wrong\n");
    }
}