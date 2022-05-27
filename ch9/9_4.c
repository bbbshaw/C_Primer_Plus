#include <stdio.h>

double cal_harmonic_mean(double x, double y);

int main(void)
{
    double num1, num2;

    printf("Plz enter two number:\n");
    scanf("%lf %lf", &num1 , &num2);

    printf("The harmonice mean:%.4lf\n", cal_harmonic_mean(num1, num2));

    return 0;
}

double cal_harmonic_mean(double x, double y)
{
    double har_mean;

    har_mean = 1 / (((1 / x) + (1 / y)) / 2);

   return har_mean;
}