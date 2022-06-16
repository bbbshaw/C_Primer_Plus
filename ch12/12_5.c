#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

void sort_arr(int *pt, int n);

int main(void)
{
    int array[SIZE];
    int i;

    srand((unsigned int)time(0));
    for ( i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10 + 1;
        printf("%5d", array[i]);

        if (i % 10 == 9)
            putchar('\n');   
    }

    sort_arr(array, SIZE);
    printf("Sorted array:\n");

    for ( i = 0; i < SIZE; i++)
    {
        printf("%5d", array[i]);
    
        if (i % 10 == 9)
            putchar('\n');
    }
    return 0;
}

void sort_arr(int *pt, int n)
{
    int i, j;
    int temp;

    for ( i = 0; i < n-1; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            if (*(pt+i) < *(pt+j))
            {
                temp = *(pt+i);
                *(pt+i) = *(pt+j);
                *(pt+j) = temp;
            }
        }
    }
}
