#include <stdio.h>

#define SIZE 41

void remove_space(char * ptr);

int main(void)
{
    char str[SIZE];

    printf("Please enter a string:\n");
    gets(str);
    while (str[0] != '\0')
    {
        remove_space(str);
        puts(str);
        printf("Please enter the string again:\n");
        gets(str);
    }
    return 0;
}

void remove_space(char * ptr)
{
    unsigned count = 0;
    while (1)
    {
        if (*ptr == ' ')
            count++;
        else
            *(ptr - count) = *ptr;
        if (*ptr == '\0')
            break;
        ptr++;    
    }
}