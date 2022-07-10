#include <stdio.h>
#include <math.h>

#define LEN 10

void transform(double *src, double *targ, int n, double (*fun)(double));
double square(double x);
double cube(double x);

int main(void)
{
    double source[LEN];
    double target[LEN];
    int i;

    for ( i = 0; i < LEN; i++)
        source[i] = i;
    
    transform(source, target, LEN, sin);
    for ( i = 0; i < LEN; i++)
        printf("sin(%.2f) = %.2f\n", source[i], target[i]);
    puts("");

    transform(source, target, LEN, square);
    for ( i = 0; i < LEN; i++)
    for ( i = 0; i < LEN; i++)
        printf("(%.2f)square = %.2f\n", source[i], target[i]);
    puts("");

    transform(source, target, LEN, cube);
    for ( i = 0; i < LEN; i++)
    for ( i = 0; i < LEN; i++)
        printf("(%.2f)cube = %.2f\n", source[i], target[i]);
    puts("");
    
    return 0;
}

void transform(double *src, double *targ, int n, double (*func)(double))
{
    for(int i = 0; i < n; i++)
        targ[i] = func(src[i]);
}

double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}
