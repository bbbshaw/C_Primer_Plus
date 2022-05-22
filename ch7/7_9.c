#include <stdio.h>

int isPrime(int number);

int main(void)
{
    unsigned int input;
    unsigned int number;

    printf("Plz enter a positive integer:");
    scanf("%u", &input);

    for ( number = 2; number <= input; number++)
    {
        if (isPrime(number))
        {
            printf("%d ", number);
            
        }
        else 
            continue;
    
    }
    printf("\n");   
    return 0;

}
int isPrime(int number)
{
    int i;

    for ( int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
        
}

