#include <stdio.h>

int main(void)
{
    int count = 0;
    int ch;

    while ((ch = getchar())!= EOF)
    {
        count++;
    }
    printf("Total characters: %d\n", count);
    
    return 0;

}
