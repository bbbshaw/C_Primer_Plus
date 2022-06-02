#include <stdio.h>

#define ROW 5
#define COL 12

void copy_ptr(double * source_pt, double * target_pt, int n);
void print_arr(double arr[][COL], int n);

int main(void)
{
    double arr1[ROW][COL] =
    {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6}, 
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3}, 
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}, 
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2}, 
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    double arr2[ROW][COL];

    for (int i = 0; i < ROW; i++)
    {
        copy_ptr(arr1[i], arr2[i], COL);
    }

    print_arr(arr2, ROW);

    return 0;
}

void copy_ptr(double * source_pt, double * target_pt, int n)
{
    for (int i = 0; i < n; i++, target_pt++, source_pt++)
    {
        *target_pt = *source_pt;
    } 
}

void print_arr(double arr[][COL], int n)
{
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    
}


