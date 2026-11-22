#include "poly.h"
#include <cstring>
#include <cmath>

Poly::Poly() {
    n = 0;
    a = nullptr;
}

Poly::Poly ( unsigned m ) {
    n = m;
    a = new double[n];
}

Poly::Poly ( unsigned n, double* ptr_a ) {
    this -> n = n;
    a = new double[n];
    memmove(a, ptr_a, n * sizeof(*a));
}

Poly::~Poly () {
    delete[] a;
}

Poly :: Poly ( const Poly& p ) {
    n = p.n;
    if ( n == 0 ) {
        a = nullptr;
    } else {
        a = new double[n];
        std::memcpy( a, p.a, n * sizeof( *a ) );
    }
}

void Poly::input() {
    if ( n == 0 ) return;
    std::cout << "Input coefficients: ";
    for ( unsigned i = 0; i < n; i++ ) {
        std::cin >> a[i];
    }
}

void Poly::coeff( unsigned index, double val ) {
    if ( index >= n ) {
        std::cerr << "Index out of range!" << std::endl;
        return;
    }
    a[index] = val;
}

double Poly::value( double x ) {
    double res = 0.0;
    for ( unsigned i = 0; i < n; i++ ) {
        res += a[i] * std::pow( x, i );
    }
    return res;
}

void Poly::show() {
    if ( n == 0 ) {
        std::cout << "0" << std::endl;
        return;
    }
    for ( unsigned i = 0; i < n; i++ ) {
        std::cout << a[i] << "*x^" << i;
        if ( i < n - 1 ) {
            std::cout << " + ";
        }
    }
    std::cout << "\n";
}