typedef struct book_struct
{
    int pages;
    char* title; // << unknown values size
    char* description; // << unknown values size
} book;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    book* my_book = (book*) malloc(sizeof(book));

    // I added (char*) before "" for preven in the compiler the: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    char* title = (char*) "The epic book";
    char* description = (char*) "Idk any about this book, because i don't read this book";

    my_book->title = (char*) malloc(strlen(title));
    my_book->description = (char*) malloc(strlen(description));


    strcpy(my_book->title, title);
    strcpy(my_book->description, description);

    my_book->pages = 26;


    FILE* file_to_save = fopen("my_book.book", "wb"); // the extension can be any, is only an extension, important Write Bytes

    // fwrite(my_book, sizeof(book), 1, file_to_save); // bye to this, now write value by value

    fwrite(&my_book->pages, sizeof(int), 1, file_to_save);

    int title_len = strlen(my_book->title);
    int description_len = strlen(my_book->description);


    fwrite(&title_len, sizeof(int), 1, file_to_save); // write the len because when read the file know how many char are here
    fwrite(my_book->title, title_len, 1, file_to_save);


    fwrite(&description_len, sizeof(int), 1, file_to_save);
    fwrite(my_book->description, description_len, 1, file_to_save);


    fclose(file_to_save);


    printf("Saved:\nPages : %d\nTitle : %s\nDescription : %s\n", my_book->pages, my_book->title, my_book->description);


    return 0;
}