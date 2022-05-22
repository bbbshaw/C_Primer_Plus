#include <stdio.h>

int main(void)
{
    char ch;
    unsigned int space = 0, newline = 0 , other = 0;


    printf("Enter: \n");

    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space++;
        else if (ch =='\n')
            newline++;
        else
            other++;
     
    }
    printf("Space: %u\nNewline: %u\nOther: %u\n", space, newline, other);
    printf("Done.\n");


    return 0;

}