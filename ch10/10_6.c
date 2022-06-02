#include <stdio.h>

#define SIZE 5

void reverse_arr(double arr[], int start, int end);
void print_arr(double arr[], int n);

int main(void)
{
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    printf("The original arry:\n");
    print_arr(arr, SIZE);
    
    reverse_arr(arr, 0, SIZE - 1);
    printf("The reverse arry:\n");
    print_arr(arr, SIZE);

    return 0;
}

void reverse_arr(double arr[], int start, int end)
{
    double temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void print_arr(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ",arr[i]);
    }
    printf("\n");
}