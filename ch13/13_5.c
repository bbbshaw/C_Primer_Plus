#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81
#define BUFSIZE 1024

void append(FILE * source, FILE * dest);

int main(int argc, char *argv[])
{
    char file_app[SIZE];
    char file_src[SIZE];
    FILE *fa, *fs;
    int files = 0;
    int i;

    if (argc < 3)
    {
        fprintf(stderr, "Invalid command.\n");
        exit(EXIT_FAILURE);
    }
    
    if((fa = fopen(argv[1], "a"))== NULL)
    {
            fprintf(stderr, "%s can't be opened\n", argv[1]);
            exit(EXIT_FAILURE);
    }

    for(i = 2; i < argc; i++)
    {
        if(strcmp(argv[1], argv[i]))
            fputs("Can't append file to it self", stderr);
        else if ((fs = fopen(argv[2], "r")) == NULL)
            fprintf(stderr, "%s can't be opened\n", file_src);
        else
        {
            append(fs, fa);
            if(ferror(fs) != 0)
                fprintf(stderr, "Error in reading %s file.\n", argv[1]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing %s file.\n",argv[i]);
            fclose(fs);
            files++;
            printf("File %s appened.\n", argv[i]);
        }
    }
    printf("Done. %d files appended.\n",files);
    fclose(fa);

    return 0;
}

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while((fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}