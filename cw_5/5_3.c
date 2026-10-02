#include <stdio.h>
int kollatz(int a, int n) {
    int a0 = a;
    int a1;
    for (int k = 0, k0 = k; k++;) {
        if (a0%2 == 0) {
            a = a0/2;
            a0 = a;
        } else {
            a = a0*3+1;
            a0 = a;
        }
    }return a;
}

int count_till_one(int a) {
    int count = 1, b = a;
    while (b != 1) {
        b = kollatz(a, count);
        count ++;
    } return count;
}

int main() {
    for (int i = 1; i <= 1000;) {
        printf("%d\n", count_till_one(i));
        i++;
    }
}