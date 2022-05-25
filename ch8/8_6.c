#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    int first_char;

    printf("Plz enter a string: \n");
    first_char = get_first();
    putchar(first_char);
    printf("\n");

    return 0;
}

char get_first(void)
{
    int input;

    while (isspace(input = getchar()));

    return input;
    
}