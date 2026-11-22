#include <iostream>
#include "point.h"

int inputPoints ( Point* mas, int max_number ) {
    while ( true ) {
        std::cout << "input next point? y/n ";
        char answer;
        std::cin >> answer;
        if ( answer == 'n' ) {
            break;
        }
        else if ( answer != 'y' ) {
            std::cout << "use format y/n\n";
            continue;
        }
        mas[ Point::counter() ].input();
        if ( Point::counter() >= max_number ) {
            break;
        }
    }
    return Point::counter();
}

int main() {
    int m;
    std::cout << "input max number of points: ";
    std::cin >> m;

    Point* mas = new Point[m];

    int m1 = inputPoints(mas, m);

    double per = 0;
    if ( m1 >=3 ) {
        per = mas[0].length( mas[m1 - 1] );
        for ( int i = 0; i < m1-1; i++ ) {
            per += mas[i].length( mas[i + 1] );
        }
    }

    std::cout << "Number of points: " << Point::counter() << std::endl;
    std::cout << "Perimeter: " << per << std::endl;

    delete[] mas;
    return 0;
}