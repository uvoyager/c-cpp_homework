#include <iostream>
#include <string>

#include <ratio.h> // needed for this problem

template <typename T>
T max2( T a, T b ) {
    return a > b ? a : b;
}

int main() {
    int x, y;
    std:: cout << "enter two numbers: ";
    std:: cin >> x >> y;
    std:: cout << "max is: " << max2(x, y) << std::endl;

    double a, b;
    std:: cout << "enter two double numbers: ";
    std:: cin >> a >> b;
    std:: cout << "max is: " << max2(a,b) << std::endl;

    std:: string s1, s2;
    std:: cout << "enter two strings: ";
    std:: cin >> s1 >> s2;
    std:: cout << "max is: " << max2(s1,s2) << std::endl;

    Ratio r1, r2;
    std:: cout << "enter two rationals: ";
    std:: cin >> r1 >> r2;
    std:: cout << "max is: " << max2(r1,r2) << std::endl;
    return 0;
}