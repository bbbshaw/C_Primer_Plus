#include <stdio.h>

#define SIZE 5

double max_min_diff(double arr[], int n);

int main(void)
{
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int index;
    double diff_val;

    diff_val = max_min_diff(arr, SIZE);

    printf("MAX INDEX: %.2f\n", diff_val);

    return 0;
}

double max_min_diff(double arr[], int n)
{
    int index = 0;
    double max;
    double min;
    double diff_val;

    
    max = arr[0];
    min = arr[0];

    for ( int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }  
    }
    for ( int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }  
    }
    diff_val = max - min;

    return diff_val;
}