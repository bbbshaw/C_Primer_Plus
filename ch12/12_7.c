#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void roll_dice(int sides, int dice);

int main(void)
{
    int sets, sides, dices;
    int i;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop:");
    while (scanf("%d",&sets) && sets > 0)
    {
        printf("How many sides and how many dice?\n");
        scanf("%d %d", &sides, &dices);
        
        printf("Here are %d sets of %d %d-sides throws.\n", sets, dices, sides);
        for ( i = 0; i < sets; i++)
        {
            roll_dice(sides, dices);
        }
        printf("\nHow many sets? Enter q to stop:\n");
    }
    return 0;
}
void roll_dice(int sides, int dice)
{
    int num;
    int tot = 0;
    int i;

    for (i = 0, tot = 0; i < dice; i++)
    {
        num = rand() % sides + 1;
        tot += num;
    }
    printf("%5d", tot);
}