#include "ratio.h"
#include <iostream>
#include <ostream>
#include <cstdlib>

void Ratio::show() {
    std::cout << nom << "/" << den << std::endl;
}

int Ratio::input() {
    std:: cout << "Input nom and den: " << std::endl;
    int a;
    unsigned b;
    if (std::cin >> a ) {
        setNom( a );
    }
    else {
        std::cerr << "incorrect nom";
        return -1;
    }
    if (std::cin >> b ) {
        setDen( b );
    }
    else {
        std:: cerr << "incorrect den";
        return -1;
    }
    return EXIT_SUCCESS;
}

Ratio Ratio::add ( Ratio second ) {
    // third = first.add( second )
    Ratio x;
    x.nom = nom * (int)second.den + (int)den * second.nom;
    x.den = den * second.den;
    x.reduce();
    return x;
}

Ratio Ratio::mult ( Ratio second ) {
    Ratio x;
    x.nom = nom * second.nom;
    x.den = den * second.den;
    x.reduce();
    return x;
}

Ratio Ratio::subtraction ( Ratio second ) {
    Ratio x;
    x.nom = nom * (int)second.den - (int)den * second.nom;
    x.den = den * second.den;
    x.reduce();
    return x;
}

Ratio Ratio::division ( Ratio second ) {
    Ratio x;
    if ( second.nom == 0 ) {
        std::cerr << "ERROR: Division by zero!" << std::endl;
        return Ratio();
    }
    x.nom = nom * (int)second.den;
    x.den = den * second.nom;
    x.reduce();
    return x;
}

unsigned Ratio::ratio_gcd ( unsigned n, unsigned m ) {
    if ( n== 0 || m == 0 ) return n + m;
    return ratio_gcd ( m, n % m );
}