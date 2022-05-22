#include <stdio.h>

double cal_fun(double num1, double num2);

int main(void)
{
    double num1, num2;
    
    printf("Please enter two floating-point numbers: \n");
    
    while (scanf("%lf %lf", &num1, &num2) == 2)
    {
        printf("The value is :%0.5lf.\n", cal_fun(num1,num2));
        scanf("Please enter two floating-point numbers(nonnumeric to quit): \n");
    }
    printf("\n");

    return 0;
}

double cal_fun(double n1, double n2)
{
    double value;
    value = (n1 - n2)/ (n1 * n2);
    
    return value;

}