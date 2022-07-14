#include <stdio.h>

#define BITS 33

int count_on(int num);
char * int_to_binstr(int num, char *pt);

int main(void)
{
    int num;
    char str[BITS];

    printf("Please enter an integer:\n");
    while(scanf("%d", &num) == 1 && num >= 0)
    {   
        printf("%d (%s) has %d bits on.\n", num, int_to_binstr(num, str), count_on(num));
        printf("Please enter next integer:\n");
    }
    return 0;
}

int count_on(int num)
{
    int count = 0;
    int i;
    for ( i = 0; i < 32 ; i++, num >>= 1)
    {
        if ((1 & num) == 1)
            count++; 
    }

    return count;
}

char * int_to_binstr(int num, char *pt)
{
    int i;

    for ( i = BITS - 2; i >= 0; i--, num>>=1)
        pt[i] = (1 & num) + '0';

    pt[BITS - 1] = '\0';

    return pt;
}