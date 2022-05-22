#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime;

    printf("Plz enter a number: \n");
    printf("Enter q to quit.\n");
    

    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime = true; (div * div) <= num; div++)
        {
            if (num % div == 0)
            {
                if (div == (num / div))
                    printf("%lu is divisible by %lu\n.", num, div);
                else
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                isPrime = false;
            }

        }
        if(isPrime)
            printf("%lu is prime.\n", num);
            
        printf("Plz enter an interger: \n");
        
    }
    printf("Done.\n");

    return 0;
}