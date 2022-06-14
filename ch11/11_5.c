#include <stdio.h>

#define SIZE 41
char *find_the_first(char * str, char ch);

int main(void)
{
    char str[SIZE];
    char ch;
    char * ptr;

    puts("Please enter a string:");
    while (gets(str) && str[0] != '\0')
    {
        puts("Please enter a character you want to find:");
        ch = getchar();

        while (getchar() != '\n');
        ptr = find_the_first(str, ch);
        
        if (ptr == NULL)
            printf("There is no %c in the string.\n", ch);
        else
            printf("%c is in %p.\n", ch, ptr);   
        puts("Please enter a string:");            
    }
    return 0;
}

char *find_the_first(char * str, char ch)
{
    while (*str != '\0')
    {
        if (*str++ == ch)
            return str;
    }
    return NULL;
}