#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char showmenu(void);
void eatline(void);
char * s_gets(char * st, int n);
void ToUpper (char *str);
void ToLower (char *str);
void Transpose(char *str);
void Dummy(char * str);
void show(void (*fp)(char *), char * str);


int main(void)
{
    char line[LEN];
    char choice;
    void (*pfun)(char *);
    char copy[LEN];

    puts("Please enter the string(Empty to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice)
            {
            case 'u':
                pfun = ToUpper;
                break;
            
            case 'l':
                pfun = ToLower;
                break;

            case 't':
                pfun = Transpose;
                break;

            case 'o':
                pfun = Dummy;
                break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter the next string(Empty to quit):"); 
    }
    puts("Bye.");

    return 0;  
}

char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase l) lowercase"); 
    puts("t) transposed case o) original case"); 
    puts("n) next string");

    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("ulton", ans) == NULL)        //return the first address 
    {
        puts("Please enter a, u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;   
}

void ToUpper (char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower (char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char *str)
{
    while(*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char * str)
{

}

void show(void (*fp)(char *), char * str)
{
    (*fp)(str);
    puts(str);
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