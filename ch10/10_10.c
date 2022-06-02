#include <stdio.h>

void cal_arr_sum(int n, int arr1[n], int arr2[n], int arr3[n]);
void show_arr(int n, int arr[n]);

int main(void)
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int arr3[5];

    cal_arr_sum(5, arr1, arr2, arr3);
    show_arr(5, arr3);

    return 0;
}

void cal_arr_sum(int n, int arr1[n], int arr2[n], int arr3[n])
{
    for (int i = 0; i < n; i++)
        arr3[i] = arr1[i] + arr2[i];
}

void show_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++)
        printf("%.1d ", arr[i]); 
    printf("\n");
}