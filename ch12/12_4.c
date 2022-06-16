#include <stdio.h>

int call_times(void);

int main(void)
{
    int count;
    int times;

    printf("Plz enter the times you want to run:\n");
    while(scanf("%d", &times) == 1 && times > 0)
    {
        while (times--)
            count = call_times();
        printf("Function has been called %d times.\n", count);
        printf("Enter the times you want to run:\n");
    }
}

int call_times(void)
{
    static int count = 0;
    
    return ++count; 
}
