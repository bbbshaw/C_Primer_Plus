#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int x ,y;

    printf("Plz enter the character:\n");
    scanf("%c", &ch);

    printf("Enter two integer:\n");
    scanf("%d %d", &x, &y);

    chline(ch, x, y);

    return 0;
}

void chline(char ch, int i, int j)
{
    int k = 0;

    while (k++ < i)
        printf(" ");
    while (i++ <= j )
        printf("%c", ch);
    
    printf("\n");
}