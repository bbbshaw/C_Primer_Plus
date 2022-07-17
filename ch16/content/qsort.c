#include <stdio.h>
#include <stdlib.h>

int mycomp(const void *p1, const void *p2);
void show_array(const int arr[], int num);

int main(void)
{
    int arr[10] = {5, 2, 11, 8, 32, 1, 12, 2, 7, 13};
    qsort(arr, 10, sizeof(int), mycomp);
    show_array(arr, 10);
}

int mycomp(const void *p1, const void *p2)
{
    const int *a1 = p1;
    const int *a2 = p2;

    if (*a1 > *a2)      // <
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;    
}

void show_array(const int arr[], int num)
{
    int i;
    for ( i = 0; i < num; i++)
        printf("%5d", arr[i]); 
    puts("");
}
