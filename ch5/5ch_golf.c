#include <stdio.h>
#define  SIZE 10
#define  PAR 72


int main(void)
{
    int scores[SIZE], index;
    int sum = 0;
    float ave, handicap;


    printf("Enter %d golf scoares:\n", SIZE);
    
    //enter the score
    for (index = 0; index < SIZE; index++)
    {
        scanf("%d", &scores[index]);
    }
    
    //show all the scores
    printf("The socres you enter are: \n");

    for (index = 0; index < SIZE; index++)
    {
        printf("%5d", scores[index]);
    }
    printf("\n");

    //cal the sum 
    for (index = 0; index < SIZE; index++)
    {
        sum = sum + scores[index];
    }
    printf("The sum: %5d\n", sum);
    
    //cal the ave
    ave = (float) sum / SIZE;
    printf("The ave: %0.2f\n", ave);

    //cal the handicap
    handicap = ave - PAR;
    printf("The handicap: %.0f.\n", handicap);

    
    return 0;


}