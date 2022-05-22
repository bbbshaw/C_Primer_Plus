#include <stdio.h>

#define SINGLE 17850.00
#define HOUSE_HOLD 23900.00
#define M_JOINT 29750.00
#define M_SEP 14875.00

#define FIRST_RATE 0.15
#define EXC_RATE 0.28

int main(void)
{
    int input_num;
    float threshold, income, tax;

    printf("Choose the Category\n");
    printf("1) single\n");
    printf("2) Head of Household\n");
    printf("3) Married, Joint\n");
    printf("4) Married, Seperate\n");
    printf("Plz enter the category number: \n");
    

    while (scanf("%d",&input_num) == 1)
    {
    
        switch (input_num)
        {
            case 1:
                threshold = SINGLE;
                break;
            case 2:
                threshold = HOUSE_HOLD;
                break;
            case 3:
                threshold = M_JOINT;
                break;
            case 4:
                threshold = M_SEP;
                break;
            default:
                printf("Plz enter valid number: ");
                continue;
        }
        printf("Your input is %d\n", input_num);
        printf("Enter your income: ");
        scanf("%f", &income);
        
        if (income > threshold)
        {
            tax = FIRST_RATE * threshold + (income - threshold) * EXC_RATE;
            
        }
        else
            tax = FIRST_RATE * threshold;
        
        printf("Your income is %0.2f, you have to pay %0.2f tax\n", income, tax);
        printf("Enter the category number again (q to quit):");
        continue;
        
    }
    return 0;
}

