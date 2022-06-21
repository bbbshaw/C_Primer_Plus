#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81
#define BUF_SIZE 1024

void to_upper_copy(FILE *sour, FILE *tar);

int main(void)
{
    char source[SIZE];
    char target[SIZE];
    FILE *fp_s;
    FILE *fp_t;
    int ch;

    //get source and target file 
    printf("Plz enter the source file name:\n");
    gets(source);
    printf("Plz enter the target file name:\n");
    gets(target);

    //check source and target file
    if (strcmp(source, target) == 0)
    {
        fprintf(stderr, "Source file and target file can't be the same.\n");
        exit(EXIT_FAILURE);
    }

    //attempt to open source and target file
    if((fp_s = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s file.\n", source);
        exit(EXIT_FAILURE);
    }

    if((fp_s = fopen(target, "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s file.\n", target);
        exit(EXIT_FAILURE);
    }

    //copy and toupper
    while((ch = getc(fp_s)) != EOF)
    {
        ch = toupper(ch);
        putc(ch, fp_t);
    }

    //close files
    if (fclose(fp_s) != 0 || fclose(fp_t) != 0)
        fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}

