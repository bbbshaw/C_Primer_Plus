#include <stdio.h>

int main(void)
{
    const int app_val = 150;
    int weeks = 0, num_fri;
    int fri_ini = 5;

    num_fri = fri_ini;

    while (num_fri < app_val)
    {
        printf("After %d weeks, the numbe of fris is %d.\n", weeks, num_fri ); 
        
        weeks++;
        num_fri -= weeks;
        num_fri *= 2;
        
    }
    printf("\n"); 
    
    return 0;

}