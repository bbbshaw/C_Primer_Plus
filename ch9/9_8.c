#include <stdio.h>

double power(double n, int p);

int main(void)
{
    double x, x_pow;
    int exp;

    printf("Enter a number and the power: \n");

    while (scanf("%lf %d", &x, &exp) == 2)
    {
        x_pow = power(x, exp);
        printf("%.3f tp the power of %d is %.5f\n", x, exp, x_pow);
        printf("Plz enter the next number: ");
    }
    printf("Done.\n");

    return 0;
}

double power(double n, int p)
{
    int i;
    double pow = 1;

    if (p == 0)
    {
        if (n == 0)
        {
            printf("0 the power of 0 is undefined.\n");
            pow = 1.0;
        }
        else 
            pow = 1.0;  
    }
    
    if (p > 0)
    {
        for (i = 0; i < p; i++)
        {
            pow *= n;
        }
    }
    
    else
        if (n != 0)
        {
            for ( i = 0; i > p; i--)
            {
                pow /= n;
            }
        }
        else 
            pow = 0;
    
    return pow;
}