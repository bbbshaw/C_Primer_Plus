#include <stdio.h>
#include <ctype.h>

void print_menu(void);
char get_choice(void);
char get_first(void);
float get_number(void);

int main(void)
{
    float first_number, second_number; 
    char operation;

    print_menu();
    while((operation = get_choice()) != 'q')
    {
        printf("Plz enter the first number:");
        first_number = get_number();
        printf("Plz enter the second number:");
        second_number = get_number();


        switch (operation)
        {
        case 'a':
            printf("%.2f + %.2f = %.2f\n", first_number, second_number, first_number + second_number);
            break;

        case 's':
            printf("%.2f - %.2f = %.2f\n", first_number, second_number, first_number - second_number);
            break;

        case 'm':
            printf("%.2f * %.2f = %.2f\n", first_number, second_number, first_number * second_number);
            break;
        
        case 'd':
            while (second_number == 0)
            {
                printf("Enter a number other than 0: ");
                second_number = get_number();
            }    
            printf("%.2f / %.2f = %.2f\n", first_number, second_number, first_number / second_number);
            break;
            
        default:
            break;
        }
        print_menu();
    }
    printf("Bye.\n");

    return 0;
}

void print_menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add                s. substract\n");
    printf("m. multiply           d. divide\n");
    printf("q. quit\n");
}

char get_choice(void)
{
    char ch;

    ch = get_first();

    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Plz enter a, s ,d or q: ");
        ch = get_first();

    }
    
    return ch;

}

char get_first(void)
{
    int first;

    while(isspace(first = getchar()));

    while ( getchar() != '\n')
    {
        continue;
    }
    return first;

}

float get_number(void)
{
    float number;
    int ch;
    
    while(scanf("%f", &number) != 1) 
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not valid number.\n");
        printf("Plz enter a number, such as 2.5, -1.78E8, or 3: ");
        
    }
    return number;
}