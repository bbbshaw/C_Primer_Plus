#include <stdio.h>

int main(void)
{
    int years;
    double interest = 0.08;
    double balance;
    double ori_balance = 1000000;
    const double withdraw = 100000;

    balance = ori_balance;

    for ( years = 0; balance > 0; years++)
    {
        // 
        balance -= withdraw;
        balance *= (1.0f + interest);

    }
    printf("After %d years, the account will be empty.\n", years);

    return 0;
}