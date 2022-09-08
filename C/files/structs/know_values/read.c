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

    FILE* file_to_read = fopen("my_book.book", "rb"); // important Read Bytes

    fread(my_book, sizeof(book), 1, file_to_read);
    
    fclose(file_to_read);

    printf("Read:\nPages : %d\nTitle : %s\nDescription : %s\n", my_book->pages, my_book->title, my_book->description);

    return 0;
}