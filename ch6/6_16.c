#include <stdio.h>


int main(void)
{
    double da = 100.00, de = 100.00;
    int years;
    const double da_i = 0.1;
    const double de_i = 0.05;
    double da_balance = da, de_balance = de;


    for ( years = 0; de_balance <= da_balance; years++)
    {
        // cal da total
        da_balance += da_i * da;

        //cal de total
        de_balance *= (1.0f + de_i);

    }

    printf("In the %d th year! The balance of DE is %5.2lf and the balance of DA is %5.2lf.\n", years, de_balance, da_balance);

    return 0;

}