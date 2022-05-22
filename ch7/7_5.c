#include <stdio.h>

#define STOP '#'
#define EXCL_MARK '!'
#define DOT '.'

int main(void)
{
    unsigned int count = 0;
    char ch;

    printf("Plz enter the string:\n");

    while ((ch = getchar()) != STOP )
    {
        switch (ch)
        {
            case DOT:
                putchar(EXCL_MARK);
                count++;
                break;
        
            case EXCL_MARK:
                putchar(EXCL_MARK);
                putchar(EXCL_MARK);
                count++;
                break;

            default:
                putchar(ch);
        }
           
        
    }
    printf("Number of substitution: %d\n", count);
    printf("Done.\n");
    
   
    return 0;

}