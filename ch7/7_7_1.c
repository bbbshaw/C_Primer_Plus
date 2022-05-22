#include <stdio.h>

#define BASIC_RATE  10.00f
#define OT  40.00f
#define OT_TIME_RATE 1.50f
#define TAX1 300.00f
#define TAX2 450.00f
#define TAX_RATE1 0.15f
#define TAX_RATE2 0.20f
#define TAX_RATE3 0.25f

float cal_gross_pay(float work_hours);
float cal_taxes(float gross_pay);


int main(void)
{
    float work_hours;
    float gross_pay, taxes, net_pay;
    
    printf("Enter the hours worked:");

    if (scanf("%f", &work_hours) == 1)
    {
        gross_pay = cal_gross_pay(work_hours);
        taxes = cal_taxes(gross_pay);
        net_pay = gross_pay - taxes;
        printf("gross_pay = %.2f, taxes = %.2f, net_pay = %.2f\n", gross_pay, taxes, net_pay);  

    }
    else
        printf("Invalid input!\n");


    return 0;
}

float cal_gross_pay(float work_hours)
{
    if (work_hours > OT)
    {
        return OT * BASIC_RATE + (work_hours - OT) * OT_TIME_RATE * BASIC_RATE;
    }
    else
        return work_hours * BASIC_RATE;
}
float cal_taxes(float gross_pay)
{
    if (gross_pay > TAX2)
    {
        return TAX1 * TAX_RATE1 + (TAX2 - TAX1) * TAX_RATE2 + (gross_pay - TAX2) *TAX_RATE3;
    }
    else if (gross_pay > TAX1)
    {
        return TAX1 * TAX_RATE1 + (gross_pay - TAX1) * TAX_RATE2;
    }
    else
        return gross_pay * TAX_RATE1;   
    
}