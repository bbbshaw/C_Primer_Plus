#include <stdio.h>
#define PERIOD '.'
#define EXCLA_MARK '!'
#define STOP '#'

int main(void)
{
    unsigned int count = 0;
    char ch;

    printf("Plz enter the string:\n");

    while ((ch = getchar()) != STOP )
    {
        if (ch == PERIOD)
        {
            putchar(EXCLA_MARK);
            count++;
        }
        else if (ch == EXCLA_MARK)
        {
            putchar(EXCLA_MARK);
            putchar(EXCLA_MARK);
            count++;
        }
        else
            putchar(ch);
           
        
    }
    printf("Number of substitution: %d\n", count);
    printf("Done.\n");
    
   
    return 0;

}