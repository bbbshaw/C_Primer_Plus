#include <stdio.h>
#include <stdlib.h>

#define SIZE 41

int main(void)
{
    char file[SIZE];
    FILE *fp;
    int count;
    long len;
    char ch;

    printf("Enter the name of the file to be processed:");
    gets(file);

    if((fp = fopen(file, "r")) == NULL);
    {
        printf("Reverse can't open %s.\n", file);
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
    
    for ( count = 1; count <= len; count++)
    {
        fseek(fp, -count, SEEK_END);  
        ch = getc(fp);
        putchar(ch);
    }
    putchar('\n');

    return 0;
}