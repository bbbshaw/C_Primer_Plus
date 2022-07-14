#include <stdio.h>

unsigned int totate_l(unsigned int num, unsigned int shift);
char *int_to_str(int num, char *pt);

int main(void)
{
    unsigned int value;
    unsigned int places;
    unsigned int rot;
    char bstr1[33];
    char bstr2[33];

    printf("Please enter an integer:\n");
    while (scanf("%u", &value))
    {
        printf("Please enter the number of bits:\n");
        scanf("%u", &places);

        rot = totate_l(value, places);
        int_to_str(value, bstr1);
        int_to_str(rot, bstr2);

        printf("%u rotated is %u\n", value, rot);
        printf("%s rotated is %s\n", bstr1, bstr2);
        printf("Please enter the next integer:\n");
    }
    return 0;
}

unsigned int totate_l(unsigned int num, unsigned int shift)
{
    unsigned int overflow;

    overflow = num >> (32 - shift);

    return (num << shift) | overflow;
}

char *int_to_str(int num, char *pt)
{
    int i;

    for (i = 31; i >= 0; i--, num >>= 1)
        pt[i] = (num & 1) + '0';
    pt[32] = '\0';

    return pt;
}