#include <stdio.h>

#define SIZE 7


void copy_ptr(double * source_pt, double * target_pt, int n);
void print_arr(double ar[], int n);

int main(void)
{
    double arr1[SIZE] =
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2};
    double arr2[3];

    copy_ptr(arr1 + 2, arr2, 3);

    print_arr(arr2, 3);

    return 0;
}

void copy_ptr(double * source_pt, double * target_pt, int n)
{
    for (int i = 0; i < n; i++, target_pt++, source_pt++)
    {
        *target_pt = *source_pt;
    } 
}

void print_arr(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", ar[i]);
    printf("\n");   
}


