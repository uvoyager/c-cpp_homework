#ifndef CLIONPROJECTS_RATIO_H
#define CLIONPROJECTS_RATIO_H

#include <iostream>
#include <cmath>


class Ratio {
    // private
    int nom;
    unsigned den;

    void reduce() {
        unsigned gcd_ = ratio_gcd( std::abs( nom ), den );
        nom /= ( int )gcd_;
        den /= gcd_;
    }

public:
    Ratio(): nom( 1 ), den( 1 ) {};
    Ratio( int a, unsigned b ): nom( a ), den( b ) {
        if ( b==0 ) {
            std::cerr << "ERROR: Division by zero!" << std::endl;
            den = 1;
        }
        reduce();
    }

    friend std::ostream& operator<< ( std::ostream& out, const Ratio& r ) {
        out << r.nom << "/" << r.den << "\n";
        return out;
    }

    friend std::istream& operator>> ( std::istream& in, Ratio& r ) {
        in >> r.nom >> r.den;
        return in;
    }

    static unsigned ratio_gcd ( unsigned n, unsigned m );

    void show();
    int input();

    void setNom ( int a ) {
        this -> nom = a;
        reduce();
    }
    int getNom() {
        return nom;
    }

    void setDen ( unsigned b ) {
        if ( b == 0 ) {
            std::cerr << "ERROR: Division by zero!" << std::endl;
            den = 1;
            return;
        }
        den = b;
        reduce();
    }
    unsigned getDen() {
        return den;
    }

    Ratio add ( Ratio second ); // third = first.add( second )
    Ratio operator+ ( const Ratio& x ) {
        return add(  x );
    }

    Ratio mult ( Ratio second );
    Ratio operator* ( const Ratio& x ) {
        return mult(  x );
    }

    Ratio subtraction ( Ratio second );
    Ratio operator- ( const Ratio& x ) {
        return subtraction(  x );
    }

    Ratio division ( Ratio second );
    Ratio operator/ ( const Ratio& x ) {
        return division(  x );
    }

    bool is_equal ( const Ratio& x ) {
        return (long long)x.den * nom == (long long)x.nom * den;
    }
    bool operator== ( const Ratio& x ) {
        return is_equal( x );
    }

    bool less ( const Ratio& x ) {
        return (long long)x.den * nom < (long long)x.nom * den;
    }
    bool operator< ( const Ratio& x ) {
        return less( x );
    }

    bool more ( const Ratio& x ) {
        return (long long)x.den * nom > (long long)x.nom * den;
    }
    bool operator> ( const Ratio& x ) {
        return more( x );
    }

    bool less_equal ( const Ratio& x ) {
        return (long long)x.den * nom <= (long long)x.nom * den;
    }
    bool operator<= ( const Ratio& x ) {
        return less_equal( x );
    }

    bool more_equal ( const Ratio& x ) {
        return (long long)x.den * nom >= (long long)x.nom * den;
    }
    bool operator>= ( const Ratio& x ) {
        return more_equal( x );
    }

    bool not_equal ( const Ratio& x ) {
        return (long long)x.den * nom != (long long)x.nom * den;
    }
    bool operator!= ( const Ratio& x ) {
        return not_equal( x );
    }

};

#endif //CLIONPROJECTS_RATIO_H
