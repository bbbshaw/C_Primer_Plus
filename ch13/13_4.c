#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    FILE *fp;
    int ch;

    //check command line 
    if (argc < 2)
    {
        fprintf(stderr,"Error No File.\n");
        exit(EXIT_FAILURE);
    }

    //print the content of each file in command line
    for ( i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        
        printf("%s file content:\n", argv[i]);
        
        puts("************************");
        while((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        puts("************************");
        fclose(fp);
    }
    printf("Done.\n");
    
    return 0;
}