#include <stdio.h>
#include <time.h>

void delay(int time);

int main(void)
{
    int delay_second;

    printf("Enter the seconds you want to deley(Q for quit):");
    while (scanf("%d", &delay_second) == 1)
    {
        delay(delay_second);
        printf("Time is up\n");
        printf("Enter the seconds you want to delay:\n");
    }
    return 0;
}

void delay(int time)
{
    double start_time;
    start_time = (double)clock();

    while((((double)clock() - start_time) / CLOCKS_PER_SEC) < time);
}