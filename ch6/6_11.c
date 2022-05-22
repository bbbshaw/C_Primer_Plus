#include <stdio.h>

#define SIZE 8

int main(void)
{
    int array[SIZE];
    int i;

    //enter array
    printf("Enter %d integers:\n", SIZE);

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    //print reverse
    for ( i = SIZE - 1; i >= 0; i--)
    {
        printf("%d", array[i]);

    }
    printf("\n");

    return 0;

    
}