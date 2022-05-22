#include <stdio.h>

#define ARTI 2.05f
#define BEETS 1.15f
#define CARROTS 1.09f   
#define DISCOUNT 0.05f
#define DISC_TS 100.00f
#define SHIP_FEE1 6.50f
#define WEIGHT1 5.00f
#define SHIP_FEE2 14.00f
#define WEIGHT2 20.00f
#define SHIP_RATE_3 0.5f

float calTotalWeight(float a_sum_weight, float b_sum_weight, float c_sum_weight);
float calTotalCost(float a_sum_weight, float b_sum_weight, float c_sum_weight);
float calShippingCharge(float total_weight);
float calDiscount(float total_cost);


int main(void)
{
    char ch;
    float a_weight, b_weight, c_weight;
    float a_sum_weight = 0.00, b_sum_weight = 0.00, c_sum_weight = 0.00;
    float total_weight, total_cost, discount, shipping_charge, total_charge;



    printf("**************************\n");
    printf("Code | Product  |  Price |\n");
    printf(" a    artichokes   $%0.2f\n", ARTI);
    printf(" b       beets     $%0.2f\n", BEETS);
    printf(" c      carrots    $%0.2f\n", CARROTS);
    printf("Enter q to quit!\n");
    
    

    while ((ch = getchar()) != 'q')
    {
        switch (ch)
        {
            case 'a':
                printf("Plz enter the weight of a): ");
                scanf("%f", &a_weight );
                a_sum_weight += a_weight;
                continue;
            
            case 'b':
                printf("Plz enter the weight of b): ");
                scanf("%f", &b_weight );
                b_sum_weight += b_weight;
                continue;
            
            case 'c':
                printf("Plz enter the weight of c): ");
                scanf("%f", &c_weight );
                c_sum_weight += c_weight;
                continue;

            default:
                break;
        }
        printf("\n");
        printf("arti wight:%0.2f\n", a_sum_weight);
        printf("beets wight:%0.2f\n", b_sum_weight);
        printf("carrot weight:%0.2f\n", c_sum_weight);
        printf("\n");
        printf("Plz enter code again (q to quit): ");
    }

    total_weight = calTotalWeight(a_sum_weight, b_sum_weight, c_sum_weight);
    total_cost = calTotalCost(a_sum_weight, b_sum_weight, c_sum_weight);
    shipping_charge = calShippingCharge(total_weight);
    discount = calDiscount(total_cost);
    total_charge = total_cost * (1 - discount) + shipping_charge;

    printf("*************************\n");
    printf("The weight of a):%0.2f\n", a_sum_weight);
    printf("The weight of b):%0.2f\n", b_sum_weight);
    printf("The weight of c):%0.2f\n", c_sum_weight);
    printf("The total weight:%0.2f\n", total_weight);
    printf("The total item cost:%0.2f\n",total_cost);
    printf("The total shipping charge:%0.2f\n", shipping_charge);
    printf("The discount rate:%0.2f\n", discount);
    printf("The total chages:%0.2f\n", total_charge);

    return 0;
}

float calTotalWeight(float a_sum_weight, float b_sum_weight, float c_sum_weight)
{
    float total_weight = 0;
    total_weight = a_sum_weight + b_sum_weight + c_sum_weight;
    return total_weight;
}

float calTotalCost(float a_sum_weight, float b_sum_weight, float c_sum_weight)
{
    float total_cost = 0;
    total_cost = a_sum_weight * ARTI + b_sum_weight * BEETS + c_sum_weight * CARROTS;

    return total_cost;
}

float calShippingCharge(float total_weight)
{
    float shipping_cahrge = 0;

    if (total_weight >= WEIGHT2 )
    {
        shipping_cahrge =  SHIP_FEE2 + (total_weight - WEIGHT2) * SHIP_RATE_3;
    }
    if (total_weight >= WEIGHT1)
    {
        shipping_cahrge = SHIP_FEE2;
    }
    else
        shipping_cahrge = SHIP_FEE1;

    return shipping_cahrge;    
}

float calDiscount(float total_cost)
{
    float discount = 0;

    if (total_cost > DISC_TS)
    {
        discount = DISCOUNT;
    }
    else
        discount = 0;
    
    return discount;    
}