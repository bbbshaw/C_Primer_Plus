#include <stdio.h>



int main(void)
{
    int i, j, k, l, row;
    char ch;
    

    printf("Plz enter an uppercase letter: \n");
    scanf("%c", &ch);
    
    row = ch - 'A';
    
    for ( i = 0; i <= row ; i++)
    {
        for ( j = i; j < row; j++)
        {
            printf(" ");
        }
        for ( k = 0; k< i+1; k++)
        {
            printf("%c", 'A' + k);
        }
        for ( l = i; l > 0; l--)
        {
            printf("%c", 'A' + (l-1));
        }
        
        printf("\n");
        
        
    }   
    
    return 0;

}