#include <stdio.h>

char get_choice(void);
char get_first(void);
void count(void);


int main(void)
{
    char choice;

    while ((choice = get_choice()) != 'q')

    {
        switch (choice)
        {
            case 'a':
                printf("Buy low and sell high.\n");
                break;

            case 'b':
                putchar('\a');
                break;

            case 'c':
                count();
                break;
            
            default:
                printf("Program error!\n");
                break;
        }
    }
    printf("Done.\n");
    

    return 0;

}

char get_choice(void)
{
    int ch;

    printf("Plz enter the letter of your choice:\n");
    printf("a. advice          b. bell\n");
    printf("c. count           q. quit\n");
    ch = get_first();

    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Plz enter a, b, c, or 'q' to quit\n");
        ch = get_first();
    }
    
    return ch;
}

char get_first(void)
{

    int ch;

    ch = getchar();

    while (getchar()!= '\n')
    {
        continue;
    }

    return ch;

}

void count(void)
{
    int number, i;
    
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("\n");

    for ( i = 1; i <= number; i++)
    {
        printf("%d\n",i);
    }
    while (getchar() != '\n')
    {
        continue;
    }
    

}
