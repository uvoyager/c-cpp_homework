#ifndef CLIONPROJECTS_POLY_H
#define CLIONPROJECTS_POLY_H
#include <iostream>
#include <fstream>


class Poly {
    unsigned n;
    double* a;
public:
    Poly();

    Poly( unsigned n );

    Poly( unsigned n, double* ptr_a );

    ~Poly();

    Poly ( const Poly& p );

    Poly& operator= ( const Poly& p ) {
        if ( this != &p ) {
            delete[] a;
            n = p.n;
            a = new double[n];
            for ( unsigned i = 0; i < n; i++ ) {
                a[i] = p.a[i];
            }
        }
        return *this;
    }
    double value( double x );
    void coeff( unsigned index, double val );

    void input();
    void show();

    friend int write_to_file( const Poly& p, const char* filename ) {
        std::ofstream file( filename );
        if ( !file.is_open() ) {
            return -1;
        }
        file << p.n << "\n";
        file.close();
        return 0;
    }
};


#endif //CLIONPROJECTS_POLY_H
