#include <stdio.h>
#include <ctype.h>

#define SIZE 41

int my_atoi(char * pt);

int main(void)
{
    char ch[SIZE];
    
    while (gets(ch) && ch[0] != '\0')
    {
        printf("%d\n", my_atoi(ch));
        puts("Please enter next:");
    }
    return 0;
}

int my_atoi(char * pt)
{
    int sign = 1;
    int num = 0;

    while (isspace(*pt))
        pt++;
    if (*pt == '-')
    {
        sign = -1;
        pt++;
    }
    if (*pt == '+')
    {
        sign = 1;
        pt++;
    }
    else 
    {
        while (isdigit(*pt))
        {
            num = (num * 10) + (*pt - '0');
            pt++;
        }
    }
    num *= sign;

    return num;
}