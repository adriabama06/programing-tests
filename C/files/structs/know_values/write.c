typedef struct book_struct
{
    int pages;
    char title[50]; // << know values size
    char description[100]; // << know values size
} book;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    book* my_book = (book*) malloc(sizeof(book));


    strcpy(my_book->title, "The epic book");
    strcpy(my_book->description, "Idk any about this book, because i don't read this book");
    my_book->pages = 26;


    FILE* file_to_save = fopen("my_book.book", "wb"); // the extension can be any, is only an extension, important Write Bytes

    fwrite(my_book, sizeof(book), 1, file_to_save);

    fclose(file_to_save);


    printf("Saved:\nPages : %d\nTitle : %s\nDescription : %s\n", my_book->pages, my_book->title, my_book->description);


    return 0;
}