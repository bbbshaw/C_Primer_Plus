#include <stdio.h>

#define YEARS 5
#define MONTHS 12

void cal_total(const double (*pt)[MONTHS], int n);
void cal_ave_y(const double (*pt)[MONTHS], int n);
void cal_ave_m(const double (*pt)[MONTHS], int n);


int main(void)
{
    double rain[YEARS][MONTHS] =
    {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6}, 
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3}, 
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}, 
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2}, 
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    cal_total(rain, YEARS);
    cal_ave_y(rain, YEARS);
    cal_ave_m(rain, YEARS);

    return 0;
}

void cal_total(const double (*pt)[MONTHS], int n)
{
    double total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MONTHS; j++)
        {
            total += pt[i][j];
        }
        printf("%d total rainfall:%.2f\n", 2010 + i, total);
        total = 0.0;
    }
    printf("\n");
}

void cal_ave_y(const double (*pt)[MONTHS], int n)
{
    double total = 0;
    double ave_y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MONTHS; j++)
        {
            total += pt[i][j];
        }
    } 
    ave_y = total / YEARS;
    printf("The yearly ave:%.2f\n", ave_y);
    printf("\n");
}

void cal_ave_m(const double (*pt)[MONTHS], int n)
{
    double subtotal = 0;

    for (int j = 0; j < MONTHS; j++)
    {
        for (int i = 0; i < n; i++)
        {
            subtotal += pt[i][j];
        }
        printf("The %d month ave: %.2f\n", j+1, subtotal / YEARS);
        subtotal = 0.0;
    }
    printf("\n");
}