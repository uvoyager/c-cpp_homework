#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "rational.h"

int nsd(int a, int b) {
    int temp;
    while (b!=0) {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void printRational(Rational r) {
    printf("your rational number is: %d/%u\n", r.num, r.den);
}

void reduce(Rational* r) {
    int g = nsd(r->num, (int)r->den);
    while (g!=1) {
        r->num/=g;
        r->den/=g;
        g = nsd(r->num, (int)r->den);
    }
}

bool inputRational(Rational* r) {
    printf("input numerator: ");
    if (scanf("%d", &r->num) != 1) {
        return false;
    }
    printf("input denominator: ");
    if (scanf("%u", &r->den) != 1 || r->den == 0) {
        printf("Error: Denominator cannot be zero.\n");
        return false;
    }
    reduce(r);
    return true;
}

void sum_rational(Rational r1, Rational r2) {
    int sum_num;
    unsigned int sum_den;
    if (r1.den == r2.den) {
        sum_num=r1.num+r2.num;
        sum_den=r1.den;
    }
    else {
        sum_num=r1.num*r2.den+r2.num*r1.den;
        sum_den=r1.den*r2.den;
    }
    Rational r={sum_num,sum_den};
    reduce(&r);
    printRational(r);
}

void multiply_rational(Rational r1, Rational r2) {
    Rational r;
    r.num=r1.num*r2.num;
    r.den=r1.den*r2.den;
    reduce(&r);
    printRational(r);
}

bool compare_rational(Rational r1, Rational r2) {
    long long x1=r1.num*r2.den;
    long long x2=r2.num*r1.den;
    return x1>x2;
}