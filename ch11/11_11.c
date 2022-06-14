#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 41
#define LIM 10
#define QUIT "quit"

void print_menu(void);
void print_sour(char * pt1[], int n);
void print_ascii(char * pt2[], int n);
void print_length(char * pt3[], int n);
int first_word(char *pt);
void print_first_word(char * pt4[], int n);

int main(void)
{
    char str[LIM][SIZE];
    char *ptr[LIM];
    char ch;
    int i, num;

    while (1)
    {
        printf("Please enter up to 10 strings (EOF) to stop:\n");
        for ( num = 0; num < LIM; num++)
        {
            gets(str[num]);
            ptr[num] = str[num];
            if (str[num][0] == '\0')
                break;
        }
        print_menu();
        printf("\n");

        ch = getchar();
        while (getchar() != '\n')
            continue;
   
        switch (ch)
        {
            case 'a': print_sour(ptr, num);
                      break;
            case 'b': print_ascii(ptr, num);
                      break;
            case 'c': print_length(ptr, num);
                      break;
            case 'd': print_first_word(ptr, num);
                      break;
            default: printf("Error!\n");
                     break;
        }
        printf("\n");
    }
    printf("Done.\n");

    return 0;
}

void print_menu(void)
{   
    printf("a. print the sourse strings.     b. print in order of ASCII.\n");
    printf("c. print in order of length.	 d. print in order of the first word's length.\n");
    printf("q. quit.\n");
    printf("Enter a character (a, b, c, d or q):");
}

void print_sour(char * pt1[], int n)
{
    int i;

    for ( i = 0; i < n; i++)
        puts(pt1[i]);
}

void print_ascii(char * pt2[], int n)
{
    int i, j;
    char * temp;

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; i < n; j++)
        {
            if (strcmp(pt2[i], pt2[j]) > 0)
            {
                temp = pt2[i];
                pt2[j] = pt2[i];
                pt2[i] = temp;
            }
        }
        for ( i = 0; i < n; i++)
            puts(pt2[i]);
    }
}

void print_length(char * pt3[], int n)
{
    int i, j;
    char * temp;

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; i < n; j++)
        {
            if (strlen(pt3[i]) > strlen(pt3[j]))
            {
                temp = pt3[i];
                pt3[j] = pt3[i];
                pt3[i] = temp;
            }
        }
        for ( i = 0; i < n; i++)
            puts(pt3[i]);
    }
}

int first_word(char * pt)
{
    int i;
    int count = 0;

    while (!isalpha(pt[i]))
        i++;
    while (isalpha(pt[i]))
    {
        i++;
        count++;
    }
    return count;  
}

void print_first_word(char * pt4[], int n)
{
    int i, j;
    char * temp;

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; i < n; j++)
        {
            if (first_word(pt4[i]) > first_word(pt4[j]))
            {
                temp = pt4[i];
                pt4[j] = pt4[i];
                pt4[i] = temp;
            } 
        }
    }
    for ( i = 0; i < n; i++)
        puts(pt4[i]);
}
