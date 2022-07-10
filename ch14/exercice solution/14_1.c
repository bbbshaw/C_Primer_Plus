#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 10
#define MAX 20
#define MONTHS 12

char * s_gets(char * st, int n);
int days(char *st);

struct month
{
    char monthname[LEN];
    char abbrev[LEN];
    int days;
    int num_month;
};

const struct month months[12] =
{
    {"january", "jan", 31, 1},
    {"february", "feb", 28, 2},
    {"march", "mar", 31, 3},
    {"april", "apr", 30, 4},
    {"may", "may", 31, 5},
    {"june", "jun", 30, 6},
    {"july", "jul", 31, 7},
    {"august", "aug", 31, 8},
    {"september", "sep", 30, 9},
    {"october", "oct", 31, 10},
    {"november", "nov", 30, 11},
    {"december", "dec", 31, 12}
};

int main(void)
{
    char input[MAX];
    int total;

    puts("Please enter the month:");
    while (s_gets(input, MAX) != NULL && input[0] != '\0')
    {
        total = days(input);
        printf("There are %d days through %s.\n", total, input);
        printf("Enter the next month (empty to quit):");
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

int days(char *st)
{
    int total = 0;
    int i = 0;
    int count;

    while (st[i])
    {
        st[i] = tolower(st[i]);
        i++;
    }

    for ( i = 0; i < MONTHS; i++)
    {
        if (strcmp(st, months[i].monthname) == 0)
            break;
    }

    if (i < MONTHS)
    {
        for (count = 0; count < months[i].num_month; count++)
            total += months[count].days;
    }
    return total;
}