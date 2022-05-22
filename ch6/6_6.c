#include <stdio.h>

int main(void)
{
    int upper, lower, i, sq, cube;

    printf("Plz enter a upper bound and a lower bound number: \n");
    scanf("%d %d",&upper , &lower);
    

    printf("%5s %10s %15s\n", "number", "square", "cube");

    for ( i = lower ; i <= upper; i++)
    {
        sq = i * i;
        cube = i * i * i;
        printf("%5d %10d %15d\n", i, sq, cube);

    }
    printf("\n");

    return 0;

}