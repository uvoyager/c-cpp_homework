#include "Point.h"
#include <cmath>

int Point::n = 0;
double Point::length( const Point& p ) {
    return hypot( p.x - x, p.y - y );
}