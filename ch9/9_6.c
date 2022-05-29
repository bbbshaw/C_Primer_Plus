#include <stdio.h>

void assign_value(double *x, double *y, double *z);

int main(void)
{
    double num1, num2, num3;

    printf("Plz enter 3 numbers: \n");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    printf("The original number value:\n");
    printf("Number1: %.2lf\n", num1);
    printf("Number2: %.2lf\n", num2);
    printf("Number3: %.2lf\n", num3);

    assign_value(&num1, &num2, &num3);

    printf("The converted number value:\n");
    printf("Number1: %.2lf\n", num1);
    printf("Number2: %.2lf\n", num2);
    printf("Number3: %.2lf\n", num3);

    return 0;
}

void assign_value(double *x, double *y, double *z)
{
    double tem;

    if (*x > *y)
    {
        tem = *y;
        *y = *x;
        *x = tem;
    }

    if (*x > *z)
    {
        tem = *z;
        *z = *x;
        *x =tem;
    }

    if (*y > *z)
    {
        tem = *z;
        *z = *y;
        *y = tem;
    }  
}