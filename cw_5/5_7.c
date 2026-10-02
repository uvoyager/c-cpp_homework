#include <stdio.h>
#include<math.h>

double sum_of_smth(int n) {
    double a1 = 0.0, a2 = 1.0, b1 = 1.0, b2 = 0.0, k = 3, ak, bk;
    double sum = 1.0/(a1+b1) + 2.0/(a2+b2);
    for (; k<=n; k++) {
        bk = b1+a1;
        ak = a1/k + a1*bk;
        a1 = a2;
        a2 = ak;
        b1 = b2;
        b2 = bk;
        sum += pow(2, k)/(ak+bk);
    }return sum;
}

int main() {
    int n;
    printf("input n: ");
    scanf("%d", &n);
    printf("sum_of_smth = %lf\n", sum_of_smth(n));
}
