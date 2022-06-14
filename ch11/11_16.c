#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    int len;
    int i;

    if (argc != 3)
    {
        printf("Not enough arguments.\n");
        return 0;
    }
    if (strcmp(argv[1], "-p") != 0 && strcmp(argv[1], "-u") != 0 && strcmp(argv[1], "-l") != 0)
    {
        printf("Please enter -p -u -l\n");
        return 0;
    }

    len = strlen(argv[2]);

    if (strcmp(argv[1], "-p") == 0)
        puts(argv[2]);
    
    if (strcmp(argv[1], "-u") == 0)
    {
        for (i = 0; i < len; i++)
            putchar(toupper(argv[2][i]));
            puts("");
    }
    if (strcmp(argv[1], "-l") == 0)
    {
        for (i = 0; i < len; i++)
            putchar(tolower(argv[2][i]));
            puts("");
    }
    return 0;
}