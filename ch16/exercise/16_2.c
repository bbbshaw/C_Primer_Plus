#include <stdio.h>

#define HARMONIC_AVE(X, Y)   ((2*(X)*(Y)) / ((X)+(Y)))

int main(void)
{  
    double x, y;
    x = 6.0;
    y = 8.0;

    printf("%.2lf and %.2lf harmonic average is %.2lf\n", x, y, HARMONIC_AVE(x, y));
    return 0;
}