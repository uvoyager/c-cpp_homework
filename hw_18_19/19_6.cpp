#include <iostream>
#include <stdexcept>
#include "black_box.h"

int main() {
    BlackBox<int> box;

    box.add(3);
    box.add(1);
    box.add(6);
    box.add(8);
    std::cout << "k = " << box.counter() + 1 << " -> " << box.next_kth_min() << "\n";
    box.add(2);
    std::cout << "k = " << box.counter() + 1 << " -> " << box.next_kth_min() << "\n";
    box.add(0);
    std::cout << "k = " << box.counter() + 1 << " -> " << box.next_kth_min() << "\n";

    try {
        while (true) {
            std::cout << "k = " << box.counter() + 1 << " -> " << box.next_kth_min() << "\n";
        }
    } catch (const std::out_of_range& ex) {
        std::cout << "Stopped: " << ex.what() << "\n";
    }

    return 0;
}