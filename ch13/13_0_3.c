#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81
#define BUFSIZE 1024

void append(FILE * source, FILE * dest);

int main(void)
{
    char file_app[SIZE];
    char file_src[SIZE];
    FILE *fa, *fs;
    int files = 0;


    puts("Enter the destination file:");
    gets(file_app);
    if((fa = fopen(file_app, "a"))== NULL)
    {
            printf(stderr, "%s can't be opened\n", file_app);
            exit(EXIT_FAILURE);
    }

    puts("Enter the first source file(empty to quit):");
    if (gets(file_src) != NULL && file_src[0] != '\0')
    {
        if(strcmp(file_src, file_app))
            fputs("Can't append file to it self", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "%s can't be opened\n", file_src);
        else
        {
            append(fs, fa);
            if(ferror(fs) != 0)
                fprintf(stderr, "Error in reading %s file.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing %s file.\n",file_app);
            fclose(fs);
            files++;
            printf("File %s appened.\n",file_src);
            printf("Plz enter the next file (empty to quit):\n");
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