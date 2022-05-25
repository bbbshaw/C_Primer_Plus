#include <stdio.h>

int main(void)
{
    int input;

    int count_upper = 0;
    int count_lower = 0;

    printf("Enter a stream of character:");

    while ((input = getchar())!= EOF)
    {
        if (input >= 'a' && input <= 'z')
        {
            count_lower++;
        }
        else if (input >= 'A' && input <= 'Z')
        {
            count_upper++;
        }
        
        
    }
    printf("Upper:%d\n",count_upper);
    printf("Lower:%d\n", count_lower);
    
    return 0;
}