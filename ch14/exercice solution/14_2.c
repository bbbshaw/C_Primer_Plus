#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 20
#define MONTHS 12

char * s_gets(char * st, int n);
int get_month(char *st);
void clear(void);
int cal_days(int days, int month, int year);

struct month
{
    char monthname[LEN];
    char abbrev[LEN];
    int days;
    char num_month[LEN];
};

struct month months[12] =
{
    {"january", "jan", 31, "1"},
    {"february", "feb", 28, "2"},
    {"march", "mar", 31, "3"},
    {"april", "apr", 30, "4"},
    {"may", "may", 31, "5"},
    {"june", "jun", 30, "6"},
    {"july", "jul", 31, "7"},
    {"august", "aug", 31, "8"},
    {"september", "sep", 30, "9"},
    {"october", "oct", 31, "10"},
    {"november", "nov", 30, "11"},
    {"december", "dec", 31, "12"}
};


int main(void)
{
    char input[LEN];
    int days;
    int year;
    int ret_month;
    int total_days;

    puts("Please enter the day:");
    scanf("%d", &days);
    clear();
    
    puts("Please enter the month:");
    s_gets(input, LEN);
    ret_month = get_month(input);

    puts("Please enter the year:");
    scanf("%d", &year);
    clear();

    total_days = cal_days(days, ret_month, year);

    printf("YEAR: %d MONTH: %s DAYS: %d  TOTAL DAYS: %d.\n", year, input, days, total_days);

    return 0;
}

int get_month(char *st)
{
    int i;
    
    while (st[i])
    {
        st[i] = tolower(st[i]);
        i++;
    }
    
    for ( i = 0; i < MONTHS; i++)
    {
        if (strcmp(st, months[i].monthname) == 0 ||
                strcmp(st, months[i].abbrev) == 0||
                strcmp(st, months[i].num_month) == 0)   
                break;
    } 
    return i;
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
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void clear(void)
{
    while (getchar() != '\n')
        continue;
}

int cal_days(int days, int month, int year)
{
    int i;
    int total = 0;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        months[1].days = 29;

    if (month == 0)
    {
        total = days;
    }
    else 
    {
        for ( i = 0; i < month; i++)
        {
            total += months[i].days;
        }
        total += days;
    }
    return total;
}
