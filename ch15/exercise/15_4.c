#include <stdio.h>

#define BITS 33

int check_bit(int num, int pos);
char *int_to_str(int num, char *pt);

int main(void)
{
    int num;
    int bit_pos;

    printf("Enter an integer and the bit positon:\n");
    while(scanf("%d %d", &num, &bit_pos) == 2 && num >= 0)
        printf("The %d position of %d is %d\n", bit_pos, num, check_bit(num, bit_pos));

    return 0;
}

int check_bit(int num, int pos)
{
    char str[BITS];

    int_to_str(num, str);
    if (str[BITS - 2 - pos] == '1')
        return 1;
    else 
        return 0;
}

char *int_to_str(int num, char *pt)
{
    int i;

    for (i = BITS - 2; i >= 0; i--, num >>= 1)
        pt[i] = (num & 1) + '0';
    pt[BITS - 1 ] = '\0';

    return pt;
}

