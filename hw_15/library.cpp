#include "books.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<Book> books = Book::get_books("../catalogue.txt");
    if (books.empty()) {
        std::cerr << "Warning: no books loaded.\n";
    }

    std::cout << "Do you want to search by author or by title?\n";
    std::string search;
    if (!(std::cin >> search)) {
        return 0;
    }

    if (search == "author") {
        std::cout << "Name of the author:\n";
        std::string author;
        std::getline(std::cin >> std::ws, author);
        Book::is_available_author(books, author);
    }
    if (search == "title") {
        std::cout << "Name of the title:\n";
        std::string title;
        std::getline(std::cin >> std::ws, title);
        Book::is_available_title(books, title);
    }

    return 0;
}
