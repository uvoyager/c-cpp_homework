//fibonnacci

#include <stdio.h>

unsigned long long fib(int n) {
    unsigned long long F0, F1, F;
    int k;
    F0 = 1ul;
    F1 = 1ul;
    for (n<=k; k++;) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    } return F;
}

unsigned long long max_fib(int n) {
    unsigned long long F0, F1, F;
    int k;
    F0 = 1ul;
    F1 = 1ul;
    while (n>=k) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
        k++;
    } return F;
}

int main() {
    double n;
    printf("enter n: ");
    scanf("%lf", &n);
    printf("the largest F is: %llu\n", max_fib(n));

}