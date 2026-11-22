#ifndef CLIONPROJECTS_BOOKS_H
#define CLIONPROJECTS_BOOKS_H

#include <string>
#include <vector>

struct Book {
    std::string name;
    std::string author;
    int num_of_pages = 0;
    int year_of_publication = 0;

    static std::vector<Book> get_books(const std::string& filename);
    static void is_available_title(const std::vector<Book>& books, const std::string& title);
    static void is_available_author(const std::vector<Book>& books, const std::string& author);
};

#endif // CLIONPROJECTS_BOOKS_H
