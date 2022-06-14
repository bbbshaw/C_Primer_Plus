#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    double num;
    int exp;

    //  gcc 11_14.c -lm
    //  ./a.out.c 2  3

    if (argc != 3)
        printf("Usage : %s number exponent", argv[0]);
    else
    {
        num = atof(argv[1]);
        exp = atoi(argv[2]);

        printf("%f to the power of %d = %f\n", num, exp, pow(num, exp));
    }
    
    return 0;
}