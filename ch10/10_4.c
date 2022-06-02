#include <stdio.h>

#define SIZE 5

int max_index(double arr[], int n);

int main(void)
{
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int index;

    index = max_index(arr, SIZE);

    printf("MAX INDEX: %d\n", index);

    return 0;
}

int max_index(double arr[], int n)
{
    int max, index = 0;
    max = arr[0];

    for ( int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }  
    }
    return index;
}