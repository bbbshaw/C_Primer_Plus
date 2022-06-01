#include <stdio.h>

#define LENGHT 5

void copy_arr(double * target_pt , double * source_pt, int n);
void copy_ptr(double * target_pt , double * source_pt, int n);
void copy_ptrs(double * target_pt, double * source_start, double * source_end);


int main(void)
{
    double source[LENGHT] = {1.1, 2.2 ,3.3, 4.4, 5.5};
    double target1[LENGHT];
    double target2[LENGHT];
    double target3[LENGHT];

    copy_arr(target1, source, LENGHT);
    copy_arr(target2, source, LENGHT);
    copy_ptrs(target3, source, source + LENGHT);

    printf("%15s|%15s|%15s\n", "Target1", "Target2", "Target3");
    for (int i = 0; i < LENGHT; i++)
    {
        printf("%15.2f|%15.2f|%15.2f\n", target1[i], target2[i], target3[i]);
    }

    return 0;
}

void copy_arr(double * target_pt , double * source_pt, int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        target_pt[i] = source_pt[i];
    }
}

void copy_ptr(double * target_pt, double * source_pt, int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        *(target_pt + i) = *(source_pt + i);
    }  
}

void copy_ptrs(double * target_pt, double * source_start, double * source_end)
{
    double *ptr;

    for ( ptr = source_start; ptr < source_end; ptr++, target_pt++)
    {
        *target_pt = *ptr;
    }
}



