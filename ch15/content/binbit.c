#include <stdio.h>

void itob(int n, char *pt);
void show_bstr(const char *pt);

int main(void)
{
    int number;
    char bin_str[33];

    puts("Please enter integer:");
    while(scanf("%d", &number) == 1)
    {
        itob(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        puts("");
    }
    puts("Bye");

    return 0;
}

void itob(int n, char *pt)
{
    int i;

    for ( i = 31 ; i >= 0; i--, n >>= 1)
        pt[i] = (1 & n) + '0';
    
    pt[32] = '\0';
}

void show_bstr(const char *pt)
{
    int i= 0;

    while(pt[i])
    {
        putchar(pt[i]);
        if (++i % 4 == 0 && pt[i])
            putchar(' ');
    }
}