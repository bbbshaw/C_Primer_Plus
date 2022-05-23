#include <stdio.h>
#include <stdbool.h>


int get_in(void);
bool bad_limits(int begin, int end, int low, int high);
int squares(int begin, int end);

int main(void)
{
    const int MIN = -1000;
    const int MAX = 1000;

    int start, stop, sum;

    printf("This program computes the sum of squares of integers in a range.\n");
    printf("The lower should not be less than %d.\n", MIN);
    printf("THe upper should not be greater than %d.\n", MAX);
    printf("Enter the range of integer.\n");
    printf("Enter the lower limit:");
    start = get_in();

    printf("Enter the upper limit:");
    stop = get_in();

    while (start !=0 || stop != 0)
    {
        if (bad_limits(start, stop, MAX, MIN))
            printf("Plz enter again.\n");
        
        else
        {
            sum = squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %d to %d is %d.\n", start, stop, sum);

        }
        printf("Enter the lower limit ('0'for both to quit):");
        start = get_in();

        printf("Enter the upper limit ('0'for both to quit):");
        stop = get_in();
    }
    printf("Done.\n");

    return 0;

}

int get_in(void)
{
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is invalid input.\n");
        printf("Plz enter an integer again.\n");
    }
    return input;
    
}

bool bad_limits(int begin, int end, int high, int low)
{
    bool not_good = false;

    if (begin > end)
    {
       printf("%d is not smaller than %d.\n", begin, end);
       not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("The values must be greater than %d", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("The values must be smaller than %d", high);
        not_good = true;
    }
    return not_good;
         
}

int squares(int begin, int end)
{
    int sum = 0;
    int i;


    for (i = begin ;  i <= end; i++)
    {
        sum += i * i;
    }
    
    return sum;

}