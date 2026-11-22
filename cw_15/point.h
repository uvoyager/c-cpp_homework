#ifndef CLIONPROJECTS_POINT_H
#define CLIONPROJECTS_POINT_H
#include <iostream>

class Point {
    double x, y;
    static int n;

public:
    Point(): x(0), y(0) {}
    Point ( double x_, double y_): x(x_), y(y_) {
        n++;
    }

    void input() {
        std:: cout << "x, y: ";
        std:: cin >> x >> y;
        n++;
    }

    double length( const Point& p );

    static int counter() {
        return n;
    }
};


#endif //CLIONPROJECTS_POINT_H
