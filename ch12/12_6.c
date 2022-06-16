#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define MAX 1000

int main(void)
{
    int i;
    int num;
    int array[SIZE] = {};

    srand((unsigned int) time(0));

    for ( i = 0; i < MAX; i++)
    {
        num = rand() % 10 + 1;
        switch (num)
        {
        case 1:
            ++array[0];
            break;
        case 2:
            ++array[1];
            break;
        case 3:
            ++array[2];
            break;
        case 4:
            ++array[3];
            break;
        case 5:
            ++array[4];
            break;
        case 6:
            ++array[5];
            break;
        case 7:
            ++array[6];
            break;
        case 8:
            ++array[7];
            break;
        case 9:
            ++array[8];
            break;
        case 10:
            ++array[9];
            break;
        default:
            break;
        }
    }
    for ( i = 0; i < SIZE; i++)
        printf("Number %2d : %5d times.\n", i+1, array[i]);

    return 0;
}