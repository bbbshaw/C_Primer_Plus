#include <stdio.h>

#define BASCI_RATE  10.00f
#define OT  40.00f
#define OT_TIME_RATE 1.50f
#define TAX1 300.00f
#define TAX2 450.00f
#define TAX_RATE1 0.15f
#define TAX_RATE2 0.20f
#define TAX_RATE3 0.25f



int main(void)
{   
    float work_hours;
    float gross_pay = 0, taxes = 0, net_pay = 0;
    

    printf("Enter the hours worked:");
    
    

    if (scanf("%f", &work_hours) == 1)
    {
        if (work_hours <= OT)
        {
            work_hours = work_hours;
            gross_pay = work_hours * BASCI_RATE;
            
            if (gross_pay <= TAX1)
            {
                taxes = gross_pay * TAX_RATE1;
                net_pay = gross_pay - taxes;
            }

            if (gross_pay > TAX1 && gross_pay <= TAX2 )
            {
                taxes = TAX1 * TAX_RATE1 + (gross_pay - TAX1) * TAX_RATE2;
                net_pay = gross_pay - taxes;     
            }
            
            else if (gross_pay > TAX2)
            {
                taxes = TAX1 * TAX_RATE1 + (TAX2 - TAX1) * TAX_RATE2 + (gross_pay - TAX2) *TAX_RATE3;
                net_pay = gross_pay - taxes;
            
            }  

        }
        else
        {
            work_hours = OT + OT_TIME_RATE * (work_hours - OT);
            gross_pay = work_hours * BASCI_RATE;

            if (gross_pay <= TAX1)
            {
                taxes = gross_pay * TAX_RATE1;
                net_pay = gross_pay - taxes;
            }

            if (gross_pay > TAX1 && gross_pay <= TAX2 )
            {
                taxes = TAX1 * TAX_RATE1 + (gross_pay - TAX1) * TAX_RATE2;
                net_pay = gross_pay - taxes;     
            }
            
            else if (gross_pay > TAX2)
            {
                taxes = TAX1 * TAX_RATE1 + (TAX2 - TAX1) * TAX_RATE2 + (gross_pay - TAX2) *TAX_RATE3;
                net_pay = gross_pay - taxes;
            
            }
        
        
        }
        
    printf("gross_pay = %.2f, taxes = %.2f, net_pay = %.2f\n", gross_pay, taxes, net_pay);  
    
    }
    else
        printf("Invalid input.\n");

    return 0;

}