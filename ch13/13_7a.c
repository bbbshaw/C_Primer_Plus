#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int ch1, ch2;

    //check the command line
    if(argc != 3)
    {
        fprintf(stderr, "Invalid command. Usage: %s file1 file2.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //attempt to open the file
    if((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((fp1 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    ch1 = getc(fp1);
    ch2 = getc(fp2);

    while (ch1 != EOF || ch2 != EOF)
    {
        while(ch1 != '\n')
        {
            putchar(ch1);
            ch1 = getc(fp1);
        }
        if (ch1 != EOF)
        {
            putchar('\n');
            ch1 = getc(fp1);
        }

        while (ch2 != '\n' && ch2 != EOF)
        {
            putchar(ch2);
            ch2 = getc(fp2);
        }
        if (ch2 != EOF)
        {
            putchar('\n');
            ch2 = getc(fp2);
        }
    }
    if(fclose(fp1) != 0 || fclose(fp2) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}