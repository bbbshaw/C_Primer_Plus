#include <stdio.h>

void copy_arr(int row, int col, double arr[row][col], double arr2[row][col]);
void show_arr(int row, int col, double arr[row][col]);

int main(void)
{
    double arr[3][5] =
    {
        {1.1,2.2,3.3,4.4,5.5},
        {6.6,7.7,8.8,9.9,1.1},
        {2.2,3.3,4.4,5.5,6.6}
    };
    double arr2[3][5];

    copy_arr(3, 5, arr, arr2);
    show_arr(3, 5, arr2);


    return 0;
}

void copy_arr(int row, int col, double arr[row][col], double arr2[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            arr2[i][j] = arr[i][j];
    } 
}

void show_arr(int row, int col, double arr[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.1f ", arr[i][j]);
        }
        printf("\n");
    }
}
