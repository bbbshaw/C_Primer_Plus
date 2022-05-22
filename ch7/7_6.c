#include <stdio.h>
#define STOP '#'
#define E 'e'
#define I 'i'

int main(void)
{
    int count = 0;
    char present, previous = '\0';

    printf("Plz enter the string:\n");
    
    while ((present = getchar()) != STOP)
    {
        if (present == I && previous == E)
        {
            count++;

        }
        previous = present;
        
    }
    printf("The number of 'ei': %d\n", count);
    

    return 0;
}