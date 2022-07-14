#include <stdio.h>
#include <string.h>
#include <math.h>

#define BITS 33

int check_value(const char * str);
int strtobin(const char * str);
char *int_to_binstr(int num, char *pt);

int main(int argc, char * argv[])
{
    int value1;
    int value2;
    char bstr[BITS];

    char num2[BITS];

    if (argc != 3)
        printf("Usage: %s Binary_number_1 Binary_number_2\n", argv[0]);

    if (!check_value(argv[1]))
        printf("Invalid input.\n");

    if (!check_value(argv[2]))
        printf("Invalid input.\n");
    
    value1 = strtobin(argv[1]);
    value2 = strtobin(argv[2]);
    
    printf("~%s = %s \n", argv[1], int_to_binstr(~value1, bstr));
    printf("~%s = %s \n", argv[2], int_to_binstr(~value2, bstr));
    printf("%s & %s = %s \n", argv[1], argv[2], int_to_binstr(value1 & value2, bstr));
    printf("%s | %s = %s \n", argv[1], argv[2], int_to_binstr(value1 | value2, bstr));
    printf("%s ^ %s = %s \n", argv[1], argv[2], int_to_binstr(value1 ^ value2, bstr));
}

int check_value(const char * str)
{
    int i;

    while (*str != '\0')
    {
        if (*str != '0' && *str != '1')
            return 0;
        str++;
    }
    
    return 1;
}

int strtobin(const char * str)
{
    int len = 0;
    int value = 0;
    int i, j;
    
    len = strlen(str);
    for ( i = 0, j = len; i < len; i++, j--)
    {
        value += (str[i] - '0') * pow(2, j - 1);
    }
    return value;
}

char *int_to_binstr(int num, char *pt)
{
    int i;

    for ( i = BITS - 1; i >= 0; i--, num>>=1)
        pt[i] = (1 & num) + '0';

    pt[BITS] = '\0';

    return pt;
}