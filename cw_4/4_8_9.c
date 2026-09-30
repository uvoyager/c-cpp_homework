#include <stdio.h>

int main() {
    unsigned long long m, power_k = 1;
    printf("input a value of m: ");
    scanf("%llu", &m);
    int k = 0;

    while (power_k<m) {
        power_k *= 4;
        k++;
    }
    printf("4^%d < %llu\n", k-1, m);
    printf("4^%d >= %llu\n", k, m);

    power_k = 0;
    k = 0;
    do {
        power_k /= 4;
    } while (power_k >=m);
    printf("4^%d >= %llu\n", k+1, m);
    printf("4^%d < %llu\n", k, m);
}