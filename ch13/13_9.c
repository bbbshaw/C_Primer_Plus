#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    int ch;
    int count = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter word to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    while((ch = getc(fp)) != EOF)
    {
        if(ch == '\n')
            count++;
    }

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d.%s\n", ++count, words);

    puts("File contents:");
    rewind(fp);
    while(fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done.\n");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file.\n");
    
    return 0;
}