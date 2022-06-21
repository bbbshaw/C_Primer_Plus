#include <stdio.h>
#include <stdlib.h>

#define SIZE 41

int main(void)
{
    char name[SIZE];
    FILE *fp;
    unsigned long count = 0;
    int ch;

    printf("Enter the file name:\n");
    gets(name);

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s file.\n", name);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", name, count);
       
    return 0;
}