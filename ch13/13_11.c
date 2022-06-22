#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[SIZE];

    if (argc != 3)
    {
        printf("Uasge: %s string filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(str, SIZE, fp))    //target length source   to '\n'  or length -1  or EOF
    {
        if(strstr(str, argv[1]))
            fputs(str, stdout);
    }
    fclose(fp);

    return 0;
}
