#include <stdio.h>
#define SIZE 255


int main(void)
{

    char str[SIZE];
    int i = 0;

    printf("Enter a line of input:");
    while (scanf("%c", &str[i]), str[i] != '\n')    // enter to stop input 
    {
        i++;
    }
    
    
    for (; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;

}
