#include <stdio.h>
#include <ctype.h>


int convert( char ch);

int main(void)
{
    int ch;

    printf("Plz enter the characters: \n");
    while ((ch = getchar()) != EOF)
    {
        if (convert(ch) == -1 && ch != '\n')
            printf("%c is not a alpha.\n", ch);
        
        if (convert(ch) == -1 && ch == '\n')
            printf("Plz enter the characters:");
       
        else 
            printf("The numerical location of '%c' is %d\n", ch, convert(ch));      
    }
    printf("Done.\n");
    
    return 0;
}

int convert( char ch)
{
    int n;

    if(isalpha(ch))
    {
        ch = toupper(ch);
        n = ch - 64;
        return n;
    }
    else 
        return -1;
    
}