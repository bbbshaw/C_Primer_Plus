#include <stdio.h>

#define SIZE 6


int main(void)
{
    int i, j;
    char ch;

    for (i = 0, ch = 'F'; i < SIZE; i++)
    {
        
        for ( j = 0; j <= i; j++)
        {
            ch = 'F' - j;
            printf("%c", ch);
        }
        printf("\n");     
    }
    
    return 0;

}