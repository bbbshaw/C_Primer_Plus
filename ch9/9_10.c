#include <stdio.h>

void to_base_n(unsigned long n, unsigned base);

int main(void)
{
    unsigned long number;
    unsigned base;
    int count;

    printf("Enter an integer(q yo quit):\n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Please enter the number of base(2-10): ");
        
        while ((count = scanf("%u", &base)) == 1 && (base < 2 || base > 10))
            printf("The base should between 2 and 10: \n");
        if (count != 1)
            break;

        printf("Base: %u  Equivalent: ", base);
        to_base_n(number, base);
        printf("\n");
        printf("Please enter the numebr again(q to quit):\n");
    }
    printf("Done!\n");

    return 0;
}

void to_base_n(unsigned long n, unsigned base)
{
    int r;

    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    
    putchar('0' + r);   
}