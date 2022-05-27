#include <stdio.h>

void print_chara(char ch, int x, int y);

int main(void)
{
    char chara;
    int times, lines;

    printf("Plz enter a character:\n");
    scanf("%c", &chara);
    printf("Plz enter the number of times and lines:\n");
    scanf("%d %d", &times , &lines);

    print_chara(chara, times, lines);

    return 0;
}

void print_chara(char ch, int x, int y)
{
    int i, j;


    for (i = 1; i <= y; i++)
    {
        for ( j = 1; j <= x; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}