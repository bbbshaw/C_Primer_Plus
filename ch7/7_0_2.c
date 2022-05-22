#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '|'

int main(void)
{
    char ch, pre;
    unsigned long n_chars = 0;
    unsigned long n_lines = 0;
    unsigned long n_words = 0;
    int p_line = 0;
    bool inword = false;



    while ((ch = getchar()) != STOP)
    {   
        n_chars++;
        if (ch == '\n')
        {
            n_lines++;
        }

        if (!isspace(ch) && !inword)        //issapce(ch) ture when is space 
        {
            n_words++;
            inword = true;
        }
        if (isspace(ch) && inword)
        {
            inword = false;
        }
        pre = ch; //the last character 
              
    }
    if (pre != '\n')
    {
        p_line = 1;
    }
    
    printf("character:%lu \nlines:%lu \nwords: %lu \np_line: %d\n", n_chars, n_lines, n_words, p_line);
    

    return 0; 
}