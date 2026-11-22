#include "poly.h"
#include <iostream>

int main() {
    Poly p1(3);
    p1.input();
    Poly p2 = p1;
    p2.coeff(0, 99);

    p1.show();
    p2.show();

    Poly p3;
    p3 = p2;
    std::cout << "val(2) = " << p3.value(2) << "\n";
}