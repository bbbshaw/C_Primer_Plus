#include <stdio.h>
#include <ctype.h>




int main(void)
{
    char ch;

    //ch = getchar();
    while ((ch = getchar())!= '\n')
    {
        if (isalpha(ch))
            putchar(ch + 1);
        else 
            putchar( ch );
        //ch = getchar();     //get next character 
    }
    putchar(ch);        //print a new line


    return 0;
}