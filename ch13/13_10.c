#include <stdio.h>
#include <stdlib.h>

#define SIZE 41

int main(void)
{
    char file_name[SIZE];
    FILE *fp;
    long index;
    long num;
    int ch;

    printf("Please enter a file name: \n");
    gets(file_name);

    if((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file %s.\n", file_name);
        exit(EXIT_FAILURE);
    }

    //get the length of the file
    fseek(fp, 0L, SEEK_END);
    num = ftell(fp);

    printf("Plz enter the position you want to start:\n");
    while(scanf("%ld", &index) == 1)
    {
        if (index < num && index > 0)
        {
            fseek(fp, index, SEEK_SET);
            while(((ch = getc(fp)) != '\n') && (ch != EOF))
                putchar(ch);
        }
        puts("");
         
        if (index > num)
        {
            printf("Plz enter a num smaller than %ld.\n", num);
            continue;
        }
        if (index < 0)
            break;

        printf("Please enter the next position:\n");
    }
    printf("Done.\n");

    return 0;
}