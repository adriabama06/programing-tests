/*
Ok let's try to convert int to string without using any library function
*/

#include <stdio.h>
#include <stdlib.h>

int length_int(int n)
{
    int result = 0;
    while (n != 0) // because n is int at the end on move the last digit to end of coma will be 0, like: 123 -> 12.3 -> 1.23 -> 0.123 <- this is the 0 in int because all after . not exist
    {
        n = n / 10; // move the last digit to end of coma
        result++;
    }
    return result;
}

int length_float(float n)
{
    int result = 0;
    int l = 0;
    while (l < n)
    {
        if(l == 0) {
            l = 1; // pass the first loop in cas the input number is 1 or between 0 and 1
        }
        l = l * 10; // multiply the number by 10 to try to get the same size of input
        result++;
    }
    
    return result;
}

int length_char(char* s)
{
    int l = 0;
    while (s[l] != '\0') { // while not find '\0' (the end of str) increase l
        l++;
    }
    return l;
}

char* to_str(int number)
{
    int l = length_int(number);

    char* str = (char*) calloc(sizeof(char*) * l, sizeof(char*));
    
    int reverse_count = l - 1;

    /*
    for(int i = 0; i < l; i++)
    {
        //                          % can be used to get the last digit of the number (only works on int)
        str[reverse_count] = number % 10 + '0'; // get the current last digit of the number and add it to the string
        number = number / 10; // divide the number by 10 to get the next last digit
        reverse_count--; // decrease the reverse_count to get where put next last digit
    }
    */

    // or i prefer this way
    // prevent edit number and can use pointer for low memory usage

    for(int i = 1; i < number; i = i * 10)
    {
        str[reverse_count] = (number / i) % 10 + '0';
        /*
        first divide the number by 10,100,1000.... (this is like do the number = number / 10)
        and get the current last digit of the number
        and add it to the string
        */
        reverse_count--;
    }


    str[l] = '\0';

    return str;
}

int main()
{
    int number = 173;

    char* str = to_str(number);

    printf("%s (%d)\n", str, length_char(str));

    free(str);

    return 0;
}