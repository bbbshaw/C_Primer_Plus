#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void choose_from_array(int *array, int size, int num);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int times;

    printf("Please enter the times you want to choose:\n");
    while (scanf("%d", &times) == 1 && times > 0 && times <= SIZE)
    {
        choose_from_array(arr, SIZE, times);
        printf("Please enter the times you want to choose:\n");
    }
    return 0;
}

void choose_from_array(int *array, int size, int num)
{
    int i;
    int temp[SIZE];
    int count = 0;

    srand((unsigned int)time(NULL));
    
    while(1)
    {
        i = rand() % 10;
        if(temp[i] != -1)
        {
            printf("%3d", array[i]);
            temp[i] = -1;
            count++;
            if (count == num)
                break; 
        }
    }
    printf("\n");
}