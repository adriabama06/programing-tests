#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int number_of_names;

    printf("Enter number of names :\n");
    scanf("%d", &number_of_names);

    char** str = (char**) malloc(number_of_names * sizeof(char*));

    printf("Enter names in any order:\n");
   
    for(int i = 0; i < number_of_names; i++)
    {
        char temp[100];
        scanf("%s", temp);

        str[i] = (char*) malloc(strlen(temp) * sizeof(char));
        strcpy(str[i], temp);
    }

    for(int i = 0; i < number_of_names; i++)
    {
        for(int j = i + 1; j < number_of_names; j++)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                char* temp = (char*) malloc(strlen(str[i]) * sizeof(char));

                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);

                free(temp);
            }
        }
    }
    
    printf("\nThe sorted order of names are:\n");
    
    for(int i = 0; i < number_of_names; i++)
    {
        printf("%s\n", str[i]);

        free(str[i]);
    }

    free(str);

    return 0;
}