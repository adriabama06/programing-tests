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


    FILE* file_to_read = fopen("my_book.book", "rb"); // important Read Bytes

    // fread(my_book, sizeof(book), 1, file_to_read); // jajajaja... no :c read value by value :c, REMEMBER THE ORDER USED TO SAVE
    
    // re do the order to save for read, first pages, after the title_len, title (char*), ...
    int pages;
    fread(&pages, sizeof(int), 1, file_to_read);
    my_book->pages = pages;

    
    
    int title_len;

    
    fread(&title_len, sizeof(int), 1, file_to_read); // read title_len


    my_book->title = (char*) malloc(sizeof(char) * title_len); // reservate memory for load


    fread(my_book->title, title_len, 1, file_to_read); // then read the title (char*)

    

    int description_len;

    
    fread(&description_len, sizeof(int), 1, file_to_read); // read description_len


    my_book->description = (char*) malloc(sizeof(char) * description_len); // reservate memory for load


    fread(my_book->description, description_len, 1, file_to_read); // then read the description (char*)
    


    fclose(file_to_read);

    
    printf("Read:\nPages : %d\nTitle : %s\nDescription : %s\n", my_book->pages, my_book->title, my_book->description);

    return 0;
}