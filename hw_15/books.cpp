#include "books.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<Book> Book::get_books(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << "\n";
        return books;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string part;
        std::vector<std::string> parts;

        while (std::getline(ss, part, ',')) {
            parts.push_back(part);
        }

        if (parts.size() < 4) {
            std::cerr << "The line does not have all information needed: " << line << "\n";
            continue;
        }

        try {
            Book book;
            book.name = parts[0];
            book.author = parts[1];
            book.num_of_pages = std::stoi(parts[2]);
            book.year_of_publication = std::stoi(parts[3]);
            books.push_back(book);
        } catch (const std::exception& e) {
            std::cerr << "Failed to parse line (" << line << "): " << e.what() << "\n";
        }
    }

    return books;
}

void Book::is_available_title(const std::vector<Book>& books, const std::string& title) {
    if (books.empty()) {
        std::cout << "Catalogue is empty\n";
        return;
    }

    bool found = false;
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].name == title) {
            std::cout << "The book is available: " << books[i].name
                      << " (" << books[i].author << ", " << books[i].year_of_publication << ")\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Book not found: " << title << "\n";
    }
}

void Book::is_available_author(const std::vector<Book>& books, const std::string& author) {
    if (books.empty()) {
        std::cout << "Catalogue is empty\n";
        return;
    }

    std::vector<Book> books_with_author;
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].author == author) {
            books_with_author.push_back(books[i]);
        }
    }

    if (books_with_author.empty()) {
        std::cout << "No books found for author: " << author << "\n";
        return;
    }

    std::cout << "Books written by " << author << ":\n";
    for (size_t i = 0; i < books_with_author.size(); ++i) {
        std::cout << "- " << books_with_author[i].name << "\n";
    }
}