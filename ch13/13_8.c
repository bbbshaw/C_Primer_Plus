#include <stdio.h>
#include <stdlib.h>

#define SIZE 41

int main(int argc, char *argv[])
{
    int count = 0;
    char ch0, ch1;
    char file_name[SIZE];
    FILE *fp;
    int i;
    
    ch0 = argv[1][0];
    
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s character file1 file2...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    else if (argc == 2)
    {
        printf("Plz enter the file name:\n");
        while(gets(file_name))
        {
            if((fp = fopen(file_name, "r")) == NULL)
            {
                fprintf(stderr, "Can't open file %s.\n", file_name);
                exit(EXIT_FAILURE);
            }
            while((ch1 = getc(fp)) != EOF)
            {
                if (ch0 == ch1)
                    count++;  
            }
            printf("There are %d character %c in file %s.\n", count, ch0, file_name);
            fclose(fp);
            printf("Plz enter the next file:\n");
        }
    }

    else 
    {
        for ( i = 2; i < argc; i++)
        {
            if((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open file %s.\n", argv[i]);
                continue;
            }
            count = 0;
            while((ch1 = getc(fp)) != EOF)
            {
                if(ch0 == ch1)
                    count++;
            } 
            printf("There are %d character %c in file %s.\n", count, ch0, argv[i]);
            fclose(fp);    
        } 
    }
    return 0;
}