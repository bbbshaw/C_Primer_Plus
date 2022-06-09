#include <stdio.h>
#include <ctype.h>

#define SIZE 41

int main(void)
{
    char str[SIZE];

    printf("Please enter some words:\n");
    get_first_words(str);
    puts(str);

    return 0;
}

void get_first_words(char * ptr)
{
    char ch;

    while (isspace(ch = getchar()))
        continue;
    do
    {
        *ptr++ = ch;
    } while (!isspace(ch = getchar()));
    *ptr = '\0';
}