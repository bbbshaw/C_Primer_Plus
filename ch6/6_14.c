#include <stdio.h>
#define SIZE 8

int main(void)
{
    double arr1[SIZE], arr2[SIZE];
    double sum;
    int i;

    //arr1 value input
    for ( i = 0; i < SIZE; i++)
    {
        printf("Enter the number: \n");
        scanf("%lf", &arr1[i]);
    }
    
    
    i = 0;
    
    //assign value to arr2
    for ( i = 0, sum = 0; i < SIZE; i++)
    {
        sum += arr1[i];
        arr2[i] = sum;           
    }
    
    i = 0;

    //print arr1 
    printf("Arr1:");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%5.2lf ", arr1[i]);
    }
    printf("\n");

    i = 0;

    //print arr2
    printf("Arr2:");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%5.2lf ", arr2[i]);
    }
    printf("\n");
 
    return 0;

}