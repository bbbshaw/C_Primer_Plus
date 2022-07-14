#include <stdio.h>
#include <string.h>
#include <math.h>

#define BITS 33

int check_value(const char * str);
int strtobin(const char * str);

int main(void)
{
    char value[BITS];

    printf("Please enter a binary number within 32 bits:\n");

    while (gets(value) && value[0] != '\0')
    {
        if (!check_value(value))
            printf("Invalid input.\n");
        else 
        {
            printf("%s is %d\n", value, strtobin(value));
        }  
        puts("Please enter the next binary number:");
    }

    return 0;
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