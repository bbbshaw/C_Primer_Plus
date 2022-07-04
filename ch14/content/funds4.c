#include <stdio.h>

#define FUNDLEN 50

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
    struct funds stan[2] = {
        {
            "Garlic-Melon Bank",
            4032.27,
            "Lucky's Saving anf Loan",
            8543.94
        },
        {
            "Honest Jack's bank",
            3620.88,
            "Party time saving",
            3802.91
        }
    };

    printf("Stan has a total of $%.2f.\n", sum(stan, 2));

    return 0;
}


double sum(const struct funds money[], int n)  //double sum(const struct *money, int n)
{
    int total;
    int i;

    for ( i = 0, total = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;
    
    return total; 
}
