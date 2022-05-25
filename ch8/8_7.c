#include <stdio.h>
#include <ctype.h>


#define OT  40.00f
#define OT_TIME_RATE 1.50f
#define TAX1 300.00f
#define TAX2 450.00f
#define TAX_RATE1 0.15f
#define TAX_RATE2 0.20f
#define TAX_RATE3 0.25f

#define RATE_1 8.75f
#define RATE_2 9.33f
#define RATE_3 10.00f
#define RATE_4 11.20f

float cal_gross_pay(float work_hours, float rate);
float cal_taxes(float gross_pay);
int enter_number(void);


int main(void)
{
    float work_hours, rate;
    float gross_pay, taxes, net_pay;
    

    printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a) $%.2f/hr 				b) $%.2f/hr\n", RATE_1, RATE_2);
	printf("c) $%.2f/hr 				d) $%.2f/hr\n", RATE_3, RATE_4);
	printf("q) quit \n");
	printf("*****************************************************************\n");

    

    switch (enter_number())
    {
        case ('a'):
            rate = RATE_1;
            break;
        case ('b'):
            rate = RATE_2;
            break;
        case ('c'):
            rate = RATE_3;
            break;
        case ('d'):
            rate = RATE_4;
            break;
        default:
            printf("Quit!\n");
            return 0;;
    }
    printf("You have select: %0.2f\n", rate);

    printf("Enter the hours worked: ");
    if (scanf("%f", &work_hours) == 1)
    {
        gross_pay = cal_gross_pay(work_hours, rate);
        taxes = cal_taxes(gross_pay);
        net_pay = gross_pay - taxes;
        printf("gross_pay = %.2f, taxes = %.2f, net_pay = %.2f\n", gross_pay, taxes, net_pay);  

    }
    
    else
        printf("Invalid input!\n");

    return 0;

}



float cal_gross_pay(float work_hours, float rate)
{
    if (work_hours > OT)
    {
        return OT * rate + (work_hours - OT) * OT_TIME_RATE * rate;
    }
    else
        return work_hours * rate;
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

int enter_number(void)
{
    int input;

    while (isspace(input = getchar()));

    while ((input < 'a' || input > 'd') && input != 'q')
    {
        
        printf("Invalid input.\n");
        printf("Plz enter again: ");
        
        while (isspace(input = getchar()));
        
    }

    return input;
    
}