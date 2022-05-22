#include <stdio.h>
#define COVERAGE 200

int main(void)
{
    int sqr_feet;
    int cans;

    printf("Enter the number of square feet to be paint:\n");
    
    while (scanf("%d", &sqr_feet) == 1)
    {
        cans = sqr_feet / COVERAGE;
        cans += (sqr_feet % COVERAGE == 0) ? 0 : 1;
        printf("You need %d %s of painting.\n", cans, (cans == 1 ? "can" : "cans"));
        printf("Enter again: \n");
    }
    
    
    return 0;

}