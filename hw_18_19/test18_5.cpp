#include <iostream>
#include <stdexcept>
#include <string>

#include "merge_sort.h"

int main() {
    Array<int> numbers(7);
    int raw[] = {38, 27, 43, 3, 9, 82, 10};
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = raw[i];
    }
    std::cout << "Before merge_sort: ";
    numbers.print();
    numbers.merge_sort();
    std::cout << "After merge_sort:  ";
    numbers.print();

    Array<std::string> words(4);
    words[0] = "pear";
    words[1] = "apple";
    words[2] = "orange";
    words[3] = "banana";

    words.merge_sort();
    std::cout << "Sorted words:      ";
    words.print();

    Array<int> empty_arr(0);
    empty_arr.merge_sort();
    std::cout << "Empty array:       ";
    empty_arr.print();

    Array<int> single_arr(1);
    single_arr[0] = 42;
    single_arr.merge_sort();
    std::cout << "Single element:    ";
    single_arr.print();

    Array<int> copied(numbers);
    Array<int> moved(std::move(copied));
    std::cout << "Moved array:       ";
    moved.print();
    std::cout << "Copied size after move: " << copied.size() << "\n";

    try {
        std::cout << numbers.at(100) << "\n";
    } catch (const std::out_of_range& ex) {
        std::cout << "Caught expected exception: " << ex.what() << "\n";
    }

    return 0;
}