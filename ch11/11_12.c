#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 41

int main(void)
{
    char str[SIZE];
    char *pt;
    int count_words = 0;
    int count_upper = 0;
    int count_lower = 0;
    int count_punt = 0;
    int count_digits = 0;
    bool flag = false;

    pt = str;

    printf("Please enter a string: \n");
    gets(str);
    printf("The string is:\n");
    puts(str);

    while (*pt != '\0')
    {
        if (islower(*pt))
            count_lower++;
        else if (isupper(*pt))
            count_upper++;
        else if (isdigit(*pt))
            count_digits++;
        else if (ispunct(*pt))
            count_punt++;

        if (!isspace(*pt) && !flag)
        {
            flag = true;
            count_words++;
        }
        if (isspace(*pt) && flag)
            flag = false;

        pt++;
    }
    
    printf("The number of words:%d\n", count_words);
    printf("The number of uppercase:%d\n", count_upper);
    printf("The number of lowercase:%d\n", count_lower);
    printf("The number of punt character:%d\n", count_punt);
    printf("The number of digits:%d\n", count_digits);

    return 0;
}



