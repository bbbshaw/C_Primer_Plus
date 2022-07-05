#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEN 31

char * s_gets(char * st, int n);

enum spectrum {
    red, orange, yellow, green, blue, violet
};

const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;
    
    puts("Enter a color (empty line to quit):");
    while(s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = 0; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
        {
            switch (color)
            {
                case red : puts("red");
                    break;
                case orange : puts("orange");
                    break;
                case yellow : puts("yellow");
                    break; 
                case green : puts("green");
                    break;
                case blue : puts("blue") ;
                    break;
                case violet : puts("violet"); 
                    break;
            }
        }
        else 
            printf("I don't lnow about the color %s.\n", choice);
        
        color_is_found = false;
        puts("Next color, please empty (line to quit):");
    }
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;       
    }
    return ret_val;  
}