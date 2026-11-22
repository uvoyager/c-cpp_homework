#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "class.h"

int main() {
    try {
        Function f(0.5, 1.5);
        f.add_power(1.0, 2.0)
         .add_cos(-1.0, 1.0, 0.0)
         .add_sqrt(0.5, 1.0, 0.0)
         .add_log(-0.2, 1.0, 1.0);
        std::cout << std::fixed << std::setprecision(8);
        std::cout << "Interval: [" << f.left() << ", " << f.right() << "]\n";
        double root = f.find_root(1e-10);
        std::cout << "Approximate root on interval: x = " << root
                  << ", f(x) = " << f(root) << "\n\n";
        const std::size_t n = 100;
        std::cout << "Integration methods on [" << f.left() << ", " << f.right()
                  << "] (n = " << n << "):\n";
        std::cout << "  Left rectangles:     " << f.left_rectangles(n) << "\n";
        std::cout << "  Right rectangles:    " << f.right_rectangles(n) << "\n";
        std::cout << "  Midpoint rectangles: " << f.midpoint_rectangles(n) << "\n";
        std::cout << "  Trapezoidal rule:    " << f.trapezoidal(n) << "\n";
        std::cout << "  Simpson's rule:      " << f.simpson(n) << "\n";
        std::cout << "\nSampling table on [0.1, 2.1] with 6 samples:";
        f.sample(0.1, 2.1, 6);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}