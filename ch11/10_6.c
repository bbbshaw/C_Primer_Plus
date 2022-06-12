#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 41
#define QUIT "quit"

bool is_within(const char * ptr, char ch);

int main(void)
{
    char str[SIZE];
    char ch;

    printf("Please enter a string(type quit to exit):\n");
    while (strcmp(gets(str), QUIT))
    {
        printf("Enter a character you want to find:\n");
        scanf("%c", &ch);
        while(getchar() != '\n')
            continue;
        if(is_within(str, ch))
            printf("Got it.\n");
        else 
            printf("%c cannot be found.\n", ch);
        printf("Please enter a string(type quit to exit):\n");
    }
    return 0;
}

bool is_within(const char * ptr, char ch)
{
    bool flag = false;
    while (*ptr != '\0')
    {
        if (*ptr++ == ch)
        {
           flag = true;
           break;
        }
    }
    return flag;
}