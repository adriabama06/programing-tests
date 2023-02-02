#include <iostream>
#include <string>

typedef struct {
    int id;
    int pages;
} book;

book new_book(int id, int pages)
{
    book r;

    r.id = id;
    r.pages = pages;

    return r;
}

inline book operator+(book book_a, book book_b)
{
    book add;

    add.id = book_a.id + book_b.id;
    add.pages = book_a.pages + book_b.pages;

    return add;
}

int main()
{
    book book1 = new_book(5, 230);
    book book2 = new_book(34, 123);

    book mix = book1 + book2;

    std::cout
    << "Book1: id> " << book1.id << " pages> " << book1.pages << std::endl
    << "Book2: id> " << book2.id << " pages> " << book2.pages << std::endl
    << "Mix: id> " << mix.id << " pages> " << mix.pages << std::endl;


    return 0;
}