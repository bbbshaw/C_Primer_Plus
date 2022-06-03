#include <stdio.h>

#define ROW 3
#define COL 5

void double_val(int (*pt)[5], int row);
void show_arr(int (*pt)[5], int row);

int main(void)
{
    int arr1[ROW][COL] =
    {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
    };

    double_val(arr1, ROW);
    show_arr(arr1, ROW);

    return 0;
}

void double_val(int (*pt)[5], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < COL; j++)
            pt[i][j] = 2 * pt[i][j];
    }
}

void show_arr(int (*pt)[5], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < COL; j++)
            printf("%d ", pt[i][j]);
        printf("\n");
    }
}