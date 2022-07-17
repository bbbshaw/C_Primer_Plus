#include <stdio.h>
#include <stdarg.h>

double sum(int lim, ...);

int main(void)
{
    double s,t;

    s = sum(3, 1.1, 2.2, 3.3);
    t = sum(4, 2.2, 3.3, 4.4, 5.5);

    printf("s = %.2f\n", s);
    printf("t = %.2f\n", t);

    return 0;
}

double sum(int lim, ...)    //1
{
    va_list ap; //2
    double sum = 0;
    int i;

    va_start(ap, lim);  //3
    for ( i = 0; i < lim; i++)
        sum = va_arg(ap, double);   //4
    va_end(ap);

    return sum;
}