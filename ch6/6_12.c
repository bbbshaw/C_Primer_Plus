#include <stdio.h>

int main(void)
{
    int count;
    double sum1 = 0, sum2 = 0;
    double i;
    int sign = 1 ;

    printf("Plz enter the times: \n");
    scanf("%d", &count);

    while (count > 0)
    {
    
        for ( i = 1.0 ; i <= count; i++, sign = 0 - sign) // sign even:-1 odd: +1
        {
            sum1 += 1.0/i;

            sum2 += sign * (1.0/i);

        }
        printf("sum1 = %lf\n", sum1);
        printf("sum1 = %lf\n", sum2);

        printf("\nPlz enter the next number of terms(zero or nagative to exit):\n");
        scanf("%d", &count);

    }
    printf("Done.\n");
   
    return 0;
}