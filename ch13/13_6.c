#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 61

int main(void)
{
    char in_file[SIZE];
    char out_file[SIZE];
    FILE *in, *out;
    int count = 0;
    int ch;

    //obtain the file name
    printf("Please enter the source file name:\n");
    gets(in_file);

    //attempt to open files
    if((in = fopen(in_file, "r")) == NULL)
    {
        fprintf(stderr, "Can not open file %s.\n", in_file);
        exit(EXIT_FAILURE);
    }
    
    //set up output
    strncpy(out_file, in_file, SIZE - 5);
    out_file[SIZE - 5 ] = '\0';
    strcat(out_file, ".red");
    if ((out = fopen(out_file, "w")) == NULL)
    {
        fprintf(stderr, "Can not open the target file %s.\n", out_file);
        exit(EXIT_FAILURE);
    }
    
    //copy data
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);  
    }

    //close file
    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}