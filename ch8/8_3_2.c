#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int input;

    int count_upper = 0;
    int count_lower = 0;

    printf("Enter a stream of character:");

    while ((input = getchar())!= EOF)
    {
        if (islower(input))
        {
            count_lower++;
        }
        else if (isupper(input))
        {
            count_upper++;
        }
        
        
    }
    printf("Upper:%d\n",count_upper);
    printf("Lower:%d\n", count_lower);
    
    return 0;
}