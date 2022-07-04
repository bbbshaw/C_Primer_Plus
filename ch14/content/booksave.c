#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40
#define MAXBKS 10

char * s_gets(char * st, int n);

struct book
{
    char title[MAX];
    char author[MAX];
    float value;
};

int main(void)
{
    FILE *pbooks;
    int count = 0;
    int index;
    int filecount;

    struct book library[MAXBKS];

    if((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Can open the book.dat.\n");
        exit(EXIT_FAILURE);
    }
    rewind(pbooks);     //go to start of the file

    while(count < MAXBKS && fread(&library[count], sizeof(struct book), 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Curren contents of book.dat:");
        printf("%s by %s: $%.2f.\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;

    if (count == MAXBKS)
    {
        puts("The book file is full.");
        exit(EXIT_FAILURE);
    }

    // read new books information into file
    puts("Please enter a new book titles.(Press ENTER at the start of a line to stop)");
    while (count < MAXBKS && s_gets(library[count].title, MAX) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author of this book:");
        s_gets(library[count].author, MAX);
        puts("Now enter the price of this book:");
        scanf("%f", &library[count].value);
        count++;
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Please enter the title of next book:");  
    }

    //show the file information
    if (count > 0)
    {
        puts("Here is the book list:");
        for ( index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        fwrite(&library[filecount], sizeof(struct book), count - filecount, pbooks);        //write the book information into file
    }
    else 
        puts("No books.");

    puts("Bye.");
    fclose(pbooks);
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;   
    }
    return ret_val;
}