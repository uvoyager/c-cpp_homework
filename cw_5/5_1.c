#include <stdio.h>

int harm_max(double a) {
    int i=1;
    double s = 0;
    while (s < a) {
        s += 1.0/i;
        i++;
    }
    return i;
}


int harm_sum(double a) {
    int i=1;
    double s = 0.0;
    while (s <= a) {
        s += 1.0/i;
        i++;
    }
    return i;
}

int main() {
    double a;
    printf("enter a: ");
    scanf("%lf", &a);
    printf("the largest i is: %d", harm_sum(a));
}