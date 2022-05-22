#include <stdio.h>
#include <math.h>
#define SIZE 8


int main(void)
{
    int arr[SIZE];
    int power;
    int i;

    for ( i = 0; i < SIZE; i++)
    {
        arr[i] = pow(2, i);     // include <mth.h>
    }
    
    i = 0;
    
    do
    {
        printf("%d\t", arr[i]);

    } while (++i < SIZE);

    return 0;

}