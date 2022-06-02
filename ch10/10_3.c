#include <stdio.h>

#define SIZE 5

int max_int(const int *pt, int n);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int max;

    max = max_int(arr, SIZE);
    printf("MAX: %d\n", max);

    return 0;
}

int max_int(const int *pt, int n)
{
    int max;
    int ini = 0;

    for (int i = 0 ; i < n; i++, pt++)
    {
        if (*pt >= ini)
        {
            max = *pt;
        }
    }
    return max;
}