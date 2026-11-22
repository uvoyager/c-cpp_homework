#include <iostream>
#include <cmath>
#include "ratio.h"

Ratio minRatio ( const Ratio* arr, int n) {
    Ratio min_r = arr[0];
    for ( int i = 1; i < n; i++ ) {
        if (min_r.less(arr[i])) { // min_r < arr[i] if overload <
            min_r = arr[i]; // operator =
        }
    }
    return min_r;
}

Ratio series_result( ) {
    double eps = 0.01;
    int n = 1;
    int sign = 1;
    Ratio sum = Ratio (0, 1);
    while ( abs( 1.0/(n*n) ) >= eps ) {
        sum = sum + Ratio( sign, n*n );
        sign = -sign;
        n++;
    }
    return sum;
}

int main () {

    Ratio a( 1, 2 ), b( 1, 3 );
    Ratio c, d, f, e;

    std::cout << a << std::endl;
    /*Ratio a, b, c;

    a.input();
    b.input(); */

    c = a.add( b );
    d = a.subtraction( b );
    f = a.mult( b );
    e = a.division( b );

    std::cout << "add: " << std::endl;
    c.show();
    std::cout << "sub: " << std::endl;
    d.show();
    std::cout << "mult: " << std::endl;
    f.show();
    std::cout << "div: " << std::endl;
    e.show();

    unsigned x = Ratio :: ratio_gcd(3, 6);
    std::cout << "gcd(3, 6) = " << x << std::endl;

    int n;
    std::cout << "input n: ";
    std::cin >> n;

    Ratio* ar = new Ratio[n];

    for ( int i = 0; i < n; i++ ) {
        std:: cin >> ar[i];
    }
    Ratio min_r = minRatio( ar, n );
    std::cout << min_r << std::endl;

    delete[] ar;

    Ratio result = series_result();
    double res = (double)result.getNom() / result.getDen();
    double actual_num = (M_PI * M_PI) / 12.0;
    std::cout << "func series_result result: " << result << " " << res<< std::endl;
    std::cout << "actual number: " << actual_num << std::endl;
}