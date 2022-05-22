#include <stdio.h>

#define ROW 6

int main(void)
{
    int i, j;
    char ch = 'A';

    for ( i = 5; i >= 0; --i)
    {
        for ( j = i; j < ROW ; ++j)
        {
            printf("%c", ch++);
        }
        printf("\n");
    }
    

    return 0;

}