#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
    double num1, num2;

    printf("Please enter two number:\n");
    scanf("%lf %lf", &num1, &num2);

    larger_of(&num1, &num2);

    printf("The result: num1 = %.4lf num2 = %.4lf \n", num1, num2);

    return 0;
}

void larger_of(double * x, double * y)
{
    *x = *y = *x > *y ? *x : *y;
}