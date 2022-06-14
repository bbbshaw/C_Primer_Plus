#include <stdio.h>
#include <string.h>

#define SIZE 41

void reverse_str(char * st);

int main(void)
{
    char str[SIZE];

    printf("Please enter string to reverse:\n");
    gets(str);
    while (str[0] != '\0')
    {
        reverse_str(str);
        puts(str);
        puts("Please enter a string again:");
        gets(str);
    } 
    printf("Done.\n");
    return 0;
}

void reverse_str(char * st)
{
    char temp;
    int len = strlen(st);
    int i;

    for ( i = 0; i < len / 2; i++)
    {
        temp = st[i];
        st[i] = st[len - 1 - i];
        st[len - 1 - i];     
    }
}